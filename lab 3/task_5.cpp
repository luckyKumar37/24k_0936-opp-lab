#include<iostream>
using namespace std;
class Musicplayer{
    private:
        string Playlist[20];
        string currentlyPlayingSong;
        int p=0;

    public:
        void Addsong(string s){
            Playlist[p++]=s;
        }
        void Removesong(string s){
            bool found=false;
            for(int i=0;i<p;i++){
                if(Playlist[i]==s){
                    found=true;
                    for(int j=i;j<p;j++){
                        Playlist[i]=Playlist[i+1];
                    }
                    p--;
                    cout<<"The song "<<s<<" has been removed from the playlist\n";
                    break;
                }
            }
            if(!found){
                cout<<"The song "<<s<<" is present in the playlist\n";
            }
        }
        void playSong(string s){
            bool found=false;
            for(int i=0;i<p;i++){
                if(Playlist[i]==s){
                    found=true;
                    cout<<"Playing song "<<s<<endl;
                }
            }
            if(!found){
                cout<<"The song "<<s<<" is present in the playlist\n";
            }
        }

        void displayPlaylist(){
            cout<<"Song playlist\n";
            for(int i=0;i<p;i++){
                cout<<Playlist[i]<<endl;
            }
        }
};
int main(){
    Musicplayer m;
    m.Addsong("Tapastry");
    m.Addsong("Crossroads");
    m.Addsong("Winterwood");
    m.Addsong("The long and winding road");
    m.Addsong("Last thing on my mind");
    m.Addsong("Something");
    m.displayPlaylist();
    m.Removesong("Last thing on my mind");
    m.displayPlaylist();
    m.playSong("The long and winding road");

}