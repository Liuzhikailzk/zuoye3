#include "head.h"

//登录后的菜单
void menuLogin() {
	cout << " ---------------------------欢迎使用仓库管理系统------------------------" << endl;
	cout << " |                         1、查询功能                                  |" << endl;
	cout << " |                         2、入库功能                                  |" << endl;
	cout << " |                         3、出库功能                                  |" << endl;
	cout << " |                         4、添加商品功能                              |" << endl;
	cout << " |                         5、删除商品功能                              |" << endl;
	cout << " |                         6、退出                                      |" << endl;
	cout << " -----------------------------------------------------------------------" << endl;
	cout << " 请输入你的选择:";
}

//查询功能的菜单
void menuQuery() {
	cout << " ---------------------------欢迎使用仓库管理系统------------------------" << endl;
	cout << " |                         1、查询账号信息                              |" << endl;
	cout << " |                         2、查询库存信息                              |" << endl;
	cout << " |                         3、退出                                      |" << endl;
	cout << " -----------------------------------------------------------------------" << endl;
	cout << " 请输入你的选择:";
}

//总菜单
void menuSub() {
	cout << " ---------------------------欢迎使用仓库管理系统------------------------" << endl;
	cout << " |                         1、注册                                      |" << endl;
	cout << " |                         2、登录                                      |" << endl;
	cout << " |                         3、退出                                      |" << endl;
	cout << " -----------------------------------------------------------------------" << endl;
	cout << " 请输入你的选择:";
};


//读取用户的信息
void user::readUser(string number) {
	string IDStr, nameStr, pwdStr;
	istringstream is(number);
	is >> IDStr >> nameStr >> pwdStr;
	this->ID = IDStr;
	this->Name = nameStr;
	this->Password = pwdStr;
}


//注册功能
void user::Register()
{
	string pw1;
	string pw2;
	user person;
flag:
	cout << "请设置您的ID:";
	cin >> person.ID;
	ifstream rfile;
	rfile.open("user.txt", ios::in);
	string temp;
	user u;
	while (getline(rfile, temp)) {
		u.readUser(temp);
		if (u.ID == person.ID) {
			cout << "该ID已存在，请重新设置!" << endl;
			goto flag;
		}
	}
	cout << "请设置您的用户名:";
	cin >> person.Name;
	cout << "请设置您的密码:";
flag0:
	cin >> pw1;
	cout << "请再次确认您的密码:";
	cin >> pw2;
	if (pw1 != pw2)
	{
		cout << "前后两次输入密码不一致，请重新设置密码!" << endl;
		goto flag0;
	}
	person.Password = pw1;
	writeUser(person.ID, person.Name, person.Password);
	cout << "\n" << endl;
	cout << "用户[" << person.Name << "]注册成功!" << endl;
	system("pause");
};

//登录功能
void user::Enter()
{
flag1:
	cout << "请输入你的ID:";
	string id;
	string pwd;
	cin >> id;
	ifstream rfileId;
	rfileId.open("user.txt", ios::in);
	string tempId;
	user userId;
	while (getline(rfileId, tempId)) {
		userId.readUser(tempId);
		if (userId.ID == id) {
			goto flag2;
		}
	}
	cout << "该ID不存在，请重新输入!" << endl;
	goto flag1;

flag2:
	cout << "请输入你的密码:";
	cin >> pwd;
	ifstream rfilePwd;
	rfilePwd.open("user.txt", ios::in);
	string tempPwd;
	user userPwd;
	while (getline(rfilePwd, tempPwd)) {
		userPwd.readUser(tempPwd);
		if (userPwd.ID == id)
		{
			if (userPwd.Password == pwd)
			{
				break;
			}
			else
			{
				cout << "密码错误，请重新输入!" << endl;
				system("pause");
				goto flag2;
			}
		}
	}
	nowUser = userPwd;
	cout << "\n" << endl;
	cout << "用户[" << userPwd.Name << "]登录成功!" << endl;
	system("pause");
	function();
};

//显示当前用户的信息
void user::queryUser() {
	cout << "您的ID为:" << this->ID << endl;
	cout << "您的密码为:" << this->Password << endl;
	cout << "您的用户名为:" << this->Name << endl;
	system("pause");
}

//将注册的用户信息写入user.txt
void writeUser(string ID, string name, string pwd) {
	fstream wfile;
	int IDLen = ID.size();
	int nameLen = name.size();
	int pwdLen = pwd.size();

	char* IDnumber = new char[IDLen];
	char* username = new char[nameLen];
	char* password = new char[pwdLen];

	strcpy(IDnumber, ID.c_str());
	strcpy(username, name.c_str());
	strcpy(password, pwd.c_str());

	wfile.open("user.txt", ios::out | ios::app);
	wfile.write(IDnumber, IDLen);
	wfile.write(" ", strlen(" "));
	wfile.write(username, nameLen);
	wfile.write(" ", strlen(" "));
	wfile.write(password, pwdLen);
	wfile.write("\n", strlen("\n"));
	wfile.close();
}


