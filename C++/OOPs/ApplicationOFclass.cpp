#include<iostream>
using namespace std;

class Player{ // Secure krne k liye hacker se
private:
    int score;
    int health;

public:
    // setter
    void setScore(int s){
        score= s;
    }
    void setHealth(int h){
        health= h;
    }

    // getter
    int getScore(){
        return score;
    }
    int getHealth(){
        return health;
    }
};
int main()
{
    Player Sniper;
    Sniper.setScore(100);
    Sniper.setHealth(50);
    cout<<Sniper.getScore()<<endl;
    cout<<Sniper.getHealth()<<endl;

return 0;
}