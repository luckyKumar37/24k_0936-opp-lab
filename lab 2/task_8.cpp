#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of Array:";
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cout<<"Array["<<i+1<<"]:";
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"Array:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    delete[] arr;
}