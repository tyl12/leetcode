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

    using Node = tuple<TreeNode*, vector<int>>;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;

        if (root == nullptr){
            return result;
        }
        
        Node node;
        stack<Node> st;
        st.push(Node(root,vector<int>()));
        while(!st.empty()){
            Node node = st.top();
            st.pop();

            vector<int> v;
            TreeNode* tn;
            tie(tn, v) = node;
            int accumVal = accumulate(v.begin(), v.end(), 0);

            if (tn->left == nullptr && tn->right == nullptr){
                if (accumVal + tn->val == targetSum){
                    v.push_back(tn->val);
                    result.push_back(v);
                }
                continue;
            }
            
            v.push_back(tn->val);
            if (tn->left != nullptr)
                st.push(Node(tn->left, v));
            if (tn->right != nullptr)
                st.push(Node(tn->right, v));
        }
        return result;
    }
};