#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <string.h>

int playerfinishingposition(int player)
{
	if (player == 0)
		return 56;
	else
		return (57 + (6 * player));
}

int inputinteger()
{
	int i;
	char c;
	while (scanf_s(" %d", &i) != 1)
	{
		puts("CAREFUL!");
		scanf_s(" %d", &i);
		while ((c = getchar()) != '\n' && c != EOF); // Flush stdin
	}
	return i;
}
void printrolls(int dice[])
{
	for (int x = 0; x < 3; x++)
	{
		if (dice[x] != 0)
			printf("\n Roll %d: %d", x + 1, dice[x]);
	}
}
void printinstructions()
{
	printf("Here is a general introduction to LUDO and how to play it\n\n");

	printf("Each player chooses one of the 4 colours(green, yellow, red or blue) and places the 4 pieces of that colour in the corresponding starting circle. A single die is thrown to determine movement.\n\n");


	printf("Play: \n\n");


	printf("Each throw, the player decides which piece to move.A piece simply moves in a clockwise direction around the track given by the number thrown.If no piece can legally move according to the number thrown, play passes to the next player.\n\n");

	printf("A throw of 6 gives another turn.\n\n");

	printf("A player must throw a 6 to move a piece from the starting circle onto the first square on the track.The piece moves 6 squares around the circuit beginning with the appropriately coloured start square(and the player then has another turn)\n\n");

	printf("If a piece lands on a piece of a different colour, the piece jumped upon is returned to its starting circle.\n\n");

	printf("A piece cannot land on a piece of the same colour. If there are no other options. The turn is skipped.\n\n\n");

	printf("Liberties taken by us :\n\n");

	printf("We have imposed certain restrictions to the code for the sake of simplicity.\n\n");
	printf("Not more than 6 pieces can occupy a safe spot at a time\n\n");



	printf("Winning: \n\n");

	printf("When a piece has circumnavigated the board, it proceeds up the home column.A piece can only be moved onto the home triangle by an exact throw.\n\n");

	printf("The first person to move all 4 pieces into the home triangle wins.\n\n");

	getch();
}
void printgeeti(int x, int y, int geeti[], int geetino[], int position)
{
	if ((((position % 13 == 0) || (position % 13 == 8)) || (position > 50)) && (position < 75) && (position != 57))
	{
		if ((position == 0) || (position == 47) || ((position > 50) && (position < 56)))
			printf("\x1b[41m");
		else if ((position == 13) || (position == 8) || ((position > 57) && (position < 63)))
			printf("\x1b[43m");
		else if ((position == 26) || (position == 21) || ((position > 63) && (position < 69)))
			printf("\x1b[42m");
		else if ((position == 39) || (position == 34) || ((position > 69) && (position < 75)))
			printf("\x1b[46m");

		switch (geeti[(x / 2) + (3 * y)])
		{
		case 0:
			printf("\x1b[31;1m");
			break;
		case 1:
			printf("\x1b[33;1m");
			break;
		case 3:
			printf("\x1b[36;1m");
			break;
		case 2:
			printf("\x1b[32;1m");
			break;
		}
		if (geeti[(x / 2) + (3 * y)] == -1)
			printf(" ");
		else if ((x % 2) == 0)
			printf("%d", geetino[(x / 2) + (3 * y)]);
		else
			printf("%c", 254);
	}
	else
	{
		switch (geeti[0])
		{
		case 0:
			printf("\x1b[31;1m");
			break;
		case 1:
			printf("\x1b[33;1m");
			break;
		case 3:
			printf("\x1b[36;1m");
			break;
		case 2:
			printf("\x1b[32;1m");
			break;
		}
		if (geeti[0] == -1)
			printf(" ");
		else if ((x == 0) || (x == 5) || ((x == 1) && (y == 1)))
			printf(" ");
		else if ((x == 1) && (y == 0))
			printf("%d", geetino[0]);
		else
			printf("%c", 219);
	}

	printf("\x1b[0m");
}
void linkPositions(int Posit[][46])
{
	for (int x = 0; x < 106; x++)                  // Initialisation
	{
		for (int y = 0; y < 46; y++)
		{
			Posit[x][y] = 1;
		}
	}

	for (int x = 7; x < 43; x++)                   // 0 1 2 3 4
	{
		for (int y = 19; y < 21; y++)
			Posit[x][y] = (x / 7) - 1;
	}
	for (int x = 43; x < 49; x++)                    // 5 6 7 8 9
	{
		for (int y = 4; y < 18; y++)
			Posit[x][y] = 10 - (y / 3);
	}

	for (int x = 43; x < 63; x++)                    // 10 11 12
	{
		for (int y = 1; y < 3; y++)
			Posit[x][y] = (x / 7) + 4;
	}

	for (int x = 57; x < 63; x++)                    // 13 14 15 16 17
	{
		for (int y = 4; y < 18; y++)
			Posit[x][y] = 12 + (y / 3);
	}
	for (int x = 50; x < 56; x++)                    // 58 59 60 61 62
	{
		for (int y = 4; y < 18; y++)
			Posit[x][y] = 57 + (y / 3);
	}
	for (int x = 64; x < 98; x++)                   // 18 19 20 21 22
	{
		for (int y = 19; y < 21; y++)
			Posit[x][y] = (x / 7) + 9;
	}

	for (int x = 99; x < 105; x++)                   // 23 24 25
	{
		for (int y = 19; y < 27; y++)
			Posit[x][y] = (y / 3) + 17;
	}

	for (int x = 64; x < 98; x++)                   // 26 27 28 29 30
	{
		for (int y = 25; y < 27; y++)
			Posit[x][y] = 39 - (x / 7);
	}

	for (int x = 64; x < 98; x++)                   // 26 27 28 29 30
	{
		for (int y = 22; y < 24; y++)
			Posit[x][y] = 77 - (x / 7);
	}

	for (int x = 57; x < 63; x++)                    // 31 32 33 34 35
	{
		for (int y = 28; y < 42; y++)
			Posit[x][y] = 22 + (y / 3);
	}

	for (int x = 43; x < 63; x++)                   // 36 37 38
	{
		for (int y = 43; y < 45; y++)
			Posit[x][y] = 44 - (x / 7);
	}

	for (int x = 43; x < 49; x++)                    // 39 40 41 42 43
	{
		for (int y = 28; y < 42; y++)
			Posit[x][y] = 52 - (y / 3);
	}

	for (int x = 50; x < 56; x++)                    // 70 71 72 73 74
	{
		for (int y = 28; y < 42; y++)
			Posit[x][y] = 83 - (y / 3);
	}

	for (int x = 1; x < 42; x++)                   // 44 45 46 47 48 49 
	{
		for (int y = 25; y < 27; y++)
			Posit[x][y] = 49 - (x / 7);
	}

	for (int x = 1; x < 42; x++)                   // 50 51 52 53 54 55 
	{
		for (int y = 22; y < 24; y++)
			Posit[x][y] = 50 + (x / 7);
	}

	for (int x = 1; x < 7; x++)                   // 57
	{
		for (int y = 19; y < 21; y++)
			Posit[x][y] = 57;
	}

	for (int x = 8; x < 14; x++)                 // 76
	{
		for (int y = 4; y < 6; y++)
			Posit[x][y] = 76;
	}

	for (int x = 29; x < 35; x++)                 // 77
	{
		for (int y = 4; y < 6; y++)
			Posit[x][y] = 77;
	}

	for (int x = 8; x < 14; x++)                 // 78
	{
		for (int y = 13; y < 15; y++)
			Posit[x][y] = 78;
	}

	for (int x = 29; x < 35; x++)                 // 79
	{
		for (int y = 13; y < 15; y++)
			Posit[x][y] = 79;
	}

	for (int x = 71; x < 77; x++)                 // 80
	{
		for (int y = 4; y < 6; y++)
			Posit[x][y] = 80;
	}

	for (int x = 92; x < 98; x++)                 // 81
	{
		for (int y = 4; y < 6; y++)
			Posit[x][y] = 81;
	}

	for (int x = 71; x < 77; x++)                 // 82
	{
		for (int y = 13; y < 15; y++)
			Posit[x][y] = 82;
	}

	for (int x = 92; x < 98; x++)                 // 83
	{
		for (int y = 13; y < 15; y++)
			Posit[x][y] = 83;
	}
	for (int x = 71; x < 77; x++)                 // 84
	{
		for (int y = 31; y < 33; y++)
			Posit[x][y] = 84;
	}
	for (int x = 92; x < 98; x++)                 // 85
	{
		for (int y = 31; y < 33; y++)
			Posit[x][y] = 85;
	}
	for (int x = 71; x < 77; x++)                 // 86
	{
		for (int y = 40; y < 42; y++)
			Posit[x][y] = 86;
	}
	for (int x = 92; x < 98; x++)                 // 87
	{
		for (int y = 40; y < 42; y++)
			Posit[x][y] = 87;
	}

	for (int x = 8; x < 14; x++)                 // 88
	{
		for (int y = 31; y < 33; y++)
			Posit[x][y] = 88;
	}
	for (int x = 29; x < 35; x++)                 // 89
	{
		for (int y = 31; y < 33; y++)
			Posit[x][y] = 89;
	}
	for (int x = 8; x < 14; x++)                 // 90
	{
		for (int y = 40; y < 42; y++)
			Posit[x][y] = 90;
	}
	for (int x = 29; x < 35; x++)                 // 91
	{
		for (int y = 40; y < 42; y++)
			Posit[x][y] = 91;
	}

}
void printboard(int Positions[][2][6])
{
	int yp = 0, xp = 0;
	char printed;
	int actualPositions[106][46];
	linkPositions(actualPositions);
	system("cls");
	printf("\n\n\n\n\n");
	printf("\n");
	for (int y = 0; y <= 45; y++)
	{
		printf("\t\t\t\t\t\t\t");
		printed = 'f';
		for (int x = 0; x <= 105; x++)
		{
			if (x < 42 && y < 18)
				printf("\x1b[31m");
			if (x > 63 && y < 18)
				printf("\x1b[33m");
			if (x < 42 && y>23)
				printf("\x1b[36m");
			if (x > 63 && y > 23)
				printf("\x1b[32m");
			if ((x > 41 && x < 64) || (y > 17 && y < 28) || ((((x >= 7) && (x <= 14)) || ((x >= 28) && (x <= 35)) || ((x >= 70) && (x <= 77)) || ((x >= 91) && (x <= 98))) && (((y >= 3) && (y <= 6)) || ((y >= 12) && (y <= 15)) || ((y >= 30) && (y <= 33)) || ((y >= 39) && (y <= 42)))))
			{
				printf("\x1b[0m");
				if (x > 42 && x < 63 && y>18 && y < 27)
				{
					printf("%c", 219);
					continue;
				}
				if (x % 7 == 0)
				{
					if ((x > 41 && x < 64) || (y > 17 && y < 28))
						printf("%c", 245);
					else
						printf(" ");
				}

				else if (y % 3 == 0)
				{
					if ((x > 41 && x < 64) || (y > 17 && y < 28))
						printf("%c", 452);
					else
						printf(" ");
				}
				else
				{
					printgeeti(xp % 6, yp % 2, Positions[actualPositions[x][y]][0], Positions[actualPositions[x][y]][1], actualPositions[x][y]);
					printed = 't';
					xp++;
				}

			}
			else
			{
				printf("%c", 219);
				printf("\x1b[0m");
			}

		}
		if (printed == 't')
			yp++;
		printf("\n");
	}

}

