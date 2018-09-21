#include <cstdio>
#include <cstring>


int main() {

//    gets(string);
//


    char string[90];
    int i = 0;

    while (scanf("%c", &string[i]) != EOF) {
        i++;
    }

    char matrix[90][90];
    int j = 0, k = 0;

    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == 32) {
            j = 0;
            k++;
        } else {
            matrix[k][j] = string[i];
            j++;
        }
    }

    for (int j = k; j > 0; j--) {
        printf("%s ", matrix[j]);
    }

    printf("%s", matrix[0]);

    return 0;
    }
