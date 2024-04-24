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

//user类
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

//good类
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

//当前用户nowUser
user nowUser;

//vector是一个封装了动态大小数组的顺序容器,用于存放所有商品的信息
vector<good> goods;



