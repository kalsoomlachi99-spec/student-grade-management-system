#include<iostream>
using namespace std;

int main(){

    /*Student Grade Calculator*/

    float maths , computer , physics , chemistry , english;
    cout<<"Enter marks of Maths : ";
    cin>>maths;
    if (maths < 0 || maths > 100){
        cout<<"Invalid input for Maths marks. Please enter a value between 0 and 100."<<endl;
        return 1; // Exit the program with an error code
    }
    cout<<"Enter marks of Computer : ";
    cin>>computer; 
    if (computer < 0 || computer > 100){
        cout<<"Invalid input for Computer marks. Please enter a value between 0 and 100."<<endl;
        return 1; // Exit the program with an error code
    }
    cout<<"Enter marks of Physics : ";
    cin>>physics;
    if (physics < 0 || physics > 100){
        cout<<"Invalid input for Physics marks. Please enter a value between 0 and 100."<<endl;
        return 1; // Exit the program with an error code
    }
    cout<<"Enter marks of Chemistry : ";
    cin>>chemistry;
    if (chemistry < 0 || chemistry > 100){
        cout<<"Invalid input for Chemistry marks. Please enter a value between 0 and 100."<<endl;
        return 1; // Exit the program with an error code
    }
    cout<<"Enter marks of English : ";
    cin>>english;
    if (english < 0 || english > 100){
        cout<<"Invalid input for English marks. Please enter a value between 0 and 100."<<endl;
        return 1; // Exit the program with an error code
    }

    float total = maths + computer + physics + chemistry + english;
    float percentage = (total/500)*100;   
    
    string grade;
    
    if(percentage >= 90){
        grade = "A+";
    } else if (percentage >= 80){
        grade = "A";
    } else if (percentage >= 70){
        grade = "B";
    } else if (percentage >= 60){
        grade = "C";
    } else if (percentage >= 50){
        grade = "D";
    } else {
        grade = "E";
    }   

    cout << "\nTotal Marks: " << total << "/ 500" << endl;
    cout << "Percentage: " << percentage << "%" << endl;    
    cout << "Grade: " << grade << endl;

    if (grade != "E") {
        cout << "Result : pass";
    } else {
        cout << "Result : fail";
    }
    

    return 0;
}