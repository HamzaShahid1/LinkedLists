#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

void DoublyLinkedListTraversal(struct Node * head){
    struct Node *ptr=head;
    while (ptr!=NULL)
    {
        printf("Element : %d\t",ptr->data);
        ptr=ptr->next;
    }
    
}

//case1
struct Node * insertaAtFirst(struct Node * head,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->prev;
    ptr->data=data;
    head->prev=ptr;
    ptr->next=head;
    
    return ptr;
}

//case2
struct Node * insertAtIndex(struct Node * head,int data,int index){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while (i<index-1 && head!=NULL)
    {
        p=p->next;
        i++;
    }
    
    ptr->data=data;
    ptr->next=p->next;
    ptr->prev=p;
    p->next->prev=ptr;
    p->next=ptr;
    return head;
}

//case3
struct Node * insertAtEnd(struct Node * head,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    ptr->next=NULL;
    ptr->prev=p;
    p->next=ptr;
    return head;
}

//case4
struct Node * insertAfterNode(struct Node * head,int data,struct Node *preNode){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;

    ptr->next=preNode->next;
    preNode->next->prev=ptr;
    preNode->next=ptr;
    ptr->prev=preNode;
    return head;
}
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->prev;
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->prev=head;
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->prev=second;
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->prev=third;
    fourth->data = 66;
    fourth->next = NULL;

    printf("\n Before insertion\n");
    DoublyLinkedListTraversal(head);

    // printf("\n After insertion\n");
    // head=insertaAtFirst(head,147);
    // DoublyLinkedListTraversal(head);

    // printf("\n After insertion\n");
    // head=insertAtIndex(head,147,2);
    // DoublyLinkedListTraversal(head);

    // printf("\n After insertion\n");
    // head=insertAtEnd(head,147);
    // DoublyLinkedListTraversal(head);

    // printf("\n After insertion\n");
    // head=insertAfterNode(head,147,head);
    // DoublyLinkedListTraversal(head);
    
    return 0;
}