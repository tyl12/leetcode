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
/*
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr){
            return nullptr;
        }
        auto node = tranverseNode(root, p, q);
        return node;
    }
    int foundCnt = 0;
    TreeNode* tranverseNode(TreeNode* root, TreeNode* p, TreeNode* q){
        if (root == nullptr)
            return nullptr;
        auto left = tranverseNode(root->left, p, q);
        if (left){
            if (foundCnt == 2)
                return left;
        }
        auto right = tranverseNode(root->right, p, q);
        if (right){
            if (foundCnt == 2)
                return right;
        }

        if (left && right){
            foundCnt = 2;
            return root;
        }
        if (left || right){//only 1 found
            if (root == p || root == q){
                foundCnt = 2;
                return root;
            }
            return (left?left:right);
        }
        return nullptr;
    }
    */
    /*
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr){
            return nullptr;
        }
        int cnt = tranverseNode(root, p, q);
        return result;
    }
    TreeNode* result = nullptr;
    int tranverseNode2(TreeNode* root, TreeNode* p, TreeNode* q){ //return found node count
        if (root == nullptr)
            return 0;

        auto leftCnt = tranverseNode(root->left, p, q);
        if (leftCnt == 2)
            return 2;
        auto rightCnt = tranverseNode(root->right, p, q);
        if (rightCnt == 2)
            return 2;
        
        if (leftCnt + rightCnt == 2){
            result = root;
            return 2;
        }
        else if (leftCnt + rightCnt == 1){
            if (root == p || root == q){
                result = root;
                return 2;
            }
            return 1;
        }
        //leftCnt=rightCnt=0
        if (root==p||root==q)
            return 1;
        
        return 0;
    }

    int tranverseNode(TreeNode* root, TreeNode* p, TreeNode* q){ //return found node count
        if (root == nullptr)
            return 0;

        auto leftCnt = tranverseNode(root->left, p, q);
        auto rightCnt = tranverseNode(root->right, p, q);
        
        if (leftCnt + rightCnt == 2){
            if (result==nullptr)
                result = root;
            return 2;
        }
        else if (leftCnt + rightCnt == 1){
            if (root == p || root == q){
                result = root;
                return 2;
            }
            return 1;
        }
        else{
            //leftCnt=rightCnt=0
            if (root==p||root==q)
                return 1;
        }
        return 0;
    }
    */

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr){
            return nullptr;
        }
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (left && right){
            return root;
        }
        if (left||right){
            if (root == p || root == q)
                return root;
            return left?left:right;
        }
        if (root == p || root == q)
            return root;
        
        return nullptr;
    }
};