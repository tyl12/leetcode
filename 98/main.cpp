#include <cstdint>
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
/*
    bool isValidBST2(TreeNode* root) {
        if (root == nullptr)
            return false;

        {
            int val=INT32_MIN;
            TreeNode* node = root->left;
            while(node != nullptr){
                val = node->val;
                node = node->right;
            }
            if (root->val <= val)
                return false;
        }
        {
            int val=INT32_MAX;
            TreeNode* node = root->right;
            while(node != nullptr){
                val = node->val;
                node = node->left;
            }
            if (root->val >= val)
                return false;
        }
        
        bool left = true;
        bool right = true;
        if (root->left != nullptr){
            left = isValidBST(root->left);
        }
        if (root->right != nullptr){
            right = isValidBST(root->right);
        }
        return left && right;
    }
*/
/*
    bool first = true;
    int last=INT32_MIN, cur=INT32_MIN;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr)
            return true;

        auto result = inorderCheckBST(root);
        return result;
    }

    bool inorderCheckBST(TreeNode* node){
        if (node->left != nullptr){
            if (inorderCheckBST(node->left) == false)
                return false;   
        }

        cur = node->val;
        if (first){
            first = false;
        }else{
            if (cur <= last){
                return false;
            }
        }
        last = cur;

        if (node->right != nullptr){
            if (inorderCheckBST(node->right) == false)
                return false;   
        }
        return true;
    }
*/
    TreeNode* prev = nullptr;
    bool isValidBST(TreeNode* root) {
        bool left = true, right = true;
        if (root == nullptr)
            return false;

        if (root->left != nullptr){
            left = isValidBST(root->left);
        }
        if (left == false)
            return false;

        if (prev == nullptr)
            prev = root;
        else{
            if (root->val <= prev->val)
                return false;
            prev = root;
        }
            
        if (root->right != nullptr){
            right = isValidBST(root->right);
        }
        if (right == false)
            return false;

        return true;
    }
};