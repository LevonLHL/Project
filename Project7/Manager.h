#pragma once
#include"Identity.h"

class Student;
class Teacher;

//管理员类
class Manager :public Identity
{
public:
	Manager();
	Manager(string name, string pwd);//有参构造：姓名、密码
	virtual void operMenu();//菜单界面
	void addPerson();//添加账号
	void showPerson();//查看账号
	void showComputer();//查看机房信息
	void cleanFile();//清空预约记录
	void initVector();//初始化容器
	bool checkRepeat(int id, int type);//检测重复（学工号/职工号，学生/老师）

	vector<Student>vStu;//学生容器
	vector<Teacher>vTea;//教师容器
	vector<ComputerRoom>vCom;//机房容器
};