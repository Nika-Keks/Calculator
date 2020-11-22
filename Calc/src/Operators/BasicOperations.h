#pragma once
#include "../include/Operator.h"
#include "../include/Grammar.h"

class Plus : public Operator
{
public:
	Plus();	
	~Plus() {};
	double calc(const Args&) override;
};


class Multiply : public Operator
{
public:
	Multiply();
	~Multiply() {};
	double calc(const Args&) override;
};

class OpenPar : public Operator
{
public:
	OpenPar();
	~OpenPar() {};
	double calc(const Args&) override { return 0.; };
};

class ClosedPar : public Operator
{
public:
	ClosedPar();
	~ClosedPar() {};
	double calc(const Args&) override { return 0.; };
};