#ifndef __MORPION__H__
#define __MORPION__H__
#define ARRAY_SIZE 3

typedef struct Players
{
	int id;
	char namePlayer[50];
	char sign;
} Players;

Players informationPlayer(Players p,int id);
Players *gameStart(Players *p1, Players *p2);
int advicePlayers(Players p,int test[]);

void showPlayers(Players p);
void showPlateau(char tab[][ARRAY_SIZE]);
void affectModelInBox(char box[][ARRAY_SIZE], int numberCase, Players p);
void verifieCondition(char box[][ARRAY_SIZE], Players player);
void action(Players *p, char plateau[][ARRAY_SIZE],int test[]);

static int boxCase = 0;
#endif