//将商品信息写入good.txt
void writeGood(string ID, string name, int originalNum, int outNum, int inNum, int finalNum) {
	char originalNumCh[10];
	_itoa(originalNum, originalNumCh, 10);
	string originalNumStr(originalNumCh, originalNumCh + strlen(originalNumCh));

	char outNumCh[10];
	_itoa(outNum, outNumCh, 10);
	string outNumStr(outNumCh, outNumCh + strlen(outNumCh));

	char inNumCh[10];
	_itoa(inNum, inNumCh, 10);
	string inNumStr(inNumCh, inNumCh + strlen(inNumCh));

	char finalNumCh[10];
	_itoa(finalNum, finalNumCh, 10);
	string finalNumStr(finalNumCh, finalNumCh + strlen(finalNumCh));

	int IDLen = ID.size();
	int nameLen = name.size();
	int originalNumStrLen = originalNumStr.size();
	int outNumStrLen = outNumStr.size();
	int inNumLen = inNumStr.size();
	int finalNumLen = finalNumStr.size();

	char* IDnumber = new char[IDLen];
	char* username = new char[nameLen];
	char* originalNumArr = new char[originalNumStrLen];
	char* outNumArr = new char[outNumStrLen];
	char* inNumArr = new char[inNumLen];
	char* finalNumArr = new char[finalNumLen];

	strcpy(IDnumber, ID.c_str());
	strcpy(username, name.c_str());
	strcpy(originalNumArr, originalNumStr.c_str());
	strcpy(outNumArr, outNumStr.c_str());
	strcpy(inNumArr, inNumStr.c_str());
	strcpy(finalNumArr, finalNumStr.c_str());

	fstream wfile;
	wfile.open("good.txt", ios::out | ios::app);
	wfile.write(IDnumber, IDLen);
	wfile.write(" ", strlen(" "));
	wfile.write(username, nameLen);
	wfile.write(" ", strlen(" "));
	wfile.write(originalNumArr, originalNumStrLen);
	wfile.write(" ", strlen(" "));
	wfile.write(outNumArr, outNumStrLen);
	wfile.write(" ", strlen(" "));
	wfile.write(inNumArr, inNumLen);
	wfile.write(" ", strlen(" "));
	wfile.write(finalNumArr, finalNumLen);
	wfile.write("\n", strlen("\n"));
	wfile.close();
}

//读取商品的信息
void good::readGood(string number) {
	string IDStr, nameStr, originalNumStr, outNumStr, inNumStr, finalNumStr;
	istringstream is(number);
	is >> IDStr >> nameStr >> originalNumStr >> outNumStr >> inNumStr >> finalNumStr;
	stringstream ssOriginalNum;
	ssOriginalNum << originalNumStr;
	int originalNum;
	ssOriginalNum >> originalNum;
	stringstream ssOutNum;
	ssOutNum << outNumStr;
	int outNum;
	ssOutNum >> outNum;
	stringstream ssInNum;
	ssInNum << inNumStr;
	int inNum;
	ssInNum >> inNum;
	stringstream ssFinalNum;
	ssFinalNum << finalNumStr;
	int finalNum;
	ssFinalNum >> finalNum;
	this->ID = IDStr;
	this->Name = nameStr;
	this->originalNum = originalNum;
	this->outNum = outNum;
	this->inNum = inNum;
	this->finalNum = finalNum;
}

//查询并显示对应商品的信息
void good::queryGood() {
	good findGood;
	string temp;
	string inNumber;
	ifstream rfile;
	rfile.open("good.txt", ios::in);
	int num = rfile.tellg();
	if (num == -1)
	{
		cout << "提示:找不到 good.txt 文件!" << endl;
		cout << "提示:请添加 good.txt 文件!" << endl;
		rfile.close();
	}
	else
	{
		rfile.close();
		while (1)
		{

			ifstream rfile;
			rfile.open("good.txt", ios::in);
			cout << "请输入查询商品的货品编号(按[~]进入名称查询):";
			cin >> inNumber;
			if (inNumber != "`")
			{
				while (getline(rfile, temp))
				{
					findGood.readGood(temp);
					if (findGood.ID == inNumber)
					{
						cout << "您的货品编号为:" << findGood.ID << endl;
						cout << "您的货品名称为:" << findGood.Name << endl;
						cout << "您的原始库存为:" << findGood.originalNum << endl;
						cout << "您的进货数目为:" << findGood.inNum << endl;
						cout << "您的出货数目为:" << findGood.outNum << endl;
						cout << "您的最终库存为:" << findGood.finalNum << endl;
						rfile.close();
						goto flag3;
					}
				}
				cout << "输入有误，请重新输入!" << endl;
			}
			else
			{
				cout << "请输入查询商品的名称:";
				cin >> inNumber;
				while (getline(rfile, temp))
				{
					findGood.readGood(temp);
					if (findGood.Name == inNumber)
					{
						cout << "您的货品编号为:" << findGood.ID << endl;
						cout << "您的货品名称为:" << findGood.Name << endl;
						cout << "您的原始库存为:" << findGood.originalNum << endl;
						cout << "您的进货数目为:" << findGood.inNum << endl;
						cout << "您的出货数目为:" << findGood.outNum << endl;
						cout << "您的最终库存为:" << findGood.finalNum << endl;
						rfile.close();
						goto flag3;
					}
				}
			}
			
			
		}
	flag3:
		system("pause");
	}
}

