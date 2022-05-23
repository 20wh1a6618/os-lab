#include<stdio.h>
int main(){
        int n;
        float avgwt=0,avgtt=0;
        printf("Enter the number of process");
        scanf("%d",&n);
        int bt[n],wt[n],tt[n];
        printf("Enter the Burst time for %d processes",n);
       for(int i = 0;i < n;i++){
               scanf("%d",&bt[i]);
       }
       wt[0] = 0;
       for(int i = 1;i < n;i++){
               wt[i] = bt[i-1] + wt[i-1];
       }
       for(int i = 0;i < n;i++){
               tt[i] = bt[i] + wt[i];
       }
       printf("Processes        Burst time      Waiting time    Turn around time\n");
       for(int i = 0;i < n;i++){
               avgwt += wt[i];
               avgtt += tt[i];
               printf("%d                %d              %d              %d\n",i+1,bt[i],wt[i],tt[i]);
       }
       printf("Average Waiting Time = %f\n",avgwt/n);
       printf("Average Turn around Time = %f",avgtt/n);
}

