#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, chk[10001]={}, num_input;
	char name[10001][20], name_input[20];
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	{
		scanf("%s %d", &name_input, &num_input);
		if(!chk[num_input])
		{
			strcpy(name[num_input], name_input);
			chk[num_input]=1;
		}
		else
		{
			chk[num_input]=-1;
		}
	}
	for(i=10000; i>0; i--)
	{
		if(chk[i]==1)
		{
			printf("%s", name[i]);
			return 0;
		}
	}
	printf("NONE");
	
	return 0;
}
