/*
236. Lowest Common Ancestor of a Binary Tree
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is
 defined between two nodes p and q as the lowest node in T that has both p and
 q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]




Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of
 itself according to the LCA definition.


Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.
 */

// 思路：
// 我们可以从根结点出发，判断当前结点的左右子树是否包含这两个结点。
// 如果左子树包含两个结点，则它们的最低公共祖先结点也一定在左子树中。
// 如果右子树包含两个结点，则它们的最低公共祖先结点也一定在右子树中。
// 如果一个结点在左子树，而另一个结点在右子树中，则当前结点就是它们的最低公共祖先结点
// 时间复杂度为O(N^2)


class Solution {
public:

    bool has_node(TreeNode* root, TreeNode* node) {
        if (root == NULL)
            return false;

        if (root == node)
            return true;

        return has_node(root->left, node) or has_node(root->right, node);
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL or root == p or root == q)
            return root;

        if (has_node(root->left, p) and has_node(root->left, q))
            return lowestCommonAncestor(root->left, p, q);

        if (has_node(root->right, p) and has_node(root->right, q))
            return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};


/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/discuss/158060/Python-DFS-tm
> 类型：DFS分制
> Time Complexity O(n)
> Space Complexity O(h)
这道Follow Up没有BST的特性，所以要对几种case一个一个进行测试。
Condition为两种：如果没找到，返回None，找到则返回当前的root(因为找到一个root就不需要继续深入)
比对方式：

如果parent的左右孩子都有返回，说明parent就是LCA
如果左边没有返回：则右边返回的就是LCA
如果右边没有返回：则左边返回的就是LCA
class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        if not root: return None
        if p == root or q == root:
            return root
        left = self.lowestCommonAncestor(root.left, p , q)
        right = self.lowestCommonAncestor(root.right, p , q)

        if left and right:
            return root
        if not left:
            return right
        if not right:
            return left



Q & A
问题一：为啥左边没有返回，则右边返回的就是lca啊 (@chris1011)

image

题目定义里明确了p和q都是unique的值，并且p和q都存在于这颗树里。
所以举个例子

如果p = 5， q = 4

我们得知的信息是，就算root节点3的右边不包含p或者q其中任何一个节点，
 左边也必须会有一个最小公共祖先，因为这道题允许嵌套关系

理解了这点，回答你的问题，我们为什么没有右则返回左(你的问题是没有左返回右，一个道理哈)，
 当我们递归完，左右分别返回到root节点3，得到下面的结果：

root的左边返回回来5
root的右边返回回来None (因为q=4，和p是嵌套关系，不在root的右边)
根据题目定义，我们知道只要左边有返回，右边返回None也没关系。因为另外一个node，
 和左边返回上来的5，一定是嵌套的关系。
所以LCA就是左边返回上来的5。
 */


class Solution2 {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (not root or root == p or root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left and right)
            return root;

        return left? left: right;
    }
};


