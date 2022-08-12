#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*first=NULL;

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

void display(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
void recurdisplay(struct node *p){
    if(p!=NULL){
        printf("%d ",p->data);
        recurdisplay(p->next);
    }
}

void recurdisplay2(struct node *p){
    if(p!=NULL){
        
        recurdisplay2(p->next);
        printf("%d ",p->data);
    }
}
int count(struct node *p){
    int c =0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}

int reccount(struct node *p){
    if(p==0)
     return 0;
    else 
     return reccount(p->next)+1;
}

int add(struct node *p){
    int sum=0;
    while(p!=0){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
int recadd(struct node *p){
    if(p==0)
     return 0;
    else
     return recadd(p->next)+p->data;
    
}
int maxi(struct node *p){
    int max = -3278;
    while(p!=0){
        if(p->data > max)
          max = p->data;
        p=p->next;
    }
    return max;
}

int recmaxi(struct node *p){
    if(p==0)
     return -1;
    else{
     int x = recmaxi(p->next);
     if(x > p->data)
      return x;
     else
      return p->data;
    }
}

struct node * linear(struct node *p,int key){
    while(p!=NULL){
        if(key == p->data){
            return p;  // returns the address of the node where the key is found
        }
        else
         p=p->next;
    }
    return 0;
}

struct node * reclinear(struct node *p,int key){
    if(p==0){
        return 0;
    }
    else if (key == p->data){
        return p;
    }
    return reclinear(p->next,key);
}

struct node * movetofront(struct node *p,int key){
    struct node *q=NULL;
    
    while(p!=NULL){
        if(key == p->data){
            q->next = p->next;
            p->next = first;
            first =p;
            return p;
            
        }
        q=p;
        p=p->next;
    }
    return 0;
}

void insert(struct node *p,int index,int key){
    if(index < 0 || index > count(p) ){
        return 0;
    }
    
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = key;
    
    if(index==0){
        t->next= first;
        first = t;
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t->next = p->next;
        p->next =t;
        
    }
}
int main(){ 
    int A[]={2,3,4,5,6};
    struct node *temp,*tempformove;
    create(A,5);
    display(first);
    printf("\n");
    recurdisplay(first);
    printf("\n");
    recurdisplay2(first);
    printf("\n");
    printf("%d",reccount(first));
    printf("\n");
    printf("%d",recadd(first));
    printf("\n");
    printf("%d ",maxi(first));
    
    printf("\n");
    printf("%d ",recmaxi(first));
    
    printf("\n");
    
/*    temp = linear(first,3);
    if(temp){                                     // used for linear search 
        printf("Key found %d ",temp->data);
    }
    else
     printf("key not found");
    printf("%d ",linear(first,3));*/
   
    printf("%d ",reclinear(first,3));
    
    printf("\n");
    tempformove = movetofront(first,6);
    display(first);
    
    printf("\n");
    insert(first,1,9);
    display(first);
   
}
