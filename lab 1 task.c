#include <stdio.h>

void displayArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertAtBeginning(int arr[], int *length, int value, int maxCapacity) {
    if (*length >= maxCapacity) {
        printf("Error: Array is full.\n");
        return;
    }
    for (int i = *length; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    (*length)++;
}

void insertAtEnd(int arr[], int *length, int value, int maxCapacity) {
    if (*length >= maxCapacity) {
        printf("Error: Array is full.\n");
        return;
    }
    arr[*length] = value;
    (*length)++;
}

void insertAtIndex(int arr[], int *length, int index, int value, int maxCapacity) {
    if (*length >= maxCapacity || index < 0 || index > *length) {
        printf("Invalid operation.\n");
        return;
    }
    for (int i = *length; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    (*length)++;
}

void deleteFirst(int arr[], int *length) {
    if (*length == 0) {
        printf("Error: Array is empty.\n");
        return;
    }
    for (int i = 0; i < *length - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*length)--;
}

void deleteLast(int arr[], int *length) {
    if (*length == 0) {
        printf("Error: Array is empty.\n");
        return;
    }
    (*length)--;
}

void deleteAtIndex(int arr[], int *length, int index) {
    if (index < 0 || index >= *length) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index; i < *length - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*length)--;
}

void searchValue(int arr[], int length, int value) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == value) {
            printf("Element found at index %d.\n", i);
            return;
        }
    }
    printf("Element not found.\n");
}

void sortAscending(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int maxCapacity, length;
    printf("Enter the maximum size of the array: ");
    scanf("%d", &maxCapacity);

    int arr[maxCapacity];

    printf("Enter the number of elements: ");
    scanf("%d", &length);

    printf("Enter the elements: ");
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original Array: ");
    displayArray(arr, length);

    insertAtBeginning(arr, &length, 5, maxCapacity);
    printf("After inserting 5 at the beginning: ");
    displayArray(arr, length);

    insertAtEnd(arr, &length, 15, maxCapacity);
    printf("After inserting 15 at the end: ");
    displayArray(arr, length);

    insertAtIndex(arr, &length, 2, 25, maxCapacity);
    printf("After inserting 25 at index 2: ");
    displayArray(arr, length);

    deleteFirst(arr, &length);
    printf("After deleting the first element: ");
    displayArray(arr, length);

    deleteLast(arr, &length);
    printf("After deleting the last element: ");
    displayArray(arr, length);

    deleteAtIndex(arr, &length, 1);
    printf("After deleting element at index 1: ");
    displayArray(arr, length);

    searchValue(arr, length, 25);

    sortAscending(arr, length);
    printf("After sorting the array: ");
    displayArray(arr, length);

    return 0;
}
