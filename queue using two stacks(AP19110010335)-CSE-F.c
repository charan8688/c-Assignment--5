#include <stdio.h>
#include <stdlib.h>
struct node
{
    int a;
    struct node *next;
};
void push(struct node** high, int a);
int pop(struct node** high);
struct queue
{
    struct node *stack1;
    struct node *stack2;
};
void enqueue(struct queue *q, int x)
{
    push(&q->stack1, x);
}
void dequeue(struct queue *q)
{
    int x;
    if (q->stack1 == NULL && q->stack2 == NULL) {
        printf("queue is empty");
        return;
    }
    if (q->stack2 == NULL) {
        while (q->stack1 != NULL) {
        x = pop(&q->stack1);
        push(&q->stack2, x);
        }
    }
    x = pop(&q->stack2);
    printf("%d\n", x);
}
void push(struct node** high, int a)
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Stack overflow \n");
            return;
        }
    newnode->a = a;
    newnode->next = (*high);
    (*high) = newnode;
}
int pop(struct node** high)
{
    int buff;
    struct node *t;
    if (*high == NULL) {
        printf("Stack underflow \n");
        return ;
    }
    else {
        t = *high;
        buff = t->a;
        *high = t->next;
        free(t);
        return buff;
    }
}
void display(struct node *high1,struct node *high2)
{
    while (high1 != NULL) {
        printf("%d\n", high1->a);
        high1 = high1->next;
    }
    while (high2 != NULL) {
        printf("%d\n", high2->a);
        high2 = high2->next;
    }
}
int main()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    int f = 0, b;
    char ch = 'y';
    q->stack1 = NULL;
    q->stack2 = NULL;
    while (ch == 'y'||ch == 'Y') {
        printf("enter ur choice\n1.add to queue\n2.remove 
               from queue\n3.display\n4.exit\n");
        scanf("%d", &f);
        switch(f) {
            case 1 : printf("enter the element to be added to queue\n");
                     scanf("%d", &b);
                     enqueue(q, b);
                     break;
            case 2 : dequeue(q);
                     break;
            case 3 : display(q->stack1, q->stack2);
                     break;
            case 4 : exit(1);
                     break;
            default : printf("invalid\n");
                      break;
        }
    }
}