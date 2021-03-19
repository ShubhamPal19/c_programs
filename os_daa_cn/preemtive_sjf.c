#include <stdlib.h>
#include <stdio.h>

struct pcb
{

    int burst_time;
    int id;
    int waiting_time, cpu_all_time, arrival_time, tag;

    struct pcb *next, *partial_process;
};
struct queue
{
    struct pcb *head;
    struct pcb *tail;
} waitQ, SJF;

int i;

void add_pcb_to_sjf(struct queue *sjf, struct pcb *temp)
{

    if (sjf->head == NULL)
    {
        sjf->head = temp;
        sjf->tail = temp;
    }

    else
    {

        sjf->tail->next = temp;
        sjf->tail = temp;
    }
}
int compare_bursttime(struct pcb *p1, struct pcb *p2)
{

    if (p2 != NULL)

        if (p2 == NULL)
            return 0;

        else if (p1->burst_time >= p2->burst_time)
            return 1;

    return -1;
}

void add_pcb_to_wait(struct queue *wq, struct pcb *temp)
{

    if (wq->head == NULL)
    {
        wq->head = temp;
        wq->tail = temp;
        return;
    }

    struct pcb *current;

    current = wq->head;

    while (compare_bursttime(temp, current->next) == 1)
    {

        current = current->next;
    }
    temp->next = current->next;
    current->next = temp;
}

struct pcb *input_process()
{
    struct pcb *temp;

    temp = (struct pcb *)malloc(sizeof(struct pcb));

    temp->next = NULL;
    temp->partial_process = NULL;
    temp->waiting_time = 0;
    temp->tag = 1;

    printf("\nEnter the name of process id : ");
    scanf("%d", &(temp->id));
    printf("Enter the name of process arrival time : ");
    scanf("%d", &(temp->arrival_time));
    printf("Enter the cpu burst time (in ns) : ");
    scanf("%d", &(temp->burst_time));
    printf("\n");
    return temp;
}

void draw_gantt_chart(struct queue queue)
{

    struct pcb *temp;
    temp = queue.head;

    i = 0;
    printf("\nPROCESS ID\n");

    while (temp != NULL)
    {
        printf("%d", temp->id);
        for (i = 0; i < temp->burst_time; i++)
        {
            printf("  ");
        }
        temp = temp->next;
    }
    printf("\n ");
    i = -1;
    while (i <= queue.tail->cpu_all_time + queue.tail->burst_time)
    {
        printf("--");
        i++;
    }
    printf("\n");

    temp = queue.head;
    while (temp != NULL)
    {
        printf("|");
        for (i = 0; i < temp->burst_time; i++)
        {
            printf("  ");
        }
        temp = temp->next;
    }
    printf("|");
    printf("\n ");
    i = -1;
    while (i <= queue.tail->cpu_all_time + queue.tail->burst_time)
    {
        printf("--");
        i++;
    }
    printf("\n");

    temp = queue.head;

    while (temp != NULL)
    {
        printf("%d", temp->cpu_all_time);
        for (i = 0; i < temp->burst_time; i++)
        {
            printf("  ");
        }
        temp = temp->next;
    }
    printf("%d\n\n", queue.tail->burst_time + queue.tail->cpu_all_time);
}
int waitingQ_to_sjf()
{
    if (waitQ.head == NULL)

        return 0;

    SJF.tail->next = waitQ.head;
    SJF.tail = waitQ.head;
    waitQ.head = waitQ.head->next;

    SJF.tail->next = NULL;
    return 1;
}

int main()
{
    int n, i, time, id, flag, remaining_time, b_time;
    double avg, total_waiting_time;
    i = 0;
    struct pcb *partial_process;
    struct queue *waitingQ, *sjf;
    sjf = &SJF;
    waitingQ = &waitQ;

    printf("\nEnter the number of processes : ");
    scanf("%d", &n); 

    struct pcb *temp;

    sjf->head = NULL;
    sjf->tail = NULL;
    time = 0;

    for (i = 0; i < n; i++)
    {
        temp = input_process();
        if (compare_bursttime(temp, waitingQ->head) == 1)
        {
            add_pcb_to_wait(waitingQ, temp);
            continue;
        }

        if ((sjf->tail) != NULL)
        {

            b_time = sjf->tail->burst_time;

            while ((time + sjf->tail->burst_time) < temp->arrival_time)
            {
                time += sjf->tail->burst_time;
                flag = waitingQ_to_sjf();
                sjf->tail->cpu_all_time = time;
                if (!flag)
                {
                    printf("\ncpu is idle from time %d to %d\n", time, temp->arrival_time);
                    break;
                }
                sjf->tail->waiting_time = time - sjf->tail->arrival_time;
            }

            remaining_time = (sjf->tail->burst_time) - (temp->arrival_time - time);
            if ((remaining_time) > temp->burst_time)
            {
                time = temp->arrival_time;

                partial_process = (struct pcb *)malloc(sizeof(struct pcb));
                sjf->tail->partial_process = partial_process;
                sjf->tail->burst_time -= remaining_time;
                partial_process->arrival_time = time;
                partial_process->burst_time = remaining_time;
                partial_process->id = sjf->tail->id;
                partial_process->waiting_time = 0;
                partial_process->tag = 0;
                sjf->tail->next = temp;
                partial_process->next = NULL;
                add_pcb_to_wait(waitingQ, partial_process);
            }

            else
                time = time + sjf->tail->burst_time;
        }

        add_pcb_to_sjf(sjf, temp);
        temp->cpu_all_time = time;
    }

    temp = waitingQ->head;

    while (waitingQ->head != NULL)
    {
        time = time + sjf->tail->burst_time;

        waitingQ_to_sjf();
        sjf->tail->cpu_all_time = time;
    }

    printf("\n\n");
    printf("Process ID\tarrival time\t\tburst time\t\tProcess waiting time\tcpu allocation time\n\n");

    temp = sjf->head;

    while (temp != NULL)
    {
        temp->waiting_time = temp->cpu_all_time - temp->arrival_time;
        total_waiting_time += temp->waiting_time;

        printf("%d\t\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", temp->id, temp->arrival_time, temp->burst_time,  temp->waiting_time, temp->cpu_all_time);

        temp = temp->next;
    }

    printf("\nThe average waiting time of the processes is = %f\n", total_waiting_time / n);

    draw_gantt_chart(*sjf);

    return 0;
}
