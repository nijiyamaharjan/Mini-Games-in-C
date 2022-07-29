#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

bool processGuess();
int title_screen();

float createStats();

float createStats(int flag)
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
  fclose(wins);
  fclose(losses);
  return(winpercent);
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

int main() {

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
    winpercent = createStats(1);
  } else {
    printf("You have used up yours guesses... the correct word is %s\n", answer);
    winpercent = createStats(0);
  }
  printf("WIN PERCENT = %f", winpercent);
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