/*
*       ******************Requirements**********************
*
*       -Write a program that plays Tic-Tac_toe
*       ----game is played on a 3x3 grid between 2 players, who take turns
*
*       -Should create an array to represent the board
*       -----Can be of type char and consist of 10 elements (do not use 0)
*       -----each element represents a coordinate on the board that the user can select
*
*       -Some Functions that you should probably create
*       ----checkForWin -  checks to see if a player has won the game or the game is a draw
*       ----drawBoard   -  redraws the board for each player turn
*       ----markBoard   -  sets the char array with a selection and check for an invalid selection
*/

#include <stdio.h>
#include <conio.h>

char board_arr[9][17] ={
            {' ',' ',' ',' ',' ','|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',},
            {' ',' ','1',' ',' ','|', ' ',' ','2',' ',' ','|',' ',' ','3',' ',},
            {'_','_','_','_','_','|','_','_','_','_','_','|','_','_','_','_','_'},
            {' ',' ',' ',' ',' ','|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',},
            {' ',' ','4',' ',' ','|', ' ',' ','5',' ',' ','|',' ',' ','6',' ',},
            {'_','_','_','_','_','|','_','_','_','_','_','|','_','_','_','_','_'},
            {' ',' ',' ',' ',' ','|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',},
            {' ',' ','7',' ',' ','|', ' ',' ','8',' ',' ','|',' ',' ','9',' ',},
            {' ',' ',' ',' ',' ','|', ' ',' ',' ',' ',' ','|',' ',' ',' ',' ',},
        };//This is the main grid and number storer

int playerChoice; //this stores the position where the player wants to make an entry
_Bool player1turn = 1; //just a boolean that stores 1 for player 1 turn and 0 for player 2 turn


int checkForWin();
void drawBoard();
char markBoard();
int result = -1;
_Bool isCheckedArray[9] = {1};

int main()

{
    int i;

    while(result != 1 && result != 0)
    {
        drawBoard();
        markBoard();
        result = checkForWin();
    }

    drawBoard(); //So that the final results are displayed before decalring the outcome

    if (result == 1)
    {   
        printf("%s",player1turn?"player 2 wins":"player 1 wins");
    }

    else
    {
       printf("Welp, its a draw,was to be expected , tbh");
    }
    
    getch();
    
}

void drawBoard()
{   
    system("cls");
    printf("\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    
    
    for(int row =0;row < 9;row++)
    {
        for(int column = 0; column<17; column++)
        {
            printf("%c",board_arr[row][column]);
        }
        printf("\n");
    }
    
    if(checkForWin() != 1 && checkForWin() != 0)
    {
        if (player1turn)
        {
            printf("Player 1, enter a number: ");
            scanf("%i",&playerChoice);
        }

        else 
        {
            printf("Player 2, enter a number: ");
            scanf("%i",&playerChoice);        
        }
    }
    
}

char markBoard()
{   
    char mark = player1turn ? 'X' : 'O';

    if(playerChoice == 1 && board_arr[1][2] == '1') 
    {
        board_arr[1][2] = mark;
    }

    else if(playerChoice == 2 && board_arr[1][8] == '2')
    {
        board_arr[1][8] = mark;
    }   

    else if(playerChoice == 3 && board_arr[1][14] == '3')
    {
        board_arr[1][14] = mark;
    }   

    else if(playerChoice == 4 && board_arr[4][2] == '4')
    {
        board_arr[4][2] = mark;
    }   

    else if(playerChoice == 5 && board_arr[4][8] == '5')
    {
        board_arr[4][8] = mark;
    }   

    else if(playerChoice == 6 && board_arr[4][14] == '6')
    {
        board_arr[4][14] = mark;
    }   

    else if(playerChoice == 7 && board_arr[7][2] == '7')
    {
        board_arr[7][2] = mark;
    }   

    else if(playerChoice == 8 && board_arr[7][8] == '8')
    {
        board_arr[7][8] = mark;
    }   

    else if(playerChoice == 9 && board_arr[7][14] == '9')
    {
        board_arr[7][14] = mark;
    }

    else 
    {   
        printf("ngl, ur choice do be looking invalid tho");
        player1turn =!player1turn;
        getch();// if i hadnt used this, the program would just print the invalid message and clear it instantly and the user would not be able to see it
    }
    player1turn = !player1turn;   
    
}

 //
int checkForWin()
{
    if (board_arr[1][2] == board_arr[1][8] && board_arr[1][8]== board_arr[1][14]) //first row
        return 1;

    else if (board_arr[4][2] == board_arr[4][8] && board_arr[4][8] == board_arr[4][14]) //second row
        return 1;

    else if (board_arr[7][2] == board_arr[7][8] && board_arr[7][8] == board_arr[7][14]) //third row
        return 1;

    else if (board_arr[1][2] == board_arr[4][8] && board_arr[4][8] == board_arr[7][14]) //straight diagnoal
        return 1;

    else if (board_arr[1][14] == board_arr[4][8] && board_arr[4][8] == board_arr[7][2])  //cross diagnoal
        return 1;

    else if (board_arr[1][2] == board_arr[4][2] && board_arr[4][2] == board_arr[7][2]) //first column
        return 1;

    else if (board_arr[1][8] == board_arr[4][8] && board_arr[4][8] == board_arr[7][8])  //second column
            return 1;

    else if (board_arr[1][14] == board_arr[4][14] && board_arr[4][14] == board_arr[7][14]) //third column
            return 1;

    else if(board_arr[1][2] != '1' && board_arr[1][8] != '2' && board_arr[1][14] != '3' && board_arr[4][2] != '4' && board_arr[4][8] != '5' && board_arr[4][14] != '6' && board_arr[7][2] != '7'  && board_arr[7][8] != '8' && board_arr[7][14] != '9') //This means its a draw
    {
        return 0;
    }   

}