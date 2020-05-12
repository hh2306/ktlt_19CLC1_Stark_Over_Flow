#include "Check_In.h"
void Check_In(string ID)
{
	int n, count = 0;
	int temp, start_hours, end_hours, start_minutes, end_minutes;
	ifstream fileR;
	ofstream fileW;
	string line,current_line_to_checkin, semester="HK2", Class="19APCS1", course="CS162";
	//cout << "Please enter semester ( Ex: HK2 ): ";
	//cin >> semester;
	//cout << "Please enter the class: ";
	//cin >> Class;
	//cout << "Please enter your course that you want to check in: ";
	//cin >> course;
	string oldname = "-Student.txt";
	string newname = "-Student-copied.txt";
	string dir = "D:\\project\\2019-2020-" + semester + '-' + Class + '-' + course;
	string cur = current_time();
	string str;
	cout << "The current time is: " << cur;
	Time current;
	//cout << cur.length() << endl;
	string* date = split_stringwithspace(cur);
	string* current_clock = split_stringwith2dots(date[3]);
	current = cur_time_format(date, current_clock);
	cout << current.dd << "/" << current.mm << "/" << current.yy << endl;
	cout << current.hhs << ":" << current.mms << endl;
	fileR.open(dir + oldname);
	if (fileR.fail())
	{
		cout << "Unable to open " << dir + oldname << endl;
		return;
	}
	fileR >> n;
	fileR.seekg(2, ios::cur);
	fileW.open(dir + newname);
	if (fileW.fail())
	{
		fileR.close();
		cout << "Unable to open file!!!\n";
		return;
	}
	fileW << n << endl;
loop1:
	{
		while (!fileR.eof())
		{
			while (fileR.peek() != '\n') //move the pointer backward
			{
				fileR.seekg(-1, ios::cur);
			}
			fileR.seekg(2, ios::cur);
			getline(fileR, line);
			if (line == ID)
			{
				fileW << line << endl;		// id user
				getline(fileR, line);
				fileW << line << endl;		//password
				getline(fileR, line);
				fileW << line << endl;		// name	
				getline(fileR, line);
				fileW << line << endl;		//date of birth
				getline(fileR, line);
				fileW << line << endl;		//Class
				getline(fileR, line);
				fileW << line << endl;		// midterm score
				getline(fileR, line);
				fileW << line << endl;		// final score
				getline(fileR, line);
				fileW << line << endl;		//extra score
				getline(fileR, line);
				fileW << line << endl;		//total score
			loop:
				{
					if (count == -1)
					{
						while (fileR.peek() != '\n') //move the pointer backward
						{
							fileR.seekg(-1, ios::cur);
						}
						fileR.seekg(2, ios::cur);
						getline(fileR, line);
						fileW << line << endl;
					}
					fileR >> temp;				//year			
					if (current.yy != temp)
					{
						count = -1;
						goto loop;
					}
					else
					{
						fileR.seekg(1, ios::cur);
						fileR >> temp;				// month
					}
					if (current.mm != temp) {
						count = -1;
						goto loop;
					}
					else
					{
						fileR.seekg(1, ios::cur);
						fileR >> temp;		//days
					}
					if (current.dd != temp) {
						count = -1;
						goto loop;
					}
					else
					{
						fileR.seekg(1, ios::cur);
						fileR >> start_hours;		// start hour
						fileR.seekg(1, ios::cur);
						fileR >> start_minutes;					//minutes
					}
					if ((current.hhs == start_hours && current.mms >= start_minutes) || current.hhs > start_hours)
					{
						fileR.seekg(1, ios::cur);			// end hour
						fileR >> end_hours;
						fileR.seekg(1, ios::cur);			//minutes
						fileR >> end_minutes;
					}
					else {
						count = -1;
						goto loop1;
					}
					if ((current.hhs == end_hours && current.mms <= end_minutes) || current.hhs < end_hours)
					{
						count = 1;
					}
					else {
						count = -1;
						goto loop1;
					}
				}
				if (count == 1)
				{
					fileW << current.yy << " ";
					if (current.mm < 10)
					{
						fileW << "0" + to_string(current.mm) << " ";
					}
					else fileW << current.mm << " ";
					if (current.dd < 10)
					{
						fileW << "0" + to_string(current.dd) << " ";
					}
					else fileW << current.dd << " ";
					//fileW << current.yy << " " << current.mm << " " << current.dd << " ";
					fileW << start_hours << " " << start_minutes << " " << end_hours << " " << end_minutes << " " << 0 << endl;
				}
				getline(fileR, line);
				while (!fileR.eof())
				{
					getline(fileR, line);
					fileW << line << endl;
				}
			}
			else
			{
				fileW << line << endl;
				goto loop1;
			}
		}
	}
	fileR.close();
	fileW.close();
	fs::rename(dir + newname, dir + oldname);
	if (count == -1) cout << "You cannot check-in right now\n";
	if (count == 1) cout << "Checked-in successfully!!!\n";
	if (count == 0) cout << "Your ID user is not found in file\n";	
}

