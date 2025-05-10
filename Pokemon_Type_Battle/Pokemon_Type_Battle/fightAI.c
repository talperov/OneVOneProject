#include "fight.h"

void create_AI_player(Player* Opponent)
{
    int pick = rand() % 99;
    strncpy(Opponent->name, titles[pick], sizeof(Opponent->name) - 1);
    Opponent->name[sizeof(Opponent->name) - 1] = '\0'; // Ensure null-termination

    Opponent->health = 100.0;
    Opponent->maxHealth = 100.0;
    Opponent->xp = 0.0;

    generate_Opponent_items(Opponent);
    
    printf("Your ENEMY is %s!\n", Opponent->name);
    printf("Opponents Starting Health: %.2lf\n", Opponent->health);
    printf("Opponents items: ");

    for (int i = 0; i < 5; i++)
    {
        printf("%d. %s", i + 1, get_item_name(Opponent->items[i]));
        if (i < 4) 
        {
            printf(", "); 
        }
    } 
    printf("\n"); 
    system("pause");
}

void generate_Opponent_items(Player* Opponent) 
{
    for (int i = 0; i < 5; i++)
    {
        int random_item = rand() % 5;
        switch (random_item)
        {
        case 0:
            Opponent->items[i] = KNIFE;
            break;
        case 1:
            Opponent->items[i] = GRENADE;
            break;
        case 2:
            Opponent->items[i] = PISTOL;
            break;
        case 3:
            Opponent->items[i] = HEALTH;
            break;
        case 4:
            Opponent->items[i] = DAMAGE_REDUCTION;
            break;
        }
        printf("Generated item %d: %s\n", i + 1, get_item_name(Opponent->items[i]));
    }
}



const char* titles[99] = { 
        "Dr. Jekyll and Mr. Hyde", "Dracula", "Dubliners", "Emma", "Ethan Frome", "Frankenstein",
        "Great Expectations", "Gulliver's Travels", "Heart of Darkness", "Jane Eyre",
        "Jude the Obscure", "Kidnapped", "Kim", "Lady Audley's Secret", "Lady Susan",
        "Lorna Doone", "Madame Bovary", "Main Street", "Middlemarch", "Moby Dick",
        "Mrs. Dalloway", "My Antonia", "Nana", "North and South", "Northanger Abbey",
        "Nostromo", "Notes from Underground", "O Pioneers!", "Oliver Twist", "Persuasion",
        "Peter and Wendy", "Portrait of a Lady", "Pride and Prejudice", "Ruth",
        "Sense and Sensibility", "Silas Marner", "Sister Carrie", "Sons and Lovers",
        "Tale of Two Cities", "Tess of the D'Urbervilles", "The Age of Innocence",
        "The Awakening", "The Beautiful and Damned", "The Brothers Karamazov",
        "The Forsyte Saga", "The House of Mirth", "The House of the Seven Gables",
        "The Jungle", "The Last of the Mohicans", "The Magic Mountain",
        "The Mayor of Casterbridge", "The Mill on the Floss", "The Picture of Dorian Gray",
        "The Professor", "The Red Badge of Courage", "The Scarlet Letter",
        "The Secret Agent", "The Secret Garden", "The Sorrows of Young Werther",
        "The Tenant of Wildfell Hall", "The Three Musketeers", "The Time Machine",
        "The Turn of the Screw", "The Voyage Out", "The War of the Worlds",
        "The Warden", "The Waste Land", "The Woman in White", "This Side of Paradise",
        "Through the Looking Glass", "To the Lighthouse", "Tom Sawyer", "Trilby",
        "Tropic of Cancer", "Twenty Thousand Leagues", "Ulysses", "Under the Greenwood Tree",
        "Vanity Fair", "Villette", "Washington Square", "Wuthering Heights", "Youth",
        "Zuleika Dobson", "The Call of the Wild", "White Fang", "The Sea-Wolf", "Martin Eden",
        "The Iron Heel", "A Daughter of the Snows", "Burning Daylight", "The Star Rover",
        "The Valley of the Moon", "The Game", "The Mutiny of the Elsinore", "The Night-Born",
        "The Son of the Wolf", "Before Adam", "The Abysmal Brute", "Michael, Brother of Jerry"
       
};



