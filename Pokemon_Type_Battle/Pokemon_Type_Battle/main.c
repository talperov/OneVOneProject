#include "fight.h"


int main(void)
{
	srand((unsigned int)time(NULL));
	Player* Opponent = malloc(sizeof(Player));
	Player user = { 0 };
	int User, AI, round = 1;


	create_menu();
	create_player(&user);
	create_AI_player(Opponent);
	decide_who_goes_first(&user, Opponent, &User, &AI);
	game_logic(&user, Opponent, &User, &AI, &round);
	free(Opponent);



	return 0;
}

/*
* STEPS TO DO
* After every round beaten save stats and do stuff with XP
* (Things XP can do cap is level 10)
* (XP things: increase item spot every 5 level, shield at like XPlevel 2 and so on increase by 20,
* add more weapons
* clean up the code to make it cleaner
*/

/*
THINGS TO COMPLETE THE GAME
Finish Xp rewarding and loophole.
save stats if closed, and reopen on previous round closed.
Add more weapons, idealy like 10 so randomization is more important
Clean the code readability such as add comments.

IN TOTAL(); HAVE FOUR MAIN OBJECTIVES LEFT.
ANYTHING optional goes into STEPS TO DO.
THINGS TO COMPLETE THE GAME are required.
*/
