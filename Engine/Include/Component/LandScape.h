#pragma once
#include "Component.h"

PUN_BEGIN

class PUN_DLL CLandScape :
	public CComponent
{
	friend class CGameObject;

protected:
	CLandScape();
	CLandScape(const CLandScape& landscape);
	virtual ~CLandScape();

private:
	unsigned int	m_iNumX;
	unsigned int	m_iNumZ;
	vector<Vertex3D>	m_vecVtx;
	vector<int>			m_vecIdx;
	vector<Vector3>		m_vecFaceNormal;
	LandScapeCBuffer	m_tCBuffer;

public:
	bool CreateLandScape(const string& strName,
		unsigned int iNumX, unsigned int iNumZ,
		const string& strTexKey = "",
		const TCHAR* pTexName = nullptr, const TCHAR* pTexNormal = nullptr,
		const TCHAR* pTexSpecular = nullptr,
		const char* pFileName = nullptr, const string& strPathKey = TEXTURE_PATH);

	bool AddSplatDifTexture(const string& strName, const vector<const TCHAR*>& pFileName,
		const string& strPathName = TEXTURE_PATH);
	bool AddSplatNrmTexture(const string& strName, const vector<const TCHAR*>& pFileName,
		const string& strPathName = TEXTURE_PATH);
	bool AddSplatSpcTexture(const string& strName, const vector<const TCHAR*>& pFileName,
		const string& strPathName = TEXTURE_PATH);
	bool AddSplatAlphaTexture(const string& strName, const vector<const TCHAR*>& pFileName,
		const string& strPathName = TEXTURE_PATH);
public:
	virtual void Start();
	virtual void AfterClone();
	virtual bool Init();
	virtual int Input(float fTime);
	virtual int Update(float fTime);
	virtual int LateUpdate(float fTime);
	virtual void Collision(float fTime);
	virtual void Render(float fTime);
	virtual CLandScape* Clone();

private:
	void ComputeNormal();
	void ComputeTangent();
};

PUN_END
