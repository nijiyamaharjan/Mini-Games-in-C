#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

char str[200] = {"apple"}; //to be used later with the function strcpy

// CLEAR THE SCREEN

void vertmid() // For center placement vertically
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
}

void horiline(int spaceH1, int lengthH, int n, char c) // to print a horizontal line(spaceH1=spacing from left column,lengthH=length of line,n=no of line,c=character)
{
    int k, h, j;
    for (j = 0; j < n; j++)
    {
    for (h = 0; h < spaceH1; h++)
    {
        printf("\t");
    }
    
        for (k = 0; k < lengthH; k++) // 70 for menu
        {
            printf("%C", c);
        }
        printf("\n");
    }
}
void vertiline(int spaceV1, int noV, int lengthV, char c) // gives bordered line
// spaceV1 gives spacing from first left column on console, noV determines no of vertical border,lengthV determines the width of vertical border
{
    int m, g;
    int p;
    for (m = 0; m < noV; m++)
    {
        for (p = 0; p < spaceV1; p++)
        {
            printf("\t");
        }

        printf("%c", c);
        for (g = 0; g < lengthV; g++)
        {
            printf(" ");
        }
        printf("%c", c);
        printf("\n");
    }
}

void space(int n) // this function gives spacing from left column of console screen
// n determines no of spacing from left column in terms of \t
{
    int q;
    for (q = 0; q < n; q++)
        printf("\t");
}
void alignborder(char str[], int spaceAB1, int spaceAB2, int lengthAB, char c) // assign border and position to string
// lengthAB dtermines spacing between two vertical border,spaceAB1=determines no of spacing from left column in terms of \t,spaceAB2=determines no of spacing from left of first vertical border in terms od \t
{
    int a, aum = 0, u;
    a = strlen(str);
    aum = lengthAB - (spaceAB2 * 8) - a + 1;
    for (u = 0; u < spaceAB1; u++)
        printf("\t");
    printf("%c", c);
    for (u = 0; u < spaceAB2; u++)
        printf("\t");
    printf("%s", str);
    for (u = 0; u < aum; u++)
        printf(" ");
    printf("%c", c);
    printf("\n");
}

void alignborderno(char str[], int spaceABN1, int spaceABN2, int lengthABN, char c, int i)
// to provide two vertical line with a string and processessible integer
// lengthABN determines spacing between two vertical border,spaceABN1=determines no of spacing from left column in terms of \t,spaceABN2=determines no of spacing from left of first vertical border in terms od \t,i=integer value to printed.

{
    int sum = 0, u, a = 0, no = i, count = 0;
    a = strlen(str);
    if (no ==0)
count =1;
else
{
    while (no != 0)
    {
        no = no / 10;
        count++;
    }
}
    sum = lengthABN - (spaceABN2 * 8) - a - count-1;

    for (u = 0; u < spaceABN1; u++)
        printf("\t");
    printf("%c", c);
    for (u = 0; u < spaceABN2; u++)
        printf("\t");
    printf("%s= %d",str,i);
    for (u = 0; u < sum; u++)
        printf(" ");
    printf("%c", c);
    printf("\n");
}
void alignborderfloatno(char str[], int spaceABFN1, int spaceABFN2, int lengthABFN, char c, float i)
// to provide two vertical line with a string and processessible real no.
// lengthABFN dtermines spacing between two vertical border,spaceABFN1=determines no of spacing from left column in terms od \t,spaceABFN2=determines no of spacing from left of first vertical border in terms od \t,i=real no. value to be printed.

{
    int sum = 0, u, a = 0,floatno, count=0;
    a = strlen(str);
    floatno= (int)i;
    if (floatno==0)
    count=1;
    else
    {
    while (floatno != 0)
    {
        floatno = floatno / 10;
        count++;
    }
    }
    sum = lengthABFN - (spaceABFN2 * 8) - a - count-3-1;
    for (u = 0; u < spaceABFN1; u++)
        printf("\t");
    printf("%c", c);
    for (u = 0; u < spaceABFN2; u++)
        printf("\t");
    printf("%s= %0.2f", str, i);
    for (u = 0; u < sum; u++)
        printf(" ");
    printf("%c", c);
    printf("\n");
}

// FUNCTIONS FOR TIC-TAC-TOE

void resetBoard();
void tictactoeFirstPrint();
void printBoard();
int checkfreespace();
void player1Move();
void player2Move();
char checkWinner();
void printWinner();

// FUNCTIONS FOR WORDLE

bool processGuess();
int wordleTitleScreen();
void createStats();

// FUNCTIONS FOR MAIN MENU

void menu();
int tictactoe();
int wordle();

int choice;

// MAIN

int main()
{

    // CALL MENU

    menu();
    return 0;
}

// MENU

