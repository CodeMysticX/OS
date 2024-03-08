#include<stdio.h>
struct Process{
    int A , B , C; 
};

int main()
{
    int n , A , B , C;
    printf("Enter the Number of Process - ");
    scanf("%d" ,&n);

    struct Process alloc[n];
    struct Process max[n];
    struct Process need[n];
    int isexecute[n];
    int ans[n];

    for(int i = 0 ; i < n ; i++)
        isexecute[i] = 0;
                
    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter the alloc and maxd Resources of P%d - " , i+1);
        scanf("%d%d%d" , &max[i].A , &max[i].B , &max[i].C);
        scanf("%d%d%d" , &alloc[i].A, &alloc[i].B, &alloc[i].C);

        need[i].A = max[i].A - alloc[i].A;
        need[i].B = max[i].B - alloc[i].B;
        need[i].C = max[i].C - alloc[i].C;  
    }

    printf("Enter the Available Resources : ");
    scanf("%d%d%d" , &A,&B,&C);

    int idx = 0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(isexecute[j] == 0){
                if(need[j].A <= A && need[j].B <= B && need[j].C <= C)
                {
                    A += alloc[j].A;
                    B += alloc[j].B;
                    C += alloc[j].C;

                    ans[idx] = j;
                    idx++;
                    isexecute[j] = 1;
                    break;
                } 
            }
        }
    }


    for(int i = 0 ; i < n ; i++)
    {
        if(isexecute[i] == 0)
        {
            printf("No Safe Sequence is Possible");
            return 0;
        }
    }
    for(int i=0; i<n; i++){
        printf("%d\t%d\t%d\n",need[i].A, need[i].B,need[i].C);
    }

    printf("The Safe Sequence is - ");
    for(int i = 0 ; i < n-1 ; i++)
    {
        printf("P%d ->" , ans[i]);
    }
    printf("P%d" , ans[n-1]);
    return 0; 
}    
