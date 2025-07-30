#pragma once
#include <windows.h>
#include <comdef.h>
#include <vector>
#include <functional>
#include <stdexcept>
#include <limits>

namespace opt {
    namespace util {

        // Convert VARIANT SafeArray to std::vector<double>
        std::vector<double> SafeArrayToVector(VARIANT& vArray) {
            std::vector<double> result;

            if (vArray.vt != (VT_ARRAY | VT_R8)) {
                throw std::invalid_argument("Expected array of doubles");
            }

            SAFEARRAY* psa = vArray.parray;
            if (!psa) {
                throw std::invalid_argument("Null array");
            }

            LONG lBound, uBound;
            SafeArrayGetLBound(psa, 1, &lBound);
            SafeArrayGetUBound(psa, 1, &uBound);

            double* pData;
            SafeArrayAccessData(psa, (void**)&pData);

            for (LONG i = lBound; i <= uBound; i++) {
                result.push_back(pData[i - lBound]);
            }

            SafeArrayUnaccessData(psa);
            return result;
        }

        // Convert std::vector<double> to VARIANT SafeArray
        VARIANT VectorToSafeArray(const std::vector<double>& vec) {
            VARIANT result;
            VariantInit(&result);

            SAFEARRAYBOUND bounds = { static_cast<ULONG>(vec.size()), 0 };
            SAFEARRAY* psa = SafeArrayCreate(VT_R8, 1, &bounds);

            double* pData;
            SafeArrayAccessData(psa, (void**)&pData);

            for (size_t i = 0; i < vec.size(); i++) {
                pData[i] = vec[i];
            }

            SafeArrayUnaccessData(psa);

            result.vt = VT_ARRAY | VT_R8;
            result.parray = psa;

            return result;
        }

        // Forward declaration
        std::function<double(const std::vector<double>&)> CreateVBAFunctionWrapper(IDispatch* pDisp, DISPID dispid);

        // Create wrapper using function name
        std::function<double(const std::vector<double>&)> CreateVBAFunctionWrapper(IDispatch* pDisp, const std::wstring& functionName) {
            if (!pDisp) {
                throw std::invalid_argument("Null IDispatch pointer");
            }

            // Get the DISPID for the function
            LPOLESTR funcName = const_cast<LPOLESTR>(functionName.c_str());
            DISPID dispid;
            HRESULT hr = pDisp->GetIDsOfNames(IID_NULL, &funcName, 1, LOCALE_USER_DEFAULT, &dispid);

            if (FAILED(hr)) {
                throw std::invalid_argument("Function not found: " + std::string(functionName.begin(), functionName.end()));
            }

            return CreateVBAFunctionWrapper(pDisp, dispid);
        }

        // Create a C++ function wrapper for VBA function calls using DISPID
        std::function<double(const std::vector<double>&)> CreateVBAFunctionWrapper(IDispatch* pDisp, DISPID dispid) {
            if (!pDisp) {
                throw std::invalid_argument("Null IDispatch pointer");
            }

            // Add reference to keep the IDispatch alive
            pDisp->AddRef();

            return [pDisp, dispid](const std::vector<double>& x) -> double {
                // RAII to ensure Release() is called
                struct DispatchReleaser {
                    IDispatch* ptr;
                    ~DispatchReleaser() { if (ptr) ptr->Release(); }
                } releaser{ pDisp };

                try {
                    // Convert vector to VARIANT array
                    VARIANT vArray = VectorToSafeArray(x);

                    // Set up parameters for the call
                    DISPPARAMS params = { 0 };
                    params.cArgs = 1;
                    params.rgvarg = &vArray;

                    VARIANT result;
                    VariantInit(&result);

                    EXCEPINFO excepInfo = { 0 };
                    UINT argErr = 0;

                    // Call the VBA function
                    HRESULT hr = pDisp->Invoke(
                        dispid,
                        IID_NULL,
                        LOCALE_USER_DEFAULT,
                        DISPATCH_METHOD,
                        &params,
                        &result,
                        &excepInfo,
                        &argErr
                    );

                    // Clean up the input array
                    VariantClear(&vArray);

                    if (FAILED(hr)) {
                        VariantClear(&result);
                        return std::numeric_limits<double>::quiet_NaN();
                    }

                    // Convert result to double
                    double returnValue = 0.0;
                    if (result.vt == VT_R8) {
                        returnValue = result.dblVal;
                    }
                    else if (result.vt == VT_I4) {
                        returnValue = static_cast<double>(result.lVal);
                    }
                    else {
                        // Try to coerce to double
                        VARIANT doubleResult;
                        VariantInit(&doubleResult);
                        hr = VariantChangeType(&doubleResult, &result, 0, VT_R8);
                        if (SUCCEEDED(hr)) {
                            returnValue = doubleResult.dblVal;
                        }
                        VariantClear(&doubleResult);
                    }

                    VariantClear(&result);
                    return returnValue;

                }
                catch (...) {
                    return std::numeric_limits<double>::quiet_NaN();
                }
                };
        }

    } // namespace util
} // namespace opt