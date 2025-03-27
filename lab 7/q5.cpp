#include<iostream>
#include<string>
using namespace std;

class Character
{
protected:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;
public: 
    Character(int id, string n, int l, int hp, string wt)
    {
        characterID = id;
        name = n;
        level = l;
        healthPoints = hp;
        weaponType = wt;
    }

    virtual void attack()
    {
        cout << "Attacking with " << weaponType << endl;
    }

    virtual void Defend()
    {
        cout << "Defending with " << weaponType << endl;
    }

    virtual void display()
    {
        cout << "Character ID: " << characterID << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health Points: " << healthPoints << endl;
        cout << "Weapon Type: " << weaponType << endl;
    }
};

class Warrior: public Character
{
    int armorStrength;
    int maleeDamage;
public: 
    Warrior(int id, string n, int l, int hp, string wt, int armor, int damage): Character(id, n, l, hp, wt)
    {
        armorStrength = armor;
        maleeDamage = damage;
    }

    void attack() override
    {
        cout << "Attacking with " << weaponType << " and " << maleeDamage << " damage" << endl;
    }

    void display() override
    {
        Character::display();
        cout<< "Armor Strength: " << armorStrength << endl;
        cout<<"Malee Damage: " << maleeDamage << endl;
    }
    
};

class Mage: public Character
{
    int spellPower;
    int manaPoints;

public:
    Mage(int id, string n, int l, int hp, string wt, int sp, int mp): Character(id, n, l, hp, wt)
    {
        spellPower = sp;
        manaPoints = mp;
    }

    void Defend() override
    {
        cout<<"Defend with magical barriers"<<endl;
    }

    void display() override
    {
        Character::display();
        cout << "Spell Power: " << spellPower << endl;
        cout << "Mana Points: " << manaPoints << endl;
    }
};

class Archer: public Character
{
    int arrowCount;
    string rangedAccuracy;

public:
    Archer(int id, string n, int l, int hp, string wt, int ac, string ra): Character(id, n, l, hp, wt)
    {
        arrowCount = ac;
        rangedAccuracy = ra;
    }

    void attack() override
    {
        cout<<"Use Arrow for Long range attack"<<endl;
    }

    void display() override
    {
        Character::display();
        cout << "Arrow Count: " << arrowCount << endl;
        cout << "Ranged Accuracy: " << rangedAccuracy << endl;
    }

};

class Rogue: public Character
{
    int stealthLevel;
    int agility;

    public: 
    Rogue(int id, string n, int l, int hp, string wt, int sl, int ag): Character(id, n, l, hp, wt)
    {
        stealthLevel = sl;
        agility = ag;
    }

    void display() override
    {
        Character::display();
        cout << "Stealth Level: " << stealthLevel << endl;
        cout << "Agility: " << agility << endl;
    }
};

int main()
{
    Warrior w1(1, "Warrior", 10, 100, "Sword", 50, 20);
    Mage m1(2, "Mage", 10, 100, "Staff", 30, 50);
    Archer a1(3, "Archer", 10, 100, "Bow", 30, "High");
    Rogue r1(4, "Rogue", 10, 100, "Dagger", 40, 40);

    w1.display();
    cout << endl;
    m1.display();
    cout << endl;
    a1.display();
    cout << endl;
    r1.display();
    cout << endl;

    w1.attack();
    m1.Defend();
    a1.attack();

    return 0;
}