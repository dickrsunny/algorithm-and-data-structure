#include <iostream>

void swap(int *a1, int *a2) {
    int temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

void swap2(int &a1, int &a2) {
    int temp = a1;
    a1 = a2;
    a2 = temp;
}

int main() {
    int a = 1, b = 6;
    swap(&a, &b);
    std::cout << a << " " << b << "\n";
    swap2(a, b);
    std::cout << a << " " << b << "\n";
    return 0;
}