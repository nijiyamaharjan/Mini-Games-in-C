#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

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

  printf("%s\n", clue);
  return strcmp(clue, "GGGGG") == 0; //if match strcmp returns 0
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
  //load title screen
  int start = title_screen();

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
  int num_of_guesses = 0;
  bool guessed_correctly = false;
  char* guess = malloc(6*sizeof(char));
  int num_of_letters;

  while (num_of_guesses < 6 && !guessed_correctly) 
  {
    //get guess from player
    printf("Input a 5-letter word and press enter: ");
    scanf("%s", guess);
    num_of_letters = strlen(guess);
    while (num_of_letters !=5)
    {
        printf("Please enter only 5-letter words. \n");
        scanf("%s", guess);
        num_of_letters = strlen(guess);
    }
    
    num_of_guesses++ ;

    printf("Guess %d : %s\n", num_of_guesses, guess);
    
    //check if the guess is correct or not
    guessed_correctly = processGuess(answer, guess);
    }

  //display end of game message
  if (guessed_correctly) {
    printf("Congratulations! You guessed the correct word in %d tries!\n", num_of_guesses);
  } else {
    printf("You have used up yours guesses... the correct word is %s\n", answer);
  }

  for (int i=0; i<wordCount; i++) {
    free(wordsList[i]);
  }
  free(wordsList);
  free(fiveLetterWord);
  free(guess);
  
  return 0;
}