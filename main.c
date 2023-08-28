#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "morpion.h"

int main()
{
	/**
	 * Two players
	 */

	// initialisation du nombre aléatoire
	srand(time(NULL));

	Players p1 = {0, "", ' '};
	Players p2 = {0, "", ' '};
	Players *playersWin = NULL;

	while (p1.sign == p2.sign)
	{
		p1 = informationPlayer(p1,1);
		p2 = informationPlayer(p2,2);

		if (p1.sign == p2.sign)
		{
			printf("\nVeuillez bien respecter que le signe ne soi pas le meme (X !== X) \n");
		}
	}

	playersWin = gameStart(&p1, &p2);

	return 0;
}
