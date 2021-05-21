#include "workManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
//using namespace std;

workManager::workManager() {
 
	//1. file is not exist
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open()) {
		cout << "file is not exist" << endl;

		//initial property
		this->employeeNumber = 0;

		this->employeeArray = NULL;

		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//2. file is exist, data is empty
	char ch;
	ifs >> ch;
	if (ifs.eof()) { 
		//file is empty
		cout << "file is empty" << endl;
		//initial property
		this->employeeNumber = 0;

		this->employeeArray = NULL;

		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//3. file is exist
	int num = this->getEmpNum();
	//cout << "the number of employee is " << num << endl;
	this->employeeNumber = num;
	//creat a new array
	this->employeeArray = new worker * [this->employeeNumber];

	this->initEmp();

	//for (int i = 0; i < this->employeeNumber; i++) {
	//	cout << "ID " << this->employeeArray[i]->workerId
	//		<< " name " << this->employeeArray[i]->workerName
	//		<< " depart id" << this->employeeArray[i]->workPostionID
	//		<< endl;
	//}
	
}

//
void workManager::showMenu() {
	cout << "****************************************************" << endl;
	cout << "**********  Welcome to use this system£¡   *********" << endl;
	cout << "**********  0.exit                     *************" << endl;
	cout << "**********  1.add employee information  ************" << endl;
	cout << "**********  2.show employee information  ***********" << endl;
	cout << "**********  3.delete dismission  information  ******" << endl;
	cout << "**********  4.modify employee information  *********" << endl;
	cout << "**********  5.search employee information  *********" << endl;
	cout << "**********  6.order by index           *************" << endl;
	cout << "**********  7.clear all fiels          *************" << endl;
	cout << "****************************************************" << endl;
	cout << endl;

}
//exit system
void workManager::exitSystem() {

	cout << "See you next time." << endl;
	system("pause");
	exit(0);
}

//add employee
void workManager::addEmp() {
	cout << "Please enter the number of new employee" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0) {

		//add
		//calculate the space of new adding
		// new space = the old space + new space
		int newSize = this->employeeNumber + addNum;

		//creat new space
		worker** newSpace = new worker * [newSize];

		//copy the old data to new space
		if (this->employeeArray !=NULL) {
			for (int i = 0; i < this->employeeNumber; i++) {
				newSpace[i] = this->employeeArray[i];
			}
		}
		//add new data
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int depSelect;

			cout << "Please enter No."<<i+1<<"employee's index" << endl;
			cin >> id;

			cout << "Please enter No." << i + 1 << "employee's name" << endl;
			cin >> name;

			cout << "Please choose the postion of the employee" << endl;
			cout << "1. normal employee" << endl;
			cout << "2. manager" << endl;
			cout << "3. president" << endl;
			cin >> depSelect;

			worker* worker = NULL;
			switch (depSelect) {
			case 1:
				worker = new employee(id, name, 1);
				break;
			case 2:
				worker = new manager(id, name, 2);
				break;
			case 3:
				worker = new boss(id, name, 3);
				break;
			default:
				break;
			}

			//save the employee pointer to array
			newSpace[this->employeeNumber + i] = worker;
		}
		//relief original space
		delete[] this->employeeArray;

		//modify new space's direction
		this->employeeArray = newSpace;

		//fresh the number of employee
		this->employeeNumber = newSize;

		//fresh file is not empty
		this->fileIsEmpty = false;

		//tip successful
		cout << "added " << addNum <<" employee successful"<< endl;

		//save data to file 
		this->save();

	}
	else
	{
		cout << "the number is error" << endl;
	}

	//
	system("pause");
	system("cls");

}

//save file
void workManager::save() {

	ofstream ofs;
	//open file with open out way
	ofs.open(FILENAME, ios::out);

	for (int i=0 ; i < this->employeeNumber; i++) {
		ofs << this->employeeArray[i]->workerId << " "
			<< this->employeeArray[i]->workerName << " "
			<< this->employeeArray[i]->workPostionID << endl;

	}
	//close file
	ofs.close();
}

//statistic employee number
int workManager::getEmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++;

	}
	return num;
}

//initial employee
void workManager::initEmp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		worker* worker = NULL;

		if (dId == 1) {
			worker = new employee(id, name, dId);
		}
		else if (dId == 2) {
			worker = new manager(id, name, dId);
		}
		else if (dId == 3) {
			worker = new boss(id, name, dId);
		}
		this->employeeArray[index] = worker;
		index++;
	}
	//close file
	ifs.close();
}

//show employee
void workManager::showEmp() {

	if (this->fileIsEmpty) {
		cout << "file is not exist or is empty " << endl;
	}
	else
	{
		for (int i = 0; i < employeeNumber; i++) {

			this->employeeArray[i]->showInfo();

		}
	}
	system("pause");
	system("cls");
}

