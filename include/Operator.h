/*
	¬ данной статической библиотеке реализован абстрактный предок дл€ всех операторов.
*/

#pragma once
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <stack>

enum class RecordType
{
	prefix = -1,
	infix,
	postfix
};

enum class Associativity
{
	lift = -1,
	right = 1
};

class Operator
{
protected:
	int nParams;
	int priority;
	std::string key;
	std::string token;
	Associativity associativity;
	RecordType recordType;
	bool isParenthesis_;
	bool isOpenPar_;
public:
	Operator();
	virtual ~Operator() {};
	virtual double calc(const std::vector<double>&) = 0;
	virtual void pars(std::string&);
	int getPriority();
	int getNParams();
	std::string getKey();
	std::string getToken();
	bool isRightAssociative();
	RecordType getRecordType();
	bool isParenthesis();
	bool isOperPar();
};


using num = double;
using ValueStack = std::stack<num>;
using OperatorMap = std::map <std::string, Operator*>;
using OperatorPair = std::pair <std::string, Operator*>;
using OperatorStack = std::stack<Operator*>;
using Args = std::vector<num>;
typedef void(__cdecl* FunDefinerT)(OperatorMap&);
