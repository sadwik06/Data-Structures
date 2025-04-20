#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteNode(struct Node* node) {
    if (node == NULL || node->next == NULL) {
        printf("Cannot delete this node.\n");
        return;
    }
    struct Node* temp = node->next;  
    node->data = temp->data;         
    node->next = temp->next;         
    free(temp);  
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 1;
    head->next = malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = malloc(sizeof(struct Node));
    head->next->next->next->data = 4;
    head->next->next->next->next = NULL;

    printf("Original List: ");
    printList(head);
    deleteNode(head->next);
    printf("List after deletion: ");
    printList(head);
    free(head->next->next);
    free(head->next);
    free(head);
    
    return 0;
}
