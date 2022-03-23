#include <string>
#include <stdio.h>
#include <stack>
#include <unistd.h>
#include <memory.h>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <deque>
#include <functional>
#include <algorithm>
#include <sstream>
using namespace std;


// Definition for a Node.
struct TreeNode {
    TreeNode * left;
    TreeNode * right;
    int val;
    TreeNode():val(0),left(nullptr), right(nullptr){}
    TreeNode(int v):val(v), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int getHeight(TreeNode* node){
        if (node == nullptr)
            return 0;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        if (leftHeight == -1 || rightHeight == -1)
            return -1;
        int delta = leftHeight - rightHeight;
        if (delta == 1 || delta == 0)
            return leftHeight+1;
        if (delta == -1)
            return rightHeight+1;
        
        return -1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (leftHeight == -1 || rightHeight == -1)
            return false;

        int delta = leftHeight - rightHeight;
        if (delta == 1 || delta == 0 || delta == -1)
            return true;
        return false;
    }
};