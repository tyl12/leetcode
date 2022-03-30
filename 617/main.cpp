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
#include <numeric>
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if (root1==nullptr && root2==nullptr)
            return nullptr;

        int val1 = 0;
        int val2 = 0;
        TreeNode* left1 = nullptr;
        TreeNode* right1 = nullptr;
        TreeNode* left2 = nullptr;
        TreeNode* right2 = nullptr;

        if (root1 != nullptr){
            val1 = root1->val;
            left1 = root1->left;
            right1 = root1->right;
        }
        if (root2 != nullptr){
            val2 = root2->val;
            left2 = root2->left;
            right2 = root2->right;
        }

        auto rootLeft = mergeTrees(left1, left2);
        auto rootRight = mergeTrees(right1, right2);
        auto root = new TreeNode(val1+val2, rootLeft, rootRight);
        return root;
    }
};