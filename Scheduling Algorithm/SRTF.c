#include<stdio.h>
#define INT_MAX 1e9
struct process{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
    int start_time;

};
int main(){
    struct process p[100];
    int n;
    printf("enter the no of processes:\n");
    scanf("%d",&n);
    int rem_bt[n];
    for(int i=0;i<n;i++){
        p[i].pid=i;
        printf("enter the arrival time and burst time for process %d :->\n",i);
        scanf("%d %d",&p[i].at,&p[i].bt);
        rem_bt[i]=p[i].bt;
    }
    int iscompleted[n];
    for(int i=0;i<n;i++){
        iscompleted[i]=0;
    }
    int completed=0;
    int current_time=0;
    int ideal_time=0;
    while(completed!=n){
     int min_index=-1;
     int min=INT_MAX;
       for(int i=0;i<n;i++){
         if(p[i].at<=current_time && iscompleted[i]==0){
            if(rem_bt[i]<min){
                min=rem_bt[i];
                min_index=i;
            }
           else if(rem_bt[i]==min){
                if(p[i].at<p[min_index].at){
                    min=rem_bt[i];
                    min_index=i;
                }
            }
         }
       }
       if(min_index!=-1){
        if(p[min_index].bt==rem_bt[min_index]){
         p[min_index].start_time=current_time;
        }
        rem_bt[min_index]--;
        current_time++;
        if(rem_bt[min_index]==0){
        p[min_index].ct=current_time;
        p[min_index].tat=p[min_index].ct-p[min_index].at;
        p[min_index].wt=p[min_index].tat-p[min_index].bt;
        p[min_index].rt=p[min_index].start_time-p[min_index].at;
        completed++;
        iscompleted[min_index]=1;
        }
       }
       else{
        ideal_time++;
        current_time++;
       }


    }
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
    }
    int max_ct=-1;
    float sum_tat=0;
    float sum_wt=0;
    float avg_tat=0;
    float avg_wt=0;
    for(int i=0;i<n;i++){
        if(max_ct<p[i].ct){
            max_ct=p[i].ct;
        }
        sum_tat+=p[i].tat;
        sum_wt+=p[i].wt;
    }
    avg_tat=sum_tat/(float)n;
    avg_wt=sum_wt/(float)n;
    float throughput=(float)n/(float)max_ct;
    float cpu_utz=(float)(max_ct-ideal_time)*100/(float)max_ct;
    printf("\nideal time is %f \n",((float)ideal_time/(float)max_ct)*100);
    printf("cpu utilization time is %f \n",cpu_utz);
    printf("average tat %f \n",avg_tat);
    printf("average wt %f ",avg_wt);
    printf("throughout is %f ",throughput);
    return 0;


}


