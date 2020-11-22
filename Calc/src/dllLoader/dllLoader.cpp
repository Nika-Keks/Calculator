#include "dllLoader.h"

void Loader::addBasicOperatotions(OperatorMap& map)
{
	Operator* op = new Plus();
	map.insert(OperatorPair(op->getKey(), op));

	op = new Multiply();
	map.insert(OperatorPair(op->getKey(), op));

	op = new OpenPar();
	map.insert(OperatorPair(op->getKey(), op));

	op = new ClosedPar();
	map.insert(OperatorPair(op->getKey(), op));

}

Loader::~Loader()
{
	for (auto i : dllList)
		FreeLibrary(i);
}

void Loader::parsDlls(OperatorMap& map)
{
	WIN32_FIND_DATAA findData;
	HANDLE hf;

	hf = FindFirstFileA((std::string(plagins) + std::string("*.dll")).c_str(), &findData);

	if (hf == INVALID_HANDLE_VALUE)
	{
		return;
	}

	do
	{
		loadDll(std::string(plagins) + std::string(findData.cFileName), map);
	} while (FindNextFileA(hf, &findData));

	FindClose(hf);
}

void Loader::loadDll(const std::string& path, OperatorMap& map)
{
	HINSTANCE module = LoadLibraryA(path.c_str());
	if (module == NULL) 
	{ 
		return; 
	}
 
	
	FARPROC adresse_la_func = GetProcAddress(module, funName.c_str());
	if (adresse_la_func != 0)
	{
		((FunDefinerT)adresse_la_func)(map);
		dllList.push_back(module);
	}
	else
		FreeLibrary(module);
}
