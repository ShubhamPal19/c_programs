#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int n, i;
struct node *current;
struct node
{
    int object, profit, weight;
    float p_w_ratio, quantity;
    struct node *next;
};

void input(struct node *temp)
{
    temp->next = NULL;
    temp->object = i;

    printf("\nEnter the object %d profit : ", i);
    scanf("%d", &temp->profit);
    printf("\nEnter the object %d weight : ", i);
    scanf("%d",&temp->weight);

    temp->p_w_ratio = (float)(temp->profit / temp->weight);
}
void insert(struct node *temp, struct node **head) //instert the node in descending order and maintain the sorted order
{
    if (*head == NULL)
    {
        *head = temp;

    }

    current = *head;

    while (current->p_w_ratio > temp->p_w_ratio && (current->next  != NULL))
    {
        current = current->next;
    }
    temp->next = current->next;
    current->next = temp;
  

}


double calculate_profit(struct node * head)
{
    double profit;
    current=head;

    while (current!= NULL)
    {
      profit = profit+current->profit*current->quantity;
     current=current->next;
    }

    return profit;

}
void main()
{
    int bag_size,occupied,remaining;
    double net_profit;
    printf("\nEnter the number of objects : ");
    scanf("%d",&n);
    struct node *temp, *head;
    head = NULL;
    

    for (i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        input(temp);
       insert( temp, &head);
    }

    printf("\nEnter the maximum weight of bag : ");
    scanf("%d",bag_size);

    remaining=bag_size;
    current=head;

    while(current!=NULL)
   {
      if(remaining==0)
      {
          current->quantity=0;
          current=current->next;
          continue;
      }
      
      if(remaining>current->weight)
      {
          current->quantity=1;
          remaining -= current->weight;
      }
      else
      {  
          current->quantity= remaining/current->weight;
      remaining=0;
      }

      current=current->next;


      

   }



   net_profit=calculate_profit(head);


   printf("\n\tObject\tprofit\tweight\tp/w ratio\tquantity");
   current=head;
   while (current!=NULL)
   {
      printf("\n\t  %d \t %d \t %d \t    %f  \t %f ",current->object,current->profit,current->weight,current->p_w_ratio,current->quantity);

      current= current->next;

   }
   

   printf(" The maximum profit is :  %f ",net_profit);
   
    






}