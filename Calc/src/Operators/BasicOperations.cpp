#include "BasicOperations.h"


Plus::Plus()
{
	token = PlusToken;
	key = PlusKey;
	nParams = 2;
	priority = 1;
	associativity = Associativity::lift;
	recordType = RecordType::infix;
	isParenthesis_ = false;
	isOpenPar_ = false;
}

double Plus::calc(const Args& args)
{
	return args[0] + args[1];
}

Multiply::Multiply()
{
	token = MultToken;
	key = MultKey;
	nParams = 2;
	priority = 2;
	associativity = Associativity::lift;
	recordType = RecordType::infix;
	isParenthesis_ = false;
	isOpenPar_ = false;
}

double Multiply::calc(const Args& args)
{
	return args[0] * args[1];
}

OpenPar::OpenPar()
{
	token = OpenParToken;
	key = OpenParKey;
	nParams = 0;
	priority = 0;
	associativity = Associativity::lift;
	recordType = RecordType::postfix;
	isParenthesis_ = true;
	isOpenPar_ = true;
}

ClosedPar::ClosedPar()
{
	token = ClosedParToken;
	key = ClosedParKey;
	nParams = 0;
	priority = 0;
	associativity = Associativity::lift;
	recordType = RecordType::postfix;
	isParenthesis_ = true;
	isOpenPar_ = false;
}
