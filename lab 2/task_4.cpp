#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void display(string *str,int n){
    for(int i=0;i<n;i++){
        cout<<str[i]<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter the number of string you want to input:";
    cin>>n;
    cin.ignore();
    string *str=new string[n];
    for(int i=0;i<n;i++){
        cout<<"Enter string "<<i+1<<":";
        getline(cin,str[i]);
    }
    cout<<"Unsorted string array"<<endl;
    display(str,n);
    sort(str,str+n);
    cout<<"Sorted string array"<<endl;
    display(str,n);
    delete[] str;
}