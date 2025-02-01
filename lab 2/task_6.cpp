#include<iostream>
using namespace std;
struct Student
{
    string name;
    int rollNo;
    float marks[3];
};
void averageMarks(Student s1){
    float sum=0;
    for(int j=0;j<3;j++){
        sum+=s1.marks[j];
    }
    cout<<"Average marks:"<<sum/3.0<<endl;
}

void input(Student *s1,int n){
    for(int i=0;i<n;i++){
        cout<<"For student "<<i+1<<endl;
        cout<<"Enter name:";
        cin.ignore();
        getline(cin,s1[i].name);
        cout<<"Enter rollno:";
        cin>>s1[i].rollNo;
        for(int j=0;j<3;j++){
            cout<<"Enter marks for subject "<<j+1<<":";
            cin>>s1[i].marks[j];
        }
    }
}
void display(Student *s1,int n){
    for(int i=0;i<n;i++){
        cout<<"Student "<<i+1<<endl;
        cout<<"Name:"<<s1[i].name<<endl;
        cout<<"Rollno:"<<s1[i].rollNo<<endl;
        for(int j=0;j<3;j++){
            cout<<"Marks of subject "<<j+1<<":"<<s1[i].marks[j]<<endl;
        }
        averageMarks(s1[i]);
    }
}
int main(){
    int n;
    cout<<"Enter the number of student:";
    cin>>n;
    Student *students=new Student[n];
    input(students,n);
    display(students,n);
    delete[] students;
}