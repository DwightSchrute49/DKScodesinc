#include <stdio.h>

int insert_position(int arr[], int n, int element, int position);
int delete_position(int arr[], int n, int position);
int delete_all(int arr[], int n, int element);
void display(int arr[], int n);

int main() {
    int arr[100];
    int n = 0;
    int choice, element, position;
    printf("ENter elements in array(enter -1 to stop):\n");
    while(1){
    	int num;
    	scanf("%d",&num);
    	if(num==-1)
    	break;
    	arr[n++]=num;
	}
    
    do {
        printf("\nMenu:\n");
        printf("1) Insert at the beginning\n");
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
        
        switch(choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                n = insert_position(arr, n, element, 0);
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                n = insert_position(arr, n, element, n);
                break;
            case 3:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                if(position >= 0 && position <= n) {
                    n = insert_position(arr, n, element, position);
                } else {
                    printf("Invalid position!\n");
                }
                break;
            case 4:
                if(n > 0)
                    n = delete_position(arr, n, 0);
                else
                    printf("Array is empty!\n");
                break;
            case 5:
                if(n > 0)
                    n = delete_position(arr, n, n - 1);
                else
                    printf("Array is empty!\n");
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                if(position >= 0 && position < n) {
                    n = delete_position(arr, n, position);
                } else {
                    printf("Invalid position!\n");
                }
                break;
            case 7:
                printf("Enter element to delete: ");
                scanf("%d", &element);
                n = delete_all(arr, n, element);
                break;
            case 8:
            	if(n>0){
            		int max=arr[0],min=arr[0],i;
            		for(i=1;i<=n;i++){
            			if(arr[i]>max)max=arr[i];
            			if(arr[i]<min)min=arr[i];
            		}
            		printf("Maxx element:%d\n",max);
            		printf("Min element:%d\n",min);
            	}
            	else
            	printf("Array is empty");
					}
                break;
            case 9:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
        
        if(choice != 9)
            display(arr, n);
        
    } while(choice != 9);
    
    return 0;
}

int insert_position(int arr[], int n, int element, int position) {
	int i;
    for(i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    return n + 1;
}

int delete_position(int arr[], int n, int position) {
	int i;
    for(i = position; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}

int delete_all(int arr[], int n, int element) {
    int i, j;
    for(i = 0, j = 0; i < n; i++) {
        if(arr[i] != element) {
            arr[j] = arr[i];
            j++;
        }
    }
    return j;
}

void display(int arr[], int n) {
	int i;
    printf("Array contents: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

