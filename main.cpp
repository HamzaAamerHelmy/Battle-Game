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
    int HP = 100;
    enActions Action;
    string ActionText = "";
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
    return randomNumber(enActions::attack, enActions::defend);
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

void checkChooses(stPlayer &player, stPlayer &computer)
{
    if (player.Action == enActions::defend && computer.Action == enActions::defend)
    {
        cout << "Both defended ." << endl;
    }

    switch (player.Action)
    {
    case enActions::attack:
    {
        int randomNumberAttack = randomNumber(10, 25);

        if (computer.Action == enActions::defend)
        {
            computer.HP = computer.HP - (randomNumberAttack / 2);
            cout << "Computer defended ." << endl
                 << endl;
            cout << "Your damage: " << randomNumberAttack << endl;
            cout << "Actual damage: " << (randomNumberAttack / 2) << endl;
        }
        else
        {
            computer.HP = computer.HP - randomNumberAttack;
            cout << "You dealt " << randomNumberAttack << " damage!" << endl;
        }
        break;
    }
    case enActions::heal:
    {
        int randomNumberHeal = randomNumber(10, 25);

        if (player.HP >= 100)
        {
        }
        else
        {
            player.HP = player.HP + randomNumberHeal;
        }

        while (player.HP > 100)
        {
            player.HP--;
        }

        cout << "You recovered " << randomNumberHeal << " HP!" << endl;
        break;
    }
    }

    switch (computer.Action)
    {
    case enActions::attack:
    {
        int randomNumberAttack = randomNumber(10, 25);

        if (player.Action == enActions::defend)
        {
            player.HP = player.HP - (randomNumberAttack / 2);
            cout << "You defended ." << endl
                 << endl;
            cout << "Incoming damage: " << randomNumberAttack << endl;
            cout << "Actual damage: " << (randomNumberAttack / 2) << endl;
        }
        else
        {
            player.HP = player.HP - randomNumberAttack;
            cout << "Computer dealt " << randomNumberAttack << " damage!" << endl;
        }
        break;
    }
    case enActions::heal:
    {
        int randomNumberHeal = randomNumber(10, 25);

        if (computer.HP >= 100)
        {
        }
        else
        {
            computer.HP = computer.HP + randomNumberHeal;
        }

        while (computer.HP > 100)
        {
            computer.HP--;
        }

        cout << "Computer recovered " << randomNumberHeal << " HP!" << endl;
        break;
    }
    }
}

short printPlayAgain()
{
    short choose = 0;

    do
    {
        cout << "----------------------------------------" << endl
             << endl;
        cout << "        1. Play Again" << endl;
        cout << "        2. Main Menu" << endl;
        cout << "        3. Exit" << endl
             << endl;
        cout << "Choose: ";
        cin >> choose;
    } while (choose > 3 || choose < 1);

    return choose;
}

short pageWin(int playerHP, int computerHP)
{
    resetScreen();
    cout << "========================================" << endl
         << endl;
    cout << "                YOU WIN!                " << endl
         << endl;
    cout << "========================================" << endl
         << endl
         << endl;
    cout << "               VICTORY!             " << endl
         << endl;
    cout << "Your HP: " << playerHP << endl;
    cout << "Enemy HP: " << computerHP << endl
         << endl
         << endl;
    short playAgain = printPlayAgain();
    return playAgain;
}

short pageLose(int playerHP, int computerHP)
{
    resetScreen();
    cout << "========================================" << endl
    << endl;
    cout << "                YOU LOST!               " << endl
    << endl;
    cout << "========================================" << endl
    << endl
    << endl;
    cout << "                GAME OVER                " << endl
    << endl;
    cout << "Your HP: " << playerHP << endl;
    cout << "Computer HP: " << computerHP << endl
         << endl
         << endl;
    short playAgain = printPlayAgain();
    return playAgain;
}

short pageDraw(int playerHP, int computerHP)
{
    resetScreen();

    cout << "========================================" << endl << endl;
    cout << "                  DRAW                  " << endl << endl;
    cout << "========================================" << endl << endl << endl;
    cout << "        Both players are defeated!      " << endl << endl;
    cout << "Your HP: " << playerHP << endl;
    cout << "Enemy's HP: " << computerHP << endl << endl << endl;
    short playAgain = printPlayAgain();
    return playAgain;
}

void startGameLoop(stPlayer &player, stPlayer &computer, bool checkHP)
{
    while (checkHP == false)
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
        cout << "        YOU              COMPUTER" << endl;
        cout << "      HP: " << player.HP << "             HP: " << computer.HP << endl
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
        player.Action = (enActions)userInput;
        player.ActionText = getChooseText(player.Action);

        computer.Action = (enActions)fillComputerInput();
        computer.ActionText = getChooseText(computer.Action);

        cout << "========================================" << endl
             << endl;
        cout << "                 BATTLE                 " << endl
             << endl;
        cout << "========================================" << endl
             << endl
             << endl;
        cout << "You Chose: " << player.ActionText << endl;
        cout << "Computer Chose: " << computer.ActionText << endl
             << endl;

        checkChooses(player, computer);

        cout << endl;
        cout << "----------------------------------------" << endl
             << endl
             << endl;
        cout << "Your HP: " << player.HP << endl;
        cout << "Enemy HP: " << computer.HP << endl
             << endl
             << endl;
        cout << "----------------------------------------" << endl
             << endl;

        if (player.HP <= 0 || computer.HP <= 0)
        {
            checkHP = true;
        }

        cout << "Press any key to continue ..";
        char input = _getch();
    }
}

string startGame(stPlayer player, stPlayer computer)
{
    bool checkHP = false;

    startGameLoop(player, computer, checkHP);

    if (player.HP <= 0 && computer.HP <= 0)
    {
        player.HP = 0;
        computer.HP = 0;
        short pageD = pageDraw(player.HP, computer.HP);
        
        if (pageD == 1)
        {
            resetScreen();
            player.HP = 100;
            computer.HP = 100;
            return startGame(player, computer);
        }
        else if (pageD == 2)
        {
            return "Main";
        }
        else
        {
            return "Exit";
        }
    }
    else if (computer.HP <= 0)
    {
        computer.HP = 0;
        short pageW = pageWin(player.HP, computer.HP);
        if (pageW == 1)
        {
            resetScreen();
            player.HP = 100;
            computer.HP = 100;
            return startGame(player, computer);
        }
        else if (pageW == 2)
        {
            return "Main";
        }
        else
        {
            return "Exit";
        }
        
    }
    else
    {
        player.HP = 0;
        short pageL = pageLose(player.HP, computer.HP);
        if (pageL == 1)
        {
            resetScreen();
            player.HP = 100;
            computer.HP = 100;
            return startGame(player, computer);
        }
        else if (pageL == 2)
        {
            return "Main";
        }
        else
        {
            return "Exit";
        }
    }
    return "Wrong";
}

void PlayGame(short &choose, stPlayer player, stPlayer computer)
{
    printMainMenuScreen();
    choose = readMainMenuChoose();
    while (choose != 3)
    {
        if (choose == 1)
        {
            string startGameText = startGame(player, computer);
            if (startGameText == "Exit")
            {
                exit(0);
            }
        }
        else if (choose == 2)
        {
            pageHowToPlay();
        }
        printMainMenuScreen();
        choose = readMainMenuChoose();
    }
}

void RunApp()
{
    srand((unsigned)time(NULL));

    stPlayer player;

    stPlayer computer;

    short choose = 0;

    PlayGame(choose, player, computer);
}

int main()
{
    RunApp();

    return 0;
}