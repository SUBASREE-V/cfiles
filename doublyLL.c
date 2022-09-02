#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
}*first=NULL;

void createDLL(int A[],int n){
    int i;
    struct node *t,*last;
    first = (struct node *)malloc(sizeof(struct node));
    
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;
    
    for(i=1;i<n;i++){
        t=(struct node*)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = last->next; //NULL
        t->prev = last;
        last->next=t;
        last=t;
        
    }
    
}

int lengthDLL(struct node* p){
    int len=0;
    while(p!=NULL){
        len++;
        p=p->next;
    }
    return len;
}

void displayDLL(struct node * p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

void insertDLL(struct node * start,int pos,int x){
    struct node *t;
    if(pos < 0 || pos > lengthDLL(start)){
        return ;
    }
    else if(pos == 0){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        t->prev = NULL;
        t->next=first;
        first->prev = t;
        first = t;
    }
    else{
        for(int i=0;i<pos-1;i++){
            start=start->next;
        }
        t=(struct node*)malloc(sizeof(struct node));
        t->data=x;
        t->next = start->next;
        t->prev = start;
        if(start->next){
            start->next->prev =t;
        }
        start->next =t;
    }
}

void deleteDLL(struct node *p,int pos){
    int x,i;
    if(pos <0 || pos > lengthDLL(p)){
        return ;
    }
    else if( pos == 1){
       first = first->next;
       if(first) 
        first->prev = NULL;
       x = p->data;
       free(p);
    }
    else{
        for(i=0;i<pos-1;i++){
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next)p->next->prev=p->prev;
        x=p->data;
        free(p);
    }
}
int main()
{
   int A[]={3,4,5,6,7,8};
   createDLL(A,6);
   printf("Length : %d\n",lengthDLL(first));
   displayDLL(first);
  /* printf("\n");
   insertDLL(first,6,10);
   displayDLL(first);*/
    
   printf("\n");
   deleteDLL(first,6);
   displayDLL(first);
    return 0;
}
