#include "export_scoreboard.h"
void export_scoreboard()
{
	int n;
	int no;  // order number
	ifstream fileR;
	//ifstream fileCSV;
	ofstream fileW;
	string line;
	//string lineCSV;
	string Class;
	string course;
	string name = "Student.txt";
	cout << "Please enter the class: ";
	cin >> Class;
	cout << "Please enter name of the course: ";
	cin >> course;
	string dir = "D:\\project\\2019-2020-HK2-";
	dir += Class + "-" + course + "-";
	string dirScoreboard ="D:\\project\\"+ Class + "-" + course + "-Scoreboard.csv";
	//string dirScoreboard2 = "D:\\project\\" + Class + "-" + course + "-Scoreboard-copied.csv";
	fileR.open(dir + name);
	if (fileR.fail())
	{
		cout << "Unable to open Student file\n";
		return;
	}
	fileR >> n;								//skip the first line
	fileR.seekg(2, ios::cur);
	fileW.open(dirScoreboard);
	if (fileW.fail())
	{
		cout << "Unable to export scoreboard csv file\n";
		fileR.close();
		return;
	}
	fileW << "No,Student ID,Fullname,Midterm,Final,Bonus,Total\n"; // first line
	for (int i = 1; i <= n; ++i)
	{
		fileW << i << ",";  // No
	loop:
		{
			getline(fileR, line); //Student ID
			if (line != "")
			{
				fileW << line << ",";
				getline(fileR, line);	//Password
				getline(fileR, line);	// Name
				fileW << line << ",";
				getline(fileR, line);	// date of birth
				getline(fileR, line);	// class
				getline(fileR, line);	//	midterm score
				fileW << line << ",";
				getline(fileR, line);	// final score
				fileW << line << ",";
				getline(fileR, line);	// bonus score
				fileW << line << ",";
				getline(fileR, line);	// total score
				fileW << line << endl;
				for (int j = 0; j < 10; ++j)
				{
					getline(fileR, line);
				}
			}
			else goto loop;
		}
	}
	fileW.close();
	fileR.close();
	cout << "Export score to scoreboard csv successfully!!!\n";
	cout << "The file is " << Class + "-" + course + "-Scoreboard.csv" << endl;
	/*fileCSV.open(dirScoreboard);
	if (fileCSV.fail())
	{
		cout << "Unable to open " << Class + "-" + course + "-Scoreboard.csv" << endl;
		return;
	}	
	fileCSV.seekg(-1, ios::end);
	if (fileCSV.peek() == '\n')
	{
		fileCSV.seekg(-1, ios::cur);
		int i = fileCSV.tellg();
		for (i; i > 0; --i)
		{
			if (fileCSV.peek() == '\n')
			{
				fileCSV.seekg(2, ios::cur);
				fileCSV >> n;
				break;
			}
			fileCSV.seekg(-1, ios::cur);
		}
	}
	list_attendance* student_score = new list_attendance[n];
	fileCSV.seekg(0, ios::beg);
	for (int i = 0; i < 1; ++i)
	{
		while (fileCSV.peek() != '\n') // skip the first line
		{
			fileCSV.seekg(1, ios::cur);
		}
		fileCSV.seekg(2, ios::cur);
	}
	for (int i=0;i<n;++i)
	{
		fileCSV >> no;		// a temp skip number oder NO.
		fileCSV.seekg(1, ios::cur);
		getline(fileCSV, student_score[i].user, ',');
		//cin.ignore();
		getline(fileCSV, student_score[i].name,',');
		//fileCSV.seekg(1, ios::cur);
		fileCSV >> student_score[i].midterm_p;
		fileCSV.seekg(1, ios::cur);
		fileCSV >> student_score[i].final_p;
		fileCSV.seekg(1, ios::cur);
		fileCSV >> student_score[i].extra_p;
		fileCSV.seekg(1, ios::cur);
		fileCSV >> student_score[i].total_p;
		fileCSV.seekg(2, ios::cur);
	}
	fileCSV.close();
	fileR.open(dir + oldname);
	fileR >> n;						// skip the first line
	fileR.seekg(2, ios::cur);

	fileW.open(dir + newname);
	fileW << n << endl;
	int i = 0;
	while (!fileR.eof())
	{
		getline(fileR, line);
		if (line == student_score[i].user)
		{
			fileW << line << endl;		//user id
			getline(fileR, line);		//password
			fileW << line << endl;
			getline(fileR, line);		//name
			fileW << line << endl;
			getline(fileR, line); // date of birth
			fileW << line << endl;
			getline(fileR, line); // Class
			fileW << line << endl;
			fileW << student_score[i].midterm_p << endl;
			fileW << student_score[i].final_p << endl;
			fileW << student_score[i].extra_p << endl;
			fileW << student_score[i].total_p << endl;
			for (int j = 0; j < 4; ++j)			// skip 4 lines
			{
				while (fileR.peek() != '\n')
				{
					fileR.seekg(1, ios::cur);
				}
				fileR.seekg(2, ios::cur);
			}
			for (int j = 0; j < 10; ++j)
			{
				getline(fileR, line);
				fileW << line << endl;
			}
			fileW << endl;
		}
		else fileW << line << endl;
	}
	fileW.close();
	fileR.close();
	fs::rename(dir + newname, dir + oldname);
	cout << "Import Scoreboard successfully!!!\n";*/
}