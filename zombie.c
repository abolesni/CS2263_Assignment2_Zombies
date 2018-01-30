#include <stdlib.h>
#include <stdio.h>

void set_zombies(int n, char fred[n+2][n+2]){
	int row;
	int col;
	while(scanf("%d %d", &row, &col) == 2){
		if (row < 0 || col < 0 || row >= n || col >= n){
			printf("Invalid input. Exiting");
			break;
		}
		row++;
		col++;
		fred[row][col] = 'Z';
	}
}
void print_zombies(int n, char fred[n+2][n+2]){
	for (int i = 0; i < n+2; i++){
		for (int j = 0; j < n+2; j++){
			printf("%c", fred[i][j]);
		}
		printf("\n");
	}
}
void block_zombies(int n, char fred[n+2][n+2]){
}

int main(){
	//Dimension n being inputted
	int n;
	scanf("%d", &n);
	char fred[n+2][n+2];
	
	//Pad array
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
	print_zombies(n, fred);

}