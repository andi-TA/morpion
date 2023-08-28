#include <stdio.h>
#include <stdlib.h>
#include "morpion.h"
#define ARRAY_SIZE 3


/**
 * fonction principale du jeu 
 * 
*/
Players *gameStart(Players *p1, Players *p2)
{
	int tourP1 = 0;
	int tourP2 = 0;

	int p1Value = 0;
	int p2Value = 0;

	int value1 = 0;
	int value2 = 0;

	int test[9] = {0};

	char plateau[ARRAY_SIZE][ARRAY_SIZE] = {' '};

	while (tourP2 == tourP1)
	{
		tourP1 = ((rand() % 6) + 1);
		tourP2 = ((rand() % 6) + 1);
	}

	if (tourP2 < tourP1)
	{
		printf("\nJoueur(%d) <%s> commence\n\n", p1->id, p1->namePlayer);

		for (int i = 0; i <= 4; ++i)
		{
			if (i <= ARRAY_SIZE)
			{
				action(p1, plateau, test);

				action(p2, plateau, test);
			}
			else
			{
				action(p1, plateau, test);
			}
		}
		printf("\n------------Match egaliter--------------\n");
	}
	else
	{
		printf("\nJoueur(%d) <%s> commence\n\n", p2->id, p2->namePlayer);

		for (int i = 0; i <= 4; ++i)
		{
			if (i <= ARRAY_SIZE)
			{
				action(p2, plateau, test);

				action(p1, plateau, test);
			}
			else
			{
				action(p2, plateau, test);
			}
		}
		printf("\n------------Match egaliter--------------\n");
	}
	exit(EXIT_SUCCESS);
}

/**
 * demande au joueur leur coup et les affectés dans les cases correspondantes
*/
void action(Players *p, char plateau[][ARRAY_SIZE], int test[])
{
	int value = advicePlayers(*p, test);
	affectModelInBox(plateau, value, *p);
	showPlateau(plateau);
}

/**
 * demander au joueurs leurs
 * n != n(precendent)
*/
int advicePlayers(Players p, int test[])
{
	int cases = 0;

	printf("Joueur(%d) <%s>\n", p.id, p.namePlayer);

	printf("Entrer votre prochain coup 0-9 : ");
	scanf("%d", &cases);

	for (int i = 0; i <= boxCase; i++)
	{
		if (test[i] == cases || cases > 9 || cases < 1)
		{
			while (test[i] == cases || cases > 9 || cases < 1)
			{
				printf("Joueur(%d) <%s>\n", p.id, p.namePlayer);
				printf("veuiller entrer un nombre different du precendent et le nombre doit etre superieur 0 et inferieur à 10 : ");
				scanf("%d", &cases);
				i = 0;
			}
			i = 0;
		}
	}

	test[boxCase] = cases;
	boxCase++;

	return cases;
}

/**
 * Verifie conditions si le joueur 1 ou 2 est gagnant
 *
 * */
void verifieCondition(char box[][ARRAY_SIZE], Players player)
{
	if (box[0][0] == player.sign && box[0][1] == player.sign && box[0][2] == player.sign)
	{
		printf("\n\n Felicitation vous avez gagnge \n Joueur(%d) <%s> gagne", player.id, player.namePlayer);
		exit(EXIT_SUCCESS);
	}

	if (box[1][0] == player.sign && box[1][1] == player.sign && box[1][2] == player.sign)
	{
		printf("\n\n Felicitation vous avez gagnge \n Joueur(%d) <%s> gagne", player.id, player.namePlayer);
		exit(EXIT_SUCCESS);
	}

	if (box[2][0] == player.sign && box[2][1] == player.sign && box[2][2] == player.sign)
	{
		printf("\n\n Felicitation vous avez gagnge \n Joueur(%d) <%s> gagne", player.id, player.namePlayer);
		exit(EXIT_SUCCESS);
	}

	if (box[0][0] == player.sign && box[1][0] == player.sign && box[2][0] == player.sign)
	{
		printf("\n\n Felicitation vous avez gagnge \n Joueur(%d) <%s> gagne", player.id, player.namePlayer);
		exit(EXIT_SUCCESS);
	}

	if (box[0][1] == player.sign && box[1][1] == player.sign && box[2][1] == player.sign)
	{
		printf("\n\n Felicitation vous avez gagnge \n Joueur(%d) <%s> gagne", player.id, player.namePlayer);
		exit(EXIT_SUCCESS);
	}

	if (box[0][2] == player.sign && box[1][2] == player.sign && box[2][2] == player.sign)
	{
		printf("\n\n Felicitation vous avez gagnge \n Joueur(%d) <%s> gagne", player.id, player.namePlayer);
		exit(EXIT_SUCCESS);
	}

	if (box[0][0] == player.sign && box[1][1] == player.sign && box[2][2] == player.sign)
	{
		printf("\n\n Felicitation vous avez gagnge \n Joueur(%d) <%s> gagne", player.id, player.namePlayer);
		exit(EXIT_SUCCESS);
	}

	if (box[0][2] == player.sign && box[1][1] == player.sign && box[2][0] == player.sign)
	{
		printf("\n\n Felicitation vous avez gagnge \n Joueur(%d) <%s> gagne", player.id, player.namePlayer);
		exit(EXIT_SUCCESS);
	}
}

/**
 * affecte le coup du joueur dans la case du plateau de jeu
 *
 * */
void affectModelInBox(char box[][ARRAY_SIZE], int numberCase, Players p)
{

	verifieCondition(box, p);

	if (numberCase < 4)
	{
		box[0][numberCase - 1] = p.sign;
		verifieCondition(box, p);
	}
	else if (numberCase >= 4 && numberCase < 7)
	{
		box[1][numberCase - 4] = p.sign;
		verifieCondition(box, p);
	}
	else
	{
		box[2][numberCase - 7] = p.sign;
		verifieCondition(box, p);
	}
}

void showPlateau(char tab[][ARRAY_SIZE])
{
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		for (int j = 0; j < ARRAY_SIZE; ++j)
		{
			printf("[%c]", tab[i][j]);
		}
		printf("\n");
	}
}

Players informationPlayer(Players p, int id)
{
	p.id = id;

	printf("Nom joueur : ");
	scanf("%s", p.namePlayer);

	printf("caractere de jeux au quelle vous joueur(x,o,a,b,X,O...) : ");
	scanf("%s", &(p.sign));

	return p;
}

void showPlayers(Players p)
{
	printf("Joueur %d\n  Nom : %s\n", p.id, p.namePlayer);
}
