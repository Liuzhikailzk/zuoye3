#pragma once
#include <iostream>
#include<string>
#include <vector>
#include <conio.h>
#include <fstream>
#include <sstream>
#pragma warning(disable : 4996)
using namespace std;

void function();
void writeUser(string ID, string name, string pwd);
void writeGood(string ID, string name, int originalNum, int outNum, int inNum, int finalNum);
void query(); 

//user��
class user {
private:
	string ID;
	string Name;
	string Password;
public:
	user() {};
	void Register();
	void Enter();
	void queryUser();
	void readUser(string number);
};

//good��
class good {
private:
	string ID;
	string Name;
	int originalNum;
	int outNum;
	int inNum;
	int finalNum;
public:
	good() {};
	void queryGood();
	void library();
	void readGood(string number);
	void outbound();
	void deleteGood();
};

//��ǰ�û�nowUser
user nowUser;

//vector��һ����װ�˶�̬��С�����˳������,���ڴ��������Ʒ����Ϣ
vector<good> goods;



