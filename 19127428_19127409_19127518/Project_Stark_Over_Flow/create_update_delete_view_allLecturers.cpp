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
	cout << " Exist\t\t\t( Enter exist )" << endl;
loop:
	{
		cout << endl;
		cout << "Enter a command: ";
		cin >> command;
		if (command == "create")
		{
			int n, skip; // skip use to skip number in NO.
			string Class;
			cout << "Enter class you want to import lecturers from csv file: ";
			cin >> Class;
			fileR.open("D:\\project\\" + Class + "-Schedule.csv");
			if (fileR.fail())
			{
				cout << "Unable to open file " <<endl;
				return;
			}
			fileR.seekg(-1, ios::end);
			if (fileR.peek() == '\n')
			{
				fileR.seekg(-1, ios::cur);
				int i = fileR.tellg();
				for (i; i > 0; --i)
				{
					if (fileR.peek() == '\n')
					{
						fileR.seekg(2, ios::cur);
						fileR >> n;
						break;
					}
					fileR.seekg(-1, ios::cur);
				}
			}
			mem.lec = new lecture[n];
			fileR.seekg(0, ios::beg);
			for (int i = 0; i < 1; ++i)
			{
				while (fileR.peek() != '\n') // skip the first line
				{
					fileR.seekg(1, ios::cur);
				}
				fileR.seekg(2, ios::cur);
			}
			for (int i = 0; i < n; ++i)
			{
				fileR >> skip;
				fileR.seekg(1, ios::cur);
				getline(fileR, line, ','); // Course ID
				getline(fileR, line, ','); // Course name
				getline(fileR, line, ','); // Class
				getline(fileR, mem.lec[i].user, ','); // username of Lecturer
				getline(fileR, mem.lec[i].name, ','); // Lecturer's name
				getline(fileR, mem.lec[i].academic_rank, ','); // degree
				if (mem.lec[i].academic_rank == "Thac Si")
				{
					mem.lec[i].user = "m." + mem.lec[i].user;
				}
				else if (mem.lec[i].academic_rank == "Tien Si")
				{
					mem.lec[i].user = "dr." + mem.lec[i].user;
				}
				else
				{
					mem.lec[i].user = "prof." + mem.lec[i].user;
				}
				getline(fileR, mem.lec[i].sex, ',');
				mem.lec[i].password = "abcdef";
				while (fileR.peek() != '\n')
				{
					fileR.seekg(1, ios::cur);
				}
				fileR.seekg(2, ios::cur);
			}
			for (int i = 0; i < n; ++i)
			{
				cout << mem.lec[i].user << endl;
				cout << mem.lec[i].name << endl;
				cout << mem.lec[i].academic_rank << endl;
				cout << mem.lec[i].sex << endl;
			}
			fileR.close();
			/*lecture NEW;
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
			cin >> NEW.sex;*/
			member old_lecturers;
			int j;
			int count=0;
			Read_lecture(old_lecturers.lec, old_lecturers.N_lecture);
			fileW.open(dir2);
			if (fileW.fail())
			{
				cout << "Unable to open Lecturers file\n";
				goto loop;
			}
			for (int i = 0; i < n; ++i)
			{
				for (j = 0; j < old_lecturers.N_lecture; ++j)
				{
					if (mem.lec[i].user == old_lecturers.lec[j].user)
					{
						count++;
					}
				}
			}
			fileW << old_lecturers.N_lecture + count << endl;
			fileW << endl;
			for (int i = 0; i < old_lecturers.N_lecture; ++i)	// Writing old lecturers to file
			{
				fileW << old_lecturers.lec[i].user << endl;
				fileW << old_lecturers.lec[i].password << endl;
				fileW << old_lecturers.lec[i].name << endl;
				fileW << old_lecturers.lec[i].academic_rank << endl;
				fileW << old_lecturers.lec[i].sex << endl;
				fileW << endl;
			}
			for (int i = 0; i < n; ++i)							// Check if not existed before, create that lecturers to file
			{
				for (j = 0; j < old_lecturers.N_lecture; ++j)
				{
					if (mem.lec[i].user == old_lecturers.lec[j].user)
					{
						i++;
					}
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
			delete[] old_lecturers.lec;
			cout << "Imported successfully!!!\n";
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
		if (command == "exist")
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