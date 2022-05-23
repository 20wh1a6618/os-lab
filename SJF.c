#include<stdio.h>
int main(){
int n,bt[20],wt[20],tt[20],p[20],temp=0;
float avgwt = 0,avgtt = 0;
printf("Enter the number of processess\n");
scanf("%d",&n);
printf("Enter the burst time of the process\n");
for(int i = 0;i < n;i++){
scanf("%d",&bt[i]);
p[i] = i;
}
for(int i = 0;i < n-1;i++){
for(int j = i + 1;j < n;j++){
if(bt[i] > bt[j]){
temp = bt[i];
bt[i] = bt[j];
bt[j] = temp;
temp = p[i];
p[i] = p[j];
p[j] = temp;
}
}
}
wt[0] = 0;
for(int i = 1;i <= n;i++){
wt[i] = bt[i-1] + wt[i-1];
tt[i-1] = bt[i-1] + wt[i-1];
}
printf("Process\tBurst time\tWaiting time\tTurnaround time\n");
for(int i = 0;i < n;i++){
avgwt  += wt[i];
avgtt += tt[i];
printf("%d\t\t%d\t\t%d\t\t%d\t\t\n",i+1,bt[i],wt[i],tt[i]);

}
printf("Average waiting time is : %f\n",avgwt/n);
printf("Average turn around time is : %f",avgtt/n);
}
