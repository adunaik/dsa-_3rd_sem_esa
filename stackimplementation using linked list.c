#include <stdio.h>
#include <stdlib.h>

// Structure to create a node with data and the next pointer
struct node
{
    int info;
    struct node *ptr;
}*top,*top1,*temp;

int count = 0;
// Push() operation on a  stack
void push(int data)
{
     if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
    printf("Node is Inserted\n\n");
}

int pop()
{
     top1 = top;

    if (top1 == NULL)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else
        top1 = top1->ptr;
    int popped = top->info;
    free(top);
    top = top1;
    count--;
    return popped;
}

void display()
 {
    // Display the elements of the stack
    top1 = top;

    if (top1 == NULL)
    {
        printf("\nStack Underflow\n");
        return;
    }

    printf("The stack is \n");
    while (top1 != NULL)
    {
        printf("%d--->", top1->info);
        top1 = top1->ptr;
    }
    printf("NULL\n\n");

}

int main()
{
    int op,item,h;
    FILE  *fp1=fopen("rNolinkedlist.txt","w");

    for(int i=0;i<10;i++)
    {
        item=rand()%100;
        fprintf(fp1,"%d ",item);
    }
    fclose(fp1);
    int k;
    FILE *fp2=fopen("rNolinkedlist.txt","r");
    while(1)
   {

    printf("Enter the option\n");
    printf(" 1: push into stack\n 2:pop\n 3:display \n");
    scanf("%d",&op);
    operdis(op);
    switch(op)
    {
        case 1:fscanf(fp2,"%d",&k);
               push(k);
               pushed(k);
               break;
        case 2:
                 h=pop();
                poped(h);
               break;
        case 3:
            display();
               break;
    }

   }
   fclose(fp2);
}
void operdis(int op)
{
  FILE *fp5=fopen("operationlinked.txt","a");
    char str1[]="push()";
    char str2[]="pop()";
    if(op==1)
    {
        fprintf(fp5,"%s\n",str1);
    }
    else if(op==2)
    {
        fprintf(fp5,"%s\n",str2);
    }
    fclose(fp5);
}

void pushed(int k)
{
    FILE *fp2=fopen("pushedlinked.txt","a");
    fprintf(fp2,"%d ",k);
    fclose(fp2);
}
void poped(int item)
{
      FILE *fp4=fopen("popedlinked.txt","a");
      fprintf(fp4,"%d ",item);
     fclose(fp4);
}