int geetis_out[4][5];

//geetis_out[player][0] Specifies how many geetis player has out previously.
//geetis_out[player][index] specifies which geeti is out. All geetis are labelled from 1 to 4.

char names[4][10]; // Stores Colour names respective to the player #

				   int rolldice()                           // USE THIS FOR QUICK CHECKING
				   {
				   int die = 0;
				   printf("\nDice roll: ");
				   die = inputinteger();
				   return die;
				   }
void dice_top()
{
	printf("\t%c", 218);
	for (int i = 0; i < 8; i++)
	{
		printf("%c", 452);
	}
	printf("%c\n", 191);
}
void dice_bottom()
{
	printf("\t%c", 192);
	for (int i = 0; i < 8; i++)
	{
		printf("%c", 452);
	}
	printf("%c\n", 217);

}
void shake_1_1()
{
	printf("\t\t\t%c          %c\n", 179, 179);
}
void shake_1_2()
{
	printf("\t\t\t");
	printf("%c", 192);
	for (int i = 0; i < 10; i++)
	{
		printf("%c", 452);
	}
	printf("%c", 217);
}
void shake_4_1()
{
	printf("\t\t\t");
	for (int i = 0; i < 12; i++)
	{
		printf("%c", 452);
	}
	printf("%c\n", 191);

}
void shake_4_2()
{
	printf("\t\t\t");
	for (int i = 0; i < 12; i++)
	{
		printf("%c", 452);
	}
	printf("%c\n", 217);

}
void shake_1()
{
	shake_1_1();
	shake_1_1();
	shake_1_1();
	shake_1_1();
	shake_1_1();
	shake_1_1();
	shake_1_2();
	printf("\n");

}
void shake_2()
{

	printf("\t\t\t\\          \\        \n");
	printf("\t\t\t \\          \\       \n");
	printf("\t\t\t  \\          \\      \n");
	printf("\t\t\t   \\          \\     \n");
	printf("\t\t\t    \\          \\    \n");
	printf("\t\t\t     \\          \\   \n");
	printf("\t\t\t      ------------ \n\n\n");
}
void shake_3()
{

	printf("\t\t\t     /          /\n");
	printf("\t\t\t    /          /\n");
	printf("\t\t\t   /          /\n");
	printf("\t\t\t  /          /\n");
	printf("\t\t\t /          /\n");
	printf("\t\t\t/          /\n");
	printf("\t\t\t-----------\n\n\n");
}
void shake_4()
{
	shake_4_1();
	printf("\t\t                    |\n");
	printf("\t\t                    |\n");
	printf("\t\t                    |\n");
	shake_4_2();
}
void one()
{
	dice_top();
	printf("\t%c        %c\n", 179, 179);
	printf("\t%c    %c   %c\n", 179, 254, 179);
	printf("\t%c        %c\n", 179, 179);
	dice_bottom();
}
void two()
{
	dice_top();

	printf("\t|       %c|\n", 254);
	printf("\t|        |\n");
	printf("\t|%c       |\n", 254);

	dice_bottom();
}
void three()
{
	dice_top();

	printf("\t|       %c|\n", 254);
	printf("\t|    %c   |\n", 254);
	printf("\t|%c       |\n", 254);

	dice_bottom();
}
void four()
{
	dice_top();
	printf("\t|%c      %c|\n", 254, 254);
	printf("\t|        |\n");
	printf("\t|%c      %c|\n", 254, 254);
	dice_bottom();
}
void five()
{
	dice_top();
	printf("\t|%c      %c|\n", 254, 254);
	printf("\t|    %c   |\n", 254);
	printf("\t|%c      %c|\n", 254, 254);

	dice_bottom();
}
void six()
{
	dice_top();
	printf("\t|%c      %c|\n", 254, 254);
	printf("\t|%c      %c|\n", 254, 254);
	printf("\t|%c      %c|\n", 254, 254);
	dice_bottom();
}

