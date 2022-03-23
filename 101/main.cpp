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

    bool compare(TreeNode* left, TreeNode* right){
        if (left == nullptr && right == nullptr)
            return true;
        if ((left != nullptr && right == nullptr) ||
            (left == nullptr && right != nullptr) ||
            (left->val != right->val)){
                return false;
        }
        auto leftRes = compare(left->left, right->right);
        auto rightRes = compare(left->right, right->left);
        if (leftRes && rightRes)
            return true;
        
        return false;
    }

    bool isSymmetric2(TreeNode* root) {
        vector<TreeNode*> st;
        if (root == nullptr)
            return true;
        auto leftRes = compare(root->left, root->right);
        return leftRes;
    }

    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> st;

        if (root == nullptr)
            return true;

        st.push(root->left);
        st.push(root->right);
        while(!st.empty()){
            auto first = st.top();
            st.pop();
            auto second = st.top();
            st.pop();

            if (first == nullptr && second == nullptr)
                continue;
            if ((first != nullptr && second == nullptr) ||
                (first == nullptr && second != nullptr) ||
                (first->val != second->val)){
                    return false;
            }          

            st.push(first->left);
            st.push(second->right);
            st.push(first->right);
            st.push(second->left);
        }
        return true;
    }


};