#pragma once
#include<iostream>
#include<string>
using namespace std;

class worker {
public:

	//show info
	virtual void showInfo() = 0;
	//get department name
	virtual string getDepName() = 0;

	//index
	int workerId;
	//name
	string workerName;

	//postion
	int workPostionID;

};