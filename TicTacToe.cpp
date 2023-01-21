#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
static char comp;
static char plyr;
static char res;


// Tic Tac Toe matrix
char mat[3][3];


void init_mat();
void disp_mat();
void plyr_choice();
void plyr_turn();
bool comp_turn();
bool check();

int main(){

    bool f = false;
    init_mat();
    disp_mat();
    plyr_choice();
    
    do
    {
        plyr_turn();
        disp_mat();
        f = comp_turn();
        disp_mat();
        if(f) break;

        f = check();
    } while (!f);
    
    cout << res;

    return 0;
}


// Initialize the matrix
void init_mat(){
    for(int i=0;i<3;i++){
        for(int j = 0;j<3;j++){
            mat[i][j]='.';
        }
    }
}


// Display matrix
void disp_mat(){

    cout << "Matrix for TIC TAC TOE is \n";

    for(int i =0;i<3;i++){
        for(int j = 0;j<3;j++){
            cout << mat[i][j] <<"   "; 
        }
        cout <<"\n";
    }

}


// taking input for player choice of character
void plyr_choice(){
    
    char temp;

    cout << "Enter your choice (X/O) : ";
    cin >> temp;
    plyr = toupper(temp);

    comp = (plyr =='X')?'O':'X';

}


//  player turn input
void plyr_turn(){
    
    int x_coord,y_coord;

    cout << "Enter the x and y coordinates of your move (x,y): ";
    cin >> x_coord >> y_coord;

    x_coord--;
    y_coord--;

    if (mat[x_coord][y_coord]=='.'){
        mat[x_coord][y_coord]=plyr;
    } else {
        cout << "Position taken\n.Choose something else.\n";
        plyr_turn();
    }
    
}


// computer turn
bool comp_turn(){

    for(int i=0;i<3;i++){
        for(int j = 0;j<3;j++){
            if (mat[i][j]=='.'){
                mat[i][j]=comp;
                res = 'D';
                return false;
            }
        }
    }

    return true;
}


// check for Win or lose of player
bool check(){

    // checking rows
    for(int i=0;i<3;i++){
        if(mat[i][0]==mat[i][1] && mat[i][1]==mat[i][2]){
            if (mat[i][0]==plyr){
                res = 'W';
                return true;
            } else if (mat[i][0]==comp){
                res = 'L';
                return true;
            }
            
        }
    }

    // checking columns
    for(int i=0;i<3;i++){
        if(mat[0][i]==mat[1][i] && mat[1][i]==mat[2][i]){
            if (mat[0][i]==plyr){
                res = 'W';
                return true;
            } else if (mat[0][i]==comp){
                res = 'L';
                return true;
            }
        }
    }

    // checking diagonals
    if(mat[0][0]==mat[1][1] && mat[1][1]==mat[2][2]){
        if (mat[0][0]==plyr){
                res = 'W';
                return true;
            } else if (mat[0][0]==comp){
                res = 'L';
                return true;
            }
    }

    return false;
}
























