// SPLIT-MAADI

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct split
{
    char name[20];
    float money;
    struct split *next;
};
typedef struct split node; 
node *start = NULL;
node *head = NULL;
node *first=NULL;
node *temp;
node *temp2;
int count=0;
node *create()
{
    node *new1;
    new1 = (node *)malloc(sizeof(node));
    printf("Enter member name\n");
    scanf("%s", new1->name);
    new1->next = NULL;
    return new1;
}
node *create2()
{
    node *new1;
    new1 = (node *)malloc(sizeof(node));
   printf("Description about expense\n");      
   scanf("%s",new1->name);
    new1->next = NULL;
    return new1;
}
void delete_member(char delete[])
{
    node *temp=start;
    node *prev=start;
    while(1)
    {
        if(strcmp(delete,temp->name)==0)
    {
    start=temp->next;
    free(temp);
    break;
    }
        if(strcmp(delete,temp->name)==0)
        {
            prev->next=temp->next;
        free(temp);
        break;
        }
        prev=temp;
        temp=temp->next;
    }
}
void add_members()
{
    node *newnode;
    temp = start;
    newnode = create();
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        // printf("%s\n", temp->name);
    }
}
void add_members2()
{
    node *newnode2;
    node *temp2 =head;
    newnode2 = create();
    if (head == NULL)
    {
    head = newnode2;
    }
    else
    {
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = newnode2;
        // printf("%s\n", temp->name);
    }
}
void add_members3(float money)
{
    node *newnode2;
    node *temp2 =first;
    newnode2 = create2();
    if (first == NULL)
    {
    first = newnode2;
    first->money=money;
    }
    else
    {
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = newnode2;
        newnode2->money=money;
        // printf("%s\n", temp->name);
    }

}
void add_expenses(float money, int n)
{
    node *temp = start;
    temp->money = 0;
    while (temp != NULL)
    {
        temp->money = temp->money + money / n;
        temp = temp->next;
    }
}
void personal_expense(node *new1)
{

    int ch;
    float amount;
    while (1)
    {
        printf("1. Add personal expense 2. Display 3.Exit \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter amount\n");
            scanf("%f", &amount);
            add_members3(amount);
            new1->money = new1->money + amount;
            break;
        case 2:
            printf("Total Expense\n");
            printf("%f\n", new1->money);
            break;
        case 3:
            break;
        default:
            printf("invalid Input\n");
            break;
        }
        if(ch>=3)
        break;
    }
}
void custom_split(float money, int m)
{
    node *temp = start;
    if(count==0)
    temp->money=0;
    for (int i = 0; i < m; i++)
    {
        add_members2();
    }
    //node *temp2 = head;
    while (temp != NULL)
    {
        node *temp2 = head;
        while (temp2 != NULL)
        {
            if (strcmp(temp2->name, temp->name) == 0)
            {
                temp->money = temp->money + (money / m);
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}
void display()
{
    node *temp = start;
    while (temp != NULL)
    {
        printf("%s\n", temp->name);
        printf("%f\n", temp->money);
        temp = temp->next;
    }
}
void display_expenses()
{
    node *temp = first;
    while (temp != NULL)
    {
        printf("%s :- ", temp->name);
        printf("%f\n", temp->money);
        temp = temp->next;
    }
}
int main()
{
    printf("Welcome to Split-Maadi\n");
    int ch;
    char delete[20];
    int n;
    float money;
    //node *temp3=first;
    node *new1 = (node *)malloc(sizeof(node));
    new1->next = NULL;
    new1->money = 0;
    // temp->money=0;
    while (1)
    {
        printf("1. Add Members\n 2. Add Group Expense\n 3. Add personal Expense\n 4. Display\n 5.Delete the member\n 6. Display expenses description\n 7.Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {

        case 1:
            printf("Enter number of members\n");
            scanf("%d", &n);

            for (int i = 0; i < n; i++)
            {
                add_members();
            }
            break;
        case 2:
            printf("Add money\n");
            scanf("%f", &money);
            add_members3(money);
            printf("1. Equal split \n");
            printf("2. Custom split \n");
            int ch;
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                add_expenses(money, n);
                count++;
                break;
            case 2:
                printf("Custom Split \n");
                int m;
                printf("Enter members for custom split\n");
                scanf("%d", &m);
                custom_split(money, m);
                break;
            default:
                printf("Invalid Input\n");
                break;
            }
             
            break;
        case 3:
            personal_expense(new1);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Enter the member to be delete\n");
            scanf("%s",delete);
            delete_member(delete);
            break;
        case 6:
             display_expenses();
             break;
        default:
            exit(0);
        }
    }
    return 0;
}