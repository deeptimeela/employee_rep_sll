
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
 
struct employee_data
{
    int  employee_no;
    char employee_Name[MAX];
    char designation[MAX];
    struct employee_data *next;
};
 

struct employee_data *insert(struct employee_data *front, int id, char name[],
char designation[])
{
    struct employee_data *newnode;
 
    newnode = (struct employee_data*)malloc(sizeof(struct employee_data));
 
    if (newnode == NULL)
    {
        printf("\n Allocation failed \n");
        exit(2);
    }
    newnode->employee_no = id;
    strcpy(newnode->employee_Name, name);
    strcpy(newnode->designation, designation);
    newnode->next = front;
    front = newnode;
    return(front);
}
/*  first allocate enough space, create the node. Front is the head here that point to the starting of the linked list. insert details like id, name and designation to the newly created node and make front point to this new created node. Newly created node will point to the node previously front was pointing to. this is similar to adding a node to the start of the linked list*/
 

void printNode(struct employee_data *p)
{
    printf("\n Employee Details...\n");
    printf("\n Employee No       : %d", p->employee_no);
    printf("\n Name of the employee           : %s", p->employee_Name);
    printf("\n Designation    : %s\n", p->designation);
    printf("-------------------------------------\n");
}
/*  This function is simply printing the details of the node. Employee number, employee name and designation  */
 

struct employee_data* deleteNode(struct employee_data *front, int id)
{
    struct employee_data *ptr; /* for this we need two pointers one is ptr and the other is back pointer because if we want to delete a node which is somewhere in the linked list, to modify the next we need information about the previous and the next pointer */
    
    struct employee_data *bptr;
 
    if (front->employee_no == id)
    {
        ptr = front; /* checking if the node to be deleted is present at the start of the singly linked list */
        
        printf("\n Node has been deleted:");
        printNode(front);
        front = front->next;
        free(ptr);
        return(front);
    }
    for (ptr = front->next, bptr = front; ptr != NULL; ptr = ptr->next,
bptr = bptr->next) 
    {
        if (ptr->employee_no == id) /* keep traversing until you reach the node that has to deleted where pt of employee no is equal to the id, now ptr is pointing to the node that has to be deleted */
        
        {
            printf("\n Node has been deleted:");
            printNode(ptr);
            bptr->next = ptr->next;
            free(ptr);
            return(front);
        }
    }
    printf("\n Employee Number %d not found ", id);
    return(front);
}

void search(struct employee_data *front, int key)
{
    struct employee_data *ptr;
 
    for (ptr = front; ptr != NULL; ptr = ptr -> next)
    {
        if (ptr->employee_no == key)
        {
            printf("\n Key found:");
            printNode(ptr);
            return;
        }
    }
    printf("\n Employee Number %d is not found ", key);
}

void display(struct employee_data  *front)
{
    struct employee_data *ptr;
 
    for (ptr = front; ptr != NULL; ptr = ptr->next)
    {
        printNode(ptr);
    }
}


void menu()
{
    printf("---------------------------------------------\n");
    printf("Press 1 to INSERT a node into the singly linked list       \n");
    printf("Press 2 to DELETE a node from the singly linked  list       \n");
    printf("Press 3 to DISPLAY the singly linked list                 \n");
    printf("Press 4 to SEARCH the singly linked list                   \n");
    printf("Press 5 to EXIT   from the sll                           \n");
    printf("---------------------------------------------\n");
}

char option()
{
    char choice;
 
    printf("\n\n>> Enter your choice: ");
    switch(choice=getchar())
    {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':   return(choice);
        default :   printf("\n Invalid choice.");
    }
    return choice;
}

void main()
{
    struct employee_data *linkList;
    char name[21], desig[51];
    char choice;
    int eno;
 
    linkList = NULL;
    printf("\n Welcome to demonstration of singly linked list \n");
    menu();
    do
    {
        /*  choose oeration to be performed */
        choice = option();
        switch(choice)
        {
        case '1':
            printf("\n Enter the Employee Number      : ");
            scanf("%d", &eno);
            printf("Enter the Employee name        : ");
            fflush(stdin);
            gets(name);
            printf("Enter the Employee Designation : ");
            gets(desig);
            linkList = insert(linkList, eno, name, desig);
            break;
        case '2':
            printf("\n\n Enter the employee number to be deleted: ");
            scanf("%d", &eno);
            linkList = deleteNode(linkList, eno);
            break;
        case '3':
            if (linkList == NULL)
            {
                printf("\n List empty.");
                break;
            }
            display(linkList);
            break;
        case '4':
            printf("\n\n Enter the employee number to be searched: ");
            scanf("%d", &eno);
            search(linkList, eno);
            break;
        case '5': break;
        }
    } while (choice != '5');
}
