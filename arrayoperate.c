#include <stdio.h>

#define MAX_SIZE 100

int insert_position(int arr[], int n, int element, int position);
int delete_position(int arr[], int n, int position);
int delete_all(int arr[], int n, int element);
void display(int arr[], int n);
int find_max(int arr[], int n);
int find_min(int arr[], int n);

int main() {
    int arr[MAX_SIZE];
    int n = 0; // Number of elements in the array
    int choice, element, position;

    printf("Enter elements into the array (-1 to stop):\n");
    // Insert elements until -1 is entered
    while (1) {
        scanf("%d", &element);
        if (element == -1)
            break;
        arr[n++] = element;
    }

    do {
        printf("\n1) Insert at the beginning\n");
        printf("2) Insert at the end\n");
        printf("3) Insert at a given position\n");
        printf("4) Delete first element\n");
        printf("5) Delete last element\n");
        printf("6) Delete element at a given position\n");
        printf("7) Delete all occurrences of a given element\n");
        printf("8) Find the maximum and minimum element\n");
        printf("9) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at the beginning: ");
                scanf("%d", &element);
                n = insert_position(arr, n, element, 0);
                display(arr, n);
                break;
            case 2:
                printf("Enter the element to insert at the end: ");
                scanf("%d", &element);
                n = insert_position(arr, n, element, n);
                display(arr, n);
                break;
            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                n = insert_position(arr, n, element, position-1);
                display(arr, n);
                break;
            case 4:
                n = delete_position(arr, n, 0);
                display(arr, n);
                break;
            case 5:
                n = delete_position(arr, n, n-1);
                display(arr, n);
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                n = delete_position(arr, n, position-1);
                display(arr, n);
                break;
            case 7:
                printf("Enter the element to delete all occurrences of: ");
                scanf("%d", &element);
                n = delete_all(arr, n, element);
                display(arr, n);
                break;
            case 8:
                printf("Maximum element: %d\n", find_max(arr, n));
                printf("Minimum element: %d\n", find_min(arr, n));
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 9.\n");
        }
    } while (choice != 9);

    return 0;
}

// Function to insert an element at a given position in the array
int insert_position(int arr[], int n, int element, int position) {
    if (n >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return n;
    }
    if (position < 0 || position > n) {
        printf("Invalid position. Insertion failed.\n");
        return n;
    }
    int i;
    // Shift elements to the right
    for (i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    return n + 1;
}

// Function to delete an element at a given position in the array
int delete_position(int arr[], int n, int position) {
    if (n <= 0) {
        printf("Array is empty. Nothing to delete.\n");
        return n;
    }
    if (position < 0 || position >= n) {
        printf("Invalid position. Deletion failed.\n");
        return n;
    }
    // Shift elements to the left
    int i;
    for (i = position; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}

// Function to delete all occurrences of a given element in the array
int delete_all(int arr[], int n, int element) {
    int i, j;
    for (i = j = 0; i < n; i++) {
        if (arr[i] != element) {
            arr[j++] = arr[i];
        }
    }
    return j;
}

// Function to display the contents of the array
void display(int arr[], int n) {
    printf("Array contents: ");
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to find the maximum element in the array
int find_max(int arr[], int n) {
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum element in the array
int find_min(int arr[], int n) {
    int min = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

