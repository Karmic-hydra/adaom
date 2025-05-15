#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b){
int c=*a;
*a=*b;
*b=c;
}

int partition(int a[],int low,int high){
int pivot=a[high];
int i=low-1;
for(int j=low;j<high-1;j++){
if(a[j]<=pivot){
i++;
swap(&a[i+1],&a[j]);
}
}
swap(&a[i+1],&a[high]);
return i+1;
}
void quicksort(int a[],int low,int high){
if(low<high){
int pi=partition(a,low,high);
quicksort(a,low,pi-1);
quicksort(a,pi+1,high);

}

}

int main(){
srand(time(NULL));
int arr[100000],n=100000;
int ele[n];
for(int i=0;i<n;i++){
ele[i]=rand()%1000;
}
printf("Elements :\t\tsorting time:   \n");
for(int size=5000;size<=n;size+=2000){
int ele[size];
for(int i=0;i<size;i++) arr[i]=ele[i];
clock_t start=clock();
quicksort(arr,0,size);
clock_t stop=clock();

double time_taken=((double)(stop-start)/CLOCKS_PER_SEC);
printf("%d\t\t%f seconds\n",size,time_taken);
}

return 0;
}
