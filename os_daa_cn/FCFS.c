#include <stdlib.h>
#include <stdio.h>

struct pcb
{

    int burst_time, id, waiting_time;

    struct pcb *next;
};
struct queue
{
    struct pcb *head;
    struct pcb *tail;
};

void add_pcb(struct queue *fcfs, struct pcb *temp)
{
    if (fcfs->head == NULL)
    {
        fcfs->head = temp;
        fcfs->tail = temp;
    }

    else
    {

        fcfs->tail->next = temp;
        fcfs->tail = temp;
    }
}

void main()
{
    int n, i, time;
    double avg, total_waiting_time;

    printf("\nEnter the number of processes : ");
    scanf("%d", &n);

    struct pcb *temp;

    struct queue fcfs;
    fcfs.head = NULL;
    fcfs.tail = NULL;

    for (i = 0; i < n; i++)
    {
        temp = (struct pcb *)malloc(sizeof(struct pcb));

        temp->next = NULL;

        printf("Enter the name of process id : ");
        scanf("%d", &(temp->id));
        printf("Enter the cpu burst time (in ns) : ");
        scanf("%d", &(temp->burst_time));
        printf("\n");
        add_pcb(&fcfs, temp);
    }
    printf("\n\n");
    printf("Process ID\t\t\tProcess waiting time\n\n");

    time = 0;
    total_waiting_time = 0.0;

    temp = fcfs.head;

    while (temp != NULL)
    {
        total_waiting_time = total_waiting_time + time;
        temp->waiting_time = time;

        printf("%d\t\t\t\t%d\n", temp->id, temp->waiting_time);
        time = time + temp->burst_time;
        temp = temp->next;
    }
    avg = (double)(total_waiting_time / n);
    printf("the average waiting time of the processes is : %f\n", avg);

    //  to draw the gantt chart

    temp = fcfs.head;

    
    i = 0;
    printf("\nPROCESS ID\n");

    while (temp != NULL)
    {
        printf("%d", temp->id);
        for (i = 1; i < temp->burst_time; i++)
        {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n ");
    i=0;
    while (i < fcfs.tail->waiting_time + fcfs.tail->burst_time)
    {
        printf("-");
        i++;
    }
    printf("\n");

    temp = fcfs.head;
    while (temp != NULL)
    {
        printf("|");
        for (i = 1; i < temp->burst_time; i++)
        {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("|");
    printf("\n ");
    i=0;
    while (i < fcfs.tail->waiting_time + fcfs.tail->burst_time)
    {
        printf("-");
        i++;
    }
    printf("\n");

    temp = fcfs.head;
    
    while (temp!=NULL)
    {
        printf("%d",temp->waiting_time);
        for (i = 2; i < temp->burst_time; i++)
        {
            printf(" ");
        }
        temp = temp->next;

        
    }
    printf("%d",fcfs.tail->burst_time+fcfs.tail->waiting_time);

    

}
