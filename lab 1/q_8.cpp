#include<iostream>
using namespace std;
void data_visual(int arr[4][7]){
    for(int i=0;i<4;i++){
        cout<<"For City "<<i+1<<endl;
        for(int j=0;j<7;j++){
            int p=arr[i][j]/50;
            cout<<"day "<<j+1<<":";
            for(int k=0;k<p;k++){
                cout<<"*";
            }
            cout<<"("<<arr[i][j]<<")"<<endl;
        }
    }
}
int main(){
    int AQI[4][7]={
    {45, 50, 48, 152, 47, 49, 46}, // city 1
    {78, 80, 82, 185, 75, 81, 79}, // city 2
    {120, 155, 156, 110, 122, 119, 118}, // city 3
    {60, 165, 70, 75, 168, 72, 66}, // city 4
    };
    data_visual(AQI);
}