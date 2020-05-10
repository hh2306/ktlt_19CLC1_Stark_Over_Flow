#include "import_score.h"
void import_scoreboard()
{
	ifstream fileR, fileCSV;
	ofstream fileW;
	string line;
	string Class;
	string course;
	string oldname = "Student.txt";
	string newname = "Student-copied.txt";
	int no, n;
	cout << "Please enter the class: ";
	cin >> Class;
	cout << "Please enter name of the course: ";
	cin >> course;
	string dir = "D:\\project\\2019-2020-HK2-";
	dir += Class + "-" + course + "-";
	string dirScoreboard = "D:\\project\\" + Class + "-" + course + "-Scoreboard.csv";
	fileCSV.open(dirScoreboard);
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
	for (int i = 0; i < n; ++i)
	{
		fileCSV >> no;		// a temp skip number oder NO.
		fileCSV.seekg(1, ios::cur);
		getline(fileCSV, student_score[i].user, ',');
		//cin.ignore();
		getline(fileCSV, student_score[i].name, ',');
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
			i++;										//increase i after filling score
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
	delete[] student_score;
	fs::rename(dir + newname, dir + oldname);
	cout << "Import Scoreboard successfully!!!\n";
}