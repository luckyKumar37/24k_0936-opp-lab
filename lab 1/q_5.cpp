#include<iostream>
using namespace std;

void bar_chart(string Event1[],int n,string Event2[],int m){
    cout<<"Event1:";
    for(int i=0;i<n;i++){
        cout<<"* ";
    }
    cout<<endl;
    cout<<"Event2:";
    for(int i=0;i<m;i++){
        cout<<"* ";
    }
    cout<<endl;
}

int main(){
    string Event1[5];
    string Event2[5];
    char chioce1;
    int i=0;
    cout<<"Enter names for Event 1"<<endl;
    while(i<5){
        cout<<"Do you want to enter a name:(y/n):";
        cin>>chioce1;
        if(chioce1=='y'){
            cout<<"Enter name "<<i+1<<":";
            cin>>Event1[i];
            i++;
        }else if(chioce1=='n'){
            break;
        }else{
            cout<<"Enter the right chioce"<<endl;
        }
    }
    char chioce2;
    int j=0;
    cout<<"Enter names for Event 2"<<endl;
    while(j<5){
        cout<<"Do you want to enter a name:(y/n):";
        cin>>chioce2;
        if(chioce2=='y'){
            cout<<"Enter name "<<j+1<<":";
            cin>>Event2[j];
            j++;
        }else if(chioce2=='n'){
            break;
        }else{
            cout<<"Enter the right chioce"<<endl;
        }
    }
    bar_chart(Event1,i,Event2,j);
    return 0;
}