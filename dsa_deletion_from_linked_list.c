#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void traversal(struct Node *ptr){
while(ptr!=NULL){
    printf("Element%d\n",ptr->data);
    ptr=ptr->next;
}
};

struct Node *deletionatbeg(struct Node *head){
    struct Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
};

struct Node *deleteatindex(struct Node *head,int index){
    struct Node *p=head;
    struct Node *q=head->next; 
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

struct Node *deleteatend(struct Node *head){
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->next!=NULL){
    p=p->next;
    q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
};

struct Node *delbetelement(struct Node *head,int value)
{
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->data!=value && q->next==NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data==value){
        p->next=q->next;
        return head;
    }
};


int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    head->data=8;
    head->next=second;
    second->data=25;
    second->next=third;
    third->data=28;
    third->next=fourth;
    fourth->data=88;
    fourth->next=NULL; 
    traversal(head);
    //head=deletionatbeg(head);
    //head=deleteatindex(head,2);
    //head=deleteatend(head);
    head=delbetelement(head,25);
    printf("\nAfter deletion:\n");
    traversal(head);
    return 0;

} 