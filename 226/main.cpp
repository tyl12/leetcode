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
using namespace std;


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

    // TreeNode* invertTree(TreeNode* root) {
    //     if (root == nullptr){
    //         return root;
    //     }
    //     if (root->left != nullptr){
    //         invertTree(root->left);
    //     }
    //     if (root->right != nullptr){
    //         invertTree(root->right);
    //     }
    //     TreeNode* tmp = root->right;
    //     root->right = root->left;
    //     root->left = tmp;
    //     return root;
    // }


    void _invertTree(TreeNode* node){
        TreeNode* tmp = node->left;
        node->left = node->right;
        node->right = tmp;
    }
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr){
            return root;
        }
        stack<TreeNode*> st;

        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
            _invertTree(node);

        }
        return root;
    }
};