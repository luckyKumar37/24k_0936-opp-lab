#include<iostream>
using namespace std;

void average(int arr[4][4][7]){
    cout<<"Monthly AQI averge for each City"<<endl;
    for(int i=0;i<4;i++){
        int sum=0;
        cout<<"For City "<<i+1<<": ";
        for(int j=0;j<4;j++){
            for(int k=0;k<7;k++){
                sum+=arr[i][j][k];
            }
        }
        cout<<float(sum)/28<<endl;
    }
}

void most_improved_city(int arr[4][4][7]){
    int best=0;
    float max=0;
    for(int i=0;i<4;i++){
        float week_1=0;
        float week_4=0;
        for(int k=0;k<7;k++){
            week_1+=arr[i][0][k];
            week_4+=arr[i][3][k];
        }
        week_1/=7.0;
        week_4/=7.0;
        float difference=week_1-week_4;
        if(difference>max){
            max=difference;
            best=i+1;
        }
    }
    cout<<"Most improved city is City "<<best<<endl;
}
int main(){
        int AQI[4][4][7] = {
        { // City 1
            {45, 46, 48, 50, 52, 49, 47}, // Week 1
            {50, 51, 53, 52, 54, 55, 50}, // Week 2
            {48, 49, 47, 50, 51, 50, 48}, // Week 3
            {49, 50, 48, 47, 49, 51, 50}  // Week 4
        },
        { // City 2
            {78, 80, 79, 81, 82, 83, 80}, // Week 1
            {80, 81, 83, 85, 84, 82, 80}, // Week 2
            {82, 83, 84, 85, 81, 80, 82}, // Week 3
            {85, 84, 82, 83, 81, 80, 79}  // Week 4
        },
        { // City 3
            {120, 118, 115, 116, 117, 118, 119}, // Week 1
            {125, 123, 122, 121, 120, 119, 118}, // Week 2
            {115, 114, 113, 112, 111, 110, 115}, // Week 3
            {110, 112, 113, 114, 115, 116, 117}  // Week 4
        },
        { // City 4
            {60, 62, 64, 65, 66, 68, 67}, // Week 1
            {65, 66, 68, 70, 72, 71, 69}, // Week 2
            {70, 72, 74, 75, 73, 72, 71}, // Week 3
            {75, 74, 72, 71, 70, 69, 68}  // Week 4
        }
    };

    average(AQI);
    most_improved_city(AQI);
}