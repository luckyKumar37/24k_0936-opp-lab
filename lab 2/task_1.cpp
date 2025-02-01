#include<iostream>
using namespace std;

struct Book
{
    string title;
    string author;
    int year;
};
void book_input(Book *books,int n){
    for(int i=0;i<n;i++){
        cout<<"Enter data for book "<<i+1<<endl;
        cout<<"Enter title:";
        cin.ignore();  // Ignore leftover newline from previous input
        getline(cin, books[i].title);
        cout<<"Enter author's name:";
        getline(cin, books[i].author);
        cout<<"Enter published year:";
        cin>>books[i].year;
    }
}
void display_books(Book *books,int n){
    for(int i=0;i<n;i++){
        cout<<"Data of book "<<i+1<<endl;
        cout<<"title:"<<books[i].title<<endl;
        cout<<"author:"<<books[i].author<<endl;
        cout<<"year:"<<books[i].year<<endl;
    }
}
void books_published_after_specific_year(Book *books,int n){
    int targetYear;
    cout<<"Enter the year:";
    cin>>targetYear;
    bool isFound=false;
    for(int i=0;i<n;i++){
        if(books[i].year>targetYear){
            cout<<"title:"<<books[i].title<<endl;
            cout<<"author:"<<books[i].author<<endl;
            cout<<"year:"<<books[i].year<<endl;
            isFound=true;
        }
    }
    if(!isFound){
        cout<<"No book was found in the data which was published after "<<targetYear<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the number of books you want:";
    cin>>n;
    Book *books=new Book[n];
    book_input(books,n);
    display_books(books,n);
    books_published_after_specific_year(books,n);
    delete[] books;
}
