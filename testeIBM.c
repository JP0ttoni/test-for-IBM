#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int calc(int n, int *vect, int k, int pivo)
{
	int count_k = 0, count_equal = 0, i;
	
	for(i = 0; i<n;i++)
	{
		if(vect[i] > pivo && count_k < k)
		{
			vect[i] = pivo;
			count_k++;
		}else if(count_k >= k){
			break;
		}
	}
	
	for(i = 0; i<n;i++)
	{
		if(vect[i] == pivo)
		{
			count_equal++;
		}
	}
	
	return count_equal;
}

int func(int n, int *vect, int k)
{
	int i, j, count_equal = 0, count_k = 0, equal[50], temp[50], maior;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			temp[j] = vect[j];
		}
		//printf("%d ", vect[i]);
		equal[i] = calc(n, temp, k, vect[i]);
		//printf("%d ", equal[i]);
	}
	maior = equal[0];
	for(i = 0; i < n; i++)
	{
		if(maior < equal[i])
		{
			maior = equal[i];
		}
	}
	
	return maior;
}
int main()
{
	int i, n, vect[50], k, result;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
	{
		scanf("%d", &vect[i]);
	}
	
	scanf("%d", &k);
	
	result = func(n, vect, k);
	printf("resultado: %d", result);
	
}
