#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_WORD_LENGTH 55
#define MAX_TRIES 6

struct hangman {
    char wordList[MAX_WORD_LENGTH];
    char hint[MAX_WORD_LENGTH];
};

void displayword(const char userInput[], const bool alphabets[]);
void drawman(int tries);

int main() {
    int tries = 0;
    int random;
srand(time(NULL));
struct hangman data[] = {
    {"pizza", "famous Italian"},
    {"elephant", "large mammal with a trunk"},
    {"computer", "electronic device for processing data"},
    {"guitar", "musical instrument with strings"},
    {"beach", "sandy shore by the sea"},
    {"apple", "fruit with a core"},
    {"mountain", "large natural elevation"},
    {"cat", "feline mammal"},
    {"jazz", "genre of music"},
    {"football", "popular sport"},
    {"sunflower", "bright yellow flower"},
    {"chocolate", "sweet treat made from cocoa"},
    {"universe", "all existing matter and space"},
    {"rainbow", "colorful arc in the sky"},
    {"coffee", "popular caffeinated beverage"},
    {"volcano", "mountain that erupts"},
    {"diamond", "precious gemstone"},
    {"moon", "natural satellite of Earth"},
    {"book", "written or printed work"},
    {"robot", "automated machine"},
    {"oxygen", "essential gas for life"},
    {"fireworks", "colorful explosions"},
    {"dragon", "mythical creature"},
    {"camera", "device for capturing images"},
    {"bicycle", "two-wheeled vehicle"},
    {"pirate", "sea-going thief"},
    {"sushi", "Japanese cuisine"},
    {"spaceship", "vehicle for outer space"},
    {"puzzle", "brainteaser"},
    {"castle", "fortified residence"},
    {"rainforest", "dense jungle"},
    {"solar system", "sun and its planetary system"},
    {"wizard", "magical person"},
    {"waterfall", "cascade of water"},
    {"desert", "arid land"},
    {"helicopter", "aircraft with rotating blades"},
    {"skyscraper", "tall building"},
    {"tiger", "large striped feline"},
    {"microscope", "instrument for viewing small objects"},
    {"submarine", "underwater vessel"},
    {"treasure", "hidden riches"},
    {"vampire", "undead creature"},
    {"telescope", "instrument for observing distant objects"},
    {"moonlight", "light from the moon"},
    {"whale", "large marine mammal"},
    {"planet", "celestial body orbiting a star"},
    {"orchestra", "group of musicians"},
    {"snowflake", "ice crystal"},
    {"wizard", "magical person"},
    {"hurricane", "powerful storm"},
    {"butterfly", "insect with colorful wings"},
    {"mermaid", "mythical sea creature"}
};


random=rand()%sizeof(data)/sizeof(data[0]) ;
   const char* secretword = data[random].wordList;
       const char* hint = data[random].hint;

    char userInput[MAX_WORD_LENGTH] = {0};
    bool alphabets[26] = {false};

    printf("\n\t\t \"Welcome to hangman\"  \n");
    printf("\t\t Hint :%s\n", hint);

    while (tries < MAX_TRIES) {
        char guess;
        bool found = false;

        printf("\n");
        displayword(userInput, alphabets); //userinput ko dikhane ke liye
        drawman(tries); //hangman ko dikhane ke liye

        printf("ENTER LETTER: ");
        scanf(" %c", &guess);

        guess = tolower(guess);

        if (alphabets[guess - 'a']) {
            printf("You have already guessed this letter. Try again.\n");
            continue;
        }

        alphabets[guess - 'a'] = true;

        for (int i = 0; i < strlen(secretword); i++) {
            if (guess == secretword[i]) {
                found = true;
                userInput[i] = guess;
            }
        }

        tries++;

        if (found) {
            printf("Good job!\n");
        } else {
            printf("Sorry, %c is not in the word.\n", guess);
        }

        if (strcmp(secretword, userInput) == 0) {
            printf("Congratulations, you've guessed the word: %s\n", secretword);
            break;
        }
    }

    if (tries == MAX_TRIES) {
        printf("Sorry, you've run out of tries. The word was: %s\n", secretword);
    }

    return 0;
}

void displayword(const char userInput[], const bool alphabets[]) {
    for (int i = 0; userInput[i] != '\0'; i++) {
        if (alphabets[userInput[i] - 'a']) {
            printf("%c ", userInput[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void drawman(int tries) {
    const char* hangmanParts[]
        = { "  ____",
            "  |  |",
            "  |  O",
            "  | /|\\",
            "  | / \\", 
            "____|_____" };

    printf("\n");
    for (int i = 0; i <= tries; i++) {
        printf("%s\n", hangmanParts[i]);
    }
}
