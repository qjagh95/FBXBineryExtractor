#pragma once

PUN_BEGIN

class PUN_DLL CResourcesManager
{
private:
	unordered_map<string, class CMesh*>		m_mapMesh;
	unordered_map<string, class CTexture*>	m_mapTexture;
	unordered_map<string, class CSampler*>	m_mapSampler;

public:
	bool Init();
	bool SamplerInit();
	bool CreateMesh(const string& strName, const string& strShaderKey, const string& strLayoutKey,
		void* pVtx, int iVtxCount, int iVtxSize, D3D11_USAGE eVtxUsage,
		D3D11_PRIMITIVE_TOPOLOGY ePrimitive, void* pIdx = nullptr, int iIdxCount = 0,
		int iIdxSize = 0, D3D11_USAGE eIdxUsage = D3D11_USAGE_DEFAULT,
		DXGI_FORMAT eFmt = DXGI_FORMAT_R16_UINT);
	bool CreateTexture(const string& strName, const TCHAR* pFileName,
		const string& strPathKey = TEXTURE_PATH);
	bool CreateTextureFromFullPath(const string& strName, const TCHAR* pFullPath);
	bool CreateTexture(const string& strName, const vector<const TCHAR*>& vecFileName,
		const string& strPathKey = TEXTURE_PATH);
	bool CreateTextureFromFullPath(const string& strName, const vector<const TCHAR*>& vecFullPath);
	bool CreateSampler(const string& strName,
		D3D11_FILTER eFilter = D3D11_FILTER_MIN_MAG_MIP_LINEAR,
		D3D11_TEXTURE_ADDRESS_MODE eU = D3D11_TEXTURE_ADDRESS_WRAP,
		D3D11_TEXTURE_ADDRESS_MODE eV = D3D11_TEXTURE_ADDRESS_WRAP,
		D3D11_TEXTURE_ADDRESS_MODE eW = D3D11_TEXTURE_ADDRESS_WRAP);

	bool LoadMesh(const string& strName, const TCHAR* pFileName, const string& strPathKey = MESH_PATH);
	bool LoadMeshFromFullPath(const string& strName, const TCHAR* pFullPath);
	class CMesh*	FindMesh(const string& strName);
	class CMesh * FindMeshNonCount(const string & strName);
	class CTexture* FindTexture(const string& strName);
	class CTexture * FindTextureNonCount(const string & strName);
	class CSampler* FindSampler(const string& strName);
	class CSampler * FindSamplerNonCount(const string & strName);
	bool GetIsAnimationMesh(const string& strName);

public:
	void CreateSphereVolum(const string& KeyName, float Radius, int StackSlice, int SliceCount, const string& ShaderKey = STANDARD_NORMAL_COLOR_SHADER, const string& LayoutKey = POS_NORMAL_COLOR_LAYOUT);
	void CreateCapsulVolum(const string& KeyName, float Radius, float Height, int StackSlice, int SliceCount);
	void CreateCornVolum(const string& KeyName, float Radius, float Height, int StackSlice, int SliceCount);
	void CreateCylinderVolum(const string& KeyName, float Radius, int Height, int SliceCount);

	DECLARE_SINGLE(CResourcesManager)
};

PUN_END