/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805514284679168
题目：
Maximum Subsequence Sum
Given a sequence of K integers { N
​1
​​ , N
​2
​​ , ..., N
​K
​​  }. A continuous subsequence is defined to be { N
​i
​​ , N
​i+1
​​ , ..., N
​j
​​  } where 1≤i≤j≤K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:
Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (≤10000). The second line contains K numbers, separated by a space.

Output Specification:
For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4

 */

#include <cstdio>

const int maxn = 10010;


int main() {
    int k, nums[maxn], i = 0;

    // 输入数字数量
    scanf("%d", &k);

    //  输入数字
    while (scanf("%d", &nums[i]) != EOF) {
        i++;
    }

    int left = 0, start = 0, end = 0;
    int temp_sum = nums[0], _sum = nums[0];

    for (int j = 1; j < k; j++) {
        if (temp_sum > 0) {
            temp_sum += nums[j];
        } else {
            temp_sum = nums[j];
            left = j;
        }

        if (temp_sum > _sum) {
            _sum = temp_sum;
            start = left;
            end = j;
        }
    }

    if(_sum < 0) {
        printf("%d %d %d", 0, nums[0], nums[k - 1]);
    } else {
        printf("%d %d %d", _sum, nums[start], nums[end]);
    }

    return 0;
}
