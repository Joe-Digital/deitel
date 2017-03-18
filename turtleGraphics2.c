#include <stdio.h>

#define MAX 50
#define CMAX 10


enum Status { NORTH, EAST, SOUTH, WEST };
enum Pen { UP, DOWN };

int main(void)
{
	int e,r;
	int a = 0, b = 0, c = 0;
	int commands[CMAX][2] = { 0 };
	int array[MAX][MAX] = { 0 };
	enum Pen penStatus;
	penStatus = UP;
	printf("Controls are:\n"
 		"1 0 = pen up\n"
		"2 0 = pen down\n"
		"3 0 = turn right\n"
		"4 0 = turn left\n"
		"5 n = move n spaces\n"
		"-1 -1 = quit\n");
	printf("Enter your commands\n");
	scanf("%d %d", &e, &r);
	if(e == 1 || e == 2 || e == 3 || e == 4) {
		commands[c][0] = e;
	}
	else if(e == 5) {
		commands[c][0] = e;
		commands[c][1] = r;
	}
		enum Status gameStatus;
		gameStatus = EAST;
		int m, z;
		while(e != -1) {
			switch(commands[m][0]) {
				case 1:
					penStatus = UP;
					break;
				case 2:
					penStatus = DOWN;
					break;
				case 3:
					if(gameStatus == EAST) {
						if(penStatus == DOWN) {
							++a;
							array[a][b] = commands[m][0];
							gameStatus = SOUTH;
							break;
						}
						else if(penStatus == UP) {
							++a;
							gameStatus = SOUTH;
							break;
						}
					}
					if(gameStatus == WEST) {
						if(penStatus == DOWN) {
        	                                	--a;
                	                        	array[a][b] = commands[m][0];
                        	                	gameStatus = NORTH;
	                                        	break;
						}
						else if(penStatus == UP) {
							--a;
							gameStatus = NORTH;
							break;
						}
	                                }
					if(gameStatus == SOUTH) {
						if(penStatus == DOWN) {
	                                   		 --b;
	                                  	        array[a][b] = commands[m][0];
	                                       		 gameStatus = WEST;
	                                                break;
	                                	}
						else if(penStatus == UP) {
							--b;
							gameStatus = WEST;
							break;
						}
					}
					if(gameStatus == NORTH) {
						if(penStatus == DOWN) {
	                                       		 ++b;
	                                       		 array[a][b] = commands[m][0];
	                                       		 gameStatus = EAST;
	                                        	break;
	                                	}
						else if(penStatus == UP) {
							++b;
							gameStatus = EAST;
							break;
						}
					}
					break;
 				case 4:
					if(gameStatus == SOUTH) {
						if(penStatus == DOWN) {
		                                	++b;
                	                        	array[a][b] = commands[m][0];
                        	                	gameStatus = EAST;
                                	        	break;
						}
						else if(penStatus == UP) {
							++b;
							gameStatus = EAST;
							break;
						}
	                                }
					if(gameStatus == EAST) {
						if(penStatus == DOWN) {
		                                        --a;
		                                        array[a][b] = commands[m][0];
	        	                                gameStatus = NORTH;
	                	                        break;
	                           	        }
						else if(penStatus == UP) {
							--a;
							gameStatus == NORTH;
							break;
						}
					}
					if(gameStatus == NORTH) {
						if(penStatus == DOWN) {
	                                        	++a; 
	                                        	--b;
	                                        	array[a][b] = commands[m][0];
	                                        	gameStatus = WEST;
	                                        	break;
	                                	}
						else if(penStatus == UP) {
							++a;
							--b;
							gameStatus = WEST;
							break;
						}
					if(gameStatus == WEST) {
						if(penStatus == DOWN) {
	                                        	++a;
	                                        	array[a][b] = commands[m][0];
	                                        	gameStatus = SOUTH;
	                                        	break;
						}
						else if(penStatus == UP) {
							++a;
							gameStatus = SOUTH;
							break;
						}
	                                }
					break;
				case 5:
					if(gameStatus == EAST) {
						if(penStatus == DOWN) {
							for(z = 0; z < commands[m][1] - 1; z++) {
								b++;
								array[a][b] = commands[m][0];
							}
						}
						else if(penStatus == UP) {
							for(z = 0; z < commands[m][1] - 1; z++) {
								b++;
							}
						}
						break;
					}
					else if(gameStatus == SOUTH) {
						if(penStatus == DOWN) {
							for(z = 0; z < commands[m][1] - 1 ; z++) {
								++a;
								array[a][b] = commands[m][0];
							}
						}
						else if(penStatus == UP) {
							for(z = 0; z < commands[m][1] - 1; z++) {
								++a;
							}
						}
						break;	
					}
					else if(gameStatus == WEST) {
						if(penStatus == DOWN) {
      	 	                                	for(z = 0; z < commands[m][1] - 1; z++) {
                                              			--b;
                                                		array[a][b] = commands[m][0];
        	                                 	}
						}
						else if(penStatus == UP) {
							for(z = 0; z < commands[m][1] - 1; z++) {
								--b;
							}
						}
						break;
					}
					else if(gameStatus == NORTH) {
						if(penStatus == DOWN) {
	                                        	for(z = 0; z < commands[m][1] - 1; z++) {
                                                		--a;
                                                		array[a][b] = commands[m][0];
                                               		}
						}
						else if(penStatus == UP) {
							for(z = 0; z < commands[m][1] - 1; z++) {
								--a;
							}
						}
                                        }
					default:
						printf("enter correct char\n");
						break;
				}
			}
			printf("\n");
			int j, k;
			for(k = 0; k < MAX; k++) {
				for(j = 0; j < MAX; j++) {
					if(array[k][j] > 0){
						printf("*");
					}
					else if(array[k][j] == 0) {
						printf(".");
					}
				}
			printf("\n");
			}
			printf("Enter Commands, enter -1 -1 to end\n");
                        scanf("%d %d", &e, &r);
			 if(e == 1 || e == 2 || e == 3 || e == 4) {
		                commands[c][0] = e;
		        }
		        else if(e == 5) {
        		        commands[c][0] = e;
                		commands[c][1] = r;
			 }

	}
	return 0;
}
