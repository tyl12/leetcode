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

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> container;
        int index = 0;
        if (root == nullptr)
            return result;
        TreeNode* node = root;
        container.push(node);

        
        while(!container.empty()){
            vector<int> tmp;
            int cnt = container.size();
            for (int i=0;i<cnt;i++){
                node = container.front();
                container.pop();
                tmp.push_back(node->val);
                if (node->left)
                    container.push(node->left);
                if (node->right)
                    container.push(node->right);
            }
            result.push_back(tmp);
        }
        return result;
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        auto result = levelOrder(root);
        reverse(result.begin(), result.end());
        return result;
    }

};