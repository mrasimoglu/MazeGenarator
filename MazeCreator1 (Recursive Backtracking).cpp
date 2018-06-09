#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void printMaze(int *, int, int);
void recursiveBacktracking(int *, int, int, int, int);

int main()
{
	srand(time(NULL));
	
	int n, m;
	
	printf("Labirentin yuksekligini giriniz: ");
	scanf("%d", &n);
	printf("Labirentin genisligini giriniz: ");
	scanf("%d", &m);
	
	int maze[n+2][m+2];
	
	for(int i=0; i<n+2; i++)
	{
		for(int j=0; j<m+2; j++)
		{
			maze[i][j] = 1;
		}
	}
	
	int x, y;
	
	x = (rand()%m)+1;
	y = (rand()%n)+1;
	
	recursiveBacktracking((int *)maze, n, m, x, y);
	
	printMaze((int *)maze, n, m);
	
	getch();
	return 0;
}

void recursiveBacktracking(int *maze, int n, int m, int x, int y)
{
	int a[4][2] = {{0,0},{0,0},{0,0},{0,0}}; 
	int b[4] = {0,1,2,3};
	
	for(int i=0; i<2; i++)
	{
		int rand1 = rand()%4;
		int temp = b[i]; 
		b[i] = b[rand1];
		b[rand1] = temp;
	}
	
	*((maze+(m+2)*y)+x) = 3;
	
//	printMaze((int *)maze, n, m);
	//getch();
	
	if(x < m)
	{
		if(*((maze+(m+2)*y)+x+1) == 1)
		{
			*((maze+(m+2)*y)+x+1) = 2;
			a[0][0] = 1;
		}
		else if(*((maze+(m+2)*y)+x+1) == 2)
		{
			*((maze+(m+2)*y)+x+1) = 4;
		}	
	}
	
//	printMaze((int *)maze, n, m);
	//getch();
	
	if(x > 1)
	{
		if(*((maze+(m+2)*y)+x-1) == 1)
		{
			*((maze+(m+2)*y)+x-1) = 2;
			a[1][0] = -1;
		}
		else if(*((maze+(m+2)*y)+x-1) == 2)
		{
			*((maze+(m+2)*y)+x-1) = 4;
		}	
	}
	
//	printMaze((int *)maze, n, m);
	//getch();
	
	if(y < n)
	{
		if(*((maze+(m+2)*(y+1))+x) == 1)
		{
			*((maze+(m+2)*(y+1))+x) = 2;
			a[2][1] = 1;
		}
		else if(*((maze+(m+2)*(y+1))+x) == 2)
		{
			*((maze+(m+2)*(y+1))+x) = 4;
		}	
	}
	
//	printMaze((int *)maze, n, m);
	//getch();
	
	if(y > 1)
	{
		if(*((maze+(m+2)*(y-1))+x) == 1)
		{
			*((maze+(m+2)*(y-1))+x) = 2;
			a[3][1] = -1;
		}
		else if(*((maze+(m+2)*(y-1))+x) == 2)
		{
			*((maze+(m+2)*(y-1))+x) = 4;
		}	
	}
	
//	printMaze((int *)maze, n, m);
	//getch();
	
	for(int i=0; i<4; i++)
	{
		if(a[b[i]][0] == 1 || a[b[i]][1] == 1 || a[b[i]][0] == -1 || a[b[i]][1] == -1)
		{
			if(*((maze+(m+2)*(y+a[b[i]][1]))+x+a[b[i]][0]) == 2)
				 recursiveBacktracking((int *)maze, n, m, x+a[b[i]][0], y+a[b[i]][1]);
		}
	}
}

void printMaze(int *maze, int n, int m)
{
	system("CLS");
	for(int i=0; i<n+2; i++)
	{
		for(int j=0; j<m+2; j++)
		{
			if(*((maze+i*(m+2))+j) == 1) printf("%c%c", 219, 219);
			else if(*((maze+i*(m+2))+j) == 2) printf("%c%c", 178, 178);
			else if(*((maze+i*(m+2))+j) == 3) printf("%c%c", 32, 32);
			else if(*((maze+i*(m+2))+j) == 4) printf("%c%c", 219, 219);
		}
		printf("\n");
	}
}
