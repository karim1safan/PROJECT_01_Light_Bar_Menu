#include <iostream>
#include <Windows.h>
#include <conio.h>
#define LEFT_TOP_BORDER char(201)
#define RIGHT_TOP_BORDER char(187)
#define LEFT_BOTTOM_BORDER char(200)
#define RIGHT_BOTTOM_BORDER char(188)
#define VERTICAL_SEPARATOR char(186)
#define HORIZONTAL_SEPARATOR char(205)
#define UP_ARROW_PRESSED 72
#define DOWN_ARROW_PRESSED 80
#define NO_ARROW_PRESSED -32
#define ENTER_PRESSED 13
#define BLACK_COLOR 15
#define WHITE_COLOR 240

using namespace std;

COORD coord = { 0,0 };

// Functions Declarations
void setConsoleCursorVisibility(bool visible);
void gotoxy(int x, int y);
void draw_box();

int main()
{
    system("cls");
    system("title Light Bar Menu @karim Safan");

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); 
    setConsoleCursorVisibility(0);                       // Make The Cursor Invisible
    
    draw_box();

    char ch;
    int pos = 1;
    
    do
    {
        SetConsoleTextAttribute(console, BLACK_COLOR);  // Make The Console Black 

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
        gotoxy(30, 18);
        cout << " 7] Exit                        *  ";

        switch (pos)
        {
        case 1:
            gotoxy(30, 11);
            SetConsoleTextAttribute(console, WHITE_COLOR);
            cout << " 1] Add a new record            *  ";
            break;
        case 2:
            gotoxy(30, 12);
            SetConsoleTextAttribute(console, WHITE_COLOR);
            cout << " 2] Update a new record         *  ";
            break;
        case 3:
            gotoxy(30, 13);
            SetConsoleTextAttribute(console, WHITE_COLOR);
            cout << " 3] Check a new record          *  ";
            break;
        case 4:
            gotoxy(30, 14);
            SetConsoleTextAttribute(console, WHITE_COLOR);
            cout << " 4] Display a new record        *  ";
            break;
        case 5:
            gotoxy(30, 15);
            SetConsoleTextAttribute(console, WHITE_COLOR);
            cout << " 5] Insert a new record         *  ";
            break;
        case 6:
            gotoxy(30, 16);
            SetConsoleTextAttribute(console, WHITE_COLOR);
            cout << " 6] Delete an existing record   *  ";
            break;
        case 7:
            gotoxy(30, 18);
            SetConsoleTextAttribute(console, WHITE_COLOR);
            cout << " 7] Exit                        *  ";
            break;
        }

        ch = _getch();      // Controling In The Kewbord Arrows [up, down, enter]

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

    } while (ch != ENTER_PRESSED);
    SetConsoleTextAttribute(console, BLACK_COLOR);
    gotoxy(30, 22);
    cout << "Your selection is: " << pos << endl;
}

// Controling In The Position Of The Drawing BOX
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Drawing The BOX 
void draw_box()
{
    // Strat the top line
    gotoxy(29, 10);
    cout << LEFT_TOP_BORDER;
    for (int i = 0; i < 35; i++)
    {
        cout << HORIZONTAL_SEPARATOR;
    }
    cout << RIGHT_TOP_BORDER;
    // End the top line

    // Start left and right line
    for (int i = 0; i < 10; i++)
    {
        gotoxy(29, 11+i);
        cout << VERTICAL_SEPARATOR;
        for (int i = 0; i < 35; i++)
        {
            cout << " ";
        }
        cout << VERTICAL_SEPARATOR;
    }
    // End left and right line
    
    // Start the bottom line
    gotoxy(29, 20);
    cout << LEFT_BOTTOM_BORDER;
    for (int i = 0; i < 35; i++)
    {
        cout << HORIZONTAL_SEPARATOR;
    }
    cout << RIGHT_BOTTOM_BORDER;
    // End the bottom line
}

// Controling In Cursor Visibility
void setConsoleCursorVisibility(bool visible) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = visible;

    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}