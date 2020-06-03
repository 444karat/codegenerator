#include "libframework.h"
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

framework::framework(std::string app_name, 
					 char exit_accel , 
					 std::string exit_caption ){
	this->app_name = app_name;
	menu.push_back((menu_item){exit_accel, exit_caption, nullptr});
	
}

void framework::add_menu_item(char accel, std::string name, callback f){
	menu.push_back((menu_item){accel, name, f});
}

void framework::show_menu(void){
	std::cout << app_name << std::endl;
	for (auto it { menu.rbegin()} ; it != menu.rend(); ++it){
		std::cout << it->accel << ' ' << it->name << std::endl;
		
	}
}

int framework::find_menu_item(char accel){
	for (auto it {1}; it < menu.size(); ++it){
		if (menu[it].accel == accel)
			return it;
	}
	return -1;
}

void framework::run (void){
	show_menu();
	char key;
	do{
		key = getchar();
		auto ind {find_menu_item(key)};
		if (ind != -1){
			system("cls");
			menu[ind].f();
			system("PAUSE");
			system("cls");
			show_menu();
		}
	} while(key != menu[0].accel);
}
