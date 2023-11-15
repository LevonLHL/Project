#include"Manager.h"


Manager::Manager() {

}

Manager::Manager(string name, string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;
	//初始化容器 获取到所有文件中的学生、教师信息
	this->initVector();
	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs>>com.m_ComId && ifs>>com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	//测试
	cout << "机房的数量为：" << vCom.size() << endl;
}

void Manager::operMenu() {
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t------------------——--\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      1.添加账号      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      2.查看账号      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      3.查看机房      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      4.清空预约      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      0.注销登录      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t--------------——------\n";
	cout << "请输入您的操作：";
}

void Manager::addPerson() {
	string fileName;//操作文件名
	string tip;//提示id号
	ofstream ofs;//文件操作对象
	int select = 0;
	while (true)
	{
		cout << "请输入添加账号的类型：" << endl;
		cout << "1、添加学生" << endl;
		cout << "2、添加教师" << endl;
		cin >> select;
		if (select == 1)//添加学生
		{
			fileName = STUDENT_FILE;
			tip = "请输入学号：";
			break;
		}
		else if (select == 2)//添加教师
		{
			fileName = TEACHER_FILE;
			tip = "请输入职工号：";
			break;
		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			this->operMenu();
		}
	}
	ofs.open(fileName, ios::out | ios::app);//用追加的方式写文件
	int id;
	string name;
	string pwd;
	while (true)
	{
		cout << tip;
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << "有重复数据，请重新输入！" << endl;
		}
		else
		{
			break;
		}
	}
	
	cout << "请输入姓名：";
	cin >> name;
	cout << "请输入密码：";
	cin >> pwd;
	//向文件中添加数据
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功！" << endl;
	ofs.close();
	//调用初始化容器的接口，重新获取文件中的数据
	this->initVector();
	system("pause");
	system("cls");
}

void Manager::showPerson() {
	while (true)
	{
		cout << "请选择查看的内容：" << endl;
		cout << "1、查看所有学生" << endl;
		cout << "2、查看所有教师" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)//查看学生
		{
			cout << "所有的学生信息如下：" << endl;
			for_each(vStu.begin(), vStu.end(), printStudent);
			system("pause");
			system("cls");
			return;
		}
		else if (select == 2)//查看教师
		{
			cout << "所有的教师信息如下：" << endl;
			for_each(vTea.begin(), vTea.end(), printTeacher);
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			this->operMenu();
		}
	}
}

void Manager::showComputer() {
	cout << "机房的信息如下：" << endl;
	for_each(vCom.begin(), vCom.end(), printComputerRoom);
	system("pause");
	system("cls");
}

void Manager::cleanFile() {
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector() {
	//确保容器清空状态
	vStu.clear();
	vTea.clear();
	//读取信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败！" << endl;
		return;
	}
	Student s;
	while (ifs>>s.m_Id && ifs>>s.m_Name && ifs>>s.m_Pwd)
	{
		vStu.push_back(s);
	}
	//测试
	cout << "当前学生数量为：" << vStu.size() << endl;
	ifs.close();
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败！" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	//测试
	cout << "当前教师数量为：" << vTea.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type) {
	if (type == 1)//检测学生
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
				return true;
		}
	}
	else    //检测教师
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
				return true;
		}
	}
	return false;
}