#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	while(n)
	{
		int arr[100005];
		for(int i=1;i<=n;i++)
			scanf("%d",&arr[i]);
		int barr[100005];
		for(int i=1;i<=n;i++)
			barr[arr[i]]=i;
		
			int i;
		for(i=1;i<=n;i++)
		{
			if(arr[i]!=barr[i])
			break;
 
 
		}
//printf("%d",i);
		if(i==n+1)
			printf("ambiguous\n");
		else
			printf("not ambiguous\n");
 
		scanf("%d",&n);
	}
	return 0;
}

