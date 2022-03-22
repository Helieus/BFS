#include<stdio.h>
#include <string.h>
#include <stdlib.h>


int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;

void bfs(int v) {
	for (i=1;i<=n;i++)
		if(a[v][i] && !visited[i])
			q[++r]=i;
	
	if(f<=r) 
	{
		visited[q[f]]=1;
		bfs(q[f++]);
	}
}

int main() 
{	
	FILE *fp;
	char filename[8];
	char filename_output[15];
	int t1,t2,t3;
	char tc;
	strcpy(filename,"data");
	strcpy(filename_output,"data_output");
	
	strcat(filename, ".txt");
	strcat(filename_output, ".txt");
	FILE* oututFile = openOutputFile(filename_output);
   
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s. Please place the input files in the same directory with the executable!\r\n",filename);
        return -1;
    }
    
    
	int v;
	
/*	printf("\n Enter the number of vertices:");
	
	scanf("%d",&n);*/
	n=15;
	for (i=1;i<=n;i++) 
	{
		q[i]=0;
		visited[i]=0;
	}
//	printf("\n Enter graph data in upper-triangular (not including the diagonal) matrix form using 1 for existing and 0 for non-existing edges:\n");
	
	
	
//	while (fgets(a, fp) != NULL)
	
	
	
	for (i=1;i<=n;i++)
	{
		for (j=i+1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			a[j][i] = a[i][j];	//just to make matrix symmetric
		}
	}
	
	printf("\n Enter the starting vertex:");
	scanf("%d",&v);
	bfs(v);
	printf("\n The nodes which are reachable are:\n");
	for (i=1;i<=n;i++)
	{
		if(visited[i])
			printf("%d\t",i); 	
		else
			printf("\n Bfs is not possible\r\n");
	}
	
	return 1;
}
