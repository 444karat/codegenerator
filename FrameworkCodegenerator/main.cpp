#include<iostream>
#include<string>
#include<vector>
#include<windows.h>
#include "libcodegenerator.h"

//Текущий файл разметки
//std::string MarkUpFileName = "E:\зинья\zinjai\projects\FrameworkCodegenerator\Debug\MarkUp.txt";

//Папка, в которой происходит генерация кода
//std::string ProgGenFolder = "G:\\MyApp\\";

//Считаем, что файлы libframework.h и libframework.cpp, FrameworkApplication.zpr расположены
//в каталоге templates который расположен там же, где и Codegenerator.exe

int main (int argc, char *argv[]) {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::string MarkUpFileName, ProgGenFolder, templates {argv[0]};
	while(templates[templates.size() - 1] != '\\')
		templates.pop_back();
	templates += "templates\\";
	ProgFramework App;
	std::cin >> MarkUpFileName;
	std::cin >> ProgGenFolder; 
	if(ProgGenFolder.empty())
		ProgGenFolder = MarkUpFileName;
	if(ProgGenFolder == MarkUpFileName)
		while(ProgGenFolder[ProgGenFolder.size() - 1] != '\\')
			ProgGenFolder.pop_back();
	CopyTemplate(templates, ProgGenFolder);
	App = CreateProgFramework(MarkUpFileName);
	Generate(App, ProgGenFolder);
	return 0;
}

