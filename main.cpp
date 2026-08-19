#include <iostream>
#include <conio.h>
using namespace std;

enum enActions
{
    attack = 1,
    heal = 2,
    defend = 3
};

struct stPlayer
{
    int playerHP     = 100;
    enActions playerChoose;
};

struct stComputer
{
    int computerHP     = 100;
    enActions computerChoose;
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

void pageHowToPlay()
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

void pageStartGame(stPlayer player, stComputer computer)
{
    resetScreen();
    short userInput = 0;
    cout << "========================================" << endl << endl;
    cout << "               BATTLE GAME              " << endl << endl;
    cout << "========================================" << endl << endl << endl;
    cout << "      HP: " << player.playerHP << "              HP: " << computer.computerHP << "      " << endl << endl << endl;
    cout << "----------------------------------------" << endl << endl << endl;
    cout << "        1. Attack" << endl;
    cout << "        2. Heal" << endl;
    cout << "        3. Defend" << endl << endl << endl;
    cout << "----------------------------------------" << endl << endl << endl;
    do
    {
        cout << "Choose Your Action: ";
        cin >> userInput;

        if (userInput > 3 || userInput < 1)
        {
            cout << "Wrong Input!" << endl;
            cout << "Please enter A valid number! .." << endl << endl;
        }
        
    } while (userInput > 3 || userInput < 1);
    

    player.playerChoose = (enActions)userInput;
}

void PlayGame(short &choose, stPlayer player, stComputer computer)
{
    while(true)
    {   
        if (choose == 1)
        {
            pageStartGame(player, computer);
        }
        else if (choose == 2)
        {
            pageHowToPlay();
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

    PlayGame(choose, player, computer);

    return 0;
}