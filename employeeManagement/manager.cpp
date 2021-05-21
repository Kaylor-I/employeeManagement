#include "manager.h"

//constructor
manager::manager(int id, string name, int dId) {
	this->workerId = id;
	this->workerName = name;
	this->workPostionID = dId;

}

//show info
void manager::showInfo() {
	cout << "index: " << this->workerId
		<< "\tname: " << this->workerName
		<< "\tpostion: " << this->getDepName()
		<< "\tresponsibalities: Complete the tasks assigned by the boss"
		<< endl;

}
//get department name
string manager::getDepName() {
	return string("manager");

}
