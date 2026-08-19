#include <iostream>
#include <conio.h>
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

void resetScreen()
{
    system("cls");
}

void printMainMenuScreen()
{
    resetScreen();

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

void PageHowToPlay()
{
    resetScreen();

    cout << "========================================" << endl << endl;
    cout << "              HOW TO PLAY              " << endl << endl;
    cout << "========================================" << endl << endl << endl;
    cout << "You will battle against the computer." << endl << endl;
    cout << "Each Round, choose one action: " << endl << endl;
    cout << "1. Attack" << endl;
    cout << "2. Heal" << endl;
    cout << "3. Defend" << endl << endl;
    cout << "Reduce The enemy's HP to 0 to win" << endl << endl;
    cout << "========================================" << endl << endl;
    cout << "Press any key to return ..";
    char input = _getch();
    

    resetScreen();
}

void openPages(short &choose)
{
    while(true)
    {   
        if (choose == 1)
        {
            /* code */
        }
        else if (choose == 2)
        {
            PageHowToPlay();
        }
        else
        {
            return;
        }
        printMainMenuScreen();
        choose = readMainMenuChoose();
    }
}

int main()
{
    srand((unsigned)time(NULL));

    stPlayer player;

    stComputer computer;

    printMainMenuScreen();
    short choose = readMainMenuChoose();

    openPages(choose);

    return 0;
}