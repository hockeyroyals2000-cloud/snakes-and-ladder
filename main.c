#include <studio.h>

int main(){// C program for creating & simulating a 3-player Snake & Ladder Game
// Original Author: Akash Mahesh Ganjal
// Modified for 3 players 

// Rules:
// 1. The game will begin with any dice value.
// 2. If a 6 appears, the player gets another turn.
// 3. Only the location of the current player is shown on the board.
// 4. Snakes: 99→1, 65→40, 25→9
// 5. Ladders: 70→93, 60→83, 13→42

#include <stdio.h>
#include <stdlib.h>

int rd() {
    int rem;
A:
    rem = rand() % 7;
    if (rem == 0)
        goto A;
    else
        return rem;
}

void displaychart(int curp, char player[4]) {
    int i, j, t, c, sft = 0, diceres;

    if (curp == 100) {
        printf("***** Congratulations *****\n\nPlayer %s wins!\n", player);
        scanf("%*s");
        exit(0);
    }

    for (i = 10; i > 0; i--) {
        t = i - 1;
        if ((sft % 2) == 0) {
            c = 0;
            for (j = 10; j >= 1; j--) {
                diceres = (i * j) + (t * c++);
                if (curp == diceres)
                    printf("%s\t", player);
                else
                    printf("%d\t", diceres);
            }
            sft++;
        } else {
            c = 9;
            for (j = 1; j <= 10; j++) {
                diceres = (i * j) + (t * c--);
                if (curp == diceres)
                    printf("%s\t", player);
                else
                    printf("%d\t", diceres);
            }
            sft++;
        }
        printf("\n\n");
    }

    printf("--------------------------------------------------------------------------\n");
}

int check_snakes_ladders(int pos) {
    switch (pos) {
        // Snakes
        case 99: return 1;
        case 65: return 40;
        case 25: return 9;
        // Ladders
        case 70: return 93;
        case 60: return 83;
        case 13: return 42;
        default: return pos;
    }
}

int main() {
    int dice;
    int cur_pos1 = 0, cur_pos2 = 0, cur_pos3 = 0;
    char ch;

    while (1) {
        printf("\n\t\t** SNAKE AND LADDER GAME **\n\t\tModified for 3 Players\n");
        printf("Snakes:- 25→9, 65→40, 99→1\nLadders:- 13→42, 60→83, 70→93\n");
        printf("Choose your option:\n");
        printf("1. Player 1 plays\n");
        printf("2. Player 2 plays\n");
        printf("3. Player 3 plays\n");
        printf("4. Exit\n");
        scanf(" %c", &ch);

        switch (ch) {
            case '1':
                dice = rd();
                system("cls || clear");
                printf("\t\t\tDice = %d\n\n", dice);
                if (dice == 6)
                    printf("Dice=6: Player 1 gets another chance after this!\n");
                cur_pos1 += dice;
                if (cur_pos1 > 100) {
                    cur_pos1 -= dice;
                    printf("Range exceeded for Player 1.\n");
                } else {
                    cur_pos1 = check_snakes_ladders(cur_pos1);
                }
                displaychart(cur_pos1, "$P1$");
                printf("Player 2 position: %d\n", cur_pos2);
                printf("Player 3 position: %d\n", cur_pos3);
                break;

            case '2':
                dice = rd();
                system("cls || clear");
                printf("\t\t\tDice = %d\n\n", dice);
                if (dice == 6)
                    printf("Dice=6: Player 2 gets another chance after this!\n");
                cur_pos2 += dice;
                if (cur_pos2 > 100) {
                    cur_pos2 -= dice;
                    printf("Range exceeded for Player 2.\n");
                } else {
                    cur_pos2 = check_snakes_ladders(cur_pos2);
                }
                displaychart(cur_pos2, "$P2$");
                printf("Player 1 position: %d\n", cur_pos1);
                printf("Player 3 position: %d\n", cur_pos3);
                break;

            case '3':
                dice = rd();
                system("cls || clear");
                printf("\t\t\tDice = %d\n\n", dice);
                if (dice == 6)
                    printf("Dice=6: Player 3 gets another chance after this!\n");
                cur_pos3 += dice;
                if (cur_pos3 > 100) {
                    cur_pos3 -= dice;
                    printf("Range exceeded for Player 3.\n");
                } else {
                    cur_pos3 = check_snakes_ladders(cur_pos3);
                }
                displaychart(cur_pos3, "$P3$");
                printf("Player 1 position: %d\n", cur_pos1);
                printf("Player 2 position: %d\n", cur_pos2);
                break;

            case '4':
                exit(0);
                break;

            default:
                printf("Invalid choice. Try again!\n");
        }
    }

    return 0;
}



    
