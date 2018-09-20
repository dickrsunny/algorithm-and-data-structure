#include <cstdio>
#include <cstring>


int main() {
    char string[90];

    gets(string);

    char matrix[90][90];
    int j = 0, k = 0;
    for (int i=0; i < strlen(string); i++) {
        if (string[i] == " ") {
            j = 0;
            k++;
            continue;
        } else {
            matrix[k][j] = string[i];
            j++;
        }
    }



//    while (scanf("%s", string[i]) != EOF) {
//        i++;
//    }
//
//        printf("%s ", string[j]);
//    }
//
    printf("%s", string);

    return 0;
}