#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char ch[20];
	int n;




}person;

int main()
{

	person * abc=(person *)malloc(3*sizeof(person));
	for(int i=0;i<3;i++)
	{
		gets(abc[i].ch);
		abc[i].n=i+1;
	}
	for(int i=0;i<3;i++)
	{
		printf("%d %s \n",abc[i].n,abc[i].ch);
		
	}

}
