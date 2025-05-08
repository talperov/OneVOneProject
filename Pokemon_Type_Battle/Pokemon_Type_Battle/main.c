#include "fight.h"


int main(void)
{
	srand((unsigned int)time(NULL));
	Player* Opponent = malloc(sizeof(Player)); 
	Player user = { 0 };
	int User, AI;

	
	create_menu(); 
	create_player(&user); 
	create_AI_player(Opponent);
	decide_who_goes_first(&user, Opponent, &User, &AI);
	image_faces();
	free(Opponent);
		


	return 0;
}

/*
* STEPS TO DO
* Amount of uses before allowed to use again.
* Randomize who starts first
* After every round beaten save stats and do stuff with XP
* Upgrade the Ai by something like 1.25x every stat or decision making or arsenal like seperate
* Reset the Health every round.
* Make turns switch.
* 

Before i make some of these I need to implement actual game logic.

*/