#include <stdio.h>
#include <stdlib.h>
struct node
{
    long int arrival;
    long int duration;
    int done;
};
struct node tasks[100000];
struct node temp[100000];
int main()
{
    long int n,i;
    scanf("%ld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%ld %ld",&(tasks[i].arrival), &(tasks[i].duration));
        tasks[i].done=0;
    }
    long int time=0;
    long int min= 1000000000;
    long long int waitime=0;
    long int minindex;
    long int tasksdone=0;
    while(1)
    {
        min= 1000000000;
        for(i=0;i<n;i++)
            {
                if(tasks[i].done==0&&tasks[i].arrival<=time&&tasks[i].duration<min)
                {
                    min=tasks[i].duration;
                    minindex=i;
                }
            }
            if(min<1000000000){
            waitime+=(time-tasks[minindex].arrival);
            waitime+=tasks[minindex].duration;
            tasks[minindex].done=1;
            time+=tasks[minindex].duration;
            printf("Task with arrival %ld and duration %ld is done\n", tasks[minindex].arrival,tasks[minindex].duration);
            tasksdone++;
            }
            else
                {


                    time++;
                }

            if(tasksdone==n)
                break;
    }
    printf("%lld\n", waitime);
}