void menu()
{
    system("cls");
    vertmid();
    horiline(8, 70, 1, '.');
    vertiline(8, 1, 68, ':'); // width two less than horizontal line
    strcpy(str,"GAME MENU");    
    alignborder(str,8,4,68,':');
    vertiline(8, 1, 68, ':');
   strcpy(str,"1. Tic-Tac-Toe");
   alignborder(str,8,3,68,':');
   strcpy(str,"2. Wordle");
   alignborder(str,8,3,68,':');
   strcpy(str,"3. Exit Menu");
   alignborder(str,8,3,68,':');
   
    vertiline(8, 1, 68, ':');
    horiline(8, 70, 1, '.');
    printf("Enter your choice(1-3) : ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        system("cls");
        tictactoe();
    }
    else if (choice == 2)
    {
        system("cls");
        wordle();
    }
    else if (choice == 3)
    {
        system("cls");
        printf("\n\n\n\n");
        horiline(4, 90, 1, '/');
        vertiline(4, 1, 88, '/');
        strcpy(str, "GOODBYE!! (ToT)");
        alignborder(str, 4, 4, 88, '/');
        vertiline(4, 1, 88, '/');
        horiline(4, 90, 1, '/');
        
    }
    else
    {
        system("cls");
        printf("\n\n\n\n");

        horiline(4, 90, 1, '/');
        vertiline(4, 1, 88, '/');
        strcpy(str, "ENTER VALID NO.(1-3)");
        alignborder(str, 4, 4, 88, '/');
        vertiline(4, 1, 88, '/');
        horiline(4, 90, 1, '/');
        printf("Press any key to continue");
        getch();

        menu();
    }
}

// WORDLE

int wordle()
{

   

    // load wordle title screen

    wordleTitleScreen();
    printf("Press any key to continue");
    getch();
    system("cls");

    // load the words

    int max_num_of_words = 100;
    char **wordsList = calloc(max_num_of_words, sizeof(char *));
    int wordCount = 0;
    char *fiveLetterWord = malloc(6 * sizeof(char));
    FILE *wordsFile;

    wordsFile = fopen("words.txt", "r");
    if (wordsFile == NULL)
    {
        printf("File could not be opened.\n");
    }

    while (fscanf(wordsFile, "%s", fiveLetterWord) != EOF && wordCount < max_num_of_words)
    {
        wordsList[wordCount] = fiveLetterWord;
        wordCount++;
        fiveLetterWord = malloc(6 * sizeof(char));
    }

    fclose(wordsFile);

    // start the game

    // pick a word randomly

    srand(time(NULL));
    char *answer = wordsList[rand() % wordCount];

    // input guess

    int num_of_guesses = 1;
    bool guessed_correctly = false;
    char *guess = malloc(6 * sizeof(char));
    int num_of_letters, response;
    horiline(4, 120, 1, '#');
    printf("\n\n");
    while (num_of_guesses <= 6 && !guessed_correctly)
    {

        // get guess from player
        space(6);
       
        printf("Guess %d : ", num_of_guesses);
        num_of_guesses++;
        scanf("%s", guess);
        num_of_letters = strlen(guess);

        while (num_of_letters != 5)
        {
            space(4);
            printf("Please enter only 5-letter words. \n");
            space(4);
            scanf("%s", guess);
            num_of_letters = strlen(guess);
        }

        // check if the guess is correct or not

        guessed_correctly = processGuess(answer, guess);
    }

    // display end of game message
    system("cls");
    horiline(1, 100, 1, '*');
    if (guessed_correctly)
    {

        strcpy(str, "CONGRATULATIONS! YOU GUESSED THE CORRECT WORD ON ATTEMPT ");
        alignborderno(str, 1, 2, 98, '*', (num_of_guesses - 1));

        createStats(1);
    }
    else
    {
        strcpy(str, "YOU HAVE USED UP YOUR GUESSES...THE CORRECT WORD IS:");
        alignborder(str, 1, 2, 98, '*');
        strcpy(str, answer);
        alignborder(str, 1, 4, 98, '*');
        createStats(0);
    }
    horiline(1, 100, 1, '*');
    space(4);
    printf("\nDo you want to go for another round?(Yes=1/NO=0)");
    scanf("%d", &response);

    if (response == 1)
    {
        system("cls");
        wordle();
    }
    else if (response == 0)
    {
        system("cls");
        menu();
    }

    
    for (int i = 0; i < wordCount; i++)
    {
        free(wordsList[i]);
    }

    free(wordsList);
    free(fiveLetterWord);
    free(guess);
    
    return 0;
}

// stats calculation for wordle

