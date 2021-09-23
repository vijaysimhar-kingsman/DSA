#include<stdio.h>
#include<stdlib.h>

void dfs(int el,int sz,int mat[sz][sz],int visit[]){
	int i=0;
	if(visit[el]==0){
		printf("%d ",el);
		visit[el]=1;
	}
	
	
	for (i=0;i<sz;i++){
		if(mat[el][i]==1 && visit[i]==0){
			dfs(i,sz,mat,visit);
		}
	}
}
int main(){
		int sz;
	printf("enter the size of your matrix: ");
	scanf("%d",&sz)	;
	int mat[sz][sz];
	int i=0,j=0;
	for(i=0;i<sz;i++){
		for(j=0;j<sz;j++){
			printf("enter element of a[%d][%d]",i,j);
			scanf("%d",&mat[i][j]);
		}
	}int visit[sz];
	for(i=0;i<sz;i++){
		visit[i]=0;
	}	
	int el=0;
	
	dfs(el,sz,mat,visit);
	for(i=0;i<sz;i++){
		if(visit[i]==0){
			dfs(i,sz,mat,visit);
		}
	}


}










