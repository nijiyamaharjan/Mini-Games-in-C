#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//*globally declaring the matrix  and vairables
char board[3][3];
int position [3][3]={{11,12,13},{21,22,23},{31,32,33}};
const char PLAYER1 = 'X' ;
const char PLAYER2 = 'O' ;
char winner = ' ';
int scr;
int psc1 = 0, psc2 = 0;
int r=1;


void resetboard();
void firstprint();
void printboard();
int checkfreespace();
void player1move();
void player2move();
char checkwinner();
void printwinner();

int main()
{
    int response;
    printf("Welcome to tic tac toe!!  :-)");
    printf ("\nplayer1=X\tplayer2=O\n");
    printf("\nThe positons are as specified below\n");
    firstprint();
    
    do
    {

        resetboard();
        winner = ' ';
        while (winner == ' ' && checkfreespace() != 0)
        {
            printf("\nLet the game begin!!");
            printf("\n\nRound %d",r);

            printboard();

            player1move();

            winner = checkwinner();
            if (winner != ' ' || checkfreespace() == 0)
            {
                break;
            }
            printboard();
            player2move();
            winner = checkwinner();
            if (winner != ' ' || checkfreespace() == 0)
            {
                break;
            }
        }
        printboard();
        printwinner(winner);
                printf("\n \nSCORE:\n");
                printf("\nPLAYER1\t PLAYER2:");
        printf("\n%d\t\t%d", psc1, psc2);
        printf("\n Do you want to go for another round?(Yes=1/NO=0)");
        scanf("%d", &response);

        if (response == 1)
              {
            printf("\nDo you want to keep the scores (Yes=1/No=0)");
            scanf("%d", &scr);
            if (scr == 0)
            {
                psc1 = 0;
                psc2 = 0;
            }
        }
        r++;
    }while (response == 1);
            
        return 0;
    
}

void firstprint()
    {
        printf("\n \n");
        printf("%d | %d| %d", position[0][0], position[0][1], position[0][2]);
        printf("\n---|---|---\n");
        printf("%d | %d| %d", position[1][0], position[1][1], position[1][2]);
        printf("\n---|---|---\n");
        printf("%d | %d| %d", position[2][0], position[2][1], position[2][2]);
        printf("\n---|---|---\n");
        printf("\n");
    }
    void resetboard()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = ' ';
            }
        }
    }
    void printboard()
{
    printf("\n \n");
    printf(" %c | %c | %c", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c", board[2][0], board[2][1], board[2][2]);
    printf("\n---|---|---\n");
    printf("\n");
}
    

    int checkfreespace()
    {
        int freespace = 9;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] != ' ')
                {
                    freespace--;
                }
            }
        }
        return freespace;
    }

    void player1move()
    {
        int x;
        int y;
        do
        {
            printf("PLayer 1\n");
            printf("Enter row (1-3):");
            scanf("%d", &x);
            x--;
            printf("Enter column (1-3):");
            scanf("%d", &y);
            y--;
            if (board[x][y] != ' ')
            {
                printf("Invalid move\n");
            }
            else
            {
                board[x][y] = PLAYER1;
                break;
            }
        } while (board[x][y] != ' ');
    }

    void player2move()
    {
        int x1;
        int y1;
        do
        {
            printf("PLayer 2\n");
            printf("Enter row (1-3):");
            scanf("%d", &x1);
            x1--;
            printf("Enter column (1-3):");
            scanf("%d", &y1);
            y1--;
            if (board[x1][y1] != ' ')
            {
                printf("Invalid move\n");
            }
            else
            {
                board[x1][y1] = PLAYER2;
                break;
            }
        } while (board[x1][y1] != ' ');
    }

    char checkwinner()

    {
        //*check rows

        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
            {
                return board[i][0];
            }
        }

        //*check column
        for (int i = 0; i < 3; i++)
        {
            if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
            {
                return board[0][i];
            }
        }
        //*check diagonal
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
        {
            return board[0][0];
        }

        if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
        {
            return board[0][2];
        }
        return ' ';
    }

    void printwinner()
    {
        if (winner == PLAYER1)
        {
            psc1++;
            printf("PLAYER 1 IS THE WINNER OF THIS GAME *<|:-) \\o");
        }
        else if (winner == PLAYER2)
        {
            psc2++;
            printf("PLAYER 2 IS THE WINNER OF THIS GAME *<|:-) o/");
        }
        else
        {
            printf("IT'S A TIE!  \\o/\\o/");
        }
    }