#include "fight.h"

void create_player(Player* user)
{
    user->health = 100.0;
    user->xp = 0.0;

    for (int i = 0; i < 5; i++)
    {
        user->items[i] = 0;
    }

    printf("Enter your name: ");
    scanf("%29s", user->name);
    generate_items(user);
    system("pause");
    system("cls");
    printf("Hello %s!\n", user->name);
    printf("Starting Health: %.2lf\n", user->health);
    printf("Starting Xp: %.2lf\n", user->xp);
    printf("Starting items: ");

    for (int i = 0; i < 5; i++)
    {
        printf("%d. %s", i + 1, get_item_name(user->items[i]));
        if (i < 4)
        {
            printf(", ");
        }
    }
    printf("\n");
}

void generate_items(Player* user)
{
    for (int i = 0; i < 5; i++)
    {
        int random_item = rand() % 5;
        switch (random_item)
        {
        case 0:
            user->items[i] = KNIFE;
            break;
        case 1:
            user->items[i] = GRENADE;
            break;
        case 2:
            user->items[i] = PISTOL;
            break;
        case 3:
            user->items[i] = HEALTH; 
            break;
        case 4:
            user->items[i] = DAMAGE_REDUCTION; 
            break;
        }
        printf("Generated item %d: %s\n", i + 1, get_item_name(user->items[i]));  
   }
}

const char* get_item_name(ItemValue item)
{
    switch (item)
    {
    case KNIFE:
        return "KNIFE";
    case GRENADE:
        return "GRENADE";
    case PISTOL:
        return "PISTOL";
    case HEALTH:
        return "HEALTH";
    case DAMAGE_REDUCTION:
        return "DAMAGE REDUCTION";
    default:
        return "UNKNOWN ITEM";
    }
}


