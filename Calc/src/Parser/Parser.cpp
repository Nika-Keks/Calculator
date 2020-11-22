#include "Parser.h"

void Parser::setString(std::string str)
{
	str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char sym) {return std::isspace(sym); }), str.end());
	this->str = str;
}

std::string Parser::nextKey()
{
	std::string nextKey_ = "";
	std::regex re("([a-zA-Z]+|[0-9]+[/.]?[0-9]*)");
	std::smatch m;
	while (std::regex_search(str, m, re))
	{
		nextKey_ = m[0].str();
		str = m.suffix().str();
		if (!nextKey_.empty())
			break;
	}
	return nextKey_;
}

void Parser::parsOperators(const OperatorMap& map)
{
	for (auto pair : map)
		pair.second->pars(str);
}

bool Parser::isNum(const std::string& str)
{
	std::regex rx("[0-9]+[\\.]?[0-9]*");
	if (std::regex_match(str, rx))
		return true;
	return false;
}

