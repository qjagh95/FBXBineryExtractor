#include "pch.h"
#include <Resource/ResourcesManager.h>
#include <Resource/Mesh.h>
#include <PathManager.h>
#include <Device.h>
#include <shellapi.h>

PUN_USING

unordered_map<string, vector<string>> EqualMap2;
void MeshDataFind();
void MeshFind();
void FileMove();
HWND GetConsoleHwnd();
vector<string>* FindName(const string& Key);

int main()
{
	CDevice::GetInst()->Init(GetConsoleHwnd(), 100, 100, true);
	CPathManager::GetInst()->Init();
	CPathManager::GetInst()->AddPath("MeshData", TEXT("MeshData\\"));
	CResourcesManager::GetInst()->Init();

	MeshDataFind();
	MeshFind();
	FileMove();

	CDevice::DestroyInst();
	CResourcesManager::DestroyInst();
	CPathManager::DestroyInst();
	return 0;
}

void MeshDataFind()
{
	const char* MeshDataPath = CPathManager::GetInst()->FindPathFromMultibyte("MeshData");
	char Ext[255] = {};

	string wMeshDataPath = MeshDataPath;
	wMeshDataPath += "*";

	WIN32_FIND_DATAA FindData;
	HANDLE hFinder = FindFirstFileA(wMeshDataPath.c_str(), &FindData);

	if (hFinder == INVALID_HANDLE_VALUE)
		return;

	string FileName;
	string FullFileName;

	do
	{
		FileName = FindData.cFileName;
		FullFileName = FindData.cFileName;

		if (FileName == "." || FileName == "..")
			continue;

		_splitpath(FileName.c_str(), NULL, NULL, NULL, Ext);
		string sExt = Ext;
		FileName.erase(FileName.find_last_of("."), 4);

		vector<string> tempVec;

		if (FindName(FileName) == NULLPTR)
			EqualMap2.insert(make_pair(FileName, tempVec));

		if (sExt == ".msh")
			FindName(FileName)->push_back(FullFileName);
		if (sExt == ".anm")
			FindName(FileName)->push_back(FullFileName);
		if (sExt == ".bne")
			FindName(FileName)->push_back(FullFileName);

	} while (FindNextFileA(hFinder, &FindData));

	FindClose(hFinder);
}

void MeshFind()
{
	const char* MeshPath = CPathManager::GetInst()->FindPathFromMultibyte(MESH_PATH);
	const TCHAR* MeshPath2 = CPathManager::GetInst()->FindPath(MESH_PATH);
	const TCHAR* MeshDataPath2 = CPathManager::GetInst()->FindPath("MeshData");
	MeshPath = CPathManager::GetInst()->FindPathFromMultibyte(MESH_PATH);

	char Ext[255] = {};

	wstring wMeshPath2 = MeshPath2;
	wstring wMeshDataPath2 = MeshDataPath2;

	string wMeshPath = MeshPath;
	wMeshPath += "*.fbx";

	WIN32_FIND_DATAA FindData;
	HANDLE hFinder = FindFirstFileA(wMeshPath.c_str(), &FindData);

	if (hFinder == INVALID_HANDLE_VALUE)
		return;

	do
	{
		string FileName = FindData.cFileName;
		string FileNameExt = FindData.cFileName;
		TCHAR ConvertFileName[256] = {};

		MultiByteToWideChar(CP_ACP, 0, FileNameExt.c_str(), -1, ConvertFileName, (int)FileNameExt.length());
		_splitpath(FileName.c_str(), NULL, NULL, NULL, Ext);

		string sExt = Ext;

		FileName.erase(FileName.find_last_of("."), 4);

		vector<string>* temp = FindName(FileName);

		if (temp != NULLPTR && (temp->size() == 3 || temp->size() == 1))
		{
			cout << "MeshData 폴더에 " << FileName << " 파일에 대한 데이터가 전부 있습니다." << endl;
			cout << "변환하지않습니다." << endl << endl;
			continue;
		}
		else
		{
			cout << FileName <<"파일 변환중..." << endl;
			CResourcesManager::GetInst()->LoadMesh(FileName.c_str(), ConvertFileName);
			cout << FileName << "파일 변환완료." << endl << endl;
		}

	} while (FindNextFileA(hFinder, &FindData));

	FindClose(hFinder);
}

void FileMove()
{
	char Ext[255] = {};

	string wMeshPath = CPathManager::GetInst()->FindPathFromMultibyte(MESH_PATH);
	wMeshPath += "*";

	WIN32_FIND_DATAA FindData;
	HANDLE hFinder = FindFirstFileA(wMeshPath.c_str(), &FindData);

	if (hFinder == INVALID_HANDLE_VALUE)
		return;

	do
	{
		string FileName = FindData.cFileName;
		string FileNameExt = FindData.cFileName;
		TCHAR ConvertFileName[256] = {};

		MultiByteToWideChar(CP_ACP, 0, FileNameExt.c_str(), -1, ConvertFileName, (int)FileNameExt.length());

		if (FileName == "." || FileName == "..")
			continue;

		_splitpath(FileName.c_str(), NULL, NULL, NULL, Ext);
		string sExt = Ext;

		if (sExt == ".fbm" || sExt == ".fbx")
			continue;

		FileName.erase(FileName.find_last_of("."), 4);

		string mPath = CPathManager::GetInst()->FindPathFromMultibyte(MESH_PATH);
		string dPath = CPathManager::GetInst()->FindPathFromMultibyte("MeshData");

		if (sExt == ".anm")
		{
			mPath += FileName + ".anm";
			dPath += FileName + ".anm";

			MoveFileA(mPath.c_str(), dPath.c_str());
		}
		if (sExt == ".bne")
		{
			mPath += FileName + ".bne";
			dPath += FileName + ".bne";

			MoveFileA(mPath.c_str(), dPath.c_str());
		}
		if (sExt == ".msh")
		{
			mPath += FileName + ".msh";
			dPath += FileName + ".msh";

			MoveFileA(mPath.c_str(), dPath.c_str());
		}

	} while (FindNextFileA(hFinder, &FindData));

	FindClose(hFinder);
}

HWND GetConsoleHwnd()
{
	HWND hwndFound;
	char pszNewWindowTitle[256];
	char pszOldWindowTitle[256];

	GetConsoleTitleA(pszOldWindowTitle, 256);
	SetConsoleTitleA(pszNewWindowTitle);
	hwndFound = FindWindowA(NULL, pszNewWindowTitle);
	SetConsoleTitleA(pszOldWindowTitle);

	return hwndFound; 
}

vector<string>* FindName(const string & Key)
{
	unordered_map<string, vector<string>>::iterator FindIter = EqualMap2.find(Key);

	if (FindIter == EqualMap2.end())
		return NULLPTR;

	return &FindIter->second;
}
