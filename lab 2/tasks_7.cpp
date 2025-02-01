#include<iostream>
using namespace std;
int** allocateArray(int rows, int cols) {
    int** arr=new int*[rows]; 
    for (int i=0; i<rows; i++) {
        arr[i]=new int[cols]; 
    }
    return arr;
}
void inputArray(int **arr1,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                cout<<"matrix1["<<i+1<<"]["<<j+1<<"]:";
                cin>>arr1[i][j];
        }
    }
}
void displayArray(int **arr,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void matrixMultiplication(int **arr1,int **arr2,int n1,int m1,int n2,int m2){
    cout<<"Multiplication of the matrix"<<endl;
    int sum=0;
    for(int i=0;i<n1;i++){
        for(int j=0;j<m2;j++){
           for(int k=0;k<m1;k++){
                sum+=arr1[i][k]*arr2[k][j];
           }  
           cout<<sum<<" ";
           sum=0;
        }
        cout<<endl;
    }
}
void deallocate(int **arr,int n){
    for(int i=0;i<n;i++){
        delete[] arr[i];
    }
    delete[] arr;
}

int main(){
    int rows1,col1;
    int rows2,col2;
    cout<<"Enter the rows of matrix1:";
    cin>>rows1;
    cout<<"Enter the column os matrix1";
    cin>>col1;
    cout<<"Enter the rows of matrix2:";
    cin>>rows2;
    cout<<"Enter the column os matrix2";
    cin>>col2;
    if(col1==rows2){
        int **arr1=allocateArray(rows1,col1);
        int **arr2=allocateArray(rows2,col2);
        cout<<"input matrix 1"<<endl;
        inputArray(arr1,rows1,col1);
        cout<<"input matrix 2"<<endl;
        inputArray(arr2,rows2,col2);
        cout<<"Matrix 1"<<endl;
        displayArray(arr1,rows1,col1);
        cout<<"Matrix 2"<<endl;
        displayArray(arr2,rows2,col2);
        matrixMultiplication(arr1,arr2,rows1,col1,rows2,col2);
        deallocate(arr1,rows1);
        deallocate(arr2,rows2);
    }else{
        cout<<"matrices can't be multiplied"<<endl;
    }
}