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

//Проанализировать файл разметки, создать и вернуть экземпляр меню
ProgFramework CreateProgFramework(std::string MarkUpFname);

//Копирует содержимое файла с полным названием BegFname в файл с полным названием EndFname
void CopyFile(std::string BegFname, std::string EndFname);

//Создает файлы menu.h и menu.cpp в каталоге EndFname на основании информации в структуре MarkUp
void Generate(ProgFramework MarkUp, std::string EndFname);

//копирует шаблонные файлы в директорию EndFname
void CopyTemplate(std::string BegFname, std::string EndFname);

#endif
