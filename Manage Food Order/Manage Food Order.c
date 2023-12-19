#include<stdio.h>
#include<stdlib.h>
struct food_order
{
    int food_number;
    char size;
    int quantity;
    struct food_order *link;
};
typedef struct food_order node;
node *front=NULL,*end=NULL;
int total=0,served=0;

int isempty()
{
    if(front==NULL && end==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void place_order(int fd_number,char s,int qnty)
{
    node *new1=malloc(sizeof(node));
    if(isempty())
    {
        front=new1;
        end=new1;
        end->food_number=fd_number;
        end->size=s;
        end->quantity=qnty;
        end->link=NULL;
        total++;
    }
    else
    {
        new1->food_number=fd_number;
        new1->size=s;
        new1->quantity=qnty;
        end->link=new1;
        end=new1;
        end->link=NULL;
        total++;
    }
}
void serve_order()
{
    if(!isempty())
    {
        if(front==end)
        {
            printf("\nFood Number: %d\n",front->food_number);
            printf("Size: %c\n",front->size);
            printf("Quantity: %d\n",front->quantity);
            printf("Order has Served.\n");
            front=NULL;
            end=NULL;
            served++;
        }
        else
        {
            printf("\nFood Number: %d\n",front->food_number);
            printf("Size: %c\n",front->size);
            printf("Quantity: %d\n",front->quantity);
            printf("Order has Served.\n");
            front=front->link;
            served++;

        }
    }
    else
    {
        printf("\nBefore Please order any food.\n");
    }
}
void display()
{
    printf("\nTotal Order Received: %d\n",total);
    printf("Total Order Served: %d\n",served);
    printf("Order Waiting: %d\n",total-served);
}
int main()
{
    while(1)
    {
        printf("\n  ***Food Order***\n");
        printf("--------------------\n");
        printf("    1. Place Order\n");
        printf("    2. Serve Order\n");
        printf("    3. Display Order\n");
        printf("    4. Exit\n");

        int choice,x;
        printf("Enter your Choice: ");
        scanf("%d",&choice);
        if(choice==4)
        {
            printf("\nThank you\n");
            break;
        }
        else if(choice==1)
        {
            int food_number;
            char size;
            int quantity;
            printf("\nEnter food number: ");
            scanf("%d",&food_number);
            printf("Enter Size(S/M/L): ");
            scanf(" %c",&size);
            printf("Enter the quantity: ");
            scanf("%d",&quantity);

            place_order(food_number,size,quantity);
        }
        else if(choice==2)
        {
            serve_order();
        }
        else if(choice==3)
        {
            display();
        }
        else
        {
            printf("\nInvalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
