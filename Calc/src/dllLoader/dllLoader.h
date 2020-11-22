#pragma once
#include <iostream>
#include <windows.h>
#include "../../include/Operator.h"
#include "../Operators/BasicOperations.h"


class Loader
{
	std::vector<HINSTANCE> dllList;
	void loadDll(const std::string&, OperatorMap&);
public:
	void parsDlls(OperatorMap&);
	void addBasicOperatotions(OperatorMap&);
	~Loader();
};