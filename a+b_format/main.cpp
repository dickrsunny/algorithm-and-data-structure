/*
1001 A+B Format （20 分）
Calculate a+b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input Specification:
Each input file contains one test case. Each case contains a pair of integers a and b where −10
​6
​​ ≤a,b≤10
​6
​​ . The numbers are separated by a space.

Output Specification:
For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input:
-1000000 9
Sample Output:
-999,991
 */


#include <iostream>
#include <string>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int _sum = a + b;
    std::string s = std::to_string(abs(_sum)), s_format;

    for (int j = s.length() - 1, k = 1; j > 0; j--, k++) {
        s_format += s[j];
        if (k % 3 == 0) s_format += ",";
    }

    s_format += s[0];

    if (_sum < 0) {
        std::cout << "-";
    }

    int format_length = s_format.length();
    for (int j = format_length - 1; j >= 0; j--) {
        std::cout << s_format[j];
    }

    return 0;
}