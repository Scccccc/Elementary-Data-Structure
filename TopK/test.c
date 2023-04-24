#define _CRT_SECURE_NO_WARNINGS 1

#include "Topk.h"


void PrintTopk(const char* file, int k)
{
	int* topk = (int*)malloc(sizeof(int) * k);
	if (topk == NULL)
	{
		perror("malloc fail");
		return;
	}

	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen fail");
		return;
	}

	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &topk[i]);
	}

	for(int i = (k - 2) / 2; i >= 0; i--)
	{
		AdjustDown(topk, k, i);
	}


	int val = 0;
	while (fscanf(fout, "%d", &val) != EOF)
	{
		if (val > topk[0])
		{
			topk[0] = val;
			AdjustDown(topk, k, 0);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", topk[i]);
	}
	printf("\n");

	fclose(fout);
	free(topk);
}

void CreateData()
{
	size_t n = 10000;
	srand((unsigned int)time(0));
	const char* file = "test.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen fail");
		return;
	}
	
	for (size_t i = 0; i < n; i++)
	{
		size_t x = rand() % 10000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}

int main()
{
	//CreateData();
	PrintTopk("test.txt", 10);

	return 0;
}