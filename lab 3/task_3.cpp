#include<iostream>
using namespace std;
class Library{
    private:
        string bookList[20];
        string borrowedBooks[20];
        string AvailableBooks[20];
        int i=0,j=0,k=0;
        public:
            void addbook(string b){
                bookList[i++]=b;
            }

            void lendBook(string s){
                bool found=false;
                for(int p=0;p<i;p++){
                    if(bookList[p]==s){
                        borrowedBooks[j++]=s;
                        found=true;
                        break;
                    }
                }
                if(!found){
                    cout<<"This book is not available\n";
                }
            }

            void Returnbook(string s){
                bool found=false;
                for(int p=0;p<j;p++){
                    if(borrowedBooks[p]==s){
                        found=true;
                        cout<<"book has been returned\n";

                        for(int q=p;q<j-1;q++){
                            borrowedBooks[q]=borrowedBooks[q+1];
                        }
                        j--;
                        break;
                    }
                }
                if(!found){
                    cout<<"This book was not borrowed\n";
                }
            }

            void availableBooks(){
                k=0;
                for(int p=0;p<i;p++){
                    bool found=false;
                    for(int b=0;b<j;b++){
                        if(bookList[p]==borrowedBooks[b]){
                            found=true;
                            break;
                        }
                    }
                    if(!found){
                        AvailableBooks[k++]=bookList[p];
                    }
                }
            }

            void displayBookList(){
                cout<<"The whole booklist:\n";
                for(int p=0;p<i;p++){
                    cout<<bookList[p]<<endl;
                }
            }

            void displayBorrowedBooks(){
                cout<<"The Borrowed Books:\n";
                for(int p=0;p<j;p++){
                    cout<<borrowedBooks[p]<<endl;
                }
            }

            void displayAvailableBooks(){
                availableBooks();
                cout<<"The Available Books:\n";
                for(int p=0;p<k;p++){
                    cout<<AvailableBooks[p]<<endl;
                }
            }    
};
int main(){
    Library l;
    l.addbook("Faust");
    l.addbook("Sorrow of the young wirter");
    l.addbook("The Cruel prince");
    l.lendBook("Faust");
    l.displayBookList();
    l.displayBorrowedBooks();
    l.availableBooks();
    l.Returnbook("Faust");
    l.displayAvailableBooks();
}