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
    // int countNodes(TreeNode* root) {
    //     if (root==nullptr){
    //         return 0;
    //     }
    //     int leftCnt = countNodes(root->left);
    //     int righCnt = countNodes(root->right);
    //     return 1+leftCnt+righCnt; 
    // }
    int countNodes(TreeNode* root) {
        stack<TreeNode*> st;
        if (root==nullptr)
            return 0;
        st.push(root);
        int cnt = 0;
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            cnt++;
            if (node->left)
                st.push(node->left);
            if (node->right)
                st.push(node->right);
        }
        return cnt;
    }
};