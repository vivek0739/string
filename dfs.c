#include<stdio.h>
#include<stdlib.h>
struct adj_list_node
{
	int dest;
	int weight;
	struct adj_list_node *next;
};
struct adj_list
{
	struct adj_list_node *head;
};
struct Graph
{
	int v;
	struct adj_list *arr;
};
 struct Graph *intialise(int v)
{
	struct Graph *g=(struct Graph *)malloc(sizeof(struct Graph));
	g->v=v;
	g->arr=(struct adj_list*)malloc(sizeof(struct adj_list)*v);
	int i;
	for(i=0;i<v;i++)
		g->arr[i].head=NULL;
	return g;
}
void addEdge(struct Graph *g ,int v,int w,int weight)
{
	struct adj_list_node *temp;
	temp=(struct adj_list_node*)malloc(sizeof(struct adj_list_node));
	temp->dest=w-1;
	temp->weight=weight;
	temp->next=g->arr[v-1].head;
	g->arr[v-1].head=temp;
}
void DFS(struct Graph *g,int v,int visited[])
{
	printf("%d\t",v+1);
	visited[v]=1;
	struct adj_list_node *temp=g->arr[v].head;
	while(temp)
	{
		if(!visited[temp->dest])
		DFS(g,temp->dest,visited);
		temp=temp->next;

	}
}
void topological(struct Graph *g,int v,int visited[],int stack[],int *top)
{
	
	visited[v]=1;
	struct adj_list_node *temp=g->arr[v].head;
	while(temp)
	{
		if(!visited[temp->dest])
		topological(g,temp->dest,visited,stack,top);
		temp=temp->next;

	}
	stack[++(*top)]=v+1;
	printf("%d\t",*top);
}
int main()
{
	struct Graph *g=NULL;
	g=intialise(3);
	addEdge(g,1,2,1);
	addEdge(g,1,3,1);
	addEdge(g,3,2,1);
	int visited[7]={0,};
	//DFS(g,0,visited);
	int stack[10]={0,};
	int top=-1,i;
	topological(g,0,visited,stack,&top);
	for( i=top;i>=0;i--)
		printf("%d ",stack[i]);
	return 0;


}