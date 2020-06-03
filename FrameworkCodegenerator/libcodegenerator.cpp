#include "libcodegenerator.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator> 

ProgFramework CreateProgFramework(std::string MarkUpFname){
	std::ifstream fin(MarkUpFname,  std::ios_base::in);
	ProgFramework  app;
	
	if ( !fin.is_open()) std::cout << "file not open";
	
	std::string str;
	auto ptr {false};
	auto flag {false};
	while (!fin.eof())
	{
		getline(fin , str);
		
		if (str[0] == '/' && str[1] == '/')
			continue;
		if (str.length() == 0)
			continue;
		if(!ptr){
			app.AppName = str.substr (1, str.length()-2);
			ptr = true;
			continue;
		}
		if(!flag){
			app.ExitItem = MenuItem( {str[0] , str.substr(3, str.length()-4) });
			flag = true;
			continue;
		}
		
		app.MenuItems.push_back( (MenuItem) {str[0] , str.substr(3, str.length()-4) } );		
	}
	
	fin.close();
	return app;
}

void CopyFile(std::string BegFname, std::string EndFname){
	std::ifstream in (BegFname, std::ios_base::in | std::ios_base::binary);
	std::ofstream out (EndFname,std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
	char buf;
	while (in.get(buf)){
		out.put(buf);
	}
	in.close();
	out.close();
}

void CopyTemplate(std::string BegFname, std::string EndFname){
	CopyFile(BegFname + "FrameworkApplication.zpr", EndFname + "\\FrameworkApplication.zpr");
	CopyFile(BegFname + "libframework.cpp", EndFname + "\\libframework.cpp");
	CopyFile(BegFname + "libframework.h", EndFname + "\\libframework.h");
}

void Generate(ProgFramework MarkUp, std::string EndFname){
	std::string mainFname = EndFname + "main.cpp";
	std::ofstream out(mainFname, std::ios_base::out);
	out << "include <iostream>\n";
	out << "include <windows.h>\n";
	out << "include \"libframework.h\"\n";
	out << "include \"menu.h\"\n\n";
	out << "int main(){\n";
	out << "SetConsoleOutputCP(1251);\n";
	out << "framework app(\"" << MarkUp.AppName; 
	if (MarkUp.ExitItem.accel != '.')
		out << "\", \'" <<MarkUp.ExitItem.accel << "\', \"" << MarkUp.ExitItem.MenuCaption << '\"'; 
	out << ");\n";
	int count = 1;
	for(auto it {MarkUp.MenuItems.begin()}; it != MarkUp.MenuItems.end(); ++it){
		out << "app.add_menu_item(\'" << it->accel << "\', \"" << it->MenuCaption << "\", menu" << count << "callback);\n";
		++count;
	}
	out << "app.run();\n";
	out << "return 0;\n";
	out << '}';
	out.close();
	std::string menuhFname = EndFname + "menu.h";
	out.open(menuhFname, std::ios_base::out);
	out << "#ifndef MENU_H\n";
	out << "#define MENU_H\n\n";
	for(auto i {1}; i < count; ++i)
		out << "void menu" << i << "callback(void);\n\n";
	out << "#endif";
	out.close();
	std::string menucppFname = EndFname + "menu.cpp";
	out.open(menucppFname, std::ios_base::out);
	out << "#include \"menu.h\"\n\n";
	for(auto i {1}; i < count; ++i){
		out << "void menu" << i << "callback(void){\n";
		out << "//add code here\n";
		out << "}\n\n";
	}
	out.close();
}
