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
#include <cmath>
#include <utility>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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
    TreeNode* insertIntoBST2(TreeNode* root, int val) {
        if (root == nullptr)
            return new TreeNode(val);
        auto node = root;
        while(true){
            auto cur = node->val;
            if (val > cur){
                if (node->right == nullptr){
                    node->right = new TreeNode(val);
                    return root;
                }
                node = node->right;
                continue;
            }
            else{
                if (node->left == nullptr){
                    node->left = new TreeNode(val);
                    return root;
                }
                node = node->left;
                continue;
            }
        }
    }
    /*
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
            return new TreeNode(val);
        auto node = root;
        if (val > root->val){
            if (node->right != nullptr){
                insertIntoBST(node->right, val);
            }else{
                node->right = new TreeNode(val);
            }
        }
        else{
            if (node->left != nullptr){
                return insertIntoBST(node->left, val);
            }else{
                node->left = new TreeNode(val);
            }
        }
        return root;
    }
    */
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
            return new TreeNode(val);
        auto node = root;
        if (val > node->val){
            node->right =  insertIntoBST(node->right, val);
        }
        else{
            node->left = insertIntoBST(node->left, val);
        }
        return root;
    }
};