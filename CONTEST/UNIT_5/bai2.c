#include <stdio.h>
#include <stdlib.h>

long long max;

void tichMax(int n, int M, int arr[], int x[], int k)
{
	if (k == n)
	{
		int sum = 0;
		for (int i = 0; i < n; i++){
			sum += arr[i] *x[i];
		}

		if (sum == M)		{
			long long tich = 1;
			for (int i = 0; i < n; i++)			{
				tich *= x[i];
			}

			if (tich > max)			{
				max = tich;
			}
		}
		return;
	}

	for (int i = 1; i <= M / arr[k]; i++)	{
		x[k] = i;
		tichMax(n, M, arr, x, k + 1);
	}
}

int main()
{
	int n, M;
	scanf("%d %d", &n, &M);
	int arr[n], x[n];

	for (int i = 0; i < n; i++)	{
		scanf("%d", &arr[i]);
	}

	max = 0;
	tichMax(n, M, arr, x, 0);
	if (max == 0)	{
		printf("None");
	}
	else{
		printf("%lld", max);
	}

	return 0;
}