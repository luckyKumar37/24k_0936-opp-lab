#include<iostream>
using namespace std;

class Student{
private:
    int Id;
    string name;
    int* examScore;
    int size;

public:
    Student(int id,string name,int arr[],int size):
    Id(id),name(name),size(size){
        examScore=new int[size];
        for(int i=0;i<size;i++){
            examScore[i]=arr[i];
        }
    }

    Student(const Student& s){
        Id=s.Id;
        name=s.name;
        size=s.size;
        examScore=new int[size];
        for(int i=0;i<size;i++){
            examScore[i]=s.examScore[i];
        }
    }

    ~Student(){
        delete[] examScore;
    }

    void display() const{
        cout<<"Student Id:"<<Id<<endl;
        cout<<"Student Name:"<<name<<endl;
        cout<<"Exam Score:"<<endl;
        for(int i=0;i<size;i++){
            cout<<"Score "<<i+1<<":"<<examScore[i]<<endl;
        }
    }

};
int main(){
    int arr[]={87,82,91,85};
    Student s1(101,"Alex",arr,4);
    s1.display();

    Student s2(s1);
    s2.display();

    return 0;
}