/*int rolldice()           // Comment this and use the other roledice function for quick checking.
{
	int dice = 0;
	srand(time(NULL));
	system("cls");
	printf("\n\n");
	shake_1();
	Sleep(200);
	system("cls");

	printf("\n\n");
	shake_3();
	Sleep(200);
	system("cls");

	printf("\n\n");
	shake_2();
	Sleep(200);
	system("cls");

	printf("\n\n");
	shake_3();
	Sleep(200);
	system("cls");

	printf("\n\n");
	shake_2();
	Sleep(200);
	system("cls");

	printf("\n\n");
	shake_4();
	Sleep(100);


	dice = ((rand() % 6) + 1);

	switch (dice)
	{
	case 1:
		one();
		printf("\n\n");
		break;
	case 2:
		two();
		printf("\n\n");

		break;
	case 3:
		three();
		printf("\n\n");
		break;
	case 4:
		four();
		printf("\n\n");
		break;
	case 5:
		five();
		printf("\n\n");
		break;
	case 6:
		six();
		printf("\n\n");
		break;
	}
	Sleep(500);
	return dice;
}*/
int findnewindex(int box[][2][6], int new_location)
{
	int new_index = 0;
	// Check if the new location is a safe zone
	if ((new_location != 56) && (new_location != 63) && (new_location != 69) && (new_location != 75) && (((new_location % 13 == 0) || (new_location % 13 == 8)) || ((new_location > 50) && (new_location < 75) && (new_location != 57))))
	{
		for (new_index = 0; new_index < 6; new_index++) // Finds Storage Location that is free for a Geeti
		{
			if (box[new_location][0][new_index] == -1)
				break;
		}
	}
	return new_index;
}
int search_for_geeti(int geetino, int box[][2][6], int player, int *pointerstorage)
{
	for (int count = 0; count < 76; count++)
	{
		for (*pointerstorage = 0; *pointerstorage < 6; *pointerstorage += 1)
		{
			if (box[count][0][*pointerstorage] == player && box[count][1][*pointerstorage] == geetino)
				return count;
		}
	}
	*pointerstorage = 0;
	return -1; // In case no Geeti is found
}
void take_out_geeti(int player, int box[][2][6])
{
	for (int geetino = 1; geetino < 5; geetino++)
	{
		if ((geetis_out[player][0] == 0) || (geetis_out[player][geetino] == 0))
		{
			geetis_out[player][0] += 1;
			geetis_out[player][geetino] = 1;
			box[((75 + geetino) + (4 * player))][0][0] = -1;
			box[((75 + geetino) + (4 * player))][1][0] = -1;
			for (int storageloc = 0; storageloc < 6; storageloc++)
			{
				if (box[(player * 13)][0][storageloc] == -1)
				{
					box[(player * 13)][0][storageloc] = player; // The starting of board position for a player can be represented by multiplying his player # with 13 
					box[(player * 13)][1][storageloc] = geetino;
					break;
				}
			}
			break;
		}
	}
}
int location_find(int olds, int dice, int start, int end)
{
	if (olds + dice > end)
		return -1;
	else if (olds + dice == 51)// For discontinuity in table labellings
		return 57;
	else if (olds == 57)          // For discontinuity in table labellings
		return (olds + dice - 58);
	else if ((olds + dice > 51) && (olds + dice < 57)) // For discontinuity in table labellings
		return (olds + dice - 52);
	else if ((olds < start) && (olds + dice >= start)) // For moving geeti up to home.
		return (olds + dice + end - start - 5);
	else
		return (olds + dice); // For Normal Movement
}
void move_geeti(int dice, int box[][2][6], int player, int geetitomove)
{
	int old_location, new_location = -1, old_index = 0, new_index = 0;
	int* pointerold_index = &old_index;
	old_location = search_for_geeti(geetitomove, box, player, pointerold_index);

	switch (player)
	{
	case 0:
		new_location = old_location + dice;
		break;
	default:
		new_location = location_find(old_location, dice, ((player * 13) - 1), ((player * 6) + 57));
		break;
	}

	new_index = findnewindex(box, new_location);

	if (new_location == 56 || new_location == 63 || new_location == 69 || new_location == 75)
	{
		printf("\n%s has scored a geeti!", names[player]);
		getch();
		box[old_location][0][old_index] = -1; //Setting old box to empty
		box[old_location][1][old_index] = -1;

		box[new_location][0][0] = player; //Adding details of moved geeti to new box
		box[new_location][1][0] += 1;
	}

	else if (box[new_location][0][new_index] != -1) //If new location is not empty
	{

		printf("\n%s's geeti has been killed by %s", names[box[new_location][0][0]], names[player]);
		getch();
		geetis_out[box[new_location][0][0]][0] -= 1; //Decrementing killed geeti player's out geetis
		geetis_out[box[new_location][0][0]][box[new_location][1][0]] = 0; //Setting flag for killed geeti as not out

		box[((75 + box[new_location][1][0]) + (4 * box[new_location][0][0]))][0][0] = box[new_location][0][0];    //Putting Killed Geeti back to its home position
		box[((75 + box[new_location][1][0]) + (4 * box[new_location][0][0]))][1][0] = box[new_location][1][0];    //Putting Killed Geeti back to its home position

		box[new_location][0][0] = player; //Adding details of moved geeti to new box
		box[new_location][1][0] = box[old_location][1][old_index];

		box[old_location][0][old_index] = -1; //Setting old box to empty
		box[old_location][1][old_index] = -1;
	}
	else
	{
		box[old_location][0][old_index] = -1;
		box[old_location][1][old_index] = -1; //Setting old location to empty

		box[new_location][0][new_index] = player;
		box[new_location][1][new_index] = geetitomove; //Putting geeti in new location
	}
}
void winner(int player)
{
	system("cls");
	printf("%s has won!!!!", names[player]);
}
void checkmovevalidities(int movevalidity[], int box[][2][6], int player, int dice)
{
	movevalidity[0] = 4;
	for (int geetino = 1; geetino <= 4; geetino++)
	{
		movevalidity[geetino] = 1;
		int old_location, new_location = -1, old_index = 0, new_index = 0;
		int* pointerold_index = &old_index;
		old_location = search_for_geeti(geetino, box, player, pointerold_index);

		switch (player)
		{
		case 0:

			if (old_location + dice <= 56)
				new_location = old_location + dice;
			break;
		default:
			new_location = location_find(old_location, dice, ((player * 13) - 1), ((player * 6) + 57));
			break;
		}

		new_index = findnewindex(box, new_location);
		if (new_location == -1 || new_index == 6 || old_location == -1 || box[new_location][0][0] == player) // Move is not Valid e
		{
			movevalidity[geetino] = 0; // Setting that move as not Valid
			movevalidity[0] -= 1; // Total Moves that are Valid are decremented 
		}
	}
}
void printgeetisavailabletomove(int movevalidity[])
{
	for (int x = 1; x <= 4; x++)
	{
		if (movevalidity[x] == 1)
			printf("%d ", x);
	}
}
int main()
{
	srand(time(NULL));
	int player = 0, game_end = 0, geetitomove, rolls = 0, whichdice, players;
	char move_or_take;
	int movevalidity[5]; // Index 1 - 4 Stores 1 if move is valid 0 if it is not. Index 0 stores the total number of valid moves. 
	int box[92][2][6];
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 5; y++)
			geetis_out[x][y] = 0;
	}
	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 92; x++)
		{
			box[x][0][y] = -1;
			box[x][1][y] = -1;
		}
	}
	strcpy(names[0], "Red");
	strcpy(names[1], "Yellow");
	strcpy(names[2], "Green");
	strcpy(names[3], "Blue");


	printinstructions();
	system("cls");
	printf("\nEnter how many players will play from 2-4:  ");
	players = inputinteger();

	while (players < 2 || players > 4)
	{
		printf("\n\nInvalid number. Enter how many players will play from 2-4:  ");
		players = inputinteger();
	}
	players--; //Because players start from 0

	for (int x = 0; x <= players; x++)                     // Initialising Home locations of Geetis
	{
		for (int y = 1; y < 5; y++)
		{
			box[((75 + y) + (4 * x))][0][0] = x;
			box[((75 + y) + (4 * x))][1][0] = y;
		}
	}

	//box[index][0][StorageLocation] specifies which player has a geeti in which storage location of a box of the board
	//box[index][1][StorageLocation] and which geeti it is

	//dice[index] saves the last roll of a player

	//geetitomove is a variable the user will provide input for to specify which geeti they want to move.

	//geetis_out[player][0] Specifies how many geetis player has out previously.
	//geetis_out[player][index] specifies which geeti is out. All geetis are labelled from 1 to 4.

	//move_or_take is for the user's input if they roll a 6

	//game_end is a flag for keeping game going until a player wins.

	box[56][1][0] = 0; //Home locations for all players. box[index][1][0] stores the number of geetis player has scored.
	box[63][1][0] = 0;
	box[69][1][0] = 0;
	box[75][1][0] = 0;

	while (game_end != 1)
	{
		printboard(box);
		int dice[3] = { 0, 0, 0 }; //Saves values of dice
		printf("%s's turn. Press any key to roll dice", names[player]);
		getch();
		dice[0] = rolldice();
		rolls = 1;
		if (dice[0] == 6)
		{
			dice[1] = rolldice();
			rolls = 2;
			if (dice[1] == 6)
			{
				dice[2] = rolldice();
				rolls = 3;
			}
		}
		if (dice[2] == 6)
		{
			printf("\nYou rolled 6 three times in a row. Your turn has been skipped.");
			getch();
		}
		else
		{
			if ((dice[0] == 6) || (geetis_out[player][0] != box[playerfinishingposition(player)][1][0]))
			{
				printboard(box);
				for (int i = 1; i <= rolls; i++)
				{
					printrolls(dice);
					if (i - rolls == 0) //If player is on his last roll 
					{
						for (int j = 0; j < rolls; j++)
						{
							if (dice[j] != 0) //Checking which roll has not been used and automatically saving it to whichdice
								whichdice = j;
						}
					}
					else if (geetis_out[player][0] == 0) //If player has no geetis out
						whichdice = 0; //Automatically use first roll which has to be 6
					else
					{
						printf("\nChoose which roll to use: ");
						whichdice = inputinteger();
						whichdice--;

						while ((whichdice != 1 && whichdice != 2 && whichdice != 0) || dice[whichdice] == 0)
						{
							printf("Invalid. Enter your choice from the ones available above: ");
							whichdice = inputinteger();
							whichdice--;
						}
					}

					checkmovevalidities(movevalidity, box, player, dice[whichdice]);

					if (dice[whichdice] == 6)
					{
						if (geetis_out[player][0] == box[playerfinishingposition(player)][1][0]) //If player has previously no Geetis out.
						{
							take_out_geeti(player, box);
							printf("\nWe took out a Geeti for you.");
							getch();
							if (i != rolls)
								printboard(box);

						}
						else if (geetis_out[player][0] != 4)
						{
							printf("\nEnter m to move or t to take out: ");
							scanf(" %c", &move_or_take);

							while (move_or_take != 'm' && move_or_take != 'M' && move_or_take != 't' && move_or_take != 'T') //Check for correct input from user
							{
								printf("\nInvalid input, please enter m to move or t to take out geeti: ");
								scanf(" %c", &move_or_take);
							}

							if (move_or_take == 'm' || move_or_take == 'M') //if user wants to move geeti
							{
								if (movevalidity[0] != 0)
								{
									if (movevalidity[0] == 1)
									{
										for (int x = 1; x <= 4; x++)
										{
											if (movevalidity[x] == 1)
												geetitomove = x;
										}
										move_geeti(dice[whichdice], box, player, geetitomove);
										printf("\nWe moved the only possible Geeti for you!");
										getch();
										if (i != rolls)
											printboard(box);
									}
									else
									{
										printf("\nChoose geeti you want to move ( ");
										printgeetisavailabletomove(movevalidity);
										printf("): ");
										geetitomove = inputinteger();
										while (geetitomove != 1 && geetitomove != 2 && geetitomove != 3 && geetitomove != 4 && movevalidity[geetitomove] != 1)
										{
											printf("\nInvalid input. Choose from available geetis above: ");
											geetitomove = inputinteger();
										}
										move_geeti(dice[whichdice], box, player, geetitomove);
										if (i != rolls)
											printboard(box);
									}
								}
							}
							else //if user wants to take geeti out
							{
								take_out_geeti(player, box);
								if (i != rolls)
									printboard(box);
							}
						}
						else //If user already has all geetis out
						{
							if (movevalidity[0] != 0)
							{
								if (movevalidity[0] == 1)
								{
									for (int x = 1; x <= 4; x++)
									{
										if (movevalidity[x] == 1)
											geetitomove = x;
									}
									move_geeti(dice[whichdice], box, player, geetitomove);
									printf("\nWe moved the only possible Geeti for you!");
									getch();
									if (i != rolls)
										printboard(box);
								}
								else
								{
									printf("\nChoose geeti you want to move ( ");
									printgeetisavailabletomove(movevalidity);
									printf("): ");
									geetitomove = inputinteger();
									while (geetitomove != 1 && geetitomove != 2 && geetitomove != 3 && geetitomove != 4 && movevalidity[geetitomove] != 1)
									{
										printf("\nInvalid input. Choose from available geetis above: ");
										geetitomove = inputinteger();
									}
									move_geeti(dice[whichdice], box, player, geetitomove);
									if (i != rolls)
										printboard(box);
								}
							}
						}

					}
					else
					{
						if (geetis_out[player][0] != 0)
						{
							if (movevalidity[0] != 0)
							{
								if (movevalidity[0] == 1)
								{
									for (int x = 1; x <= 4; x++)
									{
										if (movevalidity[x] == 1)
											geetitomove = x;
									}
									move_geeti(dice[whichdice], box, player, geetitomove);
									printf("\nWe moved the only possible Geeti for you!");
									getch();
									if (i != rolls)
										printboard(box);
								}
								else
								{
									printf("\nChoose geeti you want to move ( ");
									printgeetisavailabletomove(movevalidity);
									printf("): ");
									geetitomove = inputinteger();
									while (geetitomove != 1 && geetitomove != 2 && geetitomove != 3 && geetitomove != 4 && movevalidity[geetitomove] != 1)
									{
										printf("\nInvalid input. Choose from available geetis above: ");
										geetitomove = inputinteger();
									}
									move_geeti(dice[whichdice], box, player, geetitomove);
									if (i != rolls)
										printboard(box);
								}
							}
						}
					}
					dice[whichdice] = 0;
				}
			}

		}
		if (box[56][1][0] == 4 || box[63][1][0] == 4 || box[69][1][0] == 4 || box[75][1][0] == 4) //Check for if player has won
		{
			winner(player);
			game_end = 1;
		}

		if (player == players) //Next player's turn.
			player = 0;
		else
			player++;
	}

	getch();
	return 0;
}
