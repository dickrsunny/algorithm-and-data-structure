// 题目：3n+1
// from 算法笔记
// PAT B1001


#include <stdio.h>


int main() {
    int n;
    scanf("%d", &n);
    if (n > 1000) {
        printf("%s", "The given number must be less than 1000 or equal");
        return 0;
    }

    // 偶数
    int count = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n = (3 * n + 1) / 2;
        }
        count += 1;
    }
    printf("%d", count);
    return 0;
}
