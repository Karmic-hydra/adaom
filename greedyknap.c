#include<stdio.h>
#define MAX 50 
int p[MAX],w[MAX],x[MAX];
double maxprofit;
int n,m,i;
void greedyKnapsack(int n,int w[],int p[],int m){
double ratio [MAX];
for (i=0;i<n;i++){
ratio[i]=(double)p[i]/w[i];
}
for (i=0;i<n-1;i++){
for(int j=i+1;j<n;j++){
if (ratio[i]<ratio[j]){
double temp=ratio[i];
ratio[i]=ratio[j];
ratio[j]=temp;

int temp2 =w[i];
w[i]=w[j];
w[j]=temp2;
temp2= p[i];
p[i]=p[j];
p[j]=temp2;
}
}
}
int currentWieght=0;
maxprofit=0.0;
for (i=0;i<n;i++){
if(currentWieght+w[i]<=m){
x[i]=1;
currentWieght+=w[i];
maxprofit +=p[i];
}else{
x[i]=(m-currentWieght)/(double)w[i];
maxprofit +=x[i]*p[i];
break;
}
}
printf("optimal solution for greedy method:%.1f\n",maxprofit);
printf ("\nsolution vector for greedy method:\n");
for (i=0;i<n;i++)
printf("%d\t",x[i]);
}
int main(){
printf("enter the number of objects:");
scanf("%d",&n);
printf("enter the objects wieghts:");
for(i=0;i<n;i++)
scanf("%d",&w[i]);
printf("enter the objects profit:");
for (i=0;i<n;i++)
scanf ("%d",&p[i]);
printf("enter the maximum capacity:");
scanf ("%d",&m);
greedyKnapsack(n,w,p,m);
return 0;
}

