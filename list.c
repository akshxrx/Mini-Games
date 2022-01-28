#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void initialize(List *L) {
   L->length=0;
}

int length(List L) {
    return L.length;
}

void add(List *L, int c) {
  NodeType *new = (struct node*) malloc(sizeof(struct node*));
  new->data=c;
  new->next=L->head;
  L->head=new;
  L->length++;
}

void print(List L) {
 int i = 0; 
 NodeType *new = L.head;
 int arr[75];
 while(i<L.length){
    arr[i]=new->data;
    i++;
    new=new->next;
 }
 for(int j=i; j>=0; j--)
 {
    int data = arr[j];
    if (data >= 1 && data <= 15)
    {  if (data < 10)
       {
        printf("L0%i ", data);  
       } else {
         printf("L%i ", data);
       }
    } else if (data >= 16 && data <= 30)
    {
       printf("I%i ", data);
    } else if (data >= 31 && data <= 45)
    {
       printf("N%i ", data);
    } else if (data >= 46 && data <= 60)
    {
       printf("U%i ", data);
    } else if (data >= 61 && data <= 75)
    {
       printf("X%i ", data);
    }
 }
 printf("\n");
}

int search(List L, int c) {
   int i = 0; 
   NodeType *new = L.head;
   while(i<L.length){
      if (new->data == c) {
         return 1;
      }
      i++;
      new=new->next;
   } return 0;
}