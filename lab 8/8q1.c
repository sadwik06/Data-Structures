#include<stdio.h>
#define n 5
int deque[n];
int front =-1;
int rear =-1;
void enqueuefront(int x){
    if(front==0&&rear==n-1||front==rear+1){
        printf("full");
    }
    else if(front==-1&&rear==-1){
        front=0;
        rear=0;
        deque[front]=x;
    }
    else if(front==0){
        front=n-1;
        deque[front]=x;
    }
    else{
        front--;
         deque[front]=x;
    }
}
void enqueuerear(int x){
    if(front==0&&rear==n-1||front==rear+1){
        printf("full");
    }
    else if(front==-1&&rear==-1){
        front=0;
        rear=0;
        deque[rear]=x;
    }
    else if(rear==n-1){
        rear=0;
        deque[rear]=x;
    }
    else{
        rear++;
         deque[rear]=x;
    }
    
}
void dequeuefront(){
    if(front==-1&&rear==-1){
        printf("empty");
    }
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else if(front==n-1){
        front=0;
    }
    else{
        front++;
    }
}
void dequeuerear(){
    if(front==-1&&rear==-1){
        printf("empty");
    }
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else if(rear==0){
        rear=n-1;
    }
    else{
        rear--;
    }
}
void display(){
    int i=front;
    while(i!=rear){
        printf("%d",deque[i]);
        i=(i+1)%n;
    }
    printf("%d",deque[rear]);
}
void getfront(){
    printf("%d",deque[front]);
}
void getrear(){
    printf("%d",deque[rear]);
}
int main(){
    enqueuefront(1);
     enqueuefront(2);
      enqueuerear(3);
       enqueuerear(4);
       dequeuefront();
       dequeuerear();
       display();
       printf("front=");
       getfront();
       printf("rear");
       getrear();
   return 0;    
}