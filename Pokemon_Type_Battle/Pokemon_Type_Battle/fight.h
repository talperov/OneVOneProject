#ifndef FIGHT_H
#define FIGHT_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <time.h> 


typedef enum items_value
{
	KNIFE = 19, 
	GRENADE = 43, 
	PISTOL = 22,
	HEALTH = 50, 
	DAMAGE_REDUCTION = 25

}ItemValue;

typedef struct player
{
	char name[30];
	double health;
	double xp;
	ItemValue items[5];
}Player;



 
void generate_items(Player* user);

void generate_Opponent_items(Player* Opponent); 

const char* get_item_name(ItemValue item);

void create_menu();

void create_player(Player* user);

void create_AI_player(Player* Opponent);

extern const char* titles[99];

void start_game(); // Continue later focus on other projects.

void decide_who_goes_first(Player* user, Player* Opponent, int* User, int* AI);

void image_faces();

void game_logic_round(Player* user, Player* Opponent, int* User, int* AI, int*round ); 








#endif