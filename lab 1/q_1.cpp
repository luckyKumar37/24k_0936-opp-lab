#include<iostream>
using namespace std;
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

    cout<<"Participant for event one"<<endl;
    for(int k=0;k<=i;k++){
        cout<<Event1[k]<<endl;
    }
    cout<<"Participant for event two"<<endl;
    for(int k=0;k<=j;k++){
        cout<<Event2[k]<<endl;
    }
    return 0;
}
