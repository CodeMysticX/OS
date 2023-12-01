#include<stdio.h>
#include<stdlib.h>
struct process{
  int PID;
  int AT;
  int BT;
  int CT;
  int TAT;
  int WT;
  int RT;
  int start_time;
};
int max(int a,int b){
  if(a<b){
    return b;
  }
  return a;
}
int comparator(const void *a,const void* b){
 int x=((struct process *)a)->AT;
 int y=((struct process *)b)->AT;
 if(x<y){
 return -1;
 }
 else if(x>=y){
  return 1;
 }

}
int completion_time_IT(int n ,struct process *p){
    int temp=0;
    p[0].CT=p[0].AT+p[0].BT;
    p[0].start_time=p[0].AT;
 for(int i=1;i<n;i++){
    if(p[i].AT>p[i-1].CT){
        p[i].CT=p[i].AT+p[i].BT; 
        temp=temp+(p[i].AT-p[i-1].CT);
    }
    else{
        p[i].CT=p[i-1].CT+p[i].BT;
    }
    p[i].start_time=max(p[i-1].CT,p[i].AT);
    }
 return temp;
}
void turn_around_time(int n,struct process *p){
   for(int i=0;i<n;i++){
    p[i].TAT=p[i].CT-p[i].AT;
   }
}
void waiting_time(int n,struct process *p){
  for(int i=0;i<n;i++){
    p[i].WT=p[i].TAT-p[i].BT;
    p[i].RT=p[i].start_time-p[i].AT;
  }

}
void print(int n,struct process *p){
     printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].PID,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT,p[i].RT);
    }
}
int main(){
    int n;
    printf("enter the number of processes:\n");
    scanf("%d",&n);
    struct process p[n];
    printf("enter the arrival time and burst time:\n");
    for(int i=0;i<n;i++){
        printf("enter arrival time and burst time for process %d:->",i+1);
        scanf("%d %d",&p[i].AT,&p[i].BT);
        p[i].PID=i+1;
    }
    printf("Pno.\tAT\tBT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\n",p[i].PID,p[i].AT,p[i].BT);
    }

    qsort(p,n,sizeof(struct process),comparator);
    printf("after sorting:\n");
     printf("Pno.\tAT\tBT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\n",p[i].PID,p[i].AT,p[i].BT);
    }
    int IT=completion_time_IT(n,p);
     turn_around_time(n,p);
     waiting_time(n,p);
     print(n,p);
     int T=p[n-1].CT; //total time
     float cpu_utz=(float)(T-IT)/(float)T;
     float avg_wt,avg_tat;
     float sum_wt=0,sum_tat=0;
     for(int i=0;i<n;i++){
       sum_wt+=p[i].WT;
       sum_tat+=p[i].TAT;

     }
     float throughput=(float)n/(float)T;
     avg_wt=sum_wt/(float)n;
     avg_tat=sum_tat/(float)n;
     printf("average waiting time = %f \n",avg_wt);
     printf("average turn around time = %f \n",avg_tat);
     printf("ideal time in %f \n",((float)IT/T)*100);
     printf("cpu utilization time int %f:\n",cpu_utz*100);
     printf("throughput is %f \n",throughput);
     return 0;
}
