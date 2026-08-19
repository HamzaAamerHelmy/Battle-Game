#include <iostream>
using namespace std;



struct stPlayer
{
    int playerHP     = 100;
    int playerChoose = 0;
};

struct stComputer
{
    int computerHP     = 100;
    int computerChoose = 0;
};

int randomNumber(int from, int to)
{
    to += 1;
    int randNum = rand() % (to - from) + from;
    return randNum;
}

void printMainMenuScreen()
{
    cout << "========================================" << endl << endl;
    cout << "              BATTLE GAME               " << endl << endl;
    cout << "========================================" << endl << endl << endl;
    cout << "       1. Start Game" << endl;
    cout << "       2. How To Play" << endl;
    cout << "       3. Exit" << endl << endl << endl;
    cout << "========================================" << endl << endl;
}

short readMainMenuChoose()
{
    short userInput = 0;

    do
    {
        cout << "Choose: ";
        cin >> userInput;

        if (userInput > 3 || userInput < 1)
        {
            cout << "Wrong Input!" << endl;
            cout << "Please Enter A valid Number ..." << endl << endl;
        }
        
    } while (userInput > 3 || userInput < 1);
    
    return userInput;
}

int main()
{
    srand((unsigned)time(NULL));

    stPlayer player;

    stComputer computer;

    printMainMenuScreen();
    short choose = readMainMenuChoose();

    return 0;
}