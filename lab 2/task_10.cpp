#include<iostream>
using namespace std;
int main(){
    int x,y,z;
    cout<<"For matrix[x][y][z]"<<endl;
    cout<<"Enter x:";
    cin>>x;
    cout<<"Enter y:";
    cin>>y;
    cout<<"Enter z:";
    cin>>z;
    int ***arr=new int**[x];
    for(int i=0;i<x;i++){
        arr[i]=new int*[y];
        for(int j=0;j<y;j++){
            arr[i][j]=new int[z];
        }
    }
    cout<<"Enter Element:"<<endl;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                cout<<"Enter array["<<i+1<<"]["<<j+1<<"]["<<k+1<<"]:";
                cin>>arr[i][j][k];
            }
        }
    }
    cout<<"3D array Elements"<<endl;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                cout<<arr[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}