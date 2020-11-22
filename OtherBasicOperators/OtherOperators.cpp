#include "pch.h"
#include "OtherOperators.h"


void FunDefiner(std::map<std::string, Operator*>& map)
{
	Operator* op = new UMinus();
	map.insert(std::pair<std::string, Operator*>(op->getKey(), op));

	op = new BMinus();
	map.insert(std::pair<std::string, Operator*>(op->getKey(), op));

	op = new Pow();
	map.insert(std::pair<std::string, Operator*>(op->getKey(), op));

}


void Minus::pars(std::string& str)
{
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (str[i] == token[0])
		{
			if (isNecessaryMinus(str, i))
			{
				
				std::string lStr = str.substr(0, i);
				std::string rStr = str.substr(i + 1, str.size() - i - 1);
				str = lStr + "," + key + "," + rStr;
			}
		}
	}
}

bool Minus::isUnaryMinus(const std::string& str, size_t i)
{
	if (i == 0)
		return true;
	return (!((int)str[i - 1] >= (int)'0'  && (int)str[i - 1] <= (int)'9'));
}

bool UMinus::isNecessaryMinus(const std::string& str, size_t i)
{
	return Minus::isUnaryMinus(str, i);
}

UMinus::UMinus()
{
	token = UMinusToken;
	key = UMinusKey;
	nParams = 1;
	priority = 1;
	recordType = RecordType::prefix;
}

double UMinus::calc(const Args& args)
{
	return -args[0];
}

bool BMinus::isNecessaryMinus(const std::string& str, size_t i)
{
	return !Minus::isUnaryMinus(str, i);
}

BMinus::BMinus()
{
	token = BMinusToken;
	key = BMinusKey;
	nParams = 2;
	priority = 1;
	recordType = RecordType::infix;
}

double BMinus::calc(const Args& args)
{
	return args[1] - args[0];
}

Pow::Pow()
{
	token = PowToken;
	key = PowKey;
	nParams = 2;
	priority = 3;
	recordType = RecordType::infix;
	associativity = Associativity::right;
}

double Pow::calc(const Args& args)
{
	return pow(args[1], args[0]);
}

