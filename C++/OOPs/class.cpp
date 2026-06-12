#include<iostream>
using namespace std;

class Player{
public: // access modifiers
    int score;  // data members
    int health;

    void showHealth(){ // member function
        cout<<"Health is: "<<health;
    }
};

int main()
{
    Player Sniper;
    Sniper.score= 150;
    Sniper.health= 200;
    cout<<Sniper.score<<endl;
    cout<<Sniper.health<<endl;

    Sniper.showHealth();

return 0;
}

// Types of Access Modifiers:
//     1. public
//     2. private
//     3. protected