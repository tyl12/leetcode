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
    TreeNode* searchBST2(TreeNode* root, int val) {
        if (root==nullptr || val == root->val)
            return root;
        if (val > root->val)
            return searchBST(root->right, val);
        else
            return searchBST(root->left, val);
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* node = root;
        while(true){
            if (node == nullptr || val == node->val)
                return node;
            if (val > node->val){
                node = node->right;  
            }
            else{
                node = node->left;
            }
        }
    }

};