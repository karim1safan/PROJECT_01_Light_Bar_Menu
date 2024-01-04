#include <iostream>
#include <Windows.h>
#include <conio.h>
#define LEFT_BOTTOM_BORDER 
#define RIGHT_TOP_BORDER 187
#define LEFT_TOP_BORDER 201;
#define UP_ARROW_PRESSED 72
#define DOWN_ARROW_PRESSED 80
#define NO_ARROW_PRESSED -32
#define ENTER_PRESSED '\n'
using namespace std;

COORD coord = { 0,0 };

void setConsoleCursorVisibility(bool visible);
void gotoxy(int x, int y);
void draw_box();

int main()
{
    system("cls");
    system("title Light Bar Menu @karim Safan");

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    setConsoleCursorVisibility(0);
    draw_box();

    char ch;
    int pos = 1;
    
    do
    {
        SetConsoleTextAttribute(console, 15);

        gotoxy(30, 11);
        cout << " 1] Add a new record            *  ";
        gotoxy(30, 12);
        cout << " 2] Update a new record         *  ";
        gotoxy(30, 13);
        cout << " 3] Check a new record          *  ";
        gotoxy(30, 14);
        cout << " 4] Display a new record        *  ";
        gotoxy(30, 15);
        cout << " 5] Insert a new record         *  ";
        gotoxy(30, 16);
        cout << " 6] Delete an existing record   *  ";
        gotoxy(30, 17);
        cout << " 7] Exit                        *  ";

        switch (pos)
        {
        case 1:
            gotoxy(30, 11);
            SetConsoleTextAttribute(console, 240);
            cout << " 1] Add a new record            *  ";
            break;
        case 2:
            gotoxy(30, 12);
            SetConsoleTextAttribute(console, 240);
            cout << " 2] Update a new record         *  ";
            break;
        case 3:
            gotoxy(30, 13);
            SetConsoleTextAttribute(console, 240);
            cout << " 3] Check a new record          *  ";
            break;
        case 4:
            gotoxy(30, 14);
            SetConsoleTextAttribute(console, 240);
            cout << " 4] Display a new record        *  ";
            break;
        case 5:
            gotoxy(30, 15);
            SetConsoleTextAttribute(console, 240);
            cout << " 5] Insert a new record         *  ";
            break;
        case 6:
            gotoxy(30, 16);
            SetConsoleTextAttribute(console, 240);
            cout << " 6] Delete an existing record   *  ";
            break;
        case 7:
            gotoxy(30, 17);
            SetConsoleTextAttribute(console, 240);
            cout << " 7] Exit                        *  ";
            break;
        }

        ch = _getch();

        // if the user doesn't input char, takse from hem another input
        if (ch == NO_ARROW_PRESSED)
            ch = _getch();
        if (ch == UP_ARROW_PRESSED)
        {
            pos--;
            if (pos == 0)
                pos = 7;
        }
        if (ch == DOWN_ARROW_PRESSED)
        {
            pos++;
            if (pos == 8)
                pos = 1;
        }

    } while (ch == ENTER_PRESSED);
    
    gotoxy(30, 22);
    cout << "Your selection is: " << pos << endl;
}

void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void draw_box()
{
    // Strat the top line
    gotoxy(29, 10);
    cout << (char)LEFT_TOP_BORDER;
    for (int i = 0; i < 35; i++)
    {
        cout << char(205);
    }
    cout << char(RIGHT_TOP_BORDER);
    // End the top line

    // Start left and right line
    for (int i = 0; i < 10; i++)
    {
        gotoxy(29, 11+i);
        cout << char(186);
        for (int i = 0; i < 35; i++)
        {
            cout << char(32);
        }
        cout << char(186);
    }
    // End left and right line
    
    // Start the bottom line
    gotoxy(29, 20);
    cout << char(200);
    for (int i = 0; i < 35; i++)
    {
        cout << char(205);
    }
    cout << char(188);
    // End the bottom line
}
void setConsoleCursorVisibility(bool visible) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = visible;

    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}