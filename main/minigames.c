#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

//CLEAR THE SCREEN
void ClearScreen()
{
    int n;
    for (n = 0; n <10; n++)
        printf( "\n\n\n\n\n\n\n\n\n\n" );
}

//FUNCTIONS FOR TIC-TAC-TOE

void resetboard();
void firstprint();
void printboard();
int checkfreespace();
void player1move();
void player2move();
char checkwinner();
void printwinner();

//FUNCTIONS FOR WORDLE

bool processGuess();
int title_screen();

//FUNCTIONS FOR MAIN MENU
void menu();
int tictactoe();
int wordle();
int stats();

int choice;

//MAIN 
int main()
{
       //CALL MENU
       menu();
       return 0;
}

//MENU
void menu()
{
    printf("GAME MENU\n");
    printf("\n\n1. Tic-Tac-Toe\n2. Wordle\n3. Exit Menu");
    printf("\n\nEnter your choice\n");
    scanf("%d",&choice);
    if (choice== 1)
    {
       ClearScreen();
       tictactoe();
    }
    else if (choice == 2)
    {
        ClearScreen();
        wordle();
    }
    else if (choice == 3)
    {
        ClearScreen();
        printf("GOODBYE! Type any key to exit.\n");
        int endval;
        scanf("%i", &endval);
    }
    else
    {
        printf("Enter valid game number");
    }    
}


//WORDLE 
bool processGuess();
int title_screen();
void createStats();

int wordle() {

  int endvalue; 
  //load title screen
  title_screen();

  //load the words
  int MAX_NUM_OF_WORDS = 100;
  char** wordsList = calloc(MAX_NUM_OF_WORDS, sizeof(char*));
  int wordCount = 0;
  char* fiveLetterWord = malloc(6*sizeof(char));
  FILE* wordsFile;
  
  wordsFile = fopen("words.txt", "r");
  if (wordsFile == NULL)
  {
    printf("File could not be opened.\n");
  }

  while (fscanf(wordsFile, "%s", fiveLetterWord) != EOF && wordCount < MAX_NUM_OF_WORDS) {
    wordsList[wordCount] = fiveLetterWord;
    wordCount++;
    fiveLetterWord = malloc(6*sizeof(char));
  }
  fclose(wordsFile);

  //start the game
  //pick a word randomly
  srand(time(NULL));
  char* answer = wordsList[rand()%wordCount];
  //input guess
  int num_of_guesses = 1;
  bool guessed_correctly = false;
  char* guess = malloc(6*sizeof(char));
  int num_of_letters;

  while (num_of_guesses <= 6 && !guessed_correctly) 
  {
    //get guess from player
    printf("Guess %d : ", num_of_guesses);
    num_of_guesses++ ;
    scanf("%s", guess);
    num_of_letters = strlen(guess);
    while (num_of_letters !=5)
    {
        printf("Please enter only 5-letter words. \n");
        scanf("%s", guess);
        num_of_letters = strlen(guess);
    }
    
    //check if the guess is correct or not
    guessed_correctly = processGuess(answer, guess);
    }
float winpercent=0;
  //display end of game message
  if (guessed_correctly) {
    printf("Congratulations! You guessed the correct word in %d tries!\n", num_of_guesses-1);
    createStats(1);
  } else {
    printf("You have used up yours guesses... the correct word is %s\n", answer);
    createStats(0);
  }
  printf("Enter any key to exit.\n");
  scanf("%i", &endvalue);

  for (int i=0; i<wordCount; i++) {
    free(wordsList[i]);
  }
  free(wordsList);
  free(fiveLetterWord);
  free(guess);
  getchar();
  return 0;
 
}

void createStats(int flag)
{
  FILE *wins, *losses;
  int w,l;
  float winpercent;

  wins = fopen("E:\\Coding\\wins.txt","r+");
  losses = fopen("E:\\Coding\\losses.txt","r+");
  if (wins == NULL)
  {
      printf("Error!");               
   }
  fscanf(wins, "%d", &w);
  fscanf(losses, "%d", &l);
  if (flag == 1)
  {
   fseek( wins , 0, SEEK_SET );
   fprintf(wins, "%d", w+1);
   w++;
  }
  else if (flag == 0)
  {
   fseek( losses , 0, SEEK_SET );
   fprintf(losses, "%d", l+1);
   l++;
  }
  winpercent = (float) w/((float)w+ (float)l) * 100.0 ;
  printf("TOTAL GAMES PLAYED = %d\n WIN PERCENT = %.2f\n", (w+l), winpercent);
  fclose(wins);
  fclose(losses);
}
bool processGuess(const char* theAnswer, const char* theGuess) {
  //the clue
  char clue[6] = {'X', 'X', 'X', 'X', 'X', '\0'};
  //a set of flags indicating if that letter in the answer is used as clue
  bool answerFlags[5] = {false, false, false, false, false};

  //first pass, look for exact matches
  for (int i=0; i<5; i++) {
    if (theGuess[i] == theAnswer[i]) 
    {
      clue[i] = '#';
      answerFlags[i] = true;
    }
  }
  printf("\n");

  //second pass, look for there but elsewhere
  for (int i=0; i<5; i++) {
    if (clue[i] == 'X') {//means no exact match from first pass
      for (int j=0; j<5; j++) {
        if (theGuess[i] == theAnswer[j] && !answerFlags[j]) {
          //a match at another position and has not been used as clue
          clue[i] = 'O';
          answerFlags[j] = true;
          break; //end this j-loop because we don't want multiple clues from the same letter
        }
      }
    }
  }
  
  printf("%s\n\n", clue); // print clue

  //print letters in correct place
  for (int i=0; i<5; i++)
  {
    if (clue[i] == '#')
      printf("%c",theGuess[i]);
    else
      printf("-");
  }

  //print remaining letters
  printf("\tRemaining letters : ");
  for (int i=0; i<5; i++)
  {
    if (clue[i] == 'O')
     printf("%c ", theGuess[i]);
  }

  printf("\n\n");

  
  return strcmp(clue, "#####") == 0; //if match strcmp returns 0
}

int title_screen()
{
    printf("Welcome!\n"
           "Guess the WORDLE in six tries.\n" 
           "Each guess must be a valid five-letter word in all lowercase. Hit the enter button to submit.\n"
           "After each guess, hints are shown to show how close your guess was to the word. They look like this:\n\n"
       
		   "X = Character not found at all\n"
		   "# = Character found and position correct\n"
		   "O = Character found but position wrong\n\n"
		   "Guessing \"rates\" when the word is \"tests\" shows \"XXOO#\n\n");
    return 1;
}

//TIC-TAC-TOE

//*globally declaring the matrix  and variables
char board[3][3];
int position [3][3]={{11,12,13},{21,22,23},{31,32,33}};
const char PLAYER1 = 'X' ;
const char PLAYER2 = 'O' ;
char winner = ' ';
int scr;
int psc1 = 0, psc2 = 0;
int r=1;

int tictactoe()
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
            ClearScreen();
        }
        else if(response == 0)
        {
            ClearScreen();
            menu();
        }
        r++;
    }
    while (response == 1); 
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