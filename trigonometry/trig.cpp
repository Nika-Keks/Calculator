

#include "pch.h"
#include "trig.h"


void FunDefiner(std::map<std::string, Operator*>& map)
{
	Operator* op = new Sin();
	map.insert(std::pair<std::string, Operator*>(op->getKey(), op));
}

Sin::Sin()
{
	token = "sin";
	key = "sin";
	nParams = 1;
	priority = 3;
	associativity = Associativity::lift;
	recordType = RecordType::prefix;
	isParenthesis_ = false;
}

double Sin::calc(const std::vector<double>& args)
{
	return sin(args[0]);
}






