// floyd 
#include<stdio.h>
int min(int a,int b){
  if(a<b)
    return a;
  else
    return b;
}
void floyd(int p[10][10],int n){
int i,j,k;
for(k=1;k<=n;k++){
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
if(i==j)
 p[i][j] = 0;
else
  p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
}
}
}
}
int main(){
int p[10][10],i,j,k,n;
printf("enter the number of nodes:");
scanf("%d",&n);
printf("enter the adj matrix:\n");
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
 scanf("%d",&p[i][j]);
 if(p[i][j]==0)
   p[i][j] =999;
}
}
floyd(p,n);
printf("the shortest path are:");
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
if(i!=j)
   printf("<%d %d>=%d ",i,j,p[i][j]);
}
printf("\n");
}
return 0;
}










//warshal
#include<stdio.h>
int max(int a,int b){
  if(a<b)
    return b;
  else
    return a;
}
void warshall(int p[10][10],int n){
int i,j,k;
for(k=1;k<=n;k++){
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
  p[i][j]=max(p[i][j],(p[i][k]&&p[k][j]));
}
}
}
}
int main(){
int p[10][10],i,j,k,n;
printf("enter the number of nodes:");
scanf("%d",&n);
printf("enter the adj matrix:\n");
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
 scanf("%d",&p[i][j]);
}
}
warshall(p,n);
printf("the transitive closure matrix :");
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
   printf(" %d ",p[i][j]);
}
printf("\n");
}
return 0;
}


