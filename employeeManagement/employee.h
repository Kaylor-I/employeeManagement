#pragma once
#include <iostream>
#include "worker.h"

class employee :public worker {
public:

	//constructor
	employee(int id, string name, int dId);

	//show info
	virtual void showInfo() ;
	//get department name
	virtual string getDepName();
};