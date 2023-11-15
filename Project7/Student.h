#pragma once
#include"Identity.h"

//学生类
class Student : public Identity
{
public:
	Student();
	Student(int id, string name, string pwd);//有参构造：学号、姓名、密码
	virtual void operMenu();//菜单界面
	void applyOrder();//申请预约
	void showMyOrder();//查看自身预约
	void showAllOrder();//查看所有预约
	void cancelOrder();//取消预约

	int m_Id;//学生学号
	vector<ComputerRoom>vCom;//机房容器
};
