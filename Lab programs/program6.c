/*Design, Develop and Implement a menu driven Program in C for the following
operations on Doubly Linked List (DLL) of Professor Data with the fields: ID, Name,
Branch, Area of specialization
 a. Create a DLL stack of N Professor’s Data.
 b. Create a DLL queue of N Professor’s Data
 Display the status of DLL and count the number of nodes in it.  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[20];
    int id;
    char branch[20];
    char area[20];
    struct node *Rlink, *Llink;
};

typedef struct node *NODE;

NODE getnode() {
    NODE x = (NODE) malloc(sizeof(struct node));
    return x;
}

NODE insert_front(NODE first, char name[20], int id,char branch[20],char area[20]) {
    NODE temp = getnode();
    temp->id = id;
    strcpy(temp->name, name);
    strcpy(temp->branch, branch);
    strcpy(temp->area, area);
    temp->Rlink = NULL;
    temp->Llink = NULL;

    if (first == NULL) {
        return temp;
    }

    temp->Rlink = first;
    first->Llink = temp;
    return temp;
}

NODE delete_front(NODE first) {
    if (first == NULL) {
        printf("empty cant delete\n");
        return NULL;
    }

    NODE cur = first;
    NODE next = cur->Rlink;

    printf("the deleted name and is %s id=%d branch=%s area of specialisation= %s\n", cur->name, cur->id,cur->branch,cur->area);
    free(cur);

    if (next != NULL) {
        next->Llink = NULL;
    }

    return next;
}

NODE delete_rear(NODE first) {
    if (first == NULL) {
        printf("empty cant delete\n");
        return NULL;
    }

    if (first->Rlink == NULL) {
        printf("the deleted name and is %s id=%d branch=%s area of specialisation= %s\n", first->name, first->id,first->branch,first->area);
        free(first);
        return NULL;
    }

    NODE cur = first;
    NODE prev = NULL;

    while (cur->Rlink != NULL) 
        cur = cur->Rlink;

    prev=cur->Llink;
    printf("the deleted name and is %s id=%d branch=%s area of specialisation= %s\n", cur->name, cur->id,cur->branch,cur->area);
    free(cur);
        prev->Rlink = NULL;

    return first;
}

void display(NODE first) {
    int count=0;
    if (first == NULL) {
        printf("empty or underflow condition,count = %d \n",count);
        return;
    }

    NODE cur = first;

    while (cur != NULL) {
        printf("Name=%s ID=%d Branch=%s Area=%s\n", cur->name, cur->id,cur->branch,cur->area);
        cur = cur->Rlink;
        count++;
    }
     printf("Number of nodes: %d\n", count);
}

void stack(NODE first) {
    int id,choice;
    char name[20],branch[20],area[20];

    while (1) {
        printf("1.insert front(push) 2.delete front(pop) 3.display 4.exit\n");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                printf("enter the name and id and branch and area of specialisation\n");
                scanf("%s %d %s %s", name, &id,branch,area);
                first = insert_front(first, name, id,branch,area);
                break;

            case 2:
                first = delete_front(first);
                break;

            case 3:
                display(first);
                break;

            default:
                free(first);
                return;
        }
    }
}

void queue(NODE first) {
    int id,choice;
    char name[20],branch[20],area[20];

    while (1) {
        printf("1.insert front 2.delete rear 3.display 4.exit\n");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                printf("enter the name and id and branch and area of specialisation\n");
                scanf("%s %d %s %s", name, &id,branch,area);
                first = insert_front(first,name,id,branch,area);
                break;

            case 2:
                first = delete_rear(first);
                break;

            case 3:
                display(first);
                break;

            default:
                free(first);
                return;
        }
    }
}

int main()
{
    NODE first;
    int ch;
    while(1)
    {
        printf("\n 1.stack 2.queue 3.exit from whole program");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: first=NULL;
                   stack(first);
                    break;
                  
            case 2: first=NULL;
                    queue(first);
                    break;
                   
            default:exit(0);
      }
   }
}
