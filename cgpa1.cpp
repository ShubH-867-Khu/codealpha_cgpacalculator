#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Subject
{
public:
    string subjectname;
    int credit;
    float gradepoint;

    // constructor;

    Subject(string name, int cr, float gp)
    {
        subjectname = name;
        credit = cr;
        gradepoint = gp;
    }
};

class Student
{
public:
    string name;
    vector<Subject> subjects;

    // constructor

    Student(string studentName)
    {
        name = studentName;
    }
    void addSubject(string subjectName, int credit, float gradepoint)
    {
        Subject newSubject(subjectName, credit, gradepoint);
        subjects.push_back(newSubject);
    }

    float calculatecgpa()
    {
        int totalcredit = 0;
        float weightgradepoint = 0;
        for (const Subject &  subject : subjects)
        {
            totalcredit += subject.credit;
            weightgradepoint += subject.credit * subject.gradepoint;
        }

        return (totalcredit>0)?(weightgradepoint/totalcredit):0;
    }
    void displaycgpa(){
        cout<<"student name"<< name <<endl;
        float cgpa = calculatecgpa();
        cout<<"CGPA"<<cgpa<<endl;
    }

    void addsubject(string subjectname,int credit,float  gradepoint);
};

int main()
{

    string studentname;
    int numsub;

    Student student(studentname);

    cout << "enter student  name";
    getline(cin, studentname);

    cout << "enter the number of subjects";
    cin >> numsub;

    for (int i = 0; i < numsub; i++)
    {
        string subjectname;
        int credit;
        float gradepoint;

        cout << "enter the subjects  name";

        cin.ignore();
        getline(cin, subjectname);

        cout << "enter the credit";
        cin >> credit;

        cout << "enter the gradepoint";
        cin >> gradepoint;
        student.addSubject(subjectname,credit,gradepoint);
    }
    student.displaycgpa();
    return 0;
}