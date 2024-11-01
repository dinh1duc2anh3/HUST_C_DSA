#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int n, Row, Col;
int solution[MAX_SIZE];
int foundSolution = 0;

int check(int row, int col)
{
	for (int i = 1; i <= col - 1; i++)
	{
		if (solution[i] == row || (solution[i] - i == row - col) || (solution[i] + i == row + col))
		{
			return 0;
		}
	}

	return 1;
}

void print()
{
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", solution[i]);
	}

	printf("\n");
}

void solve(int col)
{
	for (int row = 1; row <= n; row++)
	{
		if (check(row, col))
		{
			solution[col] = row;
			if (col == n)
			{
				if (solution[Col] == Row)
				{
					foundSolution = 1;
					print();
				}
			}
			else
			{
				solve(col + 1);
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &Row, &Col);
	if (Row <= 0 || Row > n || Col <= 0 || Col > n)
	{
		printf("None\n");
		return 0;
	}

	solution[Col] = Row;
	solve(1);
	if (foundSolution == 0)
	{
		printf("None\n");
	}

	return 0;
}