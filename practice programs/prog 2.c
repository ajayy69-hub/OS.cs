#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int min = arr[0];
    int pos = 0;

    for(int i = 1; i < n; i++) {
        if(arr[i] < min) {
            min = arr[i];
            pos = i;
        }
    }

    printf("Smallest number: %d\n", min);
    printf("Position: %d\n", pos + 1);

    return 0;
}
