#include<iostream>
using namespace std;

void weekly_averages(int arr[4][4][7]){
    cout<<"Weekly AQI averge for each City"<<endl;
    for(int i=0;i<4;i++){
        cout<<"For City "<<i+1<<endl;
        for(int j=0;j<4;j++){
            cout<<"Week "<<j+1<<":";
            int sum=0;
            for(int k=0;k<7;k++){
                sum+=arr[i][j][k];
            }
            cout<<float(sum)/7<<endl;

        }
    }
}

void critical_pollution_days(int arr[4][4][7]){
    cout<<"Critical pollution days for each city"<<endl;
    for(int i=0;i<4;i++){
        cout<<"For City "<<i+1<<endl;
        for(int j=0;j<4;j++){
            for(int k=0;k<7;k++){
                if(arr[i][j][k]>150){
                    cout<<"week "<<j+1<<" day "<<k+1<<endl;
                }
            }
        }
    }
}

void max_and_min(int arr[4][4][7]){
    int min=arr[0][0][0];
    int max=arr[0][0][0];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<7;k++){
                if(arr[i][j][k]>max){
                    max=arr[i][j][k];
                }
                if(arr[i][j][k]<min){
                    min=arr[i][j][k];
                }
            }
        }
    }
    cout<<"Maximum recorded AQI in the throuthout the four cities is: "<<max<<endl;
    cout<<"Minimum recorded AQI in the throuthout the four cities is: "<<min<<endl;
}


int main(){
        int AQI[4][4][7] = {
        { // City 1
            {45, 46, 48, 50, 52, 49, 47}, // Week 1
            {50, 51, 53, 52, 54, 55, 154}, // Week 2
            {48, 49, 47, 50, 51, 150, 48}, // Week 3
            {49, 50, 48, 47, 149, 51, 50}  // Week 4
        },
        { // City 2
            {78, 80, 79, 81, 82, 83, 80}, // Week 1
            {80, 81, 183, 85, 84, 82, 80}, // Week 2
            {82, 83, 84, 85, 81, 80, 82}, // Week 3
            {85, 84, 82, 83, 181, 80, 79}  // Week 4
        },
        { // City 3
            {120, 118, 115, 116, 117, 118, 119}, // Week 1
            {125, 123, 122, 121, 120, 119, 118}, // Week 2
            {115, 114, 113, 112, 111, 110, 115}, // Week 3
            {110, 112, 113, 114, 115, 116, 117}  // Week 4
        },
        { // City 4
            {60, 62, 64, 65, 66, 68, 67}, // Week 1
            {65, 66, 68, 170, 72, 71, 69}, // Week 2
            {70, 72, 74, 75, 173, 72, 71}, // Week 3
            {75, 74, 72, 71, 70, 69, 68}  // Week 4
        }
    };

    cout<<"These are the summarize report of the data"<<endl;
    weekly_averages(AQI);
    critical_pollution_days(AQI);
    max_and_min(AQI);
}