//delete employee
void workManager::deleteEmp() {
	if (this->fileIsEmpty) {
		cout << "file is not exist or data is empty" << endl;
	}
	else
	{
		cout << "please enter the number of employee that you want to delete" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);
		if (index != -1) {

			for (int i = index; i < this->employeeNumber -1; i++) {
				//data forward
				this->employeeArray[i] = this->employeeArray[i + 1];
			}
			//fresh the number of employee
			this->employeeNumber--;
			//data be freshed to file
			this->save();
			cout << "delete successful" << endl;
		}
		else
		{
			cout << "failed, employee is not exist" << endl;
		}
	}
	system("pause");
	system("cls");
}

//judge employee if exist, if true, return the postion in array, if not return -1
int workManager::isExist(int id) {
	int index = -1;

	for (int i = 0; i < this->employeeNumber; i++) {

		if (this->employeeArray[i]->workerId == id) {
			index = i;

			break;
		}
	}
	return index;
}

//modify employee
void workManager::modifyEmp() {
	if (this->fileIsEmpty) {
		cout << "file is not exist or empty" << endl;
	}
	else
	{
		cout << "please enter the number of employee" << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1) {
			delete this->employeeArray[ret];

			int newId = 0;
			string newName = "";
			int newDepId = 0;

			cout << "please enter the new index" << endl;
			cin >> newId;
			cout << "please enter the new name" << endl;
			cin >> newName;
			cout << "please enter the new postion" << endl;
			cout << "1. noamlal employee" << endl;
			cout << "2. manager" << endl;
			cout << "3. president" << endl;
			cin >> newDepId;

			worker* worker = NULL;
			switch (newDepId)
			{
			case 1:
				worker = new employee(newId, newName, newDepId);
				break;
			case 2:
				worker = new manager(newId, newName, newDepId);
				break;
			case 3:
				worker = new boss(newId, newName, newDepId);
				break;
			default:
				break;
			}

			this->employeeArray[ret] = worker;
			cout << "modify successful!" << endl;
			//save file
			this->save();
		}
		else
		{
			cout << "failed, no the employee" << endl;
		}
	}

	system("pause");
	system("cls");

}

//find employee
void workManager::findEmp() {
	if (this->fileIsEmpty) {
		cout << "file is not exist or empty" << endl;
	}
	else
	{
		cout << "Please choose the method of search" << endl;
		cout << "1. search by index" << endl;
		cout << "2. search by name" << endl;

		int select = 0;
		cin >> select;
		if (select == 1) {
			//search by index
			int id;
			cout << "enter the index" << endl;
			cin >> id;

			int ret = isExist(id);
			if (ret != -1) {
				//find employee
				cout << "search successfully" << endl;
				this->employeeArray[ret]->showInfo();

			}
			else
			{
				cout << "failed" << endl;
			}
		}
		else if (select == 2)
		{
			//search by name
			string name;
			cout << "enter a name that you want to search" << endl;
			cin >> name;

			//flag if search successful
			bool flag = false;
			for (int i = 0; i < this->employeeNumber; i++) {
				if (this->employeeArray[i]->workerName == name) {
					cout << "search successfully, index is " 
						<<this->employeeArray[i]->workerId
						<< endl;
					flag = true;
					this->employeeArray[i]->showInfo();
				}
			}
			if (flag == false) {
				cout << "failed, no the employee" << endl;
			}
		}
		else
		{
			cout << "error input" << endl;
		}
	}
	system("pause");
	system("cls");
}

//sort file by index
void workManager::sortEmp() {
	if (this->fileIsEmpty) {
		cout << "file is not exist or empty " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "choose the way to sort" << endl;
		cout << "1. increase by index" << endl;
		cout << "2. decrease by indext" << endl;
		
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->employeeNumber; i++) {
			int minOrMax = i;
			for (int j = i+1; j < this->employeeNumber; j++)
			{
				//increase
				if (select == 1) {
					if (this->employeeArray[minOrMax]->workerId > this->employeeArray[j]->workerId) {
						minOrMax = j;
					}
				}
				//decrease
				else
				{
					if (this->employeeArray[minOrMax]->workerId < this->employeeArray[j]->workerId) {
						minOrMax = j;
					}
				}
			}
			//judge if need to change data
			if (i != minOrMax) {
				worker* temp = this->employeeArray[i];
				this->employeeArray[i] = this->employeeArray[minOrMax];
				this->employeeArray[minOrMax] = temp;
			}
		}
		cout << "" << endl;
		this->save();
		this->showEmp();
	}

}

//clean file
void workManager::cleanFile() {
	cout << "are you sure to clean?" << endl;
	cout << "1. confirm" << endl;
	cout << "2. return" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->employeeArray != NULL) {
			for (int i = 0; i < this->employeeNumber; i++)
			{
				delete this->employeeArray[i];
				this->employeeArray[i] = NULL;
			}

			delete[] this->employeeArray;
			this->employeeArray = NULL;
			this->employeeNumber = 0;
			this->fileIsEmpty = true;
		}
		cout << "clean successfully " << endl;
	}
	system("pause");
	system("cls");
}

workManager::~workManager() {
	if (this->employeeArray != NULL) {
		for (int i = 0; i < this->employeeNumber; i++)
		{
			if (this->employeeArray[i] != NULL) {
				delete this->employeeArray[i];
			}
		}
		delete[] this->employeeArray;
		this->employeeArray = NULL;
	}
}
