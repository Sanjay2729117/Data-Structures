#include <stdio.h>
#include<stdlib.h>


typedef struct Node{
    int data;
    struct Node* link;
}Node;

Node* create(int data){
    Node* newNode=(Node*)malloc(sizeof(Node*));
    newNode->data=data;
    newNode->link=NULL;
    return newNode;
}

void insertatbeginning(Node** head,int data){
    Node* newNode=create(data);
    if(*head==NULL){
        *head=newNode;
    }else{
    newNode->link=*head;
    *head=newNode;
    }
}
void insertatintermediate(Node** head,int data,int position){
    Node* newNode=create(data);
    Node* current=*head;
     Node* prev=NULL;
    int count=1;
    while(current!=NULL){
        if(count==position){
           prev->link=newNode;
           newNode->link=current;
           break;
        }
        count++;
        prev=current;
         current=current->link;
    }
}
void insertatlast(Node** head,int data){
    Node* newNode=create(data);
    Node* current=*head;
     Node* prev=NULL;
   while(current!=NULL){
        prev=current;
        current=current->link;
    } 
     prev->link=newNode;
}
void deleteatbeginning(Node** head){
    Node* current=*head;
    *head=current->link;
    free(current);
}
void deleteatlast(Node** head){
    Node* current=*head;
    Node* prev=NULL;
     while(current->link!=NULL){
       
        prev=current;
        current=current->link;
    } 
    prev->link=NULL;
    free(current);
}
void deleteatintermediate(Node** head,int position){
    Node* current=*head;
    Node* prev=NULL;
      int count=1;
     while(current!=NULL){
        if(count==position){
           prev->link=current->link;
           free(current);
           break;
        }
        prev=current;
        current=current->link;
        count++;
}
}
void reverse(Node** head){
    Node* current=*head;
    Node* prev=NULL;
    Node* next=NULL;
    while(current!=NULL)
{
    next=current->link;
    current->link=prev;
    prev=current;
    current=next;
}
    *head=prev;
}
void display(Node** head){
    Node* current=*head;
    while(current!=NULL)
{
    printf("%d ",current->data);
    current=current->link;
}}
int main() {
    Node* head=NULL;
     insertatbeginning(&head,6);
     insertatbeginning(&head,7);
     insertatbeginning(&head,7);
     insertatintermediate(&head,9,2);
     insertatlast(&head,15);
printf("\n");
display(&head);
 reverse(&head);
 
printf("\n");
display(&head);

    return 0;
}