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

void game_logic(Player* user, Player* Opponent, int* User, int* AI, int* round)
{
    char choice = '\0';
    int pick = 0;
    int userDamageReductionActive = 0;
    int opponentDamageReductionActive = 0;
    int Xp= 0;

    // Ensure health is reset to maxHealth at the start
    user->health = user->maxHealth;
    Opponent->health = Opponent->maxHealth;

    do
    {
        printf("=== Round %d ===\n", *round);
        image_faces();
        printf("User health: %.2f, Opponent health: %.2f\n", user->health, Opponent->health);

        if (*User == 1)
        {
            printf("Your turn!\n");
            printf("Select an item from your inventory:\n");
            for (int i = 0; i < 5; i++)
            {
                printf("%d. %s\n", i + 1, get_item_name(user->items[i]));
            }

            do
            {
                printf("Enter the number of the item you want to use (1-5): ");
                scanf("%d", &pick);

                if (pick < 1 || pick > 5)
                {
                    printf("Invalid choice! Please select a valid item.\n");
                }
            } while (pick < 1 || pick > 5);

            ItemValue selectedItem = user->items[pick - 1];
            printf("Using item: %s\n", get_item_name(selectedItem));

            if (selectedItem == HEALTH)
            {
                user->health += 50;
                if (user->health > user->maxHealth)
                {
                    user->health = user->maxHealth;
                }
                printf("Your health increased to: %.2f\n", user->health);
            }
            else if (selectedItem == DAMAGE_REDUCTION)
            {
                printf("Damage reduction activated! Opponent's next attack will be reduced.\n");
                userDamageReductionActive = 1;
            }
            else
            {
                double damage = selectedItem;

                if (rand() % 6 == 0) // 1 in 6 chance for a headshot
                {
                    damage *= 2; // Double the damage for a headshot
                    printf("Headshot! Critical damage dealt.\n");
                }

                Opponent->health -= damage;
                if (Opponent->health < 0)
                {
                    Opponent->health = 0;
                }
                printf("Opponent's health: %.2f\n", Opponent->health);
            }
        }
        else if (*AI == 1)
        {
            printf("AI's turn!\n");
            printf("AI is selecting a random item from inventory...\n");
            pick = rand() % 5 + 1;
            ItemValue selectedItem = Opponent->items[pick - 1];
            printf("AI used item: %s\n", get_item_name(selectedItem));

            if (selectedItem == HEALTH)
            {
                Opponent->health += 50;
                if (Opponent->health > Opponent->maxHealth)
                {
                    Opponent->health = Opponent->maxHealth;
                }
                printf("Opponent's health increased to: %.2f\n", Opponent->health);
            }
            else if (selectedItem == DAMAGE_REDUCTION)
            {
                printf("Damage reduction activated! Your next attack will be reduced.\n");
                opponentDamageReductionActive = 1;
            }
            else
            {
                double damage = selectedItem;

                if (rand() % 6 == 0) // 1 in 6 chance for a headshot
                {
                    damage *= 2; // Double the damage for a headshot
                    printf("Headshot! Critical damage dealt by AI.\n");
                }

                if (userDamageReductionActive)
                {
                    damage /= 3;
                    userDamageReductionActive = 0;
                }

                user->health -= damage;
                if (user->health < 0)
                {
                    user->health = 0;
                }
                printf("Your health: %.2f\n", user->health);
            }
        }

        if (user->health == 0 || Opponent->health == 0)
        {
            printf("Game Over!\n");
            if (user->health == 0)
            {
                printf("You lost! Opponent wins.\n");
                break;
            }
            else
            {
                printf("You win! Opponent is defeated.\n");
                user->xp += 25.0;
                if (user->xp == user->maxxp)
                {
                    Xp++;
                    printf("You have leveled up to Xp level:%d\n", Xp); 
                    user->xp *= 0;
                    //MAKE FUNCTION TO GIVE THREE SEPERATE PATHS;
                   // increase item spot every 5 level || shield at like XPlevel 2 and so on increase by 20
                }
            }

            char pop = '\0';
            printf("Would you like to continue playing and head to the next level?\n");
            printf("(Y/N): \n");
            scanf(" %c", &pop);
            if (pop == 'Y' || pop == 'y')
            {
                if (Opponent->maxHealth > 0 && user->maxHealth > 0)
                {
                    user->maxHealth += 10;
                    Opponent->maxHealth *= 1.25; 
                }
                else
                {
                    user->maxHealth = 100.0;
                    Opponent->maxHealth = 100.0; 
                }
                Opponent->health = Opponent->maxHealth; 
                user->health = user->maxHealth; 
                (*round)++;
                game_logic(user, Opponent, User, AI, round); 
                return; 
            }
            else if (pop == 'N' || pop == 'n')
            {
                printf("Ending game.\n");
                break;
            }
        }

        if (*User == 1)
        {
            *User = 0;
            *AI = 1;
        }
        else
        {
            *User = 1;
            *AI = 0;
        }

        printf("Do you want to continue to the next round? (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'Y' || choice == 'y')
        {
            (*round)++;
        }
        else if (choice == 'N' || choice == 'n')
        {
            printf("Game ended by the user.\n");
            break;
        }
        else
        {
            printf("Invalid input! Ending the game.\n");
            break;
        }

    } while (1);
}