void createStats(int flag)
{
    FILE *wins, *losses, *streak;
    int w, l, s;
    float winpercent;

    wins = fopen("E:\\Coding\\miniproject\\wins.txt", "r+");
    losses = fopen("E:\\Coding\\miniproject\\losses.txt", "r+");
    streak = fopen("E:\\Coding\\miniproject\\streak.txt", "r+");

    fscanf(wins, "%d", &w);
    fscanf(losses, "%d", &l);
    fscanf(streak, "%d", &s);

    if (flag == 1) // if the user has guessed correctly
    {
        fseek(wins, 0, SEEK_SET);
        fprintf(wins, "%d", w + 1);
        w++;
        fseek(streak, 0, SEEK_SET);
        fprintf(streak, "%d", s + 1);
        s++;
    }
    else if (flag == 0) // if the user has guessed incorrectly
    {
        fseek(losses, 0, SEEK_SET);
        fprintf(losses, "%d", l + 1);
        l++;
        fseek(streak, 0, SEEK_SET);
        fprintf(streak, "%d", 0);
        s = 0;
    }

    winpercent = (float)w / ((float)w + (float)l) * 100.0;
    strcpy(str, "TOTAL GAMES PLAYED");
    alignborderno(str, 1, 2, 98,'*',(w+l));
    strcpy(str, "WIN PERCENT");
    alignborderfloatno(str, 1, 2, 98, '*', winpercent);
    strcpy(str, "WIN STREAK");
    alignborderfloatno(str, 1, 2, 98, '*', s);
    fclose(wins);
    fclose(losses);
    fclose(streak);
}

// process guess

bool processGuess(const char *theAnswer, const char *theGuess)
{
    // the clue
    char clue[6] = {'X', 'X', 'X', 'X', 'X', '\0'};
    // a set of flags indicating if that letter in the answer is used as clue
    bool answerFlags[5] = {false, false, false, false, false};

    // first pass, look for exact matches
    for (int i = 0; i < 5; i++)
    {
        if (theGuess[i] == theAnswer[i])
        {
            clue[i] = '#';
            answerFlags[i] = true;
        }
    }
    printf("\n");

    // second pass, look for there but elsewhere
    for (int i = 0; i < 5; i++)
    {
        if (clue[i] == 'X')
        { // means no exact match from first pass
            for (int j = 0; j < 5; j++)
            {
                if (theGuess[i] == theAnswer[j] && !answerFlags[j])
                {
                    // a match at another position and has not been used as clue
                    clue[i] = 'O';
                    answerFlags[j] = true;
                    break; // end this j-loop because we don't want multiple clues from the same letter
                }
            }
        }
    }

    horiline(4, 120, 1, '_');
    space(4);
    printf("%s\n\n", clue); // print clue

    // print letters in correct place
    space(4);
    for (int i = 0; i < 5; i++)
    {
        if (clue[i] == '#')
        {
            printf("%c", theGuess[i]);
        }
        else
        {
            printf("-");
        }
    }

    // print remaining letters
    printf("\tRemaining letters : ");
    for (int i = 0; i < 5; i++)
    {
        if (clue[i] == 'O')
            printf("%c ", theGuess[i]);
    }
    printf("\n");
    horiline(4, 120, 1, '#');
    printf("\n\n");

    return strcmp(clue, "#####") == 0; // if match strcmp returns 0
}

// wordle title screen

int wordleTitleScreen()
{

    horiline(6, 120, 1, '.');
    vertiline(6, 1, 118, ':');
    strcpy(str, "WELCOME !!");
    alignborder(str, 6, 3, 118, ':');
    vertiline(6, 1, 118, ':');
    strcpy(str, "Guess the WORDLE in six tries.");
    strcpy(str, "Each guess must be a valid five-letter word in all lowercase. Hit the enter button to submit.");
    alignborder(str, 6, 1, 118, ':');
    strcpy(str, "After each guess, hints are shown to show how close your guess was to the word. They look like this");
    alignborder(str, 6, 1, 118, ':');
    strcpy(str, " X = Character not found at all");
    alignborder(str, 6, 1, 118, ':');
    strcpy(str, " # = Character found and position correct");
    alignborder(str, 6, 1, 118, ':');
    strcpy(str, " O = Character found but position wrong");
    alignborder(str, 6, 1, 118, ':');
    strcpy(str, "Guessing \"rates\" when the word is \"tests\" shows \"XXOO#");
    alignborder(str, 6, 1, 118, ':');
    horiline(6, 120, 1, '.');

    return 1;
}

// TIC-TAC-TOE

// globally declaring the matrix  and variables
char board[3][3];
int position[3][3] = {{11, 12, 13}, {21, 22, 23}, {31, 32, 33}};
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
char winner = ' ';
int scr;
int psc1 = 0, psc2 = 0;
int r = 1;

