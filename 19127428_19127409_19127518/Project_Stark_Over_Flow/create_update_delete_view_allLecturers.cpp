#include "create_update_delete_view_allLecturers.h"
void create_update_delete_view_allLecturers()
{
	string command;
	string line;
	ifstream fileR;
	ofstream fileW;
	member mem;  // mem.lecture //
	//int n_lecturers; //the first line in txt file
	string dir = "D:\\project\\Lecture.txt";
	string dir2 = "D:\\project\\Lecture-copied.txt";
	cout << " Create Lecturer\t( Enter create )" << endl;
	cout << " Update Lecturer\t( Enter update )" << endl;
	cout << " Delete Lecturer\t( Enter delete )" << endl;
	cout << " View all Lecturers\t( Enter view )" << endl;
	cout << " Exit\t\t\t( Enter exist )" << endl;
loop:
	{
		cout << endl;
		cout << "Enter a command: ";
		cin >> command;
		if (command == "create")
		{
			lecture NEW;
			cout << "Enter new lecturer's user ID: ";
			cin >> NEW.user;
			cout << "Enter new lecturer's password: ";
			cin >> NEW.password;
			cin.ignore();
			cout << "Enter new lecturer's name: ";
			getline(cin, NEW.name);
			cout << "Enter new lecturer's rank (Thac Si or Tien Si): ";
			getline(cin, NEW.academic_rank);
			string temp = NEW.academic_rank;
			transform(temp.begin(), temp.end(),temp.begin(), ::tolower); // convert all lower case to compare easier
			temp == "thac si" ? NEW.user = "m." + NEW.user : NEW.user = "dr." + NEW.user; // add m. or dr. to user name
			cout << "Your user name is now: " << NEW.user << " based on your rank" << endl;
			cout << "Enter new lecturer's sex: ";
			cin >> NEW.sex;
			// Copy the old lecturers infomation
			int n;
			fileR.open(dir);
			if (fileR.fail()) return;
			fileR >> n;
			fileR.seekg(2, ios::cur);
			fileW.open(dir2);
			if (fileW.fail())
			{
				fileR.close();
				return;
			}
			fileW << n + 1 << endl;
			while (!fileR.eof())
			{
				getline(fileR, line);
				fileW << line << endl;
			}
			/*Read_lecture(mem.lec, mem.N_lecture);		//No Need For This Approach // Slow 
			fileW << mem.N_lecture + 1 << endl;
			for (int i = 0; i < mem.N_lecture; ++i)
			{
				fileW << mem.lec[i].user << endl;
				fileW << mem.lec[i].password << endl;
				fileW << mem.lec[i].name << endl;
				fileW << mem.lec[i].academic_rank << endl;
				fileW << mem.lec[i].sex << endl;
				fileW << endl;
			}*/
			// Adding new lecturers to file
			fileW << NEW.user << endl;
			fileW << NEW.password << endl;
			fileW << NEW.name << endl;
			fileW << NEW.academic_rank << endl;
			fileW << NEW.sex << endl;
			fileR.close();
			fileW.close();
			fs::rename(dir2, dir);
			//delete[] mem.lec;
			cout << "Create successfully!!!\n";
			goto loop;
		}
		if (command == "update")
		{
			// Read Lecturers txt file to memory
			int i;
			Read_lecture(mem.lec, mem.N_lecture);
			cout << "Enter which the user ID of whose Lecturer you want to update: ";
			cin >> line;
			for (i = 0; i < mem.N_lecture; ++i)
			{
				if (line == mem.lec[i].user)
				{
					break; //got the i location of that lecturer we want to edit
				}
			}
			if (i >= mem.N_lecture)
			{
				cout << "Lecturer's user ID not found\n";
				goto loop;
			}
			// Update the infomation
			cout << "To update user ID   ( Enter user )\n";
			cout << "To update password   ( Enter password )\n";
			cout << "To update name   ( Enter name )\n";
			cout << "To update academic rank   ( Enter rank )\n";
			cout << "Exit   ( Enter exist )\n";
		loop2:
			{
				cout << "Which infomation you want to update: ";
				cin >> command;
				if (command == "user")
				{
					cout << "Enter your new user ID: ";
					cin >> mem.lec[i].user;
					goto loop2;
				}
				if (command == "password")
				{
					cout << "Enter your new password: ";
					cin >> mem.lec[i].password;
					goto loop2;
				}
				if (command == "name")
				{
					cin.ignore();
					cout << "Enter your new name: ";
					getline(cin, mem.lec[i].name);
					goto loop2;
				}
				if (command == "rank")
				{
					cin.ignore();
					cout << "Enter your new rank: ";
					getline(cin, mem.lec[i].academic_rank);
					goto loop2;
				}
				if (command == "exist")
				{
					// Updating new infomation to file
					fileW.open(dir2);
					if (fileW.fail())
					{
						cout << "Unable to open Lecturers file to update new infomation\n";
						return;
					}
					fileW << mem.N_lecture << endl;
					for (i = 0; i < mem.N_lecture; ++i)
					{
						fileW << mem.lec[i].user << endl;
						fileW << mem.lec[i].password << endl;
						fileW << mem.lec[i].name << endl;
						fileW << mem.lec[i].academic_rank << endl;
						fileW << mem.lec[i].sex << endl;
						fileW << endl;
					}
					fileW.close();
					fs::rename(dir2, dir);
					delete[] mem.lec;
					cout << "Update successfully!!!\n";
					goto loop;
				}
				else
				{
					cout << "Please enter approriate command\n";
					goto loop2;
				}
			}
		}
		if (command == "delete")
		{
			// Read Lecturers txt file to memory
			
			int i;
			Read_lecture(mem.lec, mem.N_lecture);
			cout << "Enter which the user ID of whose Lecturer you want to delete: ";
			cin >> line;
			for (i = 0; i < mem.N_lecture; ++i)
			{
				if (line == mem.lec[i].user)
				{
					break; //got the i location of that lecturer we want to delete
				}
			}
			if (i >= mem.N_lecture)
			{
				cout << "Lecturers' user ID not found!!!\n";
				goto loop;
			}
			//Remove the entered lecturer's user ID
			fileW.open(dir2);
			if (fileW.fail())
			{
				cout << "Unable to open Lecturers file to update new infomation\n";
				return;
			}
			fileW << mem.N_lecture - 1 << endl;
			for (int j = 0; j < mem.N_lecture; ++j)
			{	
				if (j == i)			//skip the lecturers that we want to delete base on the uppon location
				{
					continue;
				}
				fileW << mem.lec[i].user << endl;
				fileW << mem.lec[i].password << endl;
				fileW << mem.lec[i].name << endl;
				fileW << mem.lec[i].academic_rank << endl;
				fileW << mem.lec[i].sex << endl;
				fileW << endl;
			}
			fileW.close();
			fs::rename(dir2, dir);
			delete[] mem.lec;
			cout << "Delete successfully!!!" << endl;
			goto loop;
		}
		if (command == "view")
		{
			Read_lecture(mem.lec, mem.N_lecture);
			for (int i = 0; i < mem.N_lecture; ++i)
			{
				cout << mem.lec[i].name << endl;
			}
			delete[] mem.lec;
			goto loop;
		}
		if (command == "exit")
		{
			return;
		}
		else
		{
			cout << "Please enter approriate command\n";
			goto loop;
		}
	}
}