//查询功能
void query()
{
	char choice;
	good queryGood;
	while (1)
	{
		system("cls");
		menuQuery();
		cin >> choice;
		switch (choice)
		{
		case '1':
			nowUser.queryUser();
			break;
		case '2':
			queryGood.queryGood();
			break;
		case '3':
			return;
			break;
		default:
			cout << "提示:请输入有误，重新输入!" << endl;
			system("pause");
		}
	}
}

//入库功能
void good::library() 
{
	ifstream rfile;
	good findGood;
	rfile.open("good.txt", ios::in);
	string temp;
	string inNumber;
	int num = rfile.tellg();
	if (num == -1)
	{
		cout << "提示:找不到 good.txt 文件!" << endl;
		cout << "提示:请添加 good.txt 文件!" << endl;
	}
	else
	{
		while (1)
		{
			cout << "请输入查询商品的货品编号,按[~]退出:";
			cin >> inNumber;
			if (inNumber == "`")
				return;
			while (getline(rfile, temp))
			{
				findGood.readGood(temp);
				if (findGood.ID == inNumber)
				{
					goto flag4;
				}
			}
			cout << "输入有误，请重新输入!" << endl;
			system("pause");
		}
	flag4:
		cout << "请输入入库的数目:";
		int libraryNumber;
		cin >> libraryNumber;
		int inNumTemp = findGood.inNum;
		int finalNumTemp = findGood.finalNum;
		findGood.inNum += libraryNumber;
		findGood.finalNum += libraryNumber;

		if (findGood.inNum < 0 || findGood.finalNum < 0 || libraryNumber < 0) {
			cout << "输入的数目错误，请重新输入!" << endl;
			findGood.inNum = inNumTemp;
			findGood.finalNum = finalNumTemp;
			goto flag4;
		}

		//将文件的数据全部取出，修改对应的那行数据，再写入文件
		rfile.seekg(0);
		good tempGood;
		string tempStr;
		while (getline(rfile, tempStr))
		{
			tempGood.readGood(tempStr);
			if (tempGood.ID == inNumber)
			{
				goods.push_back(findGood);
			}
			else
			{
				goods.push_back(tempGood);
			}
		}
		ofstream f("good.txt", ios::trunc);
		f.close();
		for (int i = 0; i < goods.size(); i++)
		{
			writeGood(goods.at(i).ID, goods.at(i).Name, goods.at(i).originalNum, goods.at(i).outNum, goods.at(i).inNum, goods.at(i).finalNum);
		}
		goods.clear();
	}
	cout << "\n" << endl;
	cout << "入库成功!" << endl;
	cout << "提示:当前入库的数目为:" << findGood.inNum << "，当前库存的数目为:" << findGood.finalNum << endl;
	system("pause");
}

//出库功能
void good::outbound() 
{
	ifstream rfile;
	good findGood;
	rfile.open("good.txt", ios::in);
	string temp;
	string inNumber;
	int num = rfile.tellg();
	if (num == -1)
	{
		cout << "提示:找不到 good.txt 文件!" << endl;
		cout << "提示:请添加 good.txt 文件!" << endl;
	}
	else
	{
		while (1)
		{
			cout << "请输入查询商品的货品编号,按[~]退出:";
			cin >> inNumber;
			if (inNumber == "`")
				return;
			while (getline(rfile, temp))
			{
				findGood.readGood(temp);
				if (findGood.ID == inNumber)
				{
					goto flag5;
				}
			}
			cout << "输入有误，请重新输入!" << endl;
		}
	flag5:
		cout << "请输入出库的数目:";
		int outboundNumber;
		cin >> outboundNumber;
		int outNumTemp = findGood.outNum;
		int finalNumTemp = findGood.finalNum;
		findGood.outNum += outboundNumber;
		findGood.finalNum -= outboundNumber;
		if (findGood.outNum < 0 || findGood.finalNum < 0 || outboundNumber < 0) {
			cout << "输入的数目错误，请重新输入!" << endl;
			findGood.outNum = outNumTemp;
			findGood.finalNum = finalNumTemp;
			goto flag5;
		}

		//将文件的数据全部取出，修改对应的那行数据，清空文件数据，再重新写入文件
		rfile.seekg(0);
		good tempGood;
		string tempStr;
		while (getline(rfile, tempStr))
		{
			tempGood.readGood(tempStr);
			if (tempGood.ID == inNumber)
			{
				goods.push_back(findGood);
			}
			else
			{
				goods.push_back(tempGood);
			}
		}
		ofstream f("good.txt", ios::trunc);
		f.close();
		for (int i = 0; i < goods.size(); i++)
		{
			writeGood(goods.at(i).ID, goods.at(i).Name, goods.at(i).originalNum, goods.at(i).outNum, goods.at(i).inNum, goods.at(i).finalNum);
		}
		goods.clear();
	}
	cout << "\n" << endl;
	cout << "出库成功!" << endl;
	cout << "提示:当前出库的数目为:" << findGood.outNum << "，当前库存的数目为:" << findGood.finalNum << endl;
	system("pause");
}

