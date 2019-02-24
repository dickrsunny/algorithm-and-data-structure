/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805511923286016
题目：
1008 Elevator （20 分）
The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.

For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.

Input Specification:
Each input file contains one test case. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100.

Output Specification:
For each test case, print the total time on a single line.

Sample Input:
3 2 3 1
Sample Output:
41

 */


#include <cstdio>

const int maxn = 110;

int main() {
    int nums[maxn], i = 0, floor_level = 0;

    while (scanf("%d", &nums[i]) != EOF) {
        i++;
    }

    int _sum = 0;
    for (int j = 1; j <= nums[0]; j++ ) {
        if (nums[j] > floor_level) {
            _sum += (nums[j] - floor_level) * 6 + 5;
        }
        else {
            _sum += (floor_level - nums[j]) * 4 + 5;
        }
        floor_level = nums[j];
    }

    printf("%d", _sum);
    return 0;
}
