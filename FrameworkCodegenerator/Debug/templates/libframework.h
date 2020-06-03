#ifndef LIBFRAMEWORK_H
#define LIBFRAMEWORK_H

#include <string>
#include <vector>

//��� ������� ��������� ������
using callback = void (*) (void);

//����������� ������ ����
struct menu_item{
	char accel;
	std::string name;
	callback f;
};

//����� ���������
class framework{
private:
	std::vector<menu_item> menu;
	std::string app_name;
public:
	framework(std::string app_name, 
			   char exit_accel 			= 'q', 
			   std::string exit_caption = "��� ������");
	
	void add_menu_item(char accel, std::string name, callback f);
	
	void show_menu(void);
	
	int find_menu_item(char accel);
	
	void run(void);
	
	
};

#endif
