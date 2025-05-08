#include "fight.h"


int main(void)
{
	srand((unsigned int)time(NULL));
	Player* Opponent = malloc(sizeof(Player)); 
	Player user = { 0 };
	int User, AI, round;

	
	create_menu();  
	create_player(&user); 
	create_AI_player(Opponent);
	decide_who_goes_first(&user, Opponent, &User, &AI); 
	game_logic_round(&user, Opponent, &User, &AI, &round);
	free(Opponent); 
		


	return 0;
}

/*
* STEPS TO DO
* After every round beaten save stats and do stuff with XP
* Upgrade the Ai by something like 1.25x every stat or decision making or arsenal like seperate
* Reset the Health every round.
* add an option to go to next level
* add more weapons
* clean up the code to make it cleaner
*
* 



*/