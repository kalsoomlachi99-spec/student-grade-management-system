#include <iostream>
#include <string>
using namespace std;

// student grade calculation system using functions

float totalMarks(int n){  // total marks

    float marks;
    float total = 0;

    cout << "\nEnter subject(s) marks (between 0 and 100): " << endl ;

    for (int i = 1; i <= n; i++){
        cout << "Subject " << i << ":- ";
        cin >> marks;

        while (marks < 0 || marks > 100){
            cout << "Invalid marks. Please enter marks between 0 and 100: ";
            cin >> marks;
        }

        total += marks;
    }

    return total;
}

float percentage(float total, int n){ // percentage
    return (total / (n * 100)) * 100;
}

char grade(float percentage){ // grade
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
        case 'E' :
        return "Fail";
        default :
        return "Invalid grade";
    }
}

int main(){

    int n;
    cout << "How many students are there? ";
    cin >> n;

    for (int i = 1; i <= n; i++){
        cout << "\nRecord of " << i << " student:" << endl;
        string name;
        cout << "Enter " << i << " student name: ";
        cin >> name;
        
        int sub;
        cout << "Enter number of subjects: ";
        cin >> sub;
        while (sub <= 0){
            cout << "Invalid number of subjects. Please enter a number greater than 0: ";
            cin >> sub;
        }
        
        float total = totalMarks(sub);
        float percent = percentage(total , sub);
        char finalGrade = grade(percent);

        cout << "\nResult of " << name << ":" << endl;

        cout << "\nTotal Marks: " << total; // total marks
        cout << "\nPercentage: " << percent << "%"; // percentage
        cout << "\nGrade: " << finalGrade; // grade
        cout << "\nRemarks: " << remarks(finalGrade) << endl; // remarks

    }

    return 0;
}
