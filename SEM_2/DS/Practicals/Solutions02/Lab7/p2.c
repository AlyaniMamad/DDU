#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

typedef struct{
    struct node *head;
    struct node *tail;
}llist;

void insertAtLast(llist *l, int value){
    if(l->tail == NULL && l->head == NULL){
        l->head = (struct node *)malloc(sizeof(struct node));
        l->head->value = value;
        l->head->next = l->head;
        l->tail = l->head;
        return;
    }
    struct node *tmp = l->head;
    while(tmp != l->tail){
        tmp=tmp->next;
    }
    tmp->next = (struct node *)malloc(sizeof(struct node));
    tmp->next->value=value;
    tmp->next->next = l->head;
    l->tail = tmp->next;
}

void insertAtFirst(llist *l, int value){
    if(l->head == NULL && l->tail ==NULL){
        insertAtLast(l,value);
        return;
    }
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->next=l->head;
    new->value=value;
    l->head = new;
    l->tail->next = l->head;
}

void insertAtSpecific(llist *l, int value, int pos){
    if((l->head == NULL && l->tail)|| pos == 0){
        insertAtFirst(l,value);
        return;
    }
    struct node *tmp = l->head;
    int cnt=0;
    while(tmp != l->tail){
        if(cnt == pos-1){
            break;
        }
        tmp=tmp->next;
        cnt++;
    }
    if(tmp == l->tail){
        insertAtLast(l,value);
        return;
    }
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->value = value;
    new->next = tmp->next;
    tmp->next = new;
}

void deleteAtFirst(llist *l){
    if(l->head == NULL && l->tail == NULL){
        printf("List is empty");
        return;
    }
    if(l->head == l->tail){
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
        return;
    }
    struct node *tmp = l->head;
    l->head = l->head->next;
    l->tail->next = l->head;
    free(tmp);
}

void deleteAtLast(llist *l){
    if(l->head == NULL && l->tail == NULL){
        printf("List is empty");
        return;
    }
    if(l->head == l->tail){
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
        return;
    }
    struct node *tmp = l->head;
    while(tmp->next != l->tail){
        tmp = tmp->next;
    }
    free(l->tail);
    l->tail = tmp;
    l->tail->next = l->head;
}

void deleteAtSpecific(llist *l, int pos){
    if(l->head == NULL && l->tail == NULL){
        printf("List is empty");
        return;
    }
    if(l->head == l->tail){
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
        return;
    }
    if(pos == 0){
        deleteAtFirst(l);
        return;
    }
    struct node *tmp = l->head;
    int cnt=0;
    while(tmp != l->tail){
        if(cnt == pos-1){
            break;
        }
        tmp=tmp->next;
        cnt++;
    }
    if(tmp == l->tail){
        deleteAtLast(l);
        return;
    }
    struct node *tmp2 = tmp->next;
    tmp->next = tmp->next->next;
    free(tmp2);
}

void display(llist *l){
    printf("\n");
    if(l->head == NULL && l->tail == NULL){
        printf("List is empty");
        return;
    }
    struct node *tmp = l->head;
    while(tmp != l->tail){
        printf("%d ",tmp->value);
        tmp = tmp->next;
    }
    printf("%d ",tmp->value);
}

int main(){
    llist l;
    l.head = NULL;
    l.tail = NULL;
    insertAtLast(&l,1);
    insertAtLast(&l,2);
    insertAtLast(&l,3);
    display(&l);
    insertAtFirst(&l,0);
    display(&l);
    insertAtSpecific(&l,4,2);
    display(&l);
    deleteAtFirst(&l);
    display(&l);
    deleteAtLast(&l);
    display(&l);
    deleteAtSpecific(&l,1);
    display(&l);
    return 0;
}