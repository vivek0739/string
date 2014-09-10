#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
bool compare(char arr1[], char arr2[])
{
	int i;
    for (i=0; i<256; i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}
int main()
{
	int count=0;
	char txt[300];
	char patt[300];
	char hashp[256]={0};
	char hasht[256]={0};
	scanf("%s%s",txt,patt);
	int n=strlen(txt);
	int i;
	
	int m=strlen(patt);

	for(i=0;i<m;i++)
		hashp[patt[i]]++,hasht[txt[i]]++;
	for(i=m;i<n;i++)
	{
		if(compare(hashp,hasht))
			printf("%d\n",i-m);
		hasht[txt[i]]++;
		hasht[txt[i-m]]--;
	}
	if(compare(hashp,hasht))
			printf("%d\n",i-m);

}