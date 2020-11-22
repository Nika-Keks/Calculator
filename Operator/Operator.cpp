// Operator.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include <algorithm>
#include <cctype>
#include <regex>
#include "../include/Operator.h"

// TODO: Это пример библиотечной функции.

int Operator::getPriority()
{
	return priority;
}

int Operator::getNParams()
{
	return nParams;
}

std::string Operator::getKey()
{
	return key;
}

std::string Operator::getToken()
{
	return token;
}

bool Operator::isRightAssociative()
{
	return associativity == Associativity::right;
}

RecordType Operator::getRecordType()
{
	return recordType;
}

bool Operator::isParenthesis()
{
	return isParenthesis_;
}

bool Operator::isOperPar()
{
	return isOpenPar_;
}

Operator::Operator()
{
	nParams = 0;
	priority = 0;
	key = "";
	token = "";
	associativity = Associativity::lift;
	recordType = RecordType::postfix;
	isParenthesis_ = false;
	isOpenPar_ = false;
}

void Operator::pars(std::string& srcStr)
{
	if (token == key)
		return;
	size_t pos = 0, cnt = 0;

	while ((pos = srcStr.find(token, pos)) != std::string::npos)
	{
		srcStr.replace(pos, token.size(),"," +  key + ",");
		pos += key.size();
		cnt++;
	}
}
