#include "workManager.h"


#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main() {

	////test code
	//worker * worker = NULL;
	//worker = new employee(1, "Andy", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new manager(2, "Bob", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new boss(3, "Cndy", 3);
	//worker->showInfo();
	//delete worker;


	workManager wm;
	int choice;

	//
	while (true) {

		//call show menu
		wm.showMenu();

		cout << "Please enter your choice:" << endl;
		cin >> choice;

		switch (choice)
		{
			//exit
		case 0:
			wm.exitSystem();
			break;
			//add
		case 1:
			wm.addEmp();
			break;
			//show
		case 2:
			wm.showEmp();
			break;
			//delete
		case 3:
		/*{
			int ret = wm.isExist(10);
			if (ret != -1) {
				cout << "employee is exist" << endl;
			}
			else
			{
				cout << "employee is not exist" << endl;
			}
			break;
		}*/
			wm.deleteEmp();
			break;
			//modify
		case 4:
			wm.modifyEmp();
			break;
			//search
		case 5:
			wm.findEmp();
			break;
			//order
		case 6:
			wm.sortEmp();
			break;
			//clear
		case 7:
			wm.cleanFile();
			break;
		default:
			//clear the screen
			system("cls");

			break;
		}
	}


	system("pause");
	return 0;
}