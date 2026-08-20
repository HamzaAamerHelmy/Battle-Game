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
    int playerHP = 100;
    enActions playerAction;
    string playerActionText = "";
};

struct stComputer
{
    int computerHP = 100;
    enActions computerAction;
    string computerActionText = "";
};

int randomNumber(int from, int to)
{
    from += 1;
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

    cout << "========================================" << endl
         << endl;
    cout << "              BATTLE GAME               " << endl
         << endl;
    cout << "========================================" << endl
         << endl
         << endl;
    cout << "       1. Start Game" << endl;
    cout << "       2. How To Play" << endl;
    cout << "       3. Exit" << endl
         << endl
         << endl;
    cout << "========================================" << endl
         << endl;
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
            cout << "Please Enter A valid Number ..." << endl
                 << endl;
        }

    } while (userInput > 3 || userInput < 1);

    return userInput;
}

void pageHowToPlay()
{
    resetScreen();

    cout << "========================================" << endl
         << endl;
    cout << "              HOW TO PLAY              " << endl
         << endl;
    cout << "========================================" << endl
         << endl
         << endl;
    cout << "You will battle against the computer." << endl
         << endl;
    cout << "Each Round, choose one action: " << endl
         << endl;
    cout << "1. Attack" << endl;
    cout << "2. Heal" << endl;
    cout << "3. Defend" << endl
         << endl;
    cout << "Reduce The enemy's HP to 0 to win" << endl
         << endl;
    cout << "========================================" << endl
         << endl;
    cout << "Press any key to return ..";
    char input = _getch();

    resetScreen();
}

int fillComputerInput()
{
    return rand() % (3 - 1) + 1;
}

string getChooseText(enActions action)
{
    switch (action)
    {
    case enActions::attack:
        return "ATTACK";
    case enActions::heal:
        return "HEAL";
    case enActions::defend:
        return "DEFEND";
    }

    return "Wrong";
}

void checkChooses(stPlayer &player, stComputer &computer)
{
    switch (player.playerAction)
    {
    case enActions::attack:
    {
        int randomNumberAttack = randomNumber(10, 25);

        if (computer.computerAction == enActions::defend)
        {
            computer.computerHP = computer.computerHP - (randomNumberAttack / 2);
            cout << "Computer is defending ." << endl
                 << endl;
            cout << "Your damage: " << randomNumberAttack << endl;
            cout << "Actual damage: " << (randomNumberAttack / 2) << endl;
        }
        else
        {
            computer.computerHP = computer.computerHP - randomNumberAttack;
            cout << "You dealt " << randomNumberAttack << " damage!" << endl;
        }
        break;
    }
    case enActions::heal:
    {
        int randomNumberHeal = randomNumber(10, 25);

        if (!player.playerHP >= 100)
        {
            player.playerHP = player.playerHP + randomNumberHeal;
        }

        while (player.playerHP > 100)
        {
            player.playerHP--;
        }

        cout << "You recovered " << randomNumberHeal << " HP!" << endl;
        break;
    }
    }

    switch (computer.computerAction)
    {
    case enActions::attack:
    {
        int randomNumberAttack = randomNumber(10, 25);

        if (player.playerAction == enActions::defend)
        {
            player.playerHP = player.playerHP - (randomNumberAttack / 2);
            cout << "You is defending ." << endl
                 << endl;
            cout << "Incoming damage: " << randomNumberAttack << endl;
            cout << "Actual damage: " << (randomNumberAttack / 2) << endl;
        }
        else
        {
            player.playerHP = player.playerHP - randomNumberAttack;
            cout << "Computer dealt " << randomNumberAttack << " damage!" << endl;
        }
        break;
    }
    case enActions::heal:
    {
        int randomNumberHeal = randomNumber(10, 25);

        if (!computer.computerHP >= 100)
        {
            computer.computerHP = computer.computerHP + randomNumberHeal;
        }

        while (player.playerHP > 100)
        {
            player.playerHP--;
        }

        cout << "Computer recovered " << randomNumberHeal << " HP!" << endl;
        break;
    }
    }
}

void startGame(stPlayer player, stComputer computer)
{
    do
    {
        resetScreen();
        short userInput = 0;
        cout << "========================================" << endl
             << endl;
        cout << "               BATTLE GAME              " << endl
             << endl;
        cout << "========================================" << endl
             << endl
             << endl;
        cout << "      HP: " << player.playerHP << "              HP: " << computer.computerHP << "      " << endl
             << endl
             << endl;
        cout << "----------------------------------------" << endl
             << endl
             << endl;
        cout << "        1. Attack" << endl;
        cout << "        2. Heal" << endl;
        cout << "        3. Defend" << endl
             << endl
             << endl;
        cout << "----------------------------------------" << endl
             << endl
             << endl;
        do
        {
            cout << "Choose Your Action: ";
            cin >> userInput;

            if (userInput > 3 || userInput < 1)
            {
                cout << "Wrong Input!" << endl;
                cout << "Please enter A valid number! .." << endl
                     << endl;
            }

        } while (userInput > 3 || userInput < 1);

        resetScreen();
        player.playerAction = (enActions)userInput;
        player.playerActionText = getChooseText(player.playerAction);

        computer.computerAction = (enActions)fillComputerInput();
        computer.computerActionText = getChooseText(computer.computerAction);

        cout << "========================================" << endl
             << endl;
        cout << "                 BATTLE                 " << endl
             << endl;
        cout << "========================================" << endl
             << endl
             << endl;
        cout << "You Chose: " << player.playerActionText << endl;
        cout << "Computer Chose: " << computer.computerActionText << endl
             << endl;

        checkChooses(player, computer);

        cout << endl;
        cout << "----------------------------------------" << endl
             << endl;
        cout << "Your HP: " << player.playerHP << endl;
        cout << "Enemy HP: " << computer.computerHP << endl
             << endl;
        cout << "----------------------------------------" << endl
             << endl;
        cout << "Press any key to continue ..";
        char input = _getch();
    } while (player.playerHP > 0 || computer.computerHP > 0);
}

void PlayGame(short &choose, stPlayer player, stComputer computer)
{
    while (true)
    {
        if (choose == 1)
        {
            startGame(player, computer);
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