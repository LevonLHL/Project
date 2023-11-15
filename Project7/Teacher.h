#pragma once
#include"Identity.h"


//教师类
class Teacher : public Identity
{
public:
	Teacher();
	Teacher(int empId, string name, string pwd);//有参构造：编号、姓名、密码
	virtual void operMenu();//菜单界面
	void showAllOrder();//查看所有预约
	void validOrder();//审核预约

	int m_EmpId;//教师编号
};