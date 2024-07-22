#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Global variables to store positions of player1 and player2
int player1 = 0;
int player2 = 0;

// Function to print the board
void printboard() {
    int board[101];
    for (int i = 1; i <= 100; i++) {
        board[i] = i;
    }

    int alt = 0;
    int iterlr = 101;
    int iterrl = 80;
    int val = 100;
    while (val--) {
        if (alt == 0) {
            iterlr--;
            if (iterlr == player1) {
                printf("#P1  ");
            } else if (iterlr == player2) {
                printf("#P2  ");
            } else {
                printf("%d  ", board[iterlr]);
            }
            if (iterlr % 10 == 1) {
                printf("\n\n");
                alt = 1;
                iterlr -= 10;
            }
        } else {
            iterrl++;
            if (iterrl == player1) {
                printf("#P1  ");
            } else if (iterrl == player2) {
                printf("#P2  ");
            } else {
                printf("%d  ", board[iterrl]);
            }
            if (iterrl % 10 == 0) {
                printf("\n\n");
                alt = 0;
                iterrl -= 30;
            }
        }
        if (iterrl == 10) break;
    }
    printf("\n");
}

// Function to roll a six-sided die
int rollDie() {
    return rand() % 6 + 1;
}

// Function to move the player
int movePlayer(int currentPlayer, int roll) {
    int newPosition = currentPlayer + roll;
    // Define the positions of snakes and ladders on the board
    int snakladers[101] = {0}; // Initialize all positions to 0

    // Snakes and ladders definition
    snakladers[3] = -20;
    snakladers[13] = 10;
    snakladers[34] = 30;
    snakladers[10] = -4;
    snakladers[23] = -60;
    snakladers[63] = -50;

    int newSquare = newPosition + snakladers[newPosition];
    if (newSquare > 100) {
        return currentPlayer; // Player cannot move beyond square 100
    }

    return newSquare;
}

int main() {
    srand(time(0)); // Initialize random seed
    int won = 0;
    int currentplayer = 1;

    printf("\tSnake and Ladders Game\n");

    while (!won) {
        printf("\nPlayer %d, press Enter to roll the die...", currentplayer);
        getchar();
        int roll = rollDie();
        printf("You rolled a %d\n", roll);

        if (currentplayer == 1) {
            player1 = movePlayer(player1, roll);
            printf("Player 1 is now at square %d.\n\n", player1);
            printboard();
            if (player1 == 100) {
                printf("Player 1 wins!\n");
                won = 1;
            }
        } else {
            player2 = movePlayer(player2, roll);
            printf("Player 2 is now at square %d.\n\n", player2);
            printboard();
            if (player2 == 100) {
                printf("Player 2 wins!\n");
                won = 1;
            }
        }

        // Switch to the other player
        currentplayer = (currentplayer == 1) ? 2 : 1;
    }

    return 0;
}
