#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct process
{
    int id, arrival_time, burst_time, waiting_time, turn_around_time, priority, rbt;
    struct process *next;
};

struct gc
{
    int process_id, cpu_all_time;
    struct gc *next;
};

struct process *temp, *pq, *pq_tail, *wtq, *running_process, *current;
struct gc *gc_head, *gc_tail, *t;
int time;

void addgc(int id)
{
    t = (struct gc *)malloc(sizeof(struct gc));
    t->process_id = id;
    t->cpu_all_time = time;
    t->next = NULL;
    if (gc_head == NULL)
    {
        gc_head = t;
        gc_tail = t;

        return;
    }

    gc_tail->next = t;
    gc_tail = gc_tail->next;
}
int wt_to_pq()
{

    if (wtq == NULL)
    {
        return 0;
    }
    running_process->next = wtq;

    running_process = running_process->next;
    wtq = wtq->next;
    running_process->next = NULL;
    running_process->waiting_time += time - running_process->arrival_time;
    return 1;
}

void addto_pq()
{
    if (pq == NULL)
    {
        pq = temp;
        running_process = temp;
        return;
    }
    running_process->next = temp;
    running_process = temp;
}

void addto_wtq(struct process *temp)
{
    if (wtq == NULL)
        wtq = temp;

    else if (wtq->next == NULL)
    {
        if (wtq->priority <= temp->priority)
            wtq->next = temp;

        else
        {
            temp->next = wtq;
            wtq = temp;
        }
    }

    else
    {
        struct process *c;
        current = wtq;

        while (current->next->priority < temp->priority && current->next != NULL)
        {
            current = current->next;
        }

        c = current->next;
        current->next = temp;
        temp->next = c;
    }
}

void pq_to_wtq()
{
    addto_wtq(running_process);

    if (pq == running_process)
    {
        pq = NULL;
        running_process = NULL;
        return;
    }

    struct process *c;
    c = pq;
    while (c->next != running_process)
    {
        c = c->next;
    }
    c->next = NULL;
    running_process = c;
}

void idle()
{
    int flag;

    do
    {
        flag = wt_to_pq();

        if (flag)
        {
            addgc(running_process->id);
            time = time + running_process->rbt;
        }

        else
        {
            addgc(0);
            break;
        }
    } while (time + running_process->rbt < temp->arrival_time);
}

void gantt_chart(struct gc *head)
{
    printf("\n+");

    t = head;
    while (t != NULL)
    {
        printf("---------------+");
        t = t->next;
    }
    printf("\n|");
    t = head;
    while (t != NULL)
    {

        if (t->process_id == 0)
        {
            printf("     IDLE      |");
        }
        else
        {
            printf("      P0%d      |", t->process_id);
        }

        t = t->next;
    }
    printf("\n+");

    t = head;
    while (t != NULL)
    {
        printf("---------------+");
        t = t->next;
    }
    printf("\n");
    t = head;
    while (t != NULL)
    {
        if (t->cpu_all_time < 10)
            printf("%02d              ", t->cpu_all_time);
        else
            printf("%d              ", t->cpu_all_time);
        t = t->next;
    }
    printf("%d\n", gc_tail->cpu_all_time + running_process->burst_time);
    printf("\nhere");
}

void input()
{

    temp = (struct process *)malloc(sizeof(struct process));
    temp->next = NULL;
    temp->waiting_time = 0;
    printf("\nEnter the name of process id : ");
    scanf("%d", &(temp->id));
    printf("Enter the process arrival time : ");
    scanf("%d", &(temp->arrival_time));
    printf("Enter the process priority : ");
    scanf("%d", &(temp->priority));
    printf("Enter the cpu burst time (in ns) : ");
    scanf("%d", &(temp->burst_time));
    printf("\n");
    temp->rbt = temp->burst_time;
}

void main()
{

    int i, n, flag;
    float total_waiting_time, total_turnaround_time, avg_turnaround, avg_waiting_time;
    time = 0;
    pq = NULL;
    wtq = NULL;
    gc_head = NULL;
    running_process == NULL;

    printf("\nEnter the number of processes : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\ntime = %d ::", time);

        input();

        if (running_process == NULL)
        {
            if (temp->arrival_time != 0)
            {
                addgc(0);
            }

            time = temp->arrival_time;
            addto_pq();
            addgc(running_process->id);
            continue;
        }

        if (running_process->rbt + time < temp->arrival_time && running_process != NULL)
        {
            idle();
        }

        if (running_process->priority <= temp->priority)
        {

            addto_wtq(temp);
            continue;
        }
        else
        {
            running_process->rbt -= temp->arrival_time - time;
            time = temp->arrival_time;
            running_process->arrival_time = time;

            pq_to_wtq();

            addto_pq();
            addgc(running_process->id);
            running_process->waiting_time += time - running_process->arrival_time;
        }
    }

    time += running_process->rbt;
    current = wtq;
    flag = 1;

    while (current != NULL)
    {
        wt_to_pq();
        addgc(running_process->id);
        time += running_process->rbt;
        current = wtq;
    }

    current = pq;
    total_waiting_time = 0.0;
    total_turnaround_time = 0.0;
    printf("\nProcess id    priority    waiting time    turnaround time\n");
    while (current != NULL)
    {
        current->turn_around_time = current->burst_time + current->waiting_time;

        printf("\n     %d           %d              %d              %d  ", current->id, current->priority, current->waiting_time, current->turn_around_time);
        total_waiting_time += current->waiting_time;
        total_turnaround_time += current->turn_around_time;
        current = current->next;
    }

    avg_waiting_time = total_waiting_time / n;
    avg_turnaround = total_turnaround_time / n;
    printf("\n\nThe average waiting time is %f\n", avg_waiting_time);
    printf("\nThe average turn around time is %f\n", avg_turnaround);

    gantt_chart(gc_head);
    return;
}