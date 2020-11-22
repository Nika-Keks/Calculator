#include <iostream>
#include "Calc/Calculator.h"

int main()
{
	Calculator Calc;
	std::string str;

	std::cin >> str;

	while (str != "#")
	{
		std::cout << Calc.calc(str) << std::endl;
		std::cin >> str;
	}

	return 0;
}