//添加商品功能
void addGood() 
{
	string addID;
	string addName;
	int addOriginalNum;
	int addOutNum;
	int addInNum;
	int addFinalNum;
	cout << "请输入商品ID:";
	cin >> addID;
	cout << "请输入商品名称:";
	cin >> addName;
	cout << "请输入商品库存:";
	cin >> addOriginalNum;
	/*cout << "请输入商品出库数目:";
	cin >> addOutNum;
	cout << "请输入商品入库数目:";
	cin >> addInNum;
	cout << "请输入商品最终数目:";
	cin >> addFinalNum;*/
	writeGood(addID, addName, addOriginalNum, 0, 0, addOriginalNum);
	cout << "\n" << endl;
	cout << "商品[" << addName << "]添加成功!" << endl;
	system("pause");
}

//删除商品功能
void good::deleteGood() 
{
	ifstream rfile;
	good findGood;
	rfile.open("good.txt", ios::in);
	string temp;
	string inNumber;
	int num = rfile.tellg();
	if (num == -1)
	{
		cout << "提示:找不到 good.txt 文件!" << endl;
		cout << "提示:请添加 good.txt 文件!" << endl;
	}
	else
	{
		while (1)
		{
			cout << "请输入查询商品的货品编号,按[~]退出:";
			cin >> inNumber;
			if (inNumber == "`")
				return;
			while (getline(rfile, temp))
			{
				findGood.readGood(temp);
				if (findGood.ID == inNumber)
				{
					int i;
					cout << "确定要删除吗,按 1 确定" << endl;
					cin >> i;
					if (i == 1)
					{
						goto flag6;
					}
					else
						break;
					
				}
			}
			cout << "输入有误，请重新输入!" << endl;
		}
	flag6:
		//将文件的数据全部取出，删除对应的那行数据，清空文件数据，再重新写入文件
		rfile.seekg(0);
		good tempGood;
		string tempStr;
		while (getline(rfile, tempStr))
		{
			tempGood.readGood(tempStr);
			if (tempGood.ID != inNumber)
			{
				goods.push_back(tempGood);
			}
		}
		ofstream f("good.txt", ios::trunc);
		f.close();
		for (int i = 0; i < goods.size(); i++)
		{
			writeGood(goods.at(i).ID, goods.at(i).Name, goods.at(i).originalNum, goods.at(i).outNum, goods.at(i).inNum, goods.at(i).finalNum);
		}
		goods.clear();
		cout << "\n" << endl;
		cout << "商品删除成功!" << endl;
	}
	
	system("pause");
}

//总功能
void function() 
{
	char choice;
	good d;
	while (1)
	{
		system("cls");
		menuLogin();
		cin >> choice;
		switch (choice)
		{
		case '1':
			//查询功能
			query();
			break;
		case '2':
			//入库功能
			d.library();
			break;
		case '3':
			//出库功能
			d.outbound();
			break;
		case '4':
			//添加商品功能
			addGood();
			break;
		case '5':
			//删除商品功能
			d.deleteGood();
			break;
		case '6':
			//退出
			return;
			break;
		default:
			cout << "提示:请输入有误，重新输入!" << endl;
			system("pause");
		}
	}
}

//主函数
void main()
{
	//设置控制台窗口和字体的颜色
	system("color 70");
	char choice;
	user u;
	while (1)
	{
		system("cls");
		menuSub();
		cin >> choice;
		switch (choice)
		{
		case '1':
			//注册功能
			u.Register();
			break;
		case '2':
			//登录功能
			u.Enter();
			break;
		case '3':
			//退出
			return;
			break;
		default:
			cout << "提示:请输入有误，重新输入!" << endl;
			system("pause");
		}
	}
}

