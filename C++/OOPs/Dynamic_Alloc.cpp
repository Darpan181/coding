#include<iostream>
using namespace std;

class Player{
private:
    int health;
    int age;
    int score;
    bool alive;
public:
    void setHealth(int health){
        this->health = health;
    }
    void setAge(int age){
        this->age = age;
    }
    void setScore(int score){
        this->score = score;
    }
    void setAlive(bool alive){
        this->alive = alive;
    }

    int getHealth(){
        return health;
    }
    int getAge(){
        return age;
    }
    int getScore(){
        return score;
    }
    bool getAlive(){
        return alive;
    }
};

int main(){
    Player Sniper;
    Sniper.setHealth(76);
    Sniper.setAge(25);
    Sniper.setScore(999);
    Sniper.setAlive(true);
    
    // run time, dynamic allocation
    Player *Para = new Player; // memory allocate krne k liye
    Para->setHealth(1000);
    Para->setAge(23);
    cout<<Para->getHealth();

    // different ways of allocation:
    // 1. (*Para).getHealth();

    // 2. Player *Para= new Player;
    //    Player ParaSF= *Para;
    //    cout<< ParaSF.getHealth(); 

return 0;
}