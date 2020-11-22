/*
	В данной dll реализованы операции унарного и бинарного минуса и возведение в степень.
	Пришлось создать абстрактного предка для двух видов минусов, проблема заключалась в том, 
	что нужно было как-то различать по контексту в исхлжной строке, унарной или бинарной опирацией 
	является тот или иной минус.
	Абстрактный предок Operator и его виртуальный метод pars позволил позволил решить эту проблему.
*/

#pragma once
#include"pch.h"
#include "Grammar.h"
#include "../include/Grammar.h"


#ifdef OTHERBASICOPERATORS_EXPORTS
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"
{
#endif
	//__________________________MINUS_______________________________
	void EXPORT FunDefiner(std::map<std::string, Operator*>& map);

	class EXPORT Minus : public Operator
	{
	protected:
		bool isUnaryMinus(const std::string&, size_t);
		virtual bool isNecessaryMinus(const std::string&, size_t) = 0;
	public:
		void pars(std::string&) override;
	};


	class EXPORT UMinus : public Minus
	{
	protected:
		bool isNecessaryMinus(const std::string&, size_t) override;
	public:
		UMinus();
		~UMinus() {};
		double calc(const Args& args) override;
	};

	class EXPORT BMinus : public Minus
	{
	protected:
		bool isNecessaryMinus(const std::string&, size_t) override;
	public:
		BMinus();
		~BMinus() {};
		double calc(const Args& args) override;
	};



	//__________________________POW___________________________________
	
	class Pow : public Operator
	{
	public:
		Pow();
		~Pow() {};
		double calc(const Args& args) override;
	};

#ifdef __cplusplus
}
#endif
