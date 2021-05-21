#pragma once
#include "worker.h"

class manager :public worker {
public:

	//constructor
	manager(int id, string name, int dId);

	//show info
	virtual void showInfo();
	//get department name
	virtual string getDepName();
};