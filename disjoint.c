#include <stdio.h>
#include <stdlib.h>

/* Forward declarations */
struct node;
struct rep;
struct nodaddr;

typedef struct node
{
    int value;
    struct rep *repptr;
    struct node *next;
} node;

typedef struct rep
{
    node *head;
    node *tail;
} rep;

typedef struct nodaddr
{
    int key;
    node *obj_node_ptr;
    struct nodaddr *next;
} nodaddr;

nodaddr *ndr = NULL;

/*************** MAKSET ****************/
void makeset(int a)
{
    nodaddr *t = (nodaddr*)malloc(sizeof(nodaddr));
    rep *newset = (rep*)malloc(sizeof(rep));
    node *n = (node*)malloc(sizeof(node));

    n->value = a;
    n->repptr = newset;
    n->next = NULL;

    newset->head = newset->tail = n;

    t->obj_node_ptr = n;
    t->key = a;
    t->next = ndr;
    ndr = t;
}

/*************** FIND ****************/
rep *find(int x)
{
    nodaddr *t = ndr;

    while (t != NULL && t->key != x)
        t = t->next;

    if (t == NULL)
        return NULL;

    return t->obj_node_ptr->repptr;
}

/*************** UNION ****************/
void unionset(int key1, int key2)
{
    rep *set1 = find(key1);
    rep *set2 = find(key2);

    if (set1 == NULL || set2 == NULL)
    {
        printf("One of the elements does not exist!\n");
        return;
    }

    if (set1 == set2)
    {
        printf("\n %d and %d already belong to same set\n", key1, key2);
        return;
    }

    node *t = set2->head;
    while (t != NULL)
    {
        t->repptr = set1;
        t = t->next;
    }

    set1->tail->next = set2->head;
    set1->tail = set2->tail;

    free(set2);
}

/*************** DISPLAY ****************/
void display(int a)
{
    rep *r = find(a);

    if (r == NULL)
    {
        printf("\nElement does not exist!\n");
        return;
    }

    node *t = r->head;

    printf("\nSet containing %d:", a);
    while (t != NULL)
    {
        printf(" %d", t->value);
        t = t->next;
    }
    printf("\n");
}

/*************** MAIN ****************/
int main()
{
    int data, data1, data2, opt;

    do
    {
        printf("\n 1. Makeset");
        printf("\n 2. Findset");
        printf("\n 3. Unionset");
        printf("\n 4. Display");
        printf("\n 5. Exit");
        printf("\n Enter your option: ");
        scanf("%d", &opt);

        switch (opt)
        {
            case 1:
                printf("\nEnter the data: ");
                scanf("%d", &data);
                makeset(data);
                break;

            case 2:
                printf("\nEnter set value: ");
                scanf("%d", &data);
                printf("\nReference of set containing %d is %p\n", data, find(data));
                break;

            case 3:
                printf("\nFirst data: ");
                scanf("%d", &data1);
                printf("\nSecond data: ");
                scanf("%d", &data2);
                unionset(data1, data2);
                break;

            case 4:
                printf("\nEnter the data: ");
                scanf("%d", &data);
                display(data);
                break;

            case 5:
                exit(0);
        }
    } while (1);

    return 0;
}



