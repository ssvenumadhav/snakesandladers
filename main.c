#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int snakeladder(int pos)
{
    // Ladder positions
    if (pos == 1) return 38;
    else if (pos == 4) return 14;
    else if (pos == 8) return 30;
    else if (pos == 21) return 42;
    else if (pos == 28) return 76;
    else if (pos == 50) return 67;
    else if (pos == 71) return 92;
    else if (pos == 80) return 99;
    // Snake positions
    else if (pos == 97) return 78;
    else if (pos == 95) return 56;
    else if (pos == 88) return 24;
    else if (pos == 62) return 18;
    else if (pos == 48) return 26;
    else if (pos == 36) return 6;
    else if (pos == 32) return 10;
    else return pos; // Return the original position if no ladder or snake
}

void playGame()
{
    int p1pos = 0, p2pos = 0, p3pos = 0;
    int flag = 1;
    while (p1pos < 100 && p2pos < 100 && p3pos < 100)
    {
        int diceno = ((int)rand() % 6) + 1;

        if (flag == 1)
        {
            printf("Player 1's turn\n");
            printf("Rolled the dice: %d\n", diceno);
            if (p1pos + diceno <= 100)
            {
                p1pos += diceno;
                p1pos = snakeladder(p1pos);
            }
            printf("Player 1 moved to position: %d\n", p1pos);
            if (p1pos == 100)
            {
                printf("Player 1 wins!\n");
                break;
            }
            flag = 2;
        }
        else if (flag == 2)
        {
            printf("Player 2's turn\n");
            printf("Rolled the dice: %d\n", diceno);
            if (p2pos + diceno <= 100)
            {
                p2pos += diceno;
                p2pos = snakeladder(p2pos);
            }
            printf("Player 2 moved to position: %d\n", p2pos);
            if (p2pos == 100)
            {+
                printf("Player 2 wins!\n");
                break;
            }
            flag = 3;
        }
        else
        {
            printf("Player 3's turn\n");
            printf("Rolled the dice: %d\n", diceno);
            if (p3pos + diceno <= 100)
            {
                p3pos += diceno;
                p3pos = snakeladder(p3pos);
            }
            printf("Player 3 moved to position: %d\n", p3pos);
            if (p3pos == 100)
            {
                printf("Player 3 wins!\n");
                break;
            }
            flag = 1;
        }
    }
}

int main()
{
    srand(time(0));
    printf("Welcome to the Snake and Ladder game!\n");
    playGame();
    return 0;
}
