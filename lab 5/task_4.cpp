#include<iostream>
using namespace std;

class AlarmSystem{
private:
    string securityLevel;

public:
    AlarmSystem(string level):securityLevel(level){}

    void setSecurityLevel(string level){
        securityLevel=level;
    }
    string getSecurityLevel() const{
        return securityLevel;
    }
};

class SmartHome{
private:
    int homeId;
    string address;
    AlarmSystem alarmSystem;

public:
    SmartHome(int id,string a,string level):
    homeId(id),address(a),alarmSystem(level){}

    void display() const{
        cout<<"Home ID:"<<homeId<<endl;
        cout<<"Address:"<<address<<endl;
        cout<<"Alarm System:\n";
        cout<<"Security Level:"<<alarmSystem.getSecurityLevel()<<endl;
    }


};
int main(){
    SmartHome s1(101,"7th street New hamsher","high");
    s1.display();

}
