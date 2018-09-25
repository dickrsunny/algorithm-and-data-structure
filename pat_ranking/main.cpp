/*
题目：https://pintia.cn/problem-sets/994805342720868352/problems/994805474338127872

1025 PAT Ranking （25 分）
Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University.
 Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test.
 Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

Input Specification:
Each input file contains one test case. For each case,
 the first line contains a positive number N (≤100), the number of test locations.
 Then N ranklists follow, each starts with a line containing a positive integer K (≤300), the number of testees,
 and then K lines containing the registration number (a 13-digit number) and the total score of each testee.
 All the numbers in a line are separated by a space.

Output Specification:
For each test case, first print in one line the total number of testees.
 Then print the final ranklist in the following format:

registration_number final_rank location_number local_rank
The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks.
 The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
 */

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 30010;

struct Student {
    char id[15];
    int score;
    int location_num;
    int local_rank;
} stu[maxn];

bool cmp(Student a, Student b) {
    if (a.score != b.score) {
        return a.score > b.score;
    }
    else {
        return strcmp(a.id, b.id) < 0;
    }
}

int main() {
    int locations, ranklists, count = 0;


    scanf("%d", &locations);
    // 遍历考点
    for (int i = 1; i <= locations; i++) {

        scanf("%d", &ranklists);
        // 输入成绩条目
        for (int j = 0; j < ranklists; j++) {
            scanf("%s %d", stu[count + j].id, &stu[count + j].score);
            stu[count + j].location_num = i;
        }


        // 考场内排序
        sort(&stu[count], &stu[count] + ranklists, cmp);

        stu[count].local_rank = 1;

        // 记录考场排名
        for (int k = 1; k < ranklists; k++) {
            if (stu[count + k].score != stu[count + k - 1].score) {
                stu[count + k].local_rank = k + 1;
            }
            else {
                stu[count + k].local_rank = stu[count + k - 1].local_rank;
            }
        }

        // 记录总成绩条目
        count += ranklists;
    }

    sort(stu, stu + count, cmp);
    printf("%d\n", count);
    // 打印总排名
    int r = 1;
    for (int m = 0; m < count; m++) {
        if (m > 0 && stu[m].score != stu[m - 1].score) {
            r = m + 1;
        }
        printf("%s %d %d %d\n", stu[m].id, r, stu[m].location_num, stu[m].local_rank);
    }

    return 0;
}