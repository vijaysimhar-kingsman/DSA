#include<stdio.h>

void dfs(int n,int k, int visit[n],int graph[n][n]){
      if(visit[k] == 0){
         visit[k] = 1;
         printf("%d ",k);
         int j;
         for(j =0 ; j < n; j++){
                if(graph[k][j] == 1 && visit[j] == 0){
                      dfs(n,j,visit,graph);        }
                                   }
                        }
}
void main(){
   int n;
   printf("enter no of nodes ");
   scanf("%d",&n);
   int graph[n][n];
   int visit[n];
   int i,j,k;
   for(i = 0; i < n; i++)
   {
    for(j =0; j < n; j++)
    {
      scanf("%d",&graph[i][j]);
     }
    }
    printf("__the graph is__\n");
    for(i = 0; i < n; i++)
    {
     for(j = 0; j < n; j++)
     {
      printf("%d ",graph[i][j]);
     }
    printf("\n");
     }
    printf("__Depth first search__\n");
    for( j = 0; j < n; j++){
        visit[j]=0;} 
   for(k = 0; k < n; k ++){
         if(visit[k] != 1){
            dfs(n,k,visit,graph);
                          }
                  }
                               
}