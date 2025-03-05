#include<iostream>
using namespace std;

class Level{
private:
    string name;
    string difficulty;

public:
    Level(){}
    Level(string n,string d):name(n),difficulty(d){}

    void display() const{
        cout<<"Level name:"<<name<<endl;
        cout<<"Level Difficulty:"<<difficulty<<endl;
    }
};

class VideoGame{
private:
    string title;
    string genre;
    Level levels[10];
    int noOfLevel=0;

public:
    VideoGame(string title,string genre):
    title(title),genre(genre){}

    void addLevel(string n,string d){
        levels[noOfLevel++]=Level(n,d);
    }

    void display(){
        cout<<"Game title:"<<title<<endl;
        cout<<"Genre:"<<genre<<endl;
        cout<<"Game levels\n";
        for(int i=0;i<noOfLevel;i++){
            levels[i].display();
        }
    }
};
int main() {
    VideoGame game("Mystic Quest", "Adventure");
    game.addLevel("Forest of Beginnings", "Easy");
    game.addLevel("Cave of Shadows", "Medium");
    game.addLevel("Tower of Doom", "Hard");

    game.display();

    return 0;
}
