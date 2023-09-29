#include<stdio.h>
#include<stdlib.h>
struct node
{
    int ID;
    char Name[100];
    int hour;
    struct node *next;
};
int f=0;
struct node *head,*current,*previous;

void Add(int x)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->ID=x;
    printf("Name: ");
    scanf(" %[^\n]s",newnode->Name);
    printf("Required Hour: ");
    scanf("%d",&newnode->hour);
    printf("\n");

    printf("\"%s\" task added.\n\n",newnode->Name);

    if(f==1)head=newnode;
    else
    {
        previous->next=newnode;
    }
    previous=newnode;
    previous->next=NULL;



}
void Remove(int x)
{
    struct node *p,*back;
    p=head;
    while(p!=NULL)
    {
        if(head->ID==x)
        {
            printf("\"%s\" task removed.\n",head->Name);
            head=head->next;
            break;
        }
        else if(p->ID==x && p->next==NULL)
        {
            printf("\"%s\" task removed.\n",p->Name);
            back->next=NULL;
            previous=back;
            break;
        }
        else if(p->ID==x)
        {
            printf("\"%s\" task removed.\n",p->Name);
            back->next=p->next;
            break;
        }
        back=p;
        p=p->next;

    }
}


void display()
{
    struct node *p1=head;
    int total=0;
    printf("\nPending tasks:\n");
    while(p1 != NULL)
    {

        printf("%s - %d hr\n",p1->Name,p1->hour);
        total+=p1->hour;
        p1=p1->next;
    }
    printf("Total required time: %d hr\n\n",total);
}



int main()
{
    while(1)
    {
        f++;
        printf("Daily Task Planner:\n");
        printf("   1.Add a task\n");
        printf("   2.remove a task\n");
        printf("   3.Display task\n");
        printf("   4.Exit\n\n");
        int choice,x;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice==4)break;
        else if(choice==1)
        {
            printf("Task ID: ");
            scanf("%d",&x);
            Add(x);
        }
        else if(choice==2)
        {
            printf("Task ID: ");
            scanf("%d",&x);
            Remove(x);
        }
        else
        {
            display();
        }



    }
    return 0;
}
