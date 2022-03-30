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

    bool hasPathSum2(TreeNode* root, int targetSum) {
        if (root == nullptr){
            return false;
        }

        int val = targetSum - root->val;

        if (root->left == nullptr && root->right == nullptr){
            if (val == 0)
                return true;
            else
                return false;
        }

        bool left = false, right = false;
        if (root->left != nullptr)
            left = hasPathSum(root->left, val);
        if (root->right != nullptr)
            right = hasPathSum(root->right, val);

        if (left || right)
            return true;
        return false;
    }

    using Node = pair<TreeNode*, int>;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr){
            return false;
        }
        
        Node node;
        stack<Node> st;
        st.push(Node(root,0));
        while(!st.empty()){
            Node node = st.top();
            st.pop();

            int accumVal = node.second;
            TreeNode* tn = node.first;

            if (tn->left == nullptr && tn->right == nullptr){
                if (accumVal + tn->val == targetSum)
                    return true;
                continue;
            }

            if (tn->left != nullptr)
                st.push(Node(tn->left, accumVal+tn->val));
            if (tn->right != nullptr)
                st.push(Node(tn->right, accumVal+tn->val));     
        }
        return false;
    }
};