

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for OPT.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0628 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __OPT_i_h__
#define __OPT_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IComponentRegistrar_FWD_DEFINED__
#define __IComponentRegistrar_FWD_DEFINED__
typedef interface IComponentRegistrar IComponentRegistrar;

#endif 	/* __IComponentRegistrar_FWD_DEFINED__ */


#ifndef __ISolver_FWD_DEFINED__
#define __ISolver_FWD_DEFINED__
typedef interface ISolver ISolver;

#endif 	/* __ISolver_FWD_DEFINED__ */


#ifndef __CompReg_FWD_DEFINED__
#define __CompReg_FWD_DEFINED__

#ifdef __cplusplus
typedef class CompReg CompReg;
#else
typedef struct CompReg CompReg;
#endif /* __cplusplus */

#endif 	/* __CompReg_FWD_DEFINED__ */


#ifndef __Solver_FWD_DEFINED__
#define __Solver_FWD_DEFINED__

#ifdef __cplusplus
typedef class Solver Solver;
#else
typedef struct Solver Solver;
#endif /* __cplusplus */

#endif 	/* __Solver_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IComponentRegistrar_INTERFACE_DEFINED__
#define __IComponentRegistrar_INTERFACE_DEFINED__

/* interface IComponentRegistrar */
/* [unique][dual][uuid][object] */ 


