#include "ViewAllClasses.h"
void ViewAllClasses()
{
    string* exclude = new string[100];
    string Class;
    int i = 0;
    cout << "All available courses: " << endl;
    do {
        Class = ViewAllTextFile(exclude,i);
        exclude[i] = ExcludeClass(Class);
        if (exclude[i] != "none")
        {
            cout << exclude[i] << endl;
            i++;
        }
    } while (Class != "noclass");

    
}

string ViewAllTextFile(string*& exclude, int i) // in D:\\project 
{
    string path("D:\\project\\");
    string ext(".txt");
    int j = 0;
    for (auto& p : fs::recursive_directory_iterator(path))
    {
        string Class = ExcludeClass(p.path().string());
        if (p.path().extension() == ext && Class != "none")
        {
            if (i == 0)
            {
                return p.path().string();
            }
            for (j = 0; j < i; ++j)
            {
                if (Class != exclude[j]) {}
                else { break; }
            }
        }
        if (j  >=i && i != 0 )
        {
            for (int k = 0; k < i; ++k)
            {
                if (Class != exclude[k]) {}
                else return "none";
            }
            return p.path().string();
        }
    }
   return "noclass";
}

string ExcludeClass(string path)
{
    size_t found = path.find_last_of("_");
    string temp = path;
    path= path.substr(found + 1); 
    if (temp == path)
    {
        return "none";
    }
    found = path.find_last_of(".");
    return path.substr(0, found);
}