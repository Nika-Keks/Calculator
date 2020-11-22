#pragma once
#include "../Operators/BasicOperations.h"
#include "../Parser/Parser.h"
#include "../dllLoader/dllLoader.h"

class Calculator
{
	OperatorMap map;
	Loader loader;
	void processToken(const std::string&, ValueStack&, OperatorStack&);
	void processOperator(Operator*, ValueStack&, OperatorStack&);
	void processParenthesis(Operator*, ValueStack&, OperatorStack&);
	void processInfixOp(Operator*, ValueStack&, OperatorStack&);
	void clacOperator(Operator*, ValueStack&);
public:
	num calc(const std::string&);
	Calculator();
	~Calculator();
};