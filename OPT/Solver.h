// Solver.h : Declaration of the CSolver

#pragma once
#include "resource.h"       // main symbols
#include "core/NLOPTSolver.hpp"
#include "core/Utility.hpp"

#include "OPT_i.h"
#include <map>
#include <memory>


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CSolver

class ATL_NO_VTABLE CSolver :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSolver, &CLSID_Solver>,
	public IDispatchImpl<ISolver, &IID_ISolver, &LIBID_OPTLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CSolver()
	{
	}

DECLARE_REGISTRY_RESOURCEID(106)

BEGIN_COM_MAP(CSolver)
	COM_INTERFACE_ENTRY(ISolver)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	STDMETHOD(initialize)(LONG algo, LONG n);
	STDMETHOD(optimize)(VARIANT x0, VARIANT* result);
	STDMETHOD(setMinObjective)(IDispatch* object, BSTR function_name);
	STDMETHOD(setMaxObjective)(IDispatch* object, BSTR function_name);
	STDMETHOD(setLowerBounds)(VARIANT lb);
	STDMETHOD(setUpperBounds)(VARIANT ub);
	STDMETHOD(setXTolRel)(DOUBLE tol);
	STDMETHOD(setXTolAbs)(DOUBLE tol);
	STDMETHOD(setFTolRel)(DOUBLE tol);
	STDMETHOD(setFTolAbs)(DOUBLE tol);
	STDMETHOD(setMaxEval)(LONG max);
private:
	std::unique_ptr<opt::NLOPTSolver> solver_;

};

OBJECT_ENTRY_AUTO(__uuidof(Solver), CSolver)
