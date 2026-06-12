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
        this->health = health;  // Player::health= health
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

void addScore(Player a, Player b){
    cout<< a.getScore() + b.getScore();
}

Player getMaxscore(Player a, Player b){
    if(a.getScore() > b.getScore()){
        return a;
    }
    else return b;
}

int main()
{
    Player Sniper;        // object creation, statically
    Sniper.setHealth(60); // compile time, static allocation
    Sniper.setAge(21);
    Sniper.setScore(780);
    Sniper.setAlive(true);

    Player Medic;
    Medic.setHealth(90);
    Medic.setAge(19);
    Medic.setScore(921);
    Medic.setAlive(false);

    addScore(Sniper, Medic);
    cout<<endl;
    Player Imposter= getMaxscore(Sniper, Medic);
    cout<< Imposter.getScore()<<endl;
return 0;
}