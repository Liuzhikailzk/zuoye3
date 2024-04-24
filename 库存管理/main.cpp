#include "head.h"

//��¼��Ĳ˵�
void menuLogin() {
	cout << " ---------------------------��ӭʹ�òֿ����ϵͳ------------------------" << endl;
	cout << " |                         1����ѯ����                                  |" << endl;
	cout << " |                         2����⹦��                                  |" << endl;
	cout << " |                         3�����⹦��                                  |" << endl;
	cout << " |                         4�������Ʒ����                              |" << endl;
	cout << " |                         5��ɾ����Ʒ����                              |" << endl;
	cout << " |                         6���˳�                                      |" << endl;
	cout << " -----------------------------------------------------------------------" << endl;
	cout << " ���������ѡ��:";
}

//��ѯ���ܵĲ˵�
void menuQuery() {
	cout << " ---------------------------��ӭʹ�òֿ����ϵͳ------------------------" << endl;
	cout << " |                         1����ѯ�˺���Ϣ                              |" << endl;
	cout << " |                         2����ѯ�����Ϣ                              |" << endl;
	cout << " |                         3���˳�                                      |" << endl;
	cout << " -----------------------------------------------------------------------" << endl;
	cout << " ���������ѡ��:";
}

//�ܲ˵�
void menuSub() {
	cout << " ---------------------------��ӭʹ�òֿ����ϵͳ------------------------" << endl;
	cout << " |                         1��ע��                                      |" << endl;
	cout << " |                         2����¼                                      |" << endl;
	cout << " |                         3���˳�                                      |" << endl;
	cout << " -----------------------------------------------------------------------" << endl;
	cout << " ���������ѡ��:";
};


//��ȡ�û�����Ϣ
void user::readUser(string number) {
	string IDStr, nameStr, pwdStr;
	istringstream is(number);
	is >> IDStr >> nameStr >> pwdStr;
	this->ID = IDStr;
	this->Name = nameStr;
	this->Password = pwdStr;
}


//ע�Ṧ��
void user::Register()
{
	string pw1;
	string pw2;
	user person;
flag:
	cout << "����������ID:";
	cin >> person.ID;
	ifstream rfile;
	rfile.open("user.txt", ios::in);
	string temp;
	user u;
	while (getline(rfile, temp)) {
		u.readUser(temp);
		if (u.ID == person.ID) {
			cout << "��ID�Ѵ��ڣ�����������!" << endl;
			goto flag;
		}
	}
	cout << "�����������û���:";
	cin >> person.Name;
	cout << "��������������:";
flag0:
	cin >> pw1;
	cout << "���ٴ�ȷ����������:";
	cin >> pw2;
	if (pw1 != pw2)
	{
		cout << "ǰ�������������벻һ�£���������������!" << endl;
		goto flag0;
	}
	person.Password = pw1;
	writeUser(person.ID, person.Name, person.Password);
	cout << "\n" << endl;
	cout << "�û�[" << person.Name << "]ע��ɹ�!" << endl;
	system("pause");
};

//��¼����
void user::Enter()
{
flag1:
	cout << "���������ID:";
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
	cout << "��ID�����ڣ�����������!" << endl;
	goto flag1;

flag2:
	cout << "�������������:";
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
				cout << "�����������������!" << endl;
				system("pause");
				goto flag2;
			}
		}
	}
	nowUser = userPwd;
	cout << "\n" << endl;
	cout << "�û�[" << userPwd.Name << "]��¼�ɹ�!" << endl;
	system("pause");
	function();
};

//��ʾ��ǰ�û�����Ϣ
void user::queryUser() {
	cout << "����IDΪ:" << this->ID << endl;
	cout << "��������Ϊ:" << this->Password << endl;
	cout << "�����û���Ϊ:" << this->Name << endl;
	system("pause");
}

//��ע����û���Ϣд��user.txt
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


//����Ʒ��Ϣд��good.txt
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

