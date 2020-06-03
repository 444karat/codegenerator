#ifndef LIBCODEGENERATOR_H
#define LIBCODEGENERATOR_H

#include <string>
#include <vector>

struct MenuItem{
	char accel;
	std::string MenuCaption;
};

struct ProgFramework{
	std::string AppName;
	MenuItem ExitItem;
	std::vector<MenuItem> MenuItems;
};

//���������������� ���� ��������, ������� � ������� ��������� ����
ProgFramework CreateProgFramework(std::string MarkUpFname);

//�������� ���������� ����� � ������ ��������� BegFname � ���� � ������ ��������� EndFname
void CopyFile(std::string BegFname, std::string EndFname);

//������� ����� menu.h � menu.cpp � �������� EndFname �� ��������� ���������� � ��������� MarkUp
void Generate(ProgFramework MarkUp, std::string EndFname);

//�������� ��������� ����� � ���������� EndFname
void CopyTemplate(std::string BegFname, std::string EndFname);

#endif
