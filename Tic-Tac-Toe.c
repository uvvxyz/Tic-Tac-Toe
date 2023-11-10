/*
 * C Program to Play the Tic Tac Toe Game
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
// Globally declared 2D-array
char board4[4][4];
char board3[3][3];
 
// Function to initialize the game board
void initializeBoard4()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            board4[i][j] = ' ';
        }
    }
    int count = 1;
    printf("\n\n\t  ");
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%d", count++);
            if (j < 3)
            {
                printf("  |  ");
            }
        }
        if (i < 3)
        printf("\n\t------------------------\n\t  ");
    }
    printf("\n\n\n");
}
void initializeBoard3()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <3; j++)
        {
            board3[i][j] = ' ';
        }
    }
    int count = 1;
    printf("\n\n\t  ");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j <3; j++)
        {
            printf("%d", count++);
            if (j < 2)
            {
                printf("  |  ");
            }
        }
        if (i < 2)
        printf("\n\t----------------\n\t  ");
    }
    printf("\n\n\n");
}
 
// Function shows the game board
void showBoard4(int x, int y)
{
    printf("\n\n\t  ");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%c", board4[i][j]);
            if (j < 3)
            {
                printf("  |  ");
            }
        }
        if (i < 3)
        printf("\n\t------------------------\n\t  ");
    }
    printf("\n\n\n");
}
void showBoard3(int x, int y)
{
    printf("\n\n\t  ");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <3; j++)
        {
            printf("%c", board3[i][j]);
            if (j < 2)
            {
                printf("  |  ");
            }
        }
        if (i < 2)
        printf("\n\t----------------\n\t  ");
    }
    printf("\n\n\n");
}
 
// Function to update the game board
int updateBoard4(int cell, char playerSign)
{
    int row = (cell - 1) / 4;
    int col = (cell - 1) % 4;
    int isValid = 1;
 
    // accessing already played cell number
    if (board4[row][col] != ' ')
    {
        printf("\nInvalid: Cell is already Filled!\n");
        isValid = 0;
    }
 
    // valid cell position
    else
    {
        board4[row][col] = playerSign;
    }
    showBoard4(row, col);
 
    return isValid;
}
int updateBoard3(int cell, char playerSign)
{
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;
    int isValid = 1;
 
    // accessing already played cell number
    if (board3[row][col] != ' ')
    {
        printf("\nInvalid: Cell is already Filled!\n");
        isValid = 0;
    }
 
    // valid cell position
    else
    {
        board3[row][col] = playerSign;
    }
    showBoard3(row, col);
 
    return isValid;
}
 
// Function to check the winner of the game
int checkWinner4(char sg)
{
    // check all rows
    if (board4[0][0] == sg && board4[0][1] == sg && board4[0][2] == sg ||
      board4[1][0] == sg && board4[1][1] == sg && board4[1][2] == sg ||
      board4[2][0] == sg && board4[2][1] == sg && board4[2][2] == sg ||
      board4[3][0] == sg && board4[3][1] == sg && board4[3][2] == sg )
    {
        return 1;
      }
      // check all columns
    else if (board4[0][0] == sg && board4[1][0] == sg && board4[2][0] == sg ||
           board4[0][1] == sg && board4[1][1] == sg && board4[2][1] == sg ||
           board4[0][2] == sg && board4[1][2] == sg && board4[2][2] == sg ||
           board4[0][3] == sg && board4[1][3] == sg && board4[2][3] == sg )
    {
        return 1;
    }
    // check both diagonals
    else if (board4[0][0] == sg && board4[1][1] == sg && board4[2][2] == sg || 
             board4[1][1] == sg && board4[2][2] == sg && board4[3][3] == sg ||
             board4[0][2] == sg && board4[1][1] == sg && board4[2][0] == sg ||
             board4[1][0] == sg && board4[2][1] == sg && board4[3][2] == sg             
            )
    {
        return 1;
    }
 
    // There is no winner
    return 0;
}
int checkWinner3(char sg)
{
        // check all rows
    if (board3[0][0] == sg && board3[0][1] == sg && board3[0][2] == sg ||
      board3[1][0] == sg && board3[1][1] == sg && board3[1][2] == sg ||
      board3[2][0] == sg && board3[2][1] == sg && board3[2][2] == sg)
    {
        return 1;
      }
      // check all columns
    else if (board3[0][0] == sg && board3[1][0] == sg && board3[2][0] == sg ||
           board3[0][1] == sg && board3[1][1] == sg && board3[2][1] == sg ||
           board3[0][2] == sg && board3[1][2] == sg && board3[2][2] == sg)
    {
        return 1;
    }
    // check both diagonals
    else if (board3[0][0] == sg && board3[1][1] == sg && board3[2][2] == sg ||
           board3[0][2] == sg && board3[1][1] == sg && board3[2][0] == sg)
    {
        return 1;
    }
 
    // There is no winner
    return 0;
}
void computerMove4(char computerSign)
{
    int cell;
    srand(time(0));

    do
    {
        cell = rand() % 16 + 1;
    }
    while (!updateBoard4(cell, computerSign));
}
void computerMove3(char computerSign)
{
    int cell;
    srand(time(0));

    do
    {
        cell = rand() % 9 + 1;
    }
    while (!updateBoard3(cell, computerSign));
}
 
// Start your game from here
void playTicTacToe4()
{
    int gameMode = 0;
    int gameResult = 0;
    int cell = 0;
    int playCount = 0;
    int updationResult = 1;

    printf("\nGame Mode\n");
    printf("\nPress 1 for Player vs Player");
    printf("\nPress 2 for Player vs Computer");
    printf("\n\nChoice: ");
    scanf("%d", &gameMode);

    if (gameMode == 1)
    { 
        char playerSign = ' ';
 
        // start playing the game

        while (!gameResult && playCount < 16)
        {
            if (playCount % 2 == 0)
            {
                // player 1
                printf("\nPlayer 1 [ X ] : ");
                playerSign = 'X';
            }
            else
            {
                // player 2
                printf("\nPlayer 2 [ O ] : ");
                playerSign = 'O';
            }
            scanf("%d", &cell);
            if (cell > 0 && cell < 17)
            {
                updationResult = updateBoard4(cell, playerSign);
                // if updation is possible
                if (updationResult)
                {
                    gameResult = checkWinner4(playerSign);
                    // print the winner of the game
                    if (gameResult)
                    {
                        printf("\t *** Player %d Won!! ***\n", playerSign == 'X' ? 1 : 2);
                    }
                    playCount++;
                }
            }
            else if (cell == -1)
            {
                printf("\n\tGame Terminated\n");
                return;
            }
            else
            {
                printf("\nPlease Enter a valid cell value\n");
            }
        }
 
        // no one won the game
        if (!gameResult && playCount == 16)
        {
            printf("\n\t *** Draw...  ***\n");
        }
        printf("\n\t --- Game Over --- \n");
    }
    else if (gameMode == 2)
    {
    char playerSign = ' ';
    char computerSign = 'O';
 
    // start playing the game
    while (!gameResult && playCount < 16)
    {
        if (playCount % 2 == 0)
        {
            // player 1
            printf("\nPlayer 1 [ X ] : ");
            playerSign = 'X';
        }
        else
        {
            // player 2
            printf("\nComputer [ O ] : ");
            computerSign = 'O';
        }
        scanf("%d", &cell);
        if (cell > 0 && cell < 17)
        {
            updationResult = updateBoard4(cell, playerSign);
            // if updation is possible
            if (updationResult)
            {
                gameResult = checkWinner4(playerSign);
                // print the winner of the game
                if (gameResult)
                {
                    printf("\t *** Player %d Won!! ***\n", playerSign == 'X' ? 1 : 2);
                }
                playCount++;
            }
        }
        else if (cell == -1)
        {
            printf("\n\tGame Terminated\n");
            return;
        }
        else
        {
            printf("\nPlease Enter a valid cell value\n");
        }
        if (!gameResult && playCount < 16)
        {
            computerMove4(computerSign);
            gameResult = checkWinner4(computerSign);
            // print the winner of the game
            if (gameResult)
            {
                printf("\t *** Computer Won!! ***\n");
            }
            playCount++;
        }
    }
 
    // no one won the game
    if (!gameResult && playCount == 16)
    {
        printf("\n\t *** Draw...  ***\n");
    }
    printf("\n\t --- Game Over --- \n");
    }
    else
    {
        printf("\nInvalid Game Mode\n");
    }
}
void playTicTacToe3()
{
    int gameMode = 0;
    int gameResult = 0;
    int cell = 0;
    int playCount = 0;
    int updationResult = 1;

    printf("\nGame Mode\n");
    printf("\nPress 1 for Player vs Player");
    printf("\nPress 2 for Player vs Computer");
    printf("\n\nChoice: ");
    scanf("%d", &gameMode);

    if (gameMode == 1)
    { 
        char playerSign = ' ';
 
        // start playing the game

        while (!gameResult && playCount < 9)
        {
            if (playCount % 2 == 0)
            {
                // player 1
                printf("\nPlayer 1 [ X ] : ");
                playerSign = 'X';
            }
            else
            {
                // player 2
                printf("\nPlayer 2 [ O ] : ");
                playerSign = 'O';
            }
            scanf("%d", &cell);
            if (cell > 0 && cell < 10)
            {
                updationResult = updateBoard3(cell, playerSign);
                // if updation is possible
                if (updationResult)
                {
                    gameResult = checkWinner3(playerSign);
                    // print the winner of the game
                    if (gameResult)
                    {
                        printf("\t *** Player %d Won!! ***\n", playerSign == 'X' ? 1 : 2);
                    }
                    playCount++;
                }
            }
            else if (cell == -1)
            {
                printf("\n\tGame Terminated\n");
                return;
            }
            else
            {
                printf("\nPlease Enter a valid cell value\n");
            }
        }
 
        // no one won the game
        if (!gameResult && playCount == 9)
        {
            printf("\n\t *** Draw...  ***\n");
        }
        printf("\n\t --- Game Over --- \n");
    }
    else if (gameMode == 2)
    {
    char playerSign = ' ';
    char computerSign = 'O';
 
    // start playing the game
    while (!gameResult && playCount < 9)
    {
        if (playCount % 2 == 0)
        {
            // player 1
            printf("\nPlayer 1 [ X ] : ");
            playerSign = 'X';
        }
        else
        {
            // player 2
            printf("\nComputer [ O ] : ");
            computerSign = 'O';
        }
        scanf("%d", &cell);
        if (cell > 0 && cell < 10)
        {
            updationResult = updateBoard3(cell, playerSign);
            // if updation is possible
            if (updationResult)
            {
                gameResult = checkWinner3(playerSign);
                // print the winner of the game
                if (gameResult)
                {
                    printf("\t *** Player %d Won!! ***\n", playerSign == 'X' ? 1 : 2);
                }
                playCount++;
            }
        }
        else if (cell == -1)
        {
            printf("\n\tGame Terminated\n");
            return;
        }
        else
        {
            printf("\nPlease Enter a valid cell value\n");
        }
        if (!gameResult && playCount < 9)
        {
            computerMove3(computerSign);
            gameResult = checkWinner3(computerSign);
            // print the winner of the game
            if (gameResult)
            {
                printf("\t *** Computer Won!! ***\n");
            }
            playCount++;
        }
    }
 
    // no one won the game
    if (!gameResult && playCount == 9)
    {
        printf("\n\t *** Draw...  ***\n");
    }
    printf("\n\t --- Game Over --- \n");
    }
    else
    {
        printf("\nInvalid Game Mode\n");
    }
}

int main()
{
    int gameMode = 0;
    int gridsize = 0;
    printf("--------- Tic Tac Toe ----------\n\n");


    printf("\n* Instructions \n\n");
    printf("\tPlayer 1 sign = X\n");
    printf("\tPlayer 2 sign = O");
    printf("\n\tTo exit from game, Enter -1\n");
 
    printf("\nSelect Grid Size\n");
    printf("\nPress 1 for 4x4");
    printf("\nPress 2 for 3x3");
    printf("\n\nChoice: ");
    scanf("%d", &gridsize);

    if(gridsize == 1)
    {
    printf("\n\n* Cell Numbers on Board\n");
    initializeBoard4();
 
    char start = ' ';
    printf("\n> Press Enter to start...");
 
    scanf("%c", &start);
 
    if (start)
    {
        int userChoice = 1;
        // restart the game
        while (userChoice)
        {
            playTicTacToe4();
            printf("\n* Menu\n");
            printf("\nPress 1 to Restart");
            printf("\nPress 0 for Exit");
            printf("\n\nChoice: ");
            scanf("%d", &userChoice);
            if (userChoice)
            {
                initializeBoard4();
            }
            printf("\n");
        }
    }
    printf("\n :: Thanks for playing Tic Tac Toe game! :: \n");
    return 0;
    }
    else if(gridsize == 2)
    {
        printf("\n\n* Cell Numbers on Board\n");
        initializeBoard3();

        char start = ' ';
        printf("\n> Press Enter to start...");
 
        scanf("%c", &start);
 
        if (start)
        {
            int userChoice = 1;
            // restart the game
            while (userChoice)
            {
                playTicTacToe3();
                printf("\n* Menu\n");
                printf("\nPress 1 to Restart");
                printf("\nPress 0 for Exit");
                printf("\n\nChoice: ");
                scanf("%d", &userChoice);
                if (userChoice)
                {
                    initializeBoard3();
                }
                printf("\n");
            }
        }
        printf("\n :: Thanks for playing Tic Tac Toe game! :: \n");
        return 0;
    }
}