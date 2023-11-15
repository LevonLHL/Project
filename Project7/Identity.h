#pragma once
#include<iostream>
using namespace std;
#include"GlobalFile.h"
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include"ComputerRoom.h"
#include"OrderFile.h"


void Menu();
void Exit();
void LoginIn(string fileName, int type);//登录功能，参数（操作文件名，操作身份类型）



//身份抽象基类
class Identity
{
public:
	virtual void operMenu() = 0;//操作菜单


	string m_Name;	//用户名
	string m_Pwd;	//密码
};

void managerMenu(Identity*& manager);//进入管理员子菜单界面
void studentMenu(Identity*& student);//进入学生子菜单界面
void teacherMenu(Identity*& teacher);//进入教师子菜单界面
//下面三个文件的类要定义就需要基类，但如果基类在后面就相当于基类没有任何声明，故报错C2504：未定义的基类
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
void printStudent(Student& s);//打印学生
void printTeacher(Teacher& t);//打印教师
void printComputerRoom(ComputerRoom& c);//打印机房