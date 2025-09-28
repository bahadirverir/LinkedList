#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *start = NULL;

void display(struct Node *);
void search(struct Node *);
void countNodes(struct Node *);
void removeDuplicateNodes(struct Node *);
struct Node *addAtBeginning(struct Node *);
struct Node *addAtEnd(struct Node *);
struct Node *addBefore(struct Node *);
struct Node *addAfter(struct Node *);
struct Node *deleteAtBeginning(struct Node *);
struct Node *deleteAtEnd(struct Node *);
struct Node *deleteAfter(struct Node *);
struct Node *deleteBefore(struct Node *);
struct Node *createList(struct Node *);
struct Node *deleteAll(struct Node *);
struct Node *sortAscending(struct Node *);
struct Node *sortDescending(struct Node *);
struct Node *reverseList(struct Node *);

void menu()
{
    int choice, continueProgram;
    while (1)
    {
        printf("\n****** MAIN MENU ******\n");
        printf(" 1: Create list\n");
        printf(" 2: Display list\n");
        printf(" 3: Search nodes\n");
        printf(" 4: Count nodes\n");
        printf(" 5: Add a node at the beginning\n");
        printf(" 6: Add a node at the end\n");
        printf(" 7: Add a node before a specific node\n");
        printf(" 8: Add a node after a specific node\n");
        printf(" 9: Delete the first node\n");
        printf("10: Delete the last node\n");
        printf("11: Delete the node after a specific node\n");
        printf("12: Delete the node before a specific node\n");
        printf("13: Delete all nodes\n");
        printf("14: Sort nodes ascending\n");
        printf("15: Sort nodes descending\n");
        printf("16: Reverse the list\n");
        printf("17: Remove duplicate nodes\n");
        printf("18: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nCreating linked list...\n");
            start = createList(start);
            printf("\nLinked list created!\n");
            display(start);
            printf("\n");
            break;

        case 2:
            printf("\nDisplaying linked list...\n");
            display(start);
            printf("\n");
            break;

        case 3:
            search(start);
            printf("\n");
            break;

        case 4:
            printf("\nCounting nodes in the linked list...\n");
            countNodes(start);
            break;

        case 5:
            start = addAtBeginning(start);
            printf("Node added at the beginning.\n");
            break;

        case 6:
            start = addAtEnd(start);
            printf("Node added at the end.\n");
            break;

        case 7:
            start = addBefore(start);
            printf("Node added successfully.\n");
            break;

        case 8:
            start = addAfter(start);
            printf("Node added successfully.\n");
            break;

        case 9:
            start = deleteAtBeginning(start);
            printf("\nFirst node deleted.\n");
            break;

        case 10:
            start = deleteAtEnd(start);
            printf("\nLast node deleted.\n");
            break;

        case 11:
            start = deleteAfter(start);
            printf("Node deleted successfully.\n");
            break;

        case 12:
            start = deleteBefore(start);
            printf("Node deleted successfully.\n");
            break;

        case 13:
            start = deleteAll(start);
            printf("All nodes in the linked list deleted.\n");
            break;

        case 14:
            start = sortAscending(start);
            printf("Linked list sorted in ascending order.\n");
            break;

        case 15:
            start = sortDescending(start);
            printf("Linked list sorted in descending order.\n");
            break;

        case 16:
            start = reverseList(start);
            printf("Linked list reversed.\n");
            break;
        
        case 17:
            removeDuplicateNodes(start);
            printf("Duplicate nodes removed.\n");
            break;

        case 18:
            printf("Exiting...\n");
            return; 
            break;

        default:
            printf("Invalid choice, please try again.\n");
            break;
        }
    }
}

int main()
{
    menu();
    return 0;
}

struct Node *createList(struct Node *start) //=> 1
{
    struct Node *newNode, *ptr;
    int value;
    printf("\nEnter -1 to stop\n");
    printf("Enter a value: ");
    scanf("%d", &value);
    
    while(value != -1)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        
        if(start == NULL)
        {
            newNode->next = NULL;
            start = newNode;
        }
        else
        {
            ptr = start;
            
            while(ptr->next != NULL)
                ptr = ptr->next;
            
            ptr->next = newNode;
            newNode->next = NULL;
        }
        printf("Enter a value: ");
        scanf("%d", &value);
    }
    return start;
}

void display(struct Node *start) //=> 2
{
    struct Node *ptr;
    ptr = start;
    while(ptr != NULL)
    {
        printf(" %d\t", ptr->data);
        ptr = ptr->next;
    }
}

void search(struct Node *start) //=> 3
{
    struct Node *ptr;
    ptr = start;
    int target;
    printf("\nEnter the value to search for: ");
    scanf("%d", &target);
    while(ptr != NULL)
    {
        if(target == ptr->data)
        {
            printf("The value \"%d\" was found in the list.\n", target);
            break;
        }
        else
            ptr = ptr->next;
    }
    if(ptr == NULL)
    {
        printf("The value \"%d\" was not found in the list.\n", target);
    }
}

