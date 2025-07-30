// dllmain.h : Declaration of module class.

class COPTModule : public ATL::CAtlDllModuleT< COPTModule >
{
public :
	DECLARE_LIBID(LIBID_OPTLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_OPT, "{d1d28a2f-644d-40ee-ba0e-ad17f409d41c}")
};

extern class COPTModule _AtlModule;
