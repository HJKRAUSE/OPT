// Solver.cpp : Implementation of CSolver

#include "pch.h"
#include "Solver.h"

// CSolver

STDMETHODIMP CSolver::initialize(LONG algo, LONG n) {
    solver_ = std::make_unique<opt::NLOPTSolver>(
        static_cast<nlopt::algorithm>(algo),
        static_cast<unsigned>(n));
    return S_OK;
}

STDMETHODIMP CSolver::optimize(VARIANT x0, VARIANT* result) {
    // Initialize result to empty variant (indicates error)
    VariantInit(result);

    // Make local copy since we need non-const reference
    VARIANT x0Copy = x0;
    auto initialGuess = opt::util::SafeArrayToVector(x0Copy);

    // Perform optimization
    auto optimizedResult = solver_->optimize(initialGuess);

    // Convert result back to VARIANT
    *result = opt::util::VectorToSafeArray(optimizedResult);

    return S_OK;

}

STDMETHODIMP CSolver::setMinObjective(IDispatch* object, BSTR function_name) {
    //Convert BSTR to wstring
    std::wstring funcName(function_name, SysStringLen(function_name));
    //Create VBA function wrapper
    auto wrapper = opt::util::CreateVBAFunctionWrapper(object, funcName);
    solver_->setMinObjective(wrapper);
    return S_OK;

}

STDMETHODIMP CSolver::setMaxObjective(IDispatch* object, BSTR function_name) {
    
    // Convert BSTR to wstring
    std::wstring funcName(function_name, SysStringLen(function_name));
    
    // Create VBA function wrapper
    auto wrapper = opt::util::CreateVBAFunctionWrapper(object, funcName);
    solver_->setMaxObjective(wrapper);
    
    return S_OK;
 
}

STDMETHODIMP CSolver::setLowerBounds(VARIANT lb){
    
    // Make local copy since we need non-const reference
    VARIANT lbCopy = lb;
    auto lowerBounds = opt::util::SafeArrayToVector(lbCopy);
    solver_->setLowerBounds(lowerBounds);
    
    return S_OK;
    
}

STDMETHODIMP CSolver::setUpperBounds(VARIANT ub) {

    // Make local copy since we need non-const reference
    VARIANT ubCopy = ub;
    auto upperBounds = opt::util::SafeArrayToVector(ubCopy);
    solver_->setUpperBounds(upperBounds);
    
    return S_OK;
}

STDMETHODIMP CSolver::setXTolRel(DOUBLE tol) {
  
    return S_OK;
    solver_->setXTolRel(tol);
   
}

STDMETHODIMP CSolver::setXTolAbs(DOUBLE tol)
{

        
    solver_->setXTolAbs(tol);
    return S_OK;
    
}

STDMETHODIMP CSolver::setFTolRel(DOUBLE tol) {
    solver_->setFTolRel(tol);
    return S_OK;
}

STDMETHODIMP CSolver::setFTolAbs(DOUBLE tol)
{
    solver_->setFTolAbs(tol);
    return S_OK;
}

STDMETHODIMP CSolver::setMaxEval(LONG max) {
    solver_->setMaxEval(static_cast<int>(max));
    return S_OK;
}