#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void printMaze(int *, int, int);
int komsuBul(int *, int *, int, int, int, int, int);
int komsuYerBul(int *, int, int, int);
void diziKaydir(int *, int, int);

int main()
{
	srand(time(NULL));
	
	int n,m;
	
	printf("Labirentin yuksekligini giriniz: ");
	scanf("%d", &n);
	printf("Labirentin genisligini giriniz: ");
	scanf("%d", &m);
	
	int maze[n+2][m+2];
	
	int komsu[(n*m)/2][2];
	int kSayac = 0;
	
	//fill with 1.
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
	
	maze[y][x] = 3;
	kSayac = komsuBul((int *)maze, (int *)komsu, n, m, x, y, kSayac);
	
	printMaze((int*)maze, n, m);
	
	while(kSayac > 0)
	{
		int rand1 = rand()%kSayac;
		
		x = komsu[rand1][1];
		y = komsu[rand1][0];
		maze[y][x] = 3;
		diziKaydir((int *)komsu, kSayac, rand1);
		kSayac--;
		
		kSayac = komsuBul((int *)maze, (int *)komsu, n, m, x, y, kSayac);
		
		printMaze((int*)maze, n, m);
	}
	
	getch();
	return 0;
}

void diziKaydir(int *komsu, int kSayac, int a)
{
	for(int i=a; i<kSayac; i++)
	{
		*((komsu+2*i)+0) = *((komsu+2*(i+1))+0);
		*((komsu+2*i)+1) = *((komsu+2*(i+1))+1);
	}
}

int komsuYerBul(int *komsu, int kSayac, int x, int y)
{
	int i=0;
	while(i<kSayac)
	{
		if(x == *((komsu+2*i)+1) && y == *((komsu+2*i)+0))
		{
			return i;
		}
		i++;
	}
}

int komsuBul(int *maze, int *komsu, int n, int m, int x, int y, int kSayac)
{
	if(x < m)
	{
		if(*((maze+(m+2)*(y))+(x+1)) == 1)
		{
			*((maze+(m+2)*y)+(x+1)) = 2;
			*((komsu+2*kSayac)+0) = y;
			*((komsu+2*kSayac)+1) = x+1;
			kSayac++;
		}
		else if(*((maze+(m+2)*y)+x+1) == 2 )
		{
			*((maze+(m+2)*y)+(x+1)) = 4;
			int temp = komsuYerBul((int *)komsu, kSayac, x+1, y);
			diziKaydir((int *)komsu, kSayac, temp);
			kSayac--;
		}
	}
	
	if(x > 1)
	{
		if(*((maze+(m+2)*(y))+x-1) == 1)
		{
			*((maze+(m+2)*y)+(x-1)) = 2;
			*((komsu+2*kSayac)+0) = y;
			*((komsu+2*kSayac)+1) = x-1;
			kSayac++;
		}
		else if(*((maze+(m+2)*y)+x-1) == 2)
		{
			*((maze+(m+2)*y)+(x-1)) = 4;
			int temp = komsuYerBul((int *)komsu, kSayac, x-1, y);
			diziKaydir((int *)komsu, kSayac, temp);
			kSayac--;
		}	
	}
	
	if(y < n)
	{
		if(*((maze+(m+2)*(y+1))+x) == 1)
		{
			*((maze+(m+2)*(y+1))+(x)) = 2;
			*((komsu+2*kSayac)+0) = y+1;
			*((komsu+2*kSayac)+1) = x;
			kSayac++;
		}
		else if(*((maze+(m+2)*(y+1))+x) == 2)
		{
			*((maze+(m+2)*(y+1))+(x)) = 4;
			int temp = komsuYerBul((int *)komsu, kSayac, x, y+1);
			diziKaydir((int *)komsu, kSayac, temp);
			kSayac--;
		}	
	}
	
	if(y > 1)
	{
		if(*((maze+(m+2)*(y-1))+x) == 1)
		{
			*((maze+(m+2)*(y-1))+(x)) = 2;
			*((komsu+2*kSayac)+0) = y-1;
			*((komsu+2*kSayac)+1) = x;
			kSayac++;
		}
		else if(*((maze+(m+2)*(y-1))+x) == 2)
		{
			*((maze+(m+2)*(y-1))+(x)) = 4;
			int temp = komsuYerBul((int *)komsu, kSayac, x, y-1);
			diziKaydir((int *)komsu, kSayac, temp);
			kSayac--;
		}
	}
	
	return kSayac;
}

void printMaze(int *maze, int n, int m)
{
	system("CLS");
	for(int i=0; i<n+2; i++)
	{
		for(int j=0; j<m+2; j++)
		{
			if( *((maze+i*(m+2))+j) == 1) printf("%c%c", 219, 219);
			else if( *((maze+i*(m+2))+j) == 2) printf("%c%c", 178, 178);
			else if( *((maze+i*(m+2))+j) == 3) printf("%c%c", 32, 32);
			else if( *((maze+i*(m+2))+j) == 4) printf("%c%c", 219, 219);
		}
		printf("\n");
	}
}
