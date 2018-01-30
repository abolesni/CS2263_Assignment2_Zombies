#include <stdlib.h>
#include <stdio.h>

void set_zombies(int n, char fred[n+2][n+2]){
	//Adds 'Z' to desired position in array based of inputted integer pair. Takes into account borders (e.g. Input of 0,0 will put 'Z' at 1,1 in array)
	int row;
	int col;
	//scan pair of integers for locations
	while(scanf("%d %d", &row, &col) == 2){
		if (row < 0 || col < 0 || row >= n || col >= n){
			printf("Invalid input. Exiting");
			break;
		}
		//increment row and col location to take into account extra borders added in
		row++;
		col++;
		fred[row][col] = 'Z';
	}
}
void print_zombies(int n, char fred[n+2][n+2]){
	//Prints out entire 2D array.
	for (int i = 0; i < n+2; i++){
		for (int j = 0; j < n+2; j++){
			printf("%c", fred[i][j]);
		}
		printf("\n");
	}
}
void block_zombies(int n, char fred[n+2][n+2]){
	//Applies 'B' characters to cells adjacent to those containing a 'Z'
	for (int i = 1; i < n+2; i++){
		for (int j = 1; j < n+1; j++){
			if (fred[i][j] == 'Z'){
				if (fred[i-1][j] == '.'){
					fred[i-1][j] = 'B';
				}
				if (fred[i+1][j] == '.'){
					fred[i+1][j] = 'B';
				}
				if (fred[i][j-1] == '.'){
					fred[i][j-1] = 'B';
				}
				if (fred[i][j+1] == '.'){
					fred[i][j+1] = 'B';
				}
			}
		}
	}
}

int main(){
	//Dimension n being inputted
	int n;
	scanf("%d", &n);
	//increase n by 2 to allow borders without having to take them into account when entering zombie locations
	char fred[n+2][n+2];
	
	//Pad array with extra borders as stated in the assignment
	for (int i = 0; i < n+2; i++){
		for (int j = 0; j < n+2; j++){
			if (i == 0 || i == 11 || j == 0 || j == 11){
				fred[i][j] = 'X';
			}
			else{
				fred[i][j] = '.';
			}
		}
	}
	
	set_zombies(n, fred);
	printf("Original map (with borders)\n");
	print_zombies(n, fred);
	
	block_zombies(n, fred);
	printf("Map with blocking info\n");
	print_zombies(n, fred);

}