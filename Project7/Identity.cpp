#include"Identity.h"

void Menu() {
	cout << "=====================机房预约系统=====================" << endl;
	cout << "请输入您的身份" << endl;
	cout << "\t\t------------------——--\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      1.学生代表      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      2.教    师      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      3.管 理 员      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      0.退    出      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t--------------——------\n";
	cout << "请输入您的选择：";
}

void Exit() {
	cout << "欢迎下一次使用！" << endl;
	system("pause");
}


void LoginIn(string fileName, int type) {
	//父类指针，用于指向子类对象
	Identity *person = NULL;
	ifstream ifs;
	ifs.open(fileName, ios::in);
	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//准备接收用户信息
	int id = 0;
	string name;
	string pwd;
	//判断身份
	if (type == 1)//学生
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if(type == 2)//教师
	{
		cout << "请输入你的职工号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	if (type == 1)
	{
		//学生身份验证
		int fId;//从文件中获取Id号
		string fName;//从文件中获取姓名
		string fPwd;//从文件中获取密码
		while (ifs>>fId && ifs>>fName && ifs>>fPwd)
		{
			//与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师身份验证
		int fId;//从文件中获取Id号
		string fName;//从文件中获取姓名
		string fPwd;//从文件中获取密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师身份子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员身份验证
		string fName;//从文件中获取姓名
		string fPwd;//从文件中获取密码
		while (ifs >> fName && ifs >> fPwd)
		{
			//与用户输入的信息做对比
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员身份子菜单
				managerMenu(person);
				return;
			}
		}
	}
	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
}

void managerMenu(Identity*& manager) {
	while (true)
	{
		//调用管理员子菜单
		manager->operMenu();
		//将父类指针转为子类指针,调用子类其他接口
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		if (select == 1)//添加账号
		{
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			man->showPerson();
		}
		else if (select == 3)//查看机房
		{
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			man->cleanFile();
		}
		else if(select == 0)//注销账户
		{
			delete manager;//销毁堆区对象
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "输入错误，请重新输入！" << endl;
			system("pause");
			system("cls");
		}
	}
}

void studentMenu(Identity*& student) {
	while (true)
	{
		student->operMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1)//申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)//查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3)//查看所有人预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			stu->cancelOrder();
		}
		else if (select == 0)//注销登录
		{
			delete student;//销毁堆区对象
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "输入错误，请重新输入！" << endl;
			system("pause");
			system("cls");
		}
	}
}

void teacherMenu(Identity*& teacher) {
	while (true)
	{
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1)//查看所有预约
		{
			tea->showAllOrder();
		}
		else if (select == 2)//审核预约
		{
			tea->validOrder();
		}
		else if (select == 0)//注销登录
		{
			delete teacher;//销毁堆区对象
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "输入错误，请重新输入！" << endl;
			system("pause");
			system("cls");
		}
	}
}

void printStudent(Student& s) {
	cout << "学号：" << s.m_Id << "	姓名：" << s.m_Name << "	密码：" << s.m_Pwd << endl;
}
void printTeacher(Teacher& t) {
	cout << "职工号：" << t.m_EmpId << "	姓名：" << t.m_Name << "	密码：" << t.m_Pwd << endl;
}
void printComputerRoom(ComputerRoom& c) {
	cout << "机房编号：" << c.m_ComId << "	机房最大容量：" << c.m_MaxNum << endl;
}