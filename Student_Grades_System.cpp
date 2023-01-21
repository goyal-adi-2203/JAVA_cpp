#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define CLASSES 3
#define GRADES 3

int grd[CLASSES][GRADES];

// input of grades
int get_grd(int num)
{
    char ch[100];
    cout << "Enter grades of student " << num + 1 << "\n";
    cin >> ch;
    return atoi(ch);
}

// Enter grades
void enter_grds()
{
    for (int i = 0; i < CLASSES; i++)
    {
        cout << "CLASS " << i << "\n";
        for (int j = 0; j < GRADES; j++)
        {
            grd[i][j] = get_grd(j);
        }
    }
}

// Display grades
void disp_grds(int grd[][GRADES])
{

    for (int i = 0; i < CLASSES; i++)
    {
        cout << "Class " << i << "\n";
        for (int j = 0; j < GRADES; j++)
        {
            cout << "   STUDENT " << j + 1 << " GRADES " << grd[i][j] << "\n";
        }
    }
}

int main()
{

    char ch, str[80];

    for (;;)
    {
        do
        {
            cout << "Enter the query E/D/Q :\n";
            cin >> ch;
            ch = toupper(ch);
            // cout << ch;
        } while (ch != 'E' && ch != 'D' && ch != 'Q');

        switch (ch)
        {
        case 'E':
            enter_grds();
            // cout << "E";
            break;
        case 'D':
            disp_grds(grd);
            // cout << "D";
            break;
        case 'Q':
            exit(0);
        }
    }
    return 0;
}
