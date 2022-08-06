#include <stdio.h>
#include <stdlib.h>
struct array{
    int *A;
    int size;
    int length;
};

void display(struct array arr){
    for(int i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }
}

void append (struct array *arr,int x){
    if(arr->length <arr->size){
        arr->A[arr->length++]=x;
    }
}

void insert(struct array *arr,int index,int x){
    if(index >=0 && index <=arr->length){
        for(int i=arr->length;i>index;i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
}

int delete (struct array *arr,int index){
     int x =0;
     if(index >=0 && index <=arr->length-1){
         x = arr->A[index];
         for (int i = index ;i<arr->length-1;i++){
             arr->A[i] = arr->A[i+1];
         }
         arr->length--;
         return x;
     }
     return 0;
}

int linearsearch(struct array *arr,int x){ // call by value so use arr.length instead of arr->length
    for (int i = 0;i<arr->length;i++){
        if(x==arr->A[i]){
            swap(&arr->A[i],&arr->A[i-1]);
            return i;
        }
       
    }
     return -1;
}
void swap(int *x,int *y){ // for improving linear search use Transposition that is whenever an element is found interchange the key element with i-1 th element
                          // even we can exchange an key element with starting index element for that use 
                          // swap(&arr->A[i],&arr->A[0])
    int temp = *x;
    *x = *y;
    *y =temp;
}

int BinarySearch(struct array arr,int key)
{
 int l=0,h=arr.length-1,mid;
 
 while(l<=h){
     mid = (l+h)/2;
     if(key == arr.A[mid]){
         return mid;
     }
     else if(key < arr.A[mid]){
          h=mid-1;
     }
     else{
         l=mid+1;
     }
 }
 return -1;
}

int RecursiveBinSearch(struct array arr,int l,int h,int x){
    if(l<=h){
        int mid =(l+h)/2;
        if(x == arr.A[mid]){
            return mid;
        }
        else if (x < arr.A[mid]){
            return RecursiveBinSearch(arr,l,mid-1,x);
        }
        else {
            return RecursiveBinSearch(arr,mid+1,h,x);
        }
    }
    return -1;
}

int get(struct array arr,int index){
    if(index <0 || index > arr.length)
      return 0;
    else{
        return arr.A[index];
    }
}


void set(struct array *arr,int index ,int key){
    if(index <0 || index >arr->length)
     return 0;
    else{
        arr->A[index]=key;
    }
}

int max(struct array arr){
    int max=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(max < arr.A[i]){
            max = arr.A[i];
        }
    }
    return max;
}

int min(struct array arr){
    int min=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(min > arr.A[i]){
            min = arr.A[i];
        }
    }
    return min;
}

int sum(struct array arr){
    int tot = 0;
    for(int i=0;i<arr.length;i++){
        tot+=arr.A[i];
    }
    return tot;
}

float average (struct array arr){
    return (float)sum(arr)/arr.length;
    
}

void reverse(struct array *arr){
    int *b = (int *)malloc(arr->length *(sizeof(int)));
    for(int i=arr->length-1,j=0;i>=0;j++,i--){
        b[j]=arr->A[i];
    }
    for(int i=0;i<arr->length;i++){
        arr->A[i]=b[i];
    }
}

void revtwo(struct array *arr){
    for(int i=0,j=arr->length-1;i<j;i++,j--){
        swap(&arr->A[i],&arr->A[j]);
    }
}

void insertsort(struct array *arr,int k){
    int i = arr->length-1;
    if(arr->length==arr->size){
        return 0;
    }
    while(i>=0 && arr->A[i]>k){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1]=k;
    arr->length++;
}

int issort(struct array arr){
    for(int i = 0;i<arr.length-1;i++){
        if(arr.A[i] > arr.A[i+1]){
            return 0;
        }
        
        
    }
    return 1;
}

void rearrange(struct array *arr){
    int i=0,j=arr->length-1;
    while(i<j){
        while(arr->A[i] < 0){
            i++;
        }
        while(arr->A[j] >=0 ){
            j--;
        }
        if( i< j){
            swap(&arr->A[i],&arr->A[j]);
        }
    }
        

}

