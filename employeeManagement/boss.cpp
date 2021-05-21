#include "boss.h"


//constructor
boss::boss(int id, string name, int dId) {
	this->workerId = id;
	this->workerName = name;
	this->workPostionID = dId;
}

//show info
void boss::showInfo() {
	cout << "index: " << this->workerId
		<< "\tname: " << this->workerName
		<< "\tpostion: " << this->getDepName()
		<< "\tresponsibalities: Manage all things of company"
		<< endl;

}
//get department name
string boss::getDepName() {
	return string("president");
}