#include <stdio.h>
#define COMPARE(a, b) (a > b ? -1 : (a == b ? 0 : 1))
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int binsearch(int a[], int key, int low, int high);
void sort(int a[], int n);
int recursiveBinarySearch(int arr [], int key, int low, int high);

int main() {
    int i, key, n, choice;

    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    int a[100];

    printf("Enter the array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter key: ");
    scanf("%d", &key);
    printf("Choose a search method:\n");
    printf("1. Iterative Binary Search\n");
    printf("2. Recursive Binary Search\n");
    scanf("%d", &choice);

    // Sorting the array before binary search
    sort(a, n);
    int x,y;

    switch (choice) {
        case 1:
            // Using the iterative binary search function
            x = binsearch(a, key, 0, n - 1);
            if (x == -1) {
                printf("Element is not found using iterative binary search\n");
            } else {
                printf("The key is found at index %d using iterative binary search\n", x);
            }
            break;

        case 2:
            // Using the recursive binary search function
            y = recursiveBinarySearch(a, key, 0, n - 1);
            if (y == -1) {
                printf("Element is not found using recursive binary search\n");
            } else {
                printf("The key is found at index %d using recursive binary search\n", y);
            }
            break;

        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;
}

    

int binsearch(int a[], int key, int low, int high) {
    int middle;

    while (low <= high) {
        middle = low +( high - low) / 2;

        switch (COMPARE(a[middle], key)) {
            case -1:
                low = middle + 1;
                break;

            case 0:
                return middle;

            case 1:
                high = middle - 1;
                break;
        }
    }

    return -1;
}

void sort(int a[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        SWAP(a[i], a[min], temp);
    }

    // Print sorted array
    printf("Sorted list is:");
    for (i = 0; i < n; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");
}

int recursiveBinarySearch(int arr[], int key, int low, int high) {
    while (low<=high){
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            return recursiveBinarySearch(arr, key, low, mid - 1);
        } else {
            return recursiveBinarySearch(arr, key, mid + 1,high);
        }
    }
    return -1;
}