struct array* Merge(struct array *arr1,struct array *arr2)
{
 int i,j,k;
 i=j=k=0;

 struct array *arr3=(struct array *)malloc(sizeof(struct array));

 while(i<arr1->length && j<arr2->length)
 {
 if(arr1->A[i]<arr2->A[j])
 arr3->A[k++]=arr1->A[i++];
 else
 arr3->A[k++]=arr2->A[j++];
 }
 for(;i<arr1->length;i++)
 arr3->A[k++]=arr1->A[i];
 for(;j<arr2->length;j++)
 arr3->A[k++]=arr2->A[j];
 arr3->length=arr1->length+arr2->length;
 arr3->size=10;

 return arr3;
}
// Set operations like union,intersection , difference are implemented using merging the arrays(Arrays A,B are sorted) which
//helps to reduce the time complexity to O(n)

struct array* unionarr(struct array *arr1,struct array *arr2){
    int i ,j,k=0;
    struct array *arr3 = (struct array *)malloc(sizeof(struct array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k++]=arr1->A[i++]; // !) here A[k++], A[i++] indicate that once element is copied from location A[i] to A[k] increment both i,k by 1
        }
        else if (arr2->A[j] < arr1->A[i]){
            arr3->A[k++]=arr2->A[j++];     //!)
        }
        else{
            arr3->A[k++]=arr1->A[i++];    //!)
            j++;
        }
    }
    for(;i<arr1->length;i++){          // this portion describes if any element left in either Array A or Array B 
                                       // copy those elements to resultant array
        arr3->A[k++]=arr1->A[i];
    }
    for(;j<arr2->length;j++){
        arr3->A[k++]=arr2->A[j];
    }
    arr3->length = k;
    arr3->size = 10;
    
    return arr3;
}

struct array* intersection(struct array *arr1,struct array *arr2){
    int i,j,k=0;
    struct array *arr4 = (struct array *)malloc(sizeof(struct array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            i++;
        }
        else if(arr1->A[i] > arr2->A[j])
         j++;
         
        else{
            arr4->A[k++]=arr1->A[i++];  // copy only elements that are matched either form A(A[i++]) or B(B[j++])
            j++;
        }
    }
    arr4->length = k;
    arr4->size = 10;
    return arr4;
}

struct array* diffeAB(struct array *arr1,struct array *arr2){
    int i ,j,k=0;
    struct array *arr3 = (struct array *)malloc(sizeof(struct array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k++]=arr1->A[i++]; 
        }
        else if (arr2->A[j] < arr1->A[i]){
           j++;
        }
        else{
            i++;
            j++;
            
        }
    }
    for(;i<arr1->length;i++){          // this portion describes if any element left in  Array A 
                                       // copy those elements to resultant array
        arr3->A[k++]=arr1->A[i];
    }
    arr3->length = k;
    arr3->size = 10;
    
    return arr3;
}

int main()
{
 struct Array arr1;
 int ch;
 int x,index;

 printf("Enter Size of Array");
 scanf("%d",&arr1.size);
 arr1.A=(int *)malloc(arr1.size*sizeof(int));
 arr1.length=0;
 do
 {
 printf("\n\nMenu\n");
 printf("1. Insert\n");
 printf("2. Delete\n");
 printf("3. Search\n");
 printf("4. Sum\n");
 printf("5. Display\n");
 printf("6.Exit\n");

 printf("enter you choice ");
 scanf("%d",&ch);

 switch(ch)
 {
 case 1: printf("Enter an element and index ");
 scanf("%d%d",&x,&index);
 Insert(&arr1,index,x);
 break;
 case 2: printf("Enter index ");
 scanf("%d",&index);
 x=Delete(&arr1,index);
 printf("Deleted Element is %d\n",x);
 break;
 case 3:printf("Enter element to search ");
 scanf("%d",&x);
 index=LinearSearch(&arr1,x);
 printf("Element index %d",index);
 break;
 case 4:printf("Sum is %d\n",Sum(arr1));
 break;
 case 5:Display(arr1);

 }
 }while(ch<6);
 return 0;
}