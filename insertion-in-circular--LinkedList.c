#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next; 
};

void circularLinkedListTraversal(struct Node *head){
    struct Node * ptr=head;
    do
    {
        printf("Element : %d\t",ptr->data);
        ptr=ptr->next;
    } while (ptr!=head);  
}

//case 1
struct Node * insertAtFirst(struct Node *head,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;

    struct Node * p=head->next;
    while (p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}

//case 2
struct Node * insertAtIndex(struct Node *head,int data,int index){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    int i=0;

    struct Node * p=head;
    while (i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

//case3
struct Node * insertAtEnd(struct Node * head,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node ));
    ptr->data=data;

    struct Node *p=head;
    while (p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    return head;
}

//case4
struct Node * insertAfterNode(struct Node * head,int data,struct Node* prevNode){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;

    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;
}
int main(){
    struct Node * first;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    first=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));

    first->data=777;
    first->next=second;

    second->data=999;
    second->next=third;

    third->data=888;
    third->next=fourth;

    fourth->data=555;
    fourth->next=first;

    printf("Before insertion\n");
    circularLinkedListTraversal(first);
    printf("\n");

    // printf("\nAfter insertion\n");
    // first=insertAtFirst(first,147);
    // circularLinkedListTraversal(first);

    // printf("\nAfter insertion\n");
    // first=insertAtIndex(first,147,2);
    // circularLinkedListTraversal(first);

    // printf("\nAfter insertion\n");
    // first=insertAtEnd(first,147);
    // circularLinkedListTraversal(first);

    printf("\nAfter insertion\n");
    first=insertAfterNode(first,147,first);
    circularLinkedListTraversal(first);
    return 0;
}