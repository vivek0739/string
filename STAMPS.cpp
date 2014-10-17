#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
}

int main()
{
	int t;
	scanf("%d",&t);
	int p=0;
	while(p++<t)
	{
			int m,n;
			scanf("%d%d",&m,&n);
			int arr[1005];
			for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
			qsort(arr,n,sizeof(int),compare);
			int i;
			for(i=0;i<n;i++)
			{
				if(arr[i]>=m)
				{
					m=0;
					break;
				}
					
				else
					m-=arr[i];
					
					
			}if(m>0)
				printf("Scenario #%d\nimpossible\n\n",p);
				else
				printf("Scenario #%d\n%d\n\n",p,i+1);
		
	}
}


