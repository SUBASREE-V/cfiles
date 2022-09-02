#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
}*Head;

void createCLL(int A[],int n){
    struct node *t,*last;
    int i=0;
    Head = (struct node *)malloc(sizeof(struct node));
    
    Head->data =A[0];
    Head->next=Head;
    last = Head;
    
    for(i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void display(struct node * p){
    
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=Head);
    printf("\n");
}

void Recursive_display(struct node * p){
    static int flag=0;
    if(p!=Head || flag==0){
        flag =1;
        printf("%d ",p->data);
        Recursive_display(p->next);
    }
    flag=0;
}

int lengthofCLL(struct node *p){
    int len=0;
    do{
        len++;
        p=p->next;
    }while(p!=Head);
    return len;
}

void insertinCLL(struct node *p,int pos ,int x){
    struct node *t;
    int i;
    if(pos < 0 || pos > lengthofCLL(p)){
        return ;
    }
    if(pos==0){
        t=(struct node*)malloc(sizeof(struct node));
        t->data = x;
        if(Head == NULL){
        Head = t;
        Head->next = Head;
      }
    else {
        while(p->next != Head){
            p=p->next;
        }
        p->next = t;
        t->next = Head;
        Head = t;
        
        }
    
    }
    else{
        for(i=0;i<pos-1;i++) p=p->next;
        t=(struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->next = p->next;
        p->next = t;
        
    }
    
}

int deletefromCLL(struct node* p,int pos){
    struct node *q;
    int i,x;
    if(pos < 0 || pos > lengthofCLL(Head)){
        return -1;
    }
    if(pos==1){
        while(p->next !=Head){
            p=p->next;
        }
        x=Head->data;
        if(Head==p){
            free(Head);
            Head = NULL;
        }
        else{
            p->next=Head->next;
            free(Head);
            Head = p->next;
        }
        
    }
    
    else{
        for(i=0;i<pos-2;i++)p=p->next;
        q=p->next;
        p->next = q->next;
        x=q->data;
        free(q);
   }
    return x;
}

int main()
{
  int A[]={2,3,4,5,6};
  createCLL(A,5);
  //Recursive_display(Head);
  printf("%d\n",lengthofCLL(Head));
  //insertinCLL(Head,4,10);
  deletefromCLL(Head,1);
  display(Head);
  
}

