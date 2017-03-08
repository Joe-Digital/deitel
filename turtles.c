#include <stdio.h>

#define MAX 50
#define CMAX 10

enum Status { NORTH, EAST, SOUTH, WEST };
 
enum Dir { UP, DOWN, LEFT, RIGHT };


int main(void)
{
	int count;
	int c = 0;
	int commands[CMAX][2] = { 0 };
	int array[MAX][MAX] = { 0 };
	int a = 0, b = 0;
	int z = 0, x = 0;
	printf("Enter commands\n");
	for(count = 1; count <= CMAX ; count++, c++) {
		scanf("%d", &commands[c]);
		}
	int m;
	enum Status gameStatus;
	gameStatus = EAST;
	for(m = 0; m <= CMAX; m++) {
		switch(commands[m][0]) {
			case 2:
				array[a][b] = commands[m][0];
				if(gameStatus == SOUTH){
                                        ++a;
                                        array[a][b] = commands[m][0];
                               		break;
				 }
				else if(gameStatus == EAST){
					if(b < MAX) {
                                        b++;
                                	}
	                                if (b >= MAX) {
                                        a++;
                                        b = 0;
                                	}
					break;
				}
				else if(gameStatus ==  WEST) {
					--b;
					array[a][b] = commands[m][0];
					break;
				}
				
				break;

			case 3:
				if(gameStatus == EAST) {
					++a;
					--b;
					array[a][b] = commands[m][0];
					gameStatus = SOUTH;
					break;
				}
				if(gameStatus == WEST) {
					--a;
					array[a][b] =  commands[m][0];
					gameStatus = NORTH;
					break;
				}
				if (gameStatus == SOUTH) {
					--b;
					array[a][b] = commands[m][0];
					gameStatus = WEST;
					break;
				}
				break;
			
			case 4:
				if(gameStatus == SOUTH) {
					++b;
					array[a][b] = commands[m][0];
					gameStatus = EAST;
					break;
				}
				if(gameStatus == EAST) {
					--a;
					array[a][b] =  commands[m][0];
					gameStatus = NORTH;
					break;
				}
				if(gameStatus == NORTH) {
					--b;
					array[a][b] = commands[m][0];
					gameStatus = WEST;
					break;
				}
				if(gameStatus == WEST) {
					++a;
					array[a][b] = commands[m][0];
					gameStatus = SOUTH;
					break;
				}
			case 5:
				if(gameStatus == EAST) {
					for(z = 1; z <= commands[m][1]; z++) {
						++b;
						array[a][b] = 2;
					}
					break;
				}
				if(gameStatus == SOUTH) {
					for(z = 1; z <= commands[m][1]; z++) {
						++a;
						array[a][b] = 2;
					}
					break;
				}
				if(gameStatus == NORTH) {
					for(z = 1; z <= commands[m][1]; z++) {
						--a;
						array[a][b] = 2;
					}
					break;
				}
				if(gameStatus == WEST) {
					for(z = 1; z <= commands[m][1]; z++) {
						--b;
						array[a][b] = 2;
					}
					break;
				}
			default:
				printf("Enter correct char\n");
				break;

		}

	}
	int j, k;
	for(j = 0; j < MAX; j++) {
		for(k = 0; k < MAX; k++) {
			if(array[j][k] == 2 || array[j][k] == 3 || array[j][k] == 5) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
	printf("\n");
	}
	return 0;
}
