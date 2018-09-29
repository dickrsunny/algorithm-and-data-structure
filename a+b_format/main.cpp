/*
    1001 A+B Format （20 分）
    Calculate a+b and output the sum in standard format -- that is,
    the digits must be separated into groups of three by commas (unless there are less than four digits).

    Input Specification:
    Each input file contains one test case. Each case contains a pair of integers a and b where −10
    ​6
    ​​ ≤a,b≤10
    ​6
    ​​ . The numbers are separated by a space.

    Output Specification:
    For each test case, you should output the sum of a and b in one line.
    The sum must be written in the standard format.

    Sample Input:
    -1000000 9
    Sample Output:
    -999,991
 */


 /*
    题目大意：计算A+B的和，然后以每三位加一个”,”的格式输出。

    分析：把a+b的和转为字符串s。除了第一位是负号的情况，
    只要当前位的下标i满足(i + 1) % 3 == len % 3并且i不是最后一位，
    就在逐位输出的时候在该位输出后的后面加上一个逗号
  */

#include <iostream>
using namespace std;

int main() {
    int a, b, seq = 0;

    cin >> a >> b;

    string s = to_string(a + b);
    if (s[0] == '-') {
        seq += 1;
        cout << "-";
    }

    int len = s.length();
    for (int i = seq; i < len; i++) {
        cout << s[i];
        if ((i + 1) % 3 == len % 3 && i != len - 1) cout << ",";
    }
    return 0;
}