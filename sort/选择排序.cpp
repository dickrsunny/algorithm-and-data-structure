#include <iostream>


int main() {
    int nums[10] = {1, 9, 5, 2, 6, 3, 7, 5, 8, 3};

    int length = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < length - 1; i++) {
        int min = i;

        for (int j = i; j < length; j++) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }

        int temp = nums[i];
        nums[i] = nums[min];
        nums[min] = temp;
    }

    for (int k = 0; k < length; k++) {
        printf("%d\n", nums[k]);
    }

    return 0;
}