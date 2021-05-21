#pragma once
#include <iostream>
#include "worker.h"

class boss :public worker {
public:

	//constructor
	boss(int id, string name, int dId);

	//show info
	virtual void showInfo();

	//get department name
	virtual string getDepName();
};