
/*

      1
    /  \
   2    3
  / \   / \
 4   5  6  7

 */

#include <iostream>
#include <queue>

using namespace std;


void GetPostOrder(const int pre_order[], int post_order[], int pre_left, int pre_right, int post_left, int post_right) {
    if(pre_left > pre_right)
        return;

    post_order[post_right] = pre_order[pre_left];
    int mid = (pre_right - pre_left) / 2;
    GetPostOrder(pre_order, post_order, pre_left+1, pre_left+mid, post_left, post_left+mid-1);
    GetPostOrder(pre_order, post_order, pre_left+mid+1, pre_right, post_left+mid, post_right-1);
}


int main() {
    int pre_order[] = {1, 2, 4, 5, 3, 6, 7};
    int length = sizeof(pre_order) / sizeof(pre_order[0]);
    int post_order[length];

    GetPostOrder(pre_order, post_order, 0, 6, 0, 6);

    for(int i=0; i<length; i++) {
        cout << post_order[i] << " ";
    }
}