EXTERN_C const IID IID_IComponentRegistrar;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a817e7a2-43fa-11d0-9e44-00aa00b6770a")
    IComponentRegistrar : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Attach( 
            /* [in] */ BSTR bstrPath) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RegisterAll( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UnregisterAll( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetComponents( 
            /* [out] */ SAFEARRAY * *pbstrCLSIDs,
            /* [out] */ SAFEARRAY * *pbstrDescriptions) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RegisterComponent( 
            /* [in] */ BSTR bstrCLSID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UnregisterComponent( 
            /* [in] */ BSTR bstrCLSID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IComponentRegistrarVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IComponentRegistrar * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IComponentRegistrar * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IComponentRegistrar * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IComponentRegistrar * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IComponentRegistrar * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IComponentRegistrar * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IComponentRegistrar * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IComponentRegistrar, Attach)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IComponentRegistrar * This,
            /* [in] */ BSTR bstrPath);
        
        DECLSPEC_XFGVIRT(IComponentRegistrar, RegisterAll)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RegisterAll )( 
            IComponentRegistrar * This);
        
        DECLSPEC_XFGVIRT(IComponentRegistrar, UnregisterAll)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UnregisterAll )( 
            IComponentRegistrar * This);
        
        DECLSPEC_XFGVIRT(IComponentRegistrar, GetComponents)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetComponents )( 
            IComponentRegistrar * This,
            /* [out] */ SAFEARRAY * *pbstrCLSIDs,
            /* [out] */ SAFEARRAY * *pbstrDescriptions);
        
        DECLSPEC_XFGVIRT(IComponentRegistrar, RegisterComponent)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RegisterComponent )( 
            IComponentRegistrar * This,
            /* [in] */ BSTR bstrCLSID);
        
        DECLSPEC_XFGVIRT(IComponentRegistrar, UnregisterComponent)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UnregisterComponent )( 
            IComponentRegistrar * This,
            /* [in] */ BSTR bstrCLSID);
        
        END_INTERFACE
    } IComponentRegistrarVtbl;

    interface IComponentRegistrar
    {
        CONST_VTBL struct IComponentRegistrarVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IComponentRegistrar_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IComponentRegistrar_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IComponentRegistrar_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IComponentRegistrar_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IComponentRegistrar_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IComponentRegistrar_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IComponentRegistrar_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IComponentRegistrar_Attach(This,bstrPath)	\
    ( (This)->lpVtbl -> Attach(This,bstrPath) ) 

#define IComponentRegistrar_RegisterAll(This)	\
    ( (This)->lpVtbl -> RegisterAll(This) ) 

#define IComponentRegistrar_UnregisterAll(This)	\
    ( (This)->lpVtbl -> UnregisterAll(This) ) 

#define IComponentRegistrar_GetComponents(This,pbstrCLSIDs,pbstrDescriptions)	\
    ( (This)->lpVtbl -> GetComponents(This,pbstrCLSIDs,pbstrDescriptions) ) 

#define IComponentRegistrar_RegisterComponent(This,bstrCLSID)	\
    ( (This)->lpVtbl -> RegisterComponent(This,bstrCLSID) ) 

#define IComponentRegistrar_UnregisterComponent(This,bstrCLSID)	\
    ( (This)->lpVtbl -> UnregisterComponent(This,bstrCLSID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IComponentRegistrar_INTERFACE_DEFINED__ */


#ifndef __ISolver_INTERFACE_DEFINED__
#define __ISolver_INTERFACE_DEFINED__

/* interface ISolver */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISolver;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2637d647-5828-46ba-bb5f-b18889547b1b")
    ISolver : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE initialize( 
            /* [in] */ LONG algorithm,
            /* [in] */ LONG dimensions) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE optimize( 
            /* [in] */ VARIANT x0,
            /* [retval][out] */ VARIANT *result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setMinObjective( 
            /* [in] */ IDispatch *object,
            /* [in] */ BSTR function_name) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setMaxObjective( 
            /* [in] */ IDispatch *object,
            /* [in] */ BSTR function_name) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setLowerBounds( 
            /* [in] */ VARIANT lb) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setUpperBounds( 
            /* [in] */ VARIANT ub) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setXTolRel( 
            /* [in] */ DOUBLE tol) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setXTolAbs( 
            /* [in] */ DOUBLE tol) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setFTolRel( 
            /* [in] */ DOUBLE tol) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setFTolAbs( 
            /* [in] */ DOUBLE tol) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setMaxEval( 
            /* [in] */ LONG max) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISolverVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISolver * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISolver * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISolver * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISolver * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISolver * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISolver * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISolver * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(ISolver, initialize)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *initialize )( 
            ISolver * This,
            /* [in] */ LONG algorithm,
            /* [in] */ LONG dimensions);
        
        DECLSPEC_XFGVIRT(ISolver, optimize)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *optimize )( 
            ISolver * This,
            /* [in] */ VARIANT x0,
            /* [retval][out] */ VARIANT *result);
        
        DECLSPEC_XFGVIRT(ISolver, setMinObjective)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setMinObjective )( 
            ISolver * This,
            /* [in] */ IDispatch *object,
            /* [in] */ BSTR function_name);
        
        DECLSPEC_XFGVIRT(ISolver, setMaxObjective)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setMaxObjective )( 
            ISolver * This,
            /* [in] */ IDispatch *object,
            /* [in] */ BSTR function_name);
        
        DECLSPEC_XFGVIRT(ISolver, setLowerBounds)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setLowerBounds )( 
            ISolver * This,
            /* [in] */ VARIANT lb);
        
        DECLSPEC_XFGVIRT(ISolver, setUpperBounds)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setUpperBounds )( 
            ISolver * This,
            /* [in] */ VARIANT ub);
        
        DECLSPEC_XFGVIRT(ISolver, setXTolRel)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setXTolRel )( 
            ISolver * This,
            /* [in] */ DOUBLE tol);
        
        DECLSPEC_XFGVIRT(ISolver, setXTolAbs)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setXTolAbs )( 
            ISolver * This,
            /* [in] */ DOUBLE tol);
        
        DECLSPEC_XFGVIRT(ISolver, setFTolRel)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setFTolRel )( 
            ISolver * This,
            /* [in] */ DOUBLE tol);
        
        DECLSPEC_XFGVIRT(ISolver, setFTolAbs)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setFTolAbs )( 
            ISolver * This,
            /* [in] */ DOUBLE tol);
        
        DECLSPEC_XFGVIRT(ISolver, setMaxEval)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setMaxEval )( 
            ISolver * This,
            /* [in] */ LONG max);
        
        END_INTERFACE
    } ISolverVtbl;

    interface ISolver
    {
        CONST_VTBL struct ISolverVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISolver_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISolver_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISolver_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISolver_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISolver_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISolver_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISolver_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISolver_initialize(This,algorithm,dimensions)	\
    ( (This)->lpVtbl -> initialize(This,algorithm,dimensions) ) 

#define ISolver_optimize(This,x0,result)	\
    ( (This)->lpVtbl -> optimize(This,x0,result) ) 

#define ISolver_setMinObjective(This,object,function_name)	\
    ( (This)->lpVtbl -> setMinObjective(This,object,function_name) ) 

#define ISolver_setMaxObjective(This,object,function_name)	\
    ( (This)->lpVtbl -> setMaxObjective(This,object,function_name) ) 

#define ISolver_setLowerBounds(This,lb)	\
    ( (This)->lpVtbl -> setLowerBounds(This,lb) ) 

#define ISolver_setUpperBounds(This,ub)	\
    ( (This)->lpVtbl -> setUpperBounds(This,ub) ) 

#define ISolver_setXTolRel(This,tol)	\
    ( (This)->lpVtbl -> setXTolRel(This,tol) ) 

#define ISolver_setXTolAbs(This,tol)	\
    ( (This)->lpVtbl -> setXTolAbs(This,tol) ) 

#define ISolver_setFTolRel(This,tol)	\
    ( (This)->lpVtbl -> setFTolRel(This,tol) ) 

#define ISolver_setFTolAbs(This,tol)	\
    ( (This)->lpVtbl -> setFTolAbs(This,tol) ) 

#define ISolver_setMaxEval(This,max)	\
    ( (This)->lpVtbl -> setMaxEval(This,max) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISolver_INTERFACE_DEFINED__ */



#ifndef __OPTLib_LIBRARY_DEFINED__
#define __OPTLib_LIBRARY_DEFINED__

/* library OPTLib */
/* [custom][version][uuid] */ 


EXTERN_C const IID LIBID_OPTLib;

EXTERN_C const CLSID CLSID_CompReg;

#ifdef __cplusplus

class DECLSPEC_UUID("dc228e50-dfbe-4430-bfd4-51b5049fb371")
CompReg;
#endif

EXTERN_C const CLSID CLSID_Solver;

#ifdef __cplusplus

class DECLSPEC_UUID("7f5e805f-33b0-4cdf-b102-6d37098153e5")
Solver;
#endif
#endif /* __OPTLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize64(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal64(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal64(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree64(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


