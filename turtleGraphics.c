#include <stdio.h>

#define MAX 50
#define CMAX 10


enum Status { NORTH, EAST, SOUTH, WEST };


int main(void)
{
	int e,r;
	int a = 0, b = 0, c = 0;
	int commands[CMAX][2] = { 0 };
	int array[MAX][MAX] = { 0 };
	printf("Enter commands\n");
	int t;
	for(t = 1; t < CMAX; t++, c++) {
		scanf("%d %d", &e, &r);
		if(e == 2 || e == 3 || e == 4) {
			commands[c][0] = e;
		}
		if(e == 5) {
			commands[c][0] = e;
			commands[c][1] = r;
		}
	}

	enum Status gameStatus;
	gameStatus = EAST;
	int m, z;
	for(m = 0; m < CMAX; m++) {
		switch(commands[m][0]) {
			case 2:
				array[a][b] = commands[m][0];
				if(gameStatus == SOUTH){
					++a;
					array[a][b] = commands[m][0];
					break;
				}
				else if(gameStatus == EAST){
					b++;
					array[a][b] = commands[m][0];
					break;
				}
				else if(gameStatus == WEST) {
					--b;
					array[a][b] = commands[m][0];
					break;
				}
				break;
			case 3:
				if(gameStatus == EAST) {
					++a;
					array[a][b] = commands[m][0];
					gameStatus = SOUTH;
					break;
				}
				if(gameStatus == WEST) {
                                        --a;
                                        array[a][b] = commands[m][0];
                                        gameStatus = NORTH;
                                        break;
                                }
				if(gameStatus == SOUTH) {
                                        --b;
                                        array[a][b] = commands[m][0];
                                        gameStatus = WEST;
                                        break;
                                }
				if(gameStatus == NORTH) {
                                        ++b;
                                        array[a][b] = commands[m][0];
                                        gameStatus = EAST;
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
                                        array[a][b] = commands[m][0];
                                        gameStatus = NORTH;
                                        break;
                                }
				if(gameStatus == NORTH) {
                                        ++a; 
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
				break;
			case 5:
				if(gameStatus == EAST) {
					for(z = 0; z < commands[m][1]; z++) {
						b++;
						array[a][b] = commands[m][0];
					}
					break;
				}
				else if(gameStatus == SOUTH) {
					for(z = 0; z < commands[m][1]; z++) {
						++a;
						array[a][b] = commands[m][0];
						continue;
					}
					break;	
				}
				else if(gameStatus == WEST) {
                                         for(z = 0; z < commands[m][1]; z++) {
                                              	 --b;
                                                 array[a][b] = commands[m][0];
                                         }
					break;
				}
				else if(gameStatus == NORTH) {
                                         for(z = 0; z < commands[m][1]; z++) {
                                               --a;
                                               array[a][b] = commands[m][0];
                                                }
                                        }
				default:

					printf("enter correct char\n");
					break;
		}
	}


//	printf("\n");
//	int z, j, k;
//	for (z = 0; z < MAX; z++) {
//		for(j = 0; j < MAX; j++) {
//			printf("%d", array[z][j]);
//		}
//	}





	printf("\n");
	int j, k;
	for(k = 0; k < MAX; k++) {
		for(j = 0; j < MAX; j++) {
			if(array[k][j] > 0){
				printf("*");
			}
//			else if(array[k][j] == 5) {
//				printf("*");
//			}
			else if(array[k][j] == 0) {
				printf(".");
			}
		}
		printf("\n");
	}



//	int z, x;
//	for(z = 0; z < CMAX; z++) {
//		if(commands[z][d] == 2) {
//			printf("*");
//		}
//		if(commands[z][d] == 5) {
//			for(x = 0; x < commands[c][1]; x++) {
//				printf("*");
//			}
//		}
//	}

	return 0;
}
