#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// student grade calculation system using functions

struct Student{
    string name;
    int subjects;
    float total;
    float percent;
    char grade;
    string remark;
};

int getPositiveInt(const string& prompt){
    int value;

    cout << prompt;
    while (!(cin >> value) || value <= 0){
        cout << "Invalid input. Please enter a number greater than 0: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

float getMarks(int subjectNumber){
    float marks;

    cout << "Subject " << subjectNumber << ": ";
    while (!(cin >> marks) || marks < 0 || marks > 100){
        cout << "Invalid marks. Please enter marks between 0 and 100: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return marks;
}

float totalMarks(int n){  // total marks
    float total = 0;

    cout << "\nEnter subject marks (between 0 and 100): " << endl;

    for (int i = 1; i <= n; i++){
        total += getMarks(i);
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return total;
}

float percentage(float total, int n){ // percentage
    return total / n ;
}

char calculateGrade(float percentage){ // grade
    if (percentage >= 80)
        return 'A';
    else if (percentage >= 70)
        return 'B';
    else if (percentage >= 60)
        return 'C';
    else if (percentage >= 50)
        return 'D';
    else
        return 'F';
}

string remarks(char grade){  // remarks
    switch (grade){
        case 'A' : 
            return "Outstanding";
        case 'B' :
            return "Great";
        case 'C' :
            return "Good";
        case 'D' :
            return "Fair";
        case 'F' :
            return "Fail";
        default :
            return "Invalid grade";
    }
}

bool compareByPercentage(const Student& a, const Student& b){
    return a.percent > b.percent;
}

int main(){

    vector<Student> students;

    cout << fixed << setprecision(2);

    int n = getPositiveInt("How many students are there? ");

    for (int i = 1; i <= n; i++){
        cout << "\nRecord of student " << i << ":" << endl;

        string name;
        cout << "Enter student name: ";
        getline(cin, name);
        
        int sub = getPositiveInt("Enter number of subjects: ");
        float total = totalMarks(sub);
        float percent = percentage(total , sub);
        char finalGrade = calculateGrade(percent);

        cout << "\nResult of " << name << ":" << endl;
        cout << "\n Subjects: " << sub; // number of subjects   
        cout << "\nTotal Marks: " << total; // total marks
        cout << "\nPercentage: " << percent << "%"; // percentage
        cout << "\nGrade: " << finalGrade; // grade
        cout << "\nRemarks: " << remarks(finalGrade) << endl; // remarks

        Student s = {name, sub, total, percent, finalGrade, remarks(finalGrade)};
        students.emplace_back(s);

    }
    sort(students.begin(), students.end(), compareByPercentage);
    cout << "\n\n===== TOP POSITION HOLDERS =====\n";
    
    int top = min(3, (int)students.size());
    
    for (int i = 0; i < top; i++){
        cout << "\nPosition " << i + 1
        << ": " << students[i].name
        << " (" << students[i].percent << "%)";
    }
    cout << endl;
    
    cout << "\n\n===== ALL STUDENTS =====\n";
    
    for (const Student& s : students){
        cout << "\n------------------------";
        cout << "\nName: " << s.name;
        cout << "\nSubjects: " << s.subjects;
        cout << "\nTotal: " << s.total;
        cout << "\nPercentage: " << s.percent << "%";
        cout << "\nGrade: " << s.grade;
        cout << "\nRemark: " << s.remark << "\n";
    }

    return 0;
}
