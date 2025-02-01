#include<iostream>
using namespace std;

void average(int arr[4][7]){
    cout<<"Averge AQI value for each city throughtout the week"<<endl;
    for(int i=0;i<4;i++){
        int sum=0;
        cout<<"City "<<i+1<<":";
        for(int j=0;j<7;j++){
            sum+=arr[i][j];
        }
        cout<<float(sum)/7<<endl;
    }
}

void city_with_worst_AQI(int arr[4][7]){
    int max_average=0;
    int worst_city=0;
    for(int i=0;i<4;i++){
        int sum=0;
        for(int j=0;j<7;j++){
            sum+=arr[i][j];
        }
        int average=float(sum)/7;
        if(average>max_average){
            max_average=average;
            worst_city=i+1;
        }
    }
    cout<<"City with Worst AQI is City "<<worst_city<<endl;
}
int main(){
    int AQI[4][7]={
    {45, 50, 48, 52, 47, 49, 46}, // city 1
    {78, 80, 82, 85, 75, 81, 79}, // city 2
    {120, 125, 115, 110, 122, 119, 118}, // city 3
    {60, 65, 70, 75, 68, 72, 66}, // city 4
    };

    average(AQI);
    city_with_worst_AQI(AQI);

}