//��ȡ��Ʒ����Ϣ
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

//��ѯ����ʾ��Ӧ��Ʒ����Ϣ
void good::queryGood() {
	good findGood;
	string temp;
	string inNumber;
	ifstream rfile;
	rfile.open("good.txt", ios::in);
	int num = rfile.tellg();
	if (num == -1)
	{
		cout << "��ʾ:�Ҳ��� good.txt �ļ�!" << endl;
		cout << "��ʾ:����� good.txt �ļ�!" << endl;
		rfile.close();
	}
	else
	{
		rfile.close();
		while (1)
		{

			ifstream rfile;
			rfile.open("good.txt", ios::in);
			cout << "�������ѯ��Ʒ�Ļ�Ʒ���(��[~]�������Ʋ�ѯ):";
			cin >> inNumber;
			if (inNumber != "`")
			{
				while (getline(rfile, temp))
				{
					findGood.readGood(temp);
					if (findGood.ID == inNumber)
					{
						cout << "���Ļ�Ʒ���Ϊ:" << findGood.ID << endl;
						cout << "���Ļ�Ʒ����Ϊ:" << findGood.Name << endl;
						cout << "����ԭʼ���Ϊ:" << findGood.originalNum << endl;
						cout << "���Ľ�����ĿΪ:" << findGood.inNum << endl;
						cout << "���ĳ�����ĿΪ:" << findGood.outNum << endl;
						cout << "�������տ��Ϊ:" << findGood.finalNum << endl;
						rfile.close();
						goto flag3;
					}
				}
				cout << "������������������!" << endl;
			}
			else
			{
				cout << "�������ѯ��Ʒ������:";
				cin >> inNumber;
				while (getline(rfile, temp))
				{
					findGood.readGood(temp);
					if (findGood.Name == inNumber)
					{
						cout << "���Ļ�Ʒ���Ϊ:" << findGood.ID << endl;
						cout << "���Ļ�Ʒ����Ϊ:" << findGood.Name << endl;
						cout << "����ԭʼ���Ϊ:" << findGood.originalNum << endl;
						cout << "���Ľ�����ĿΪ:" << findGood.inNum << endl;
						cout << "���ĳ�����ĿΪ:" << findGood.outNum << endl;
						cout << "�������տ��Ϊ:" << findGood.finalNum << endl;
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

//��ѯ����
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
			cout << "��ʾ:������������������!" << endl;
			system("pause");
		}
	}
}

//��⹦��
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
		cout << "��ʾ:�Ҳ��� good.txt �ļ�!" << endl;
		cout << "��ʾ:����� good.txt �ļ�!" << endl;
	}
	else
	{
		while (1)
		{
			cout << "�������ѯ��Ʒ�Ļ�Ʒ���,��[~]�˳�:";
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
			cout << "������������������!" << endl;
			system("pause");
		}
	flag4:
		cout << "������������Ŀ:";
		int libraryNumber;
		cin >> libraryNumber;
		int inNumTemp = findGood.inNum;
		int finalNumTemp = findGood.finalNum;
		findGood.inNum += libraryNumber;
		findGood.finalNum += libraryNumber;

		if (findGood.inNum < 0 || findGood.finalNum < 0 || libraryNumber < 0) {
			cout << "�������Ŀ��������������!" << endl;
			findGood.inNum = inNumTemp;
			findGood.finalNum = finalNumTemp;
			goto flag4;
		}

		//���ļ�������ȫ��ȡ�����޸Ķ�Ӧ���������ݣ���д���ļ�
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
	cout << "���ɹ�!" << endl;
	cout << "��ʾ:��ǰ������ĿΪ:" << findGood.inNum << "����ǰ������ĿΪ:" << findGood.finalNum << endl;
	system("pause");
}

//���⹦��
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
		cout << "��ʾ:�Ҳ��� good.txt �ļ�!" << endl;
		cout << "��ʾ:����� good.txt �ļ�!" << endl;
	}
	else
	{
		while (1)
		{
			cout << "�������ѯ��Ʒ�Ļ�Ʒ���,��[~]�˳�:";
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
			cout << "������������������!" << endl;
		}
	flag5:
		cout << "������������Ŀ:";
		int outboundNumber;
		cin >> outboundNumber;
		int outNumTemp = findGood.outNum;
		int finalNumTemp = findGood.finalNum;
		findGood.outNum += outboundNumber;
		findGood.finalNum -= outboundNumber;
		if (findGood.outNum < 0 || findGood.finalNum < 0 || outboundNumber < 0) {
			cout << "�������Ŀ��������������!" << endl;
			findGood.outNum = outNumTemp;
			findGood.finalNum = finalNumTemp;
			goto flag5;
		}

		//���ļ�������ȫ��ȡ�����޸Ķ�Ӧ���������ݣ�����ļ����ݣ�������д���ļ�
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
	cout << "����ɹ�!" << endl;
	cout << "��ʾ:��ǰ�������ĿΪ:" << findGood.outNum << "����ǰ������ĿΪ:" << findGood.finalNum << endl;
	system("pause");
}

//�����Ʒ����
void addGood() 
{
	string addID;
	string addName;
	int addOriginalNum;
	int addOutNum;
	int addInNum;
	int addFinalNum;
	cout << "��������ƷID:";
	cin >> addID;
	cout << "��������Ʒ����:";
	cin >> addName;
	cout << "��������Ʒ���:";
	cin >> addOriginalNum;
	/*cout << "��������Ʒ������Ŀ:";
	cin >> addOutNum;
	cout << "��������Ʒ�����Ŀ:";
	cin >> addInNum;
	cout << "��������Ʒ������Ŀ:";
	cin >> addFinalNum;*/
	writeGood(addID, addName, addOriginalNum, 0, 0, addOriginalNum);
	cout << "\n" << endl;
	cout << "��Ʒ[" << addName << "]��ӳɹ�!" << endl;
	system("pause");
}

//ɾ����Ʒ����
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
		cout << "��ʾ:�Ҳ��� good.txt �ļ�!" << endl;
		cout << "��ʾ:����� good.txt �ļ�!" << endl;
	}
	else
	{
		while (1)
		{
			cout << "�������ѯ��Ʒ�Ļ�Ʒ���,��[~]�˳�:";
			cin >> inNumber;
			if (inNumber == "`")
				return;
			while (getline(rfile, temp))
			{
				findGood.readGood(temp);
				if (findGood.ID == inNumber)
				{
					int i;
					cout << "ȷ��Ҫɾ����,�� 1 ȷ��" << endl;
					cin >> i;
					if (i == 1)
					{
						goto flag6;
					}
					else
						break;
					
				}
			}
			cout << "������������������!" << endl;
		}
	flag6:
		//���ļ�������ȫ��ȡ����ɾ����Ӧ���������ݣ�����ļ����ݣ�������д���ļ�
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
		cout << "��Ʒɾ���ɹ�!" << endl;
	}
	
	system("pause");
}

//�ܹ���
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
			//��ѯ����
			query();
			break;
		case '2':
			//��⹦��
			d.library();
			break;
		case '3':
			//���⹦��
			d.outbound();
			break;
		case '4':
			//�����Ʒ����
			addGood();
			break;
		case '5':
			//ɾ����Ʒ����
			d.deleteGood();
			break;
		case '6':
			//�˳�
			return;
			break;
		default:
			cout << "��ʾ:������������������!" << endl;
			system("pause");
		}
	}
}

//������
void main()
{
	//���ÿ���̨���ں��������ɫ
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
			//ע�Ṧ��
			u.Register();
			break;
		case '2':
			//��¼����
			u.Enter();
			break;
		case '3':
			//�˳�
			return;
			break;
		default:
			cout << "��ʾ:������������������!" << endl;
			system("pause");
		}
	}
}

