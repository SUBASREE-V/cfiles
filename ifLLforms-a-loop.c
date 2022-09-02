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

int ifLLforms_aloop(struct node *start){
    struct node *p,*q=start;
    do{
        p=p->next;
        q=q->next;
        if(q!=NULL){
            q=q->next;
        }
        else
         q=NULL;
        
    }while(p && q && p!=q);
    
    if(p==q)
        return 1;
    
    else
     return 0;
    
}

int main(){ 
    struct node *t1,*t2;
    int A[]={2,6,8,10,11};
    
    create(A,5);
      
    t1=first->next->next;
    t2=first;
    while(t2->next!=NULL){
        t2=t2->next;
    }
    t2->next = t1;
    
    printf("%d\n",ifLLforms_aloop(first));
    return 0;
}   

