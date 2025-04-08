//Q2 - In the user input linked list, make two new linked list one having even data and one odd data.

#include <stdio.h>
#include <stdlib.h>

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

    struct node *even_head = NULL, *even_temp, *odd_head = NULL, *odd_temp;

    temp = head;

    while(temp != NULL){
        if(temp->data % 2 == 0){
            struct node *even_nnode = (struct node *) malloc (sizeof(struct node));

            even_nnode->data = temp->data;
            even_nnode->next = NULL;
            
            if(even_head == NULL){
                even_head = even_nnode;
                even_temp = even_nnode;
            } else {
                even_temp->next = even_nnode;
                even_temp = even_nnode;
            }
        } else {
            struct node *odd_nnode = (struct node *) malloc (sizeof(struct node));

            odd_nnode->data = temp->data;
            odd_nnode->next = NULL;

            if(odd_head == NULL){
                odd_head = odd_nnode;
                odd_temp = odd_nnode;
            } else {
                odd_temp->next = odd_nnode;
                odd_temp = odd_nnode;
            }
        }
        temp = temp->next;
    }

    printf("\nEntered linked list :\n");
    temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    printf("\nNew even linked list :\n");
    even_temp = even_head;
    while(even_temp != NULL){
        printf("%d\n", even_temp->data);
        even_temp = even_temp->next;
    }

    printf("\nNew odd linked list :\n");
    odd_temp = odd_head;
    while(odd_temp != NULL){
        printf("%d\n", odd_temp->data);
        odd_temp = odd_temp->next;
    }
}