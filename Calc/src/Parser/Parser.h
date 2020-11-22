#pragma once
#include <iostream>
#include <algorithm>
#include <cctype>
#include <regex>
#include "../../../include/Operator.h"

class Parser
{
	std::string str;
public:
	// передаётся по значения для того чтобы исходная строка была неизменной
	void setString(std::string);
	std::string nextKey();
	void parsOperators(const OperatorMap&);
	static bool isNum(const std::string&);
};
