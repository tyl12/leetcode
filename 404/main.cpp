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

struct Node{
    TreeNode* node;
    bool isLeft;
    Node(TreeNode* n, bool i){
        node = n;
        isLeft = i;
    }
};

class Solution {
public:
    int sumNode(TreeNode* node, int isLeft){
        int s1=0;
        int s2=0;

        if (node == nullptr)
            return 0;
        

        if (isLeft && node->left == nullptr && node->right == nullptr){
            return node->val;
        }
        
        return sumNode(node->left, 1) + sumNode(node->right, 0);

    }
    int sumOfLeftLeaves2(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int s1=0,s2=0;

        s1 = sumNode(root->left, 1); //left
        s2 = sumNode(root->right, 0);

        return s1 + s2;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr)
            return 0;

        stack<Node> st;

        int result = 0;
        st.push(Node(root, false));
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            auto TN = node.node;
            auto isLeft = node.isLeft;

            if (TN == nullptr)
                continue;

            if (isLeft){
                if (TN->left == nullptr && TN->right == nullptr){
                    result += TN->val;
                    continue;
                }
            }
            st.push(Node(TN->left, true));
            st.push(Node(TN->right, false));
        }
        return result;
    }

};