int tictactoe()
{
    int response;
    horiline(4, 70, 1, '.');
    vertiline(4, 1, 68, ':');
    strcpy(str, "     WELCOME TO TIC TAC TOE !!  :-)");
    alignborder(str, 4, 2, 68, ':');
    vertiline(4, 1, 68, ':');
    vertiline(4, 1, 68, ':');
    vertiline(4, 1, 68, ':');
    strcpy(str, ":PLAYER1=X:              :PLAYER2=O:");
    alignborder(str, 4, 2, 68, ':');
    vertiline(4, 1, 68, ':');
    vertiline(4, 1, 68, ':');
    strcpy(str, "The positons are as specified below:");
    alignborder(str, 4, 2, 68, ':');
    vertiline(4, 1, 68, ':');
    vertiline(4, 1, 68, ':');
    tictactoeFirstPrint();
    vertiline(4, 1, 68, ':');
    vertiline(4, 1, 68, ':');
    vertiline(4, 1, 68, ':');
    horiline(4, 70, 1, '.');
    printf("Press any key to continue");
    getch();
    system("cls");

    do
    {
 horiline(6, 70, 1, '.');
            vertiline(6, 1, 68, ':');
            strcpy(str, "LET THE GAME BEGIN !!");
            alignborder(str, 6, 2, 68, ':');
            vertiline(6, 1, 68, ':');
            horiline(6, 70, 1, '.');
            printf("\n\n");
            horiline(9, 15, 1, '/');
            vertiline(9, 1, 13, '\\');
            strcpy(str, "  ROUND");
            alignborderno(str, 9, 0, 12, '\\', r);
            vertiline(9, 1, 13, '\\');
            horiline(9, 15, 1, '/');
        resetBoard();
        winner = ' ';

        // start game

        while (winner == ' ' && checkfreespace() != 0)
        {
           
            printf("\n\n\n");

            printBoard();

            player1Move();

            winner = checkWinner();
            if (winner != ' ' || checkfreespace() == 0)
            {
                break;
            }
            printBoard();
            player2Move();
            winner = checkWinner();
            if (winner != ' ' || checkfreespace() == 0)
            {
                break;
            }
        }
        printBoard();
        printWinner(winner);
        printf("\n \nSCORE:\n");
        printf("\nPLAYER1\t PLAYER2:");
        printf("\n%d\t\t%d", psc1, psc2);
        printf("\nDo you want to go for another round?(Yes=1/NO=0)");
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
            system("cls");
        }
        else if (response == 0)
        {
            system("cls");
            menu();
        }
        r++;
    } while (response == 1);
    
    return 0;
}

// print game matrix

void tictactoeFirstPrint()
{
    space(7);
    printf("    %d | %d| %d\n", position[0][0], position[0][1], position[0][2]);
    space(7);
    printf("    ---|---|---\n");
    space(7);
    printf("    %d | %d| %d\n", position[1][0], position[1][1], position[1][2]);
    space(7);
    printf("    ---|---|---\n");
    space(7);
    printf("    %d | %d| %d\n", position[2][0], position[2][1], position[2][2]);
    space(7);
    printf("    ---|---|---\n");
}

// empty board for new game

void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void printBoard()
{
    horiline(7,50,1,'@');
    vertiline(7,2,48,'@');
    space(7);
    printf("@");
    space(2);
    printf("   %c | %c | %c", board[0][0], board[0][1], board[0][2]);
    space(3);
    printf(" @");
    printf("\n");
    space(7);
     printf("@");
    space(2);
    printf("  ---|---|---");
     space(3);
    printf(" @");
    printf("\n");
    space(7);
     printf("@");       
    space(2);
    printf("   %c | %c | %c", board[1][0], board[1][1], board[1][2]);
     space(3);
    printf(" @");
    printf("\n");
    space(7);
     printf("@");
    space(2);
    printf("  ---|---|---");
     space(3);
    printf(" @");
    printf("\n");
    space(7);
     printf("@");
    space(2);
    printf("   %c | %c | %c", board[2][0], board[2][1], board[2][2]);
     space(3);
    printf(" @");
    printf("\n");
    space(7);
     printf("@");
    space(2);
    printf("  ---|---|---");
     space(3);
    printf(" @");
    printf("\n");
    vertiline(7,2,48,'@');
    horiline(7,50,1,'@');
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

// input player1's move

void player1Move()
{
    int x;
    int y;
    do
    {
        printf("PLayer 1\n");
        printf("Enter row (1-3): ");
        scanf("%d", &x);
        x--;
        printf("Enter column (1-3): ");
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

// input player2's move

void player2Move()
{
    int x1;
    int y1;
    do
    {
        printf("PLayer 2\n");
        printf("Enter row (1-3): ");
        scanf("%d", &x1);
        x1--;
        printf("Enter column (1-3): ");
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

/// check for winner

char checkWinner()

{
    // check rows

    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    // check column
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    // check diagonal

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

// print winner

void printWinner()
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
