#include <iostream>
#include <cstdlib> // For srand and rand
#include <ctime>   // For time
#include <string.h>
using namespace std;

int main()
{


    // Array of words for the game
    string words[] = {"program", "hangman", "computer", "language", "coding"};
    int numWords = sizeof(words) / sizeof(words[0]); 	// Calculating the number of words in the array

    srand(time(0)); 					// Seed the random number generator with current time

    // Randomly select a word from the array
    string selectedWord = words[rand() % numWords];

    // Convert selected word to lowercase for consistency
    for (char &c : selectedWord)
    {
        c = tolower(c);
    }

    char guessWord[selectedWord.length()];   		// Update guessWord array size to match selected word
    strcpy(guessWord, selectedWord.c_str()); 		// Copy characters of selected word to guessWord array

    char to_guess[selectedWord.length()]; 		// Array to display the guessed word
    for (int i = 0; i < selectedWord.length(); ++i)
    {
        to_guess[i] = '_'; // Initialize to_guess with underscores
    }
    to_guess[selectedWord.length()] = '\0'; 		// Null-terminate the string

    char guess;
    int wrongGuess = 0;
    int tries = 7; 					// Number of tries

    bool found; 					// for checking if match found

    cout << "\nWelcome to Hangman Game! " << endl;
    cout << to_guess << endl;

    while (wrongGuess < tries)
    {
        cout << "Guess a letter \n";
        cin >> guess;

        found = 0;
        for (int j = 0; j <= 8; j++)
        {
            if (guess == guessWord[j])
            {
                to_guess[j] = guessWord[j];

                found = 1;
            }
        }

        if (found)
        {
            cout << to_guess << endl;

            // Check if the entire word has been guessed
            if (strcmp(to_guess, guessWord) == 0)
            {
                cout << "\nCongratulations! You Won, Wait for your Surprise !!!\n";
                break;
            }
        }
        else
        {
            wrongGuess++;
            int a = tries - wrongGuess;

            switch (a)
            {
            case 6:
            {
                cout << " +---+" << endl;
                cout << " |   |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "======" << endl;

                break;
            }
            case 5:
            {
                cout << " +---+" << endl;
                cout << " |   |" << endl;
                cout << " O   |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "======" << endl;

                break;
            }
            case 4:
            {
                cout << " +---+" << endl;
                cout << " |   |" << endl;
                cout << " O   |" << endl;
                cout << " |   |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "======" << endl;

                break;
            }
            case 3:
            {
                cout << " +---+" << endl;
                cout << " |   |" << endl;
                cout << " O   |" << endl;
                cout << "/|   |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "======" << endl;

                break;
            }
            case 2:
            {
                cout << " +---+" << endl;
                cout << " |   |" << endl;
                cout << " O   |" << endl;
                cout << "/|\\  |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "======" << endl;

                break;
            }
            case 1:
            {
                cout << " +---+" << endl;
                cout << " |   |" << endl;
                cout << " O   |" << endl;
                cout << "/|\\  |" << endl;
                cout << "/    |" << endl;
                cout << "     |" << endl;
                cout << "======" << endl;

                break;
            }
            case 0:
            {
                cout << " +---+" << endl;
                cout << " |   |" << endl;
                cout << " O   |" << endl;
                cout << "/|\\  |" << endl;
                cout << "/ \\  |" << endl;
                cout << "     |" << endl;
                cout << "======" << endl;
                cout << "\nGame over you have used all of your tries.\nHangman is hanged";

                break;
            }

            default:
                cout << "Error";
            }
        }
    }

    return 0;
}
