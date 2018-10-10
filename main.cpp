// Program: Memory Matching Game
// Author:  Lauren Safwat
// ID:      20170203
// Date:    8 October 2018


#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

char shuffle(char arr[4][4]){
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            arr[i][j] = '0';
    int x, y;
    char numbers[16]={'1','2','3','4','5','6','7','8','1','2','3','4','5','6','7','8'};
    srand(time(0));
    x = (rand()%4);
    y = (rand()%4);
    for (int i=0; i<16; i++){
        while (arr[x][y] != '0')
        {
            x = (rand()%4);
            y = (rand()%4);
        }
    arr[x][y] = numbers[i];
    }
}


void displayBoard(char arr[4][4]){
    cout << endl;
    cout << "        1  2  3  4" << endl;
    cout << "     ----------------" << endl;
    for (int i=0;  i<4; i++){
        cout << "  " << i+1 << "  |  ";
        for (int j=0; j<4; j++){
            cout << arr[i][j]<<"  " ;
        }
        cout << endl ;
    }
    cout << endl;
}


void compare(char stars[4][4], char num[4][4], int r1, int c1, int r2, int c2)
{
    int counter=0;
    stars[r1][c1] = num[r1][c1];
    stars[r2][c2] = num[r2][c2];
    displayBoard(stars);
    if (stars[r1][c1] != stars[r2][c2])
    {
        for (int i=0; i<1; i++)
            cout << endl;
        stars[r1][c1] = stars[r2][c2] = '*';
        displayBoard(stars);
    }
}


int main()
{
    char num[4][4]={{'1','2','3','4'},{'5','6','7','8'},{'1','2','3','4'},{'5','6','7','8'}};
    int choice;
    int counter=0;

    while (true)
    {
        char stars[4][4]={{'*','*','*','*'},{'*','*','*','*'},{'*','*','*','*'},{'*','*','*','*'}};
        int r1,c1,r2,c2;
        bool isFinished = true;
        displayBoard(stars);
        while(isFinished == true)
        {
            cout << "Enter the index of your first choice: ";
            cin >> r1 >> c1;
            cout << "Enter the index of your second choice: ";
            cin >> r2 >> c2;
            compare(stars,num,r1-1,c1-1,r2-1,c2-1);
            counter = 0;
            for (int i=0; i<4; i++){
                for (int j=0; j<4; j++){
                    if (stars[i][j] != '*'){
                        counter += 1;
                    }
                }
            }
            if (counter == 16){
                isFinished = false;
            }
        }
        cout << "CONGRATULATIONS :), YOU WON!" << endl;
        shuffle(num);

        cout << "\nWhat do you want to do?";
        cout << "\n1) Play again";
        cout << "\n2) Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        if (choice == 2)
            return 0;

    }

}

