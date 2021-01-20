#include<stdio.h>
#include<stdlib.h>
void swap(int a[],int i ,int j){
	int temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void quicksort(int a[],int start,int end){
	if(end-start >1){
		int pivot =a[start];
		int i;
		i= start+1;
		int j;
		j = end;
		while(i<j){
			while(a[i]<pivot && i<j){
				i++;
			}while(a[j]>pivot && i<j){
				j--;
			}if(j!=i){
				swap(a,i,j);
			}
		}if(j-1!=0){
			swap(a,start,j-1);
		}if(j-1!=0){
			quicksort(a,start,j-2);
		}if(i<end){
			quicksort(a,j,end);
		}
	}else{
		if(a[start]>a[end]){
			swap(a,start,end);
		}
	}
}
int main(){
	int len;
	printf("\nEnter no of elements you wanna sort: ");
	scanf("%d",&len);
	int end;
	end=len-1;
	int start;
	start=0;
	int k=0;
	int a[len];
	while(k<len){
		printf("\nEnter  index element: ");
		scanf("%d",&a[k]);
		k++;	
	}
	quicksort(a,start,end);
	int l=0;
	while(l<len){
		printf("%d ",a[l]);	
		l++;		
	}
}


