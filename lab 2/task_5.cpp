#include<iostream>
using namespace std;
void display(int *arr,int n){
    cout<<"Arrary elements:";
    for(int i=0;i<n;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}
void sum(int *arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=*(arr+i);
    }
    cout<<"Sum of Array:"<<sum<<endl;
}
int main(){
    int n;
    cout<<"Enter the number of element you want to input:";
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cout<<"arr["<<i+1<<"]:";
        cin>>*(arr+i);
    }
    display(arr,n);
    sum(arr,n);
    delete[] arr;
}