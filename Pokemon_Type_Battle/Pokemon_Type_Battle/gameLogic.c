#include "fight.h"


void create_menu()

{
    printf("===============WELCOME TO ONE ON ONE MASTA WOMBO COMBO FIGHTSU===============\n");
    printf("       =========================ENJOY THE GAME==========================\n");
    system("pause");
    system("cls");
}

void decide_who_goes_first(Player* user, Player* Opponent, int* User, int* AI)
{   
  *User = 0;
 *AI = 0;
    int choice = 0;
    do
    {
        printf("Who would like to go first?\n");
        printf("1. User (YOU)\n");
        printf("2. Opponent (AI)\n");
        printf("3. Randomize\n");
        printf("Select your choice 1-3: \n");
        scanf("%d", &choice);
        
        if (choice == 1)
        {
            *User = 1;
            *AI = 0;

            printf("User (YOU) is starting first. . .\n");
           
        }
        else if (choice == 2)
        {
            *User = 0;
            *AI = 1;
            printf("Opponent (AI) is starting first. . .\n");

        }
        else if (choice == 3)
        {
            choice = 2;
            choice = rand() % 2 + 1;
            if (choice == 1)
            {
                *User = 1;
                *AI = 0;

                printf("User (YOU) is starting first. . .\n");
            }
            else if (choice == 2)
            {
                *User = 0;
                *AI = 1;
                printf("Opponent (AI) is starting first. . .\n");
            }
        }
        else
        {
            printf("Select a valid choice!\n");
            system("pause");
            system("cls");
        }
    } while (choice < 1 || choice > 3);
}

void image_faces()
{
    printf("       _.--\"\"--._       \n");
    printf("     .'          `.     \n");
    printf("    /   O      O   \\    \n");
    printf("   |    \\  ^^  /    |   \n");
    printf("   \\     `----'     /   \n");
    printf("    `. _______ .'  /  \n");
    printf("      //_____\\\\      \n");
    printf("     (( ____ ))     \n");
    printf("      `------'      \n");
    printf("================================\n");
    printf("      .--\"\"--.      \n");
    printf("     /        \\     \n");
    printf("    |  O    O  |    \n");
    printf("    \\   .--.   /    \n");
    printf("     '. \\__/ .'     \n");
    printf("       `----'       \n");
    printf("      /  ()  \\      \n");
    printf("     /________\\     \n");
    printf("    |__________|    \n");
}

void game_logic_round(Player* user, Player* Opponent, int* User, int* AI, int* round)
{
    char choice = '\0';
    *round = 0;
    do
    {
        //function




        if (choice == 'Y' || 'y')
        {
            *round = -1;
            break;
        }
        else
        {
            continue;
        }
        
        *round++; 
    } while (*round != -1);
}