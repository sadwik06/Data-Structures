#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*front=0;
struct node*rear=0;
void enqueue(int x){
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;
    if(rear==0){
        rear=front=newnode;
        rear->next=front;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}
void dequeue(){
    struct node*temp;
    temp=front;
    front=front->next;
    rear->next=front;
    free(temp);
}
void display(){
   struct node*temp;
    temp=front; 
    while(temp->next!=front){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}
int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    dequeue();
    display();
}