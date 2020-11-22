#include "Calculator.h"

num Calculator::calc(const std::string& str)
{
	Parser parser;
	parser.setString(str);
	parser.parsOperators(map);
	ValueStack vStack;
	OperatorStack opStack;

	
	try
	{
		std::string token = parser.nextKey();
		while (!token.empty())
		{
			processToken(token, vStack, opStack);
			token = parser.nextKey();
		}
		while (!(opStack.empty()))
		{
			clacOperator(opStack.top(), vStack);
			opStack.pop();
		}
		if (vStack.size() != 1 || !opStack.empty())
			throw inError;

		return vStack.top();
	}
	catch (std::string msg)
	{
		std::cout << msg << std::endl;
	}
	return 0.;
}

void Calculator::processToken(const std::string& token, ValueStack& vStack, OperatorStack& opStack)
{
	if (Parser::isNum(token))
		vStack.push(std::stod(token));
	else if (map.find(token) == map.end())
		throw "Undefeted operator" + token;
	else if (map[token]->isParenthesis())
		processParenthesis(map[token], vStack, opStack);
	else
		processOperator(map[token], vStack, opStack);
}

void Calculator::processOperator(Operator* op, ValueStack& vStack, OperatorStack& opStack)
{
	if (op->getRecordType() == RecordType::prefix)
		opStack.push(op);
	else if (op->getRecordType() == RecordType::postfix)
		clacOperator(op, vStack);
	else
		processInfixOp(op, vStack, opStack);
}

void Calculator::processParenthesis(Operator* op, ValueStack& vStack, OperatorStack& opStack)
{
	if (op->isOperPar())
		opStack.push(op);
	else
	{
		if (opStack.empty())
			throw parError;
		Operator* nextOp = opStack.top();
		while (!(nextOp->isOperPar()))
		{
			clacOperator(opStack.top(), vStack);
			opStack.pop();
			if (opStack.empty())
				throw parError;

			nextOp = opStack.top();
		}
		opStack.pop();
	}
}

void Calculator::processInfixOp(Operator* op, ValueStack& vStack, OperatorStack& opStack)
{
	if (opStack.empty())
	{
		opStack.push(op);
		return;
	}
	Operator* nextOp = opStack.top();
	while (nextOp->getRecordType() == RecordType::prefix ||
		nextOp->getPriority() > op->getPriority() ||
		(!(nextOp->isRightAssociative()) && nextOp->getPriority() == op->getPriority()))
	{
		clacOperator(opStack.top(), vStack);
		opStack.pop();
		if (opStack.empty())
			break;
		nextOp = opStack.top();
	}
	opStack.push(op);
}

void Calculator::clacOperator(Operator* op, ValueStack& vStack)
{
	Args args;
	for (int i = 0; i < op->getNParams(); i++)
	{
		if (vStack.empty())
			throw inError;
		args.push_back(vStack.top());
		vStack.pop();
	}
	vStack.push(op->calc(args));
}

Calculator::Calculator()
{
	loader.addBasicOperatotions(map);
	loader.parsDlls(map);
}

Calculator::~Calculator()
{
	for (auto i : map)
		delete i.second;
}
