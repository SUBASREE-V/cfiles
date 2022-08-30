#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int A[],int n){
    struct node *t,*last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->next =NULL;
    last = first;
    
    for(int i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    
}

void create2(int A[],int n){
    struct node *t,*last;
    second=(struct node *)malloc(sizeof(struct node));
    second->data = A[0];
    second->next =NULL;
    last = second;
    
    for(int i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    
}

void display(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

void concattwoLL(struct node * start1,struct node * start2){

    struct node *p  = start1;
    third = p;
    while(p->next !=NULL){
        p=p->next;
    }
    p->next = start2;
}

void mergetwoLL(struct node * p,struct node *q){
    
    struct node *rlast =NULL;
    
    if(p->data < q->data){
       third=rlast=p;
       p=p->next;
       rlast->next = NULL;
    }
    else
    {
        third=rlast=q;
        q=q->next;
        rlast->next=NULL;
    }
    
    while(p!=NULL && q!=NULL){
        if(p->data < q->data){
            rlast->next = p;
            rlast=p;
            p=p->next;
            rlast->next = NULL;
        
        }
        else{
            rlast->next=q;
            rlast = q;
            q=q->next;
            rlast->next=NULL;
        }
    }
    if(p!=NULL) rlast->next = p;
    else rlast->next = q;
}


int main(){ 
  
    int A[]={2,6,8,10,11};
    create(A,5);
    
    display(first);
    printf("\n");

    int B[]={1,73,93,123,133};
    create2(B,5);
    display(second);
    printf("\n");
    
    /*concattwoLL(first,second);
    display(third);
    */
    
    printf("\n");
    mergetwoLL(first,second);
    display(third);
    
    
  
}   
