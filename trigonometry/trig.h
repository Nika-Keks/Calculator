/*
	� ������ dll ������������ �������� ������.
	��� ��������� ������������������ �������� ����������� ����������.
	���������� ���������� �������� � ����� ���������� �� ������������ �������� �����.
*/

#pragma once
#include"pch.h"


#ifdef TRIGONOMETRY_EXPORTS
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"
{
#endif

	class EXPORT Sin : public Operator
	{
	public:
		Sin();
		~Sin() {};
		double calc(const std::vector<double>& args) override;
		void pars(std::string&) override {};
	};

	void EXPORT FunDefiner(std::map<std::string, Operator*>& map);
	

#ifdef __cplusplus
}
#endif
