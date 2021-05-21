#include "employee.h"


//constructor
employee::employee(int id, string name, int dId) {
	this->workerId = id;
	this->workerName = name;
	this->workPostionID = dId;
}

//show info
void employee::showInfo() {
	cout << "index: " <<this->workerId 
		<<"\tname: " <<this->workerName
		<<"\tpostion: " << this->getDepName()
		<<"\tresponsibalities: Complete the tasks assigned by the manager"
		<< endl;

}
//get department name
string employee::getDepName() {
	return string("employee");
}