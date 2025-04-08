//Q1 - In the user input linked list, find the smallest int data node and swap it with first node similarly swap the largest data node with end node.

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct node{
    int data;
    struct node *next;
};

int main(){
    int size;
    printf("Enter the number of node : ");
    scanf("%d", &size);

    struct node *head = NULL, *temp;

    for(int i = 1; i <= size; i++){
        struct node *nnode = (struct node *) malloc (sizeof(struct node));

        if(nnode == NULL){
            printf("Memory allocation failed!");
            return 1;
        }

        printf("Enter data : ");
        scanf("%d", &nnode->data);
        nnode->next = NULL;

        if (head == NULL){
            head = nnode;
            temp = nnode;
        } else {
            temp->next = nnode;
            temp = nnode;
        }
    }
    struct node *end = temp;

    temp = head;
    int min = temp->data, max = temp->data;
    while(temp != NULL){
        if(temp->data < min){
            min = temp->data;
        }
        if(temp->data > max){
            max = temp->data;
        }
        temp = temp->next;
    }

    temp = head;
    while(temp->data != min){
        temp = temp->next;
    }

    swap(&head->data, &temp->data);

    temp = head;
    while(temp->data != max){
        temp = temp->next;
    }

    swap(&end->data, &temp->data);

    printf("linked list : ");
    temp = head;
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}