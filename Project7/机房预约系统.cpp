#include<iostream>
using namespace std;
#include"Identity.h"


int main() {
	int select = 0;//接收用户选择
	while (true)
	{
		Menu();
		cin >> select;
		switch (select)
		{
		case 1:		//学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:		//老师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:		//管理员身份
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:		//退出
			Exit();
			exit(0);
			break;
		default:
			cout << "输入有误重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	return 0;
}