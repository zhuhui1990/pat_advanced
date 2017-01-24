#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool issorted (int *numList, int length)
{
	for(int i = 1; i < length; i++)
	{
		if(numList[i] < numList[i-1])
			return false;
	}
	return true;
}

int func(int i)
{
    return ((i > 0) && ((i & (i - 1)) == 0));
}

int main()
{
	int flag = 0, seqlength = 1;
	int n;
	scanf("%d", &n);
	int *numList = (int *) malloc (n * sizeof(int));
	int *ul = (int *) malloc (n * sizeof(int));

	int i;
	for(i = 0; i < n; i++)
		scanf("%d", &ul[i]);

	for(i = 0; i < n; i++)
	{	
		scanf("%d", &numList[i]);
		if(i >= 1)
		{
			if(numList[i] >= numList[i-1] && flag == 0)
				seqlength++;
			else
				flag = 1;
		}
	}	

	int sortlength = seqlength;

	sort(ul, ul+seqlength);
	for(i = 0; i < n; i++)
		if(ul[i] != numList[i])
			break;

	if(i == n)
		flag = 1;		

	else
	{
		flag = 0;
		int allpass = 0;
		if(! func(sortlength))
			sortlength = 2;
		
		else
		{
			while(sortlength >= 2 && allpass == 0)
			{
				allpass = 1;
				int k = n / sortlength;
				for(i = 0; i < k; i++)
					if(! issorted(numList+i*sortlength, sortlength))
					{
						allpass = 0;
						break;
					}

				if(! issorted(numList+k*sortlength, n-k*sortlength))
					allpass = 0;

				if(allpass == 0)
					sortlength /= 2;
			}
		}		
	}
	

	if(flag == 0)
	{
		printf("Merge Sort\n");
		int step = sortlength*2;
		if(step >= n)
			sort(numList, numList+n);
		else
		{
			int k = n/step;
			for(i = 0; i < k; i++)
				sort(numList+i*step, numList+(i+1)*step);
			if(n % step != 0)
				sort(numList+k*step, numList+n);
		}
	}
	else
	{
		printf("Insertion Sort\n");
		sort(numList, numList+seqlength+1);
	}

	for(i = 0; i < n; i++)
	{
		printf("%d", numList[i]);
		if(i < n - 1)
			printf(" ");
	}	
	printf("\n");

	return 0;
}