void countNodes(struct Node *start) //=> 4
{
    struct Node *ptr;
    ptr = start;
    int counter = 0;
    while(ptr != NULL)
    {
        counter++;
        ptr = ptr->next;
    }
    printf("Number of nodes = %d\n", counter);
}

struct Node *addAtBeginning(struct Node *start) //=> 5
{
    struct Node *ptr;
    int value;
    printf("\nEnter a value: ");
    scanf("%d", &value);

    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->next = start;
    start = ptr;
    return start;
}

struct Node *addAtEnd(struct Node *start) //=> 6
{
    struct Node *newNode, *ptr;
    int value;
    printf("\nEnter a value: ");
    scanf("%d", &value);
    
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    ptr = start;
    while(ptr->next != NULL)
        ptr = ptr->next;
    
    ptr->next = newNode;
    return start;
}

struct Node *addBefore(struct Node *start) //=> 7
{
    struct Node *newNode, *ptr, *preptr;
    int value, target;
    printf("\nEnter a value: ");
    scanf("%d", &value);    
    printf("\nEnter the value before which to insert: ");
    scanf("%d", &target);
    
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    ptr = start;   
    preptr = ptr;
    
    while(ptr->data != target)
    {
        preptr = ptr;        
        ptr = ptr->next;
    }    
    preptr->next = newNode;
    newNode->next = ptr;    
    return start;
}

struct Node *addAfter(struct Node *start) //=> 8
{
    struct Node *newNode, *ptr, *preptr;
    int value, target;
    printf("\nEnter a value: ");
    scanf("%d", &value);
    printf("\nEnter the value after which to insert: ");    
    scanf("%d", &target);
    
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    ptr = start;    
	preptr = ptr;
    
    while(preptr->data != target)
    {
        preptr = ptr;        
		ptr = ptr->next;
    }    
    preptr->next = newNode;
    newNode->next = ptr;    
    return start;
}

struct Node *deleteAtBeginning(struct Node *start) //=> 9
{
    struct Node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

struct Node *deleteAtEnd(struct Node *start) //=> 10
{
    struct Node *ptr, *preptr;
    ptr = start; 
    preptr = ptr;
    
    while(ptr->next != NULL)
    {
        preptr = ptr; 
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}

struct Node *deleteAfter(struct Node *start) //=> 11
{
    struct Node *ptr, *preptr;
    int target;
    printf("\nEnter the value after which to delete: ");
    scanf("%d", &target);
    ptr = start;
    preptr = ptr;
    
    while(preptr->data != target)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);    
    return start;
}

struct Node *deleteBefore(struct Node *start) //=> 12
{
    struct Node *ptr = start, *preptr = NULL;
    int target;
    printf("\nEnter the value before which to delete: ");
    scanf("%d", &target);
    while(ptr->next != NULL && ptr->next->data != target)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    
    if(preptr == NULL) 
        start = ptr->next;
    else
        preptr->next = ptr->next;
    free(ptr);
    return start;
}

struct Node *deleteAll(struct Node *start) //=> 13
{
    struct Node *ptr, *next_ptr;
    ptr = start;
    while(ptr != NULL)
    {
        next_ptr = ptr->next; 
        free(ptr);
        ptr = next_ptr; 
    }
    start = NULL; 
    return start;
}

struct Node *sortAscending(struct Node *start) //=> 14
{
    struct Node *ptr1, *ptr2;
    int temp;
    for (ptr1 = start; ptr1->next != NULL; ptr1 = ptr1->next) 
    {
        for (ptr2 = start; ptr2->next != NULL; ptr2 = ptr2->next) 
        {
            if (ptr2->data > ptr2->next->data) 
            { 
                temp = ptr2->data;
                ptr2->data = ptr2->next->data;
                ptr2->next->data = temp;
            }
        }
    }
    return start;
}

struct Node *sortDescending(struct Node *start) //=> 15
{
    struct Node *ptr1, *ptr2;
    int temp;
    for (ptr1 = start; ptr1->next != NULL; ptr1 = ptr1->next) 
    {
        for (ptr2 = start; ptr2->next != NULL; ptr2 = ptr2->next) 
        {
            if (ptr2->data < ptr2->next->data) 
            { 
                temp = ptr2->data;
                ptr2->data = ptr2->next->data;
                ptr2->next->data = temp;
            }
        }
    }
    return start;
}

struct Node *reverseList(struct Node *start) //=> 16
{
    struct Node *prev = NULL;   
    struct Node *ptr = start; 
    struct Node *next_ptr = NULL;   
    while (ptr != NULL) 
    {
        next_ptr = ptr->next; 
        ptr->next = prev; 
        prev = ptr;          
        ptr = next_ptr;         
    }
    start = prev; 
    return start;
}

void removeDuplicateNodes(struct Node *start) //=> 17
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;
    while (ptr1 != NULL && ptr1->next != NULL) 
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL) 
        {
            if (ptr1->data == ptr2->next->data) 
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            } 
            else 
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}
