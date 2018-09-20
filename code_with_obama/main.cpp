#include <cstdio>
#include <cmath>

void printC(char c, int rows, int n) {
    for (int i = 0; i < rows; i++) {
        if (i > 0 && i < rows - 1) {
            for (int j = 0; j < n; j++) {
                if (j > 0 && j < n - 1) {
                    printf(" ");
                }
                else {
                    printf("%c", c);
                }
            }
            printf("\n");
        }
        else {
            for (int j = 0; j < n; j++) {
                printf("%c", c);
            }
            printf("\n");

        }
    }
}


int main() {
    int N, rows;
    char C;

    scanf("%d %s", &N, &C);

    rows = round(N / 2.0);
    printC(C, rows, N);

    return 0;
}
