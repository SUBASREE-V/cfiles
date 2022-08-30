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

void Insertsort(struct node *p,int x){
    struct node *t,*q=NULL;
    t=(struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next=NULL;
    
    if(first == NULL)
        first = t;
    
    else{
        while(p && p->data < x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next = first;
            first =t;
        }
        else{
            t->next=q->next;
            q->next = t;
        }
    }
}

int deletenode (struct node *start,int pos){
    struct node *p=first,*q=NULL;
    
    int x=-1;
    if(pos < 1 || pos > count(p)){
        return x;
    }
    else{
        if(pos==1){
            p=first;
            x=p->data;
            first=first->next;
            free(p);
            return x;
        }
        else{
            for(int i=0;i<pos-1 && p;i++){
                q=p;
                p=p->next;
            }
            if(p){
                q->next=p->next;
                x = p->data;
                free(p);
                return x;
            }
        }
    }
    
}

int isSorted(struct Node *start)
{
 int x=-65536;
 struct node *p=first;
 while(p!=NULL)
 {
 if(p->data < x)
 return 0;
 x=p->data;
 p=p->next;
 }
 return 1;

}

void removeduplicatesinsortedLL(struct node *start){
    struct node *p=first,*q=first->next;
    
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

void reverseusing_array(struct node *p){
    struct node *q=first;
    int *A,i=0;
    
    A=(int *)malloc(sizeof(int)*count(p));
    
    while(q!=NULL){
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=first;
    i--;
    while(q!=NULL){
        q->data =A[i--];
        q=q->next;
    }
}

void revrse_slidingpointers(struct node *start){
    struct node *p=start,*q=NULL,*r=NULL;
    
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    first = q;
    
}

void reverse_recursively(struct node *q,struct node *p){
  
    if(p!=NULL){
        reverse_recursively(p,p->next);
        p->next=q;
    }
    else
     first = q;
    
}

void mergetwoLL(struct node * start1,struct node * start2){
    struct node *p  = start1;
    while(p!=NULL){
        p=p->next;
    }
    p->next = start2;
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
    
    printf("\n");
    int B[]={10,20,30,30,40,40};
    create(B,6);
    display(first);
    printf("\n\n");
    Insertsort(first,5);
    Insertsort(first,2);
    display(first);
    printf("\n");
    printf("Deleted element : %d",deletenode(first,4));
    printf("\n");
    display(first);
    printf("\n");
    printf("Sorted:0; Not sorted:1; %d\n",isSorted(first));
   /* int C[]={3,1,5,6};
    create(C,4);
    display(first);
    printf("Sorted:0; Not sorted:1; %d\n",isSorted(first));
    printf("\n");*/
    
    removeduplicatesinsortedLL(first);
    display(first);
    printf("\n");
   /* reverseusing_array(first);
    display(first);
    printf("\n");*/
    /*revrse_slidingpointers(first);
    display(first);*/
    
    printf("\n");
    reverse_recursively(NULL,first);
    display(first);
    
   
}

