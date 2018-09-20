//  题目：回文串
//  codeup 5901

#include <cstdio>
#include <cstring>

const int maxn = 30;

int main() {
    char string[maxn];
    while(gets(string)) {
        int length = strlen(string);
        bool flag = true;
        for(int i = 0, j = length / 2; i < j ; i++) {
            if (string[i] != string[length - i - 1]) {
                flag = false;
            }
        }

        if (flag) {
            printf("YES");
        }
        else {
            printf("NO");
        }
    }
    return 0;
}