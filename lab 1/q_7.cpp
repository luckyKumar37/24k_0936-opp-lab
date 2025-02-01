#include<iostream>
using namespace std;

void critical_pollution_days(int arr[4][7]){
    cout<<"Critical pollution days for cities throughtout the week"<<endl;
    for(int i=0;i<4;i++){
        cout<<"For City "<<i+1<<": ";
        for(int j=0;j<7;j++){
            if(arr[i][j]>150){
                cout<<"day "<<j+1<<" ";
            }
        }
        cout<<endl;
    }
}
int main(){
    int AQI[4][7]={
    {45, 50, 48, 152, 47, 49, 46}, // city 1
    {78, 80, 82, 185, 75, 81, 79}, // city 2
    {120, 155, 156, 110, 122, 119, 118}, // city 3
    {60, 165, 70, 75, 168, 72, 66}, // city 4
    };

    critical_pollution_days(AQI);
}