#pragma once
#include <iostream>
#include "worker.h"
using namespace std;

#include <fstream>
#define FILENAME "empFile.txt"



class workManager {
public:

	//constructor
	workManager();

	//show menu
	void showMenu();

	//exit system
	void exitSystem();

	//record employee number
	int employeeNumber;

	//employee array pointer
	worker** employeeArray;

	//add employee
	void addEmp();

	//save file
	void save();

	//judge file if is null
	bool fileIsEmpty;

	//statistic employee number
	int getEmpNum();

	//initial employee
	void initEmp();

	//show employee
	void showEmp();

	//delete employee
	void deleteEmp();

	//judge employee if exist, if true, return the postion in array, if not return -1
	int isExist(int id);

	//modify employee
	void modifyEmp();

	//find employee
	void findEmp();

	//sort file by index
	void sortEmp();

	//clean file
	void cleanFile();

	//deconstructor
	~workManager();
};