string current_time()
{
	auto now = chrono::system_clock::now();
	time_t current_time = chrono::system_clock::to_time_t(now);
	char curtime[35];
	ctime_s(curtime, sizeof curtime, &current_time);
	string str(curtime);
	return str;
}
string* split_stringwithspace(string str)
{
	size_t pos = 0;
	string *result = new string [5];
	string token = " ";
	int i = 0;
	while ((pos = str.find(token)) != string::npos)
	{
		result[i] = str.substr(0, str.find(token));
		++i;
		str.erase(0, pos + token.length());
	}
	result[4] = str;
	return result;
}

string* split_stringwith2dots(string str)
{
	size_t pos = 0;
	string* result = new string[2];
	string token = ":";
	int i = 0;
	while ((pos = str.find(token)) != string::npos)
	{
		result[i] = str.substr(0, str.find(token));
		++i;
		str.erase(0, pos + token.length());
	}
	return result;
}
Time cur_time_format(string* time,string *clock) {
	Time result;
	for (int i = 0; i <= 4; ++i)
	{
		switch (i)
		{
		case 0:
		{
			for (int j = 0; j <= 24; ++j)
			{
				//if (clock[i] == to_string(j)) result.hhs = j;
				if (j < 10)
				{
					if (clock[i] == ("0" + to_string(j)))
					{
						result.hhs = j;
						break;
					}
				}
				else
				{
					if (clock[i] == to_string(j))
					{
						result.hhs = j;
						break;
					}
				}
			}
			break;
		}
		case 1:
		{
			if (time[i] == "Jan") result.mm = 1;
			if (time[i] == "Feb") result.mm = 2;
			if (time[i] == "Mar") result.mm = 3;
			if (time[i] == "Apr") result.mm = 4;
			if (time[i] == "May") result.mm = 5;
			if (time[i] == "Jun") result.mm = 6;
			if (time[i] == "Jul") result.mm = 7;
			if (time[i] == "Aug") result.mm = 8;
			if (time[i] == "Sept") result.mm = 9;
			if (time[i] == "Oct") result.mm = 10;
			if (time[i] == "Nov") result.mm = 11;
			if (time[i] == "Dec") result.mm = 12;
			/////////////////
			
			for (int j = 0; j <= 60; ++j)
			{
				if (j < 10)
				{
					if (clock[i] == ("0" + to_string(j)))
					{
						result.mms = j;
						break;
					}
				}
				else
				{
					if (clock[i] == to_string(j))
					{
						result.mms = j;
						break;
					}
				}
			}
			break;
		}
		case 2:
		{
			for (int j = 1; j <= 31; ++j)
			{
				if (time[i] == to_string(j))
				{
					result.dd = j;
					break;
				}
			}
			break;
		}
		case 4:
		{
			result.yy = atoi(time[i].c_str());
			break;
		}
		}
	}
	return result;
}