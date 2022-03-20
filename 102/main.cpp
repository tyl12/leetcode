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
    vector<vector<int>> levelOrder2(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> container[2];
        int index = 0;
        if (root == nullptr)
            return result;
        
        TreeNode* node = root;
        container[index].push(node);
        vector<int> tmp;
        while(true){
            if (!container[(index)%2].empty()){
                node = container[(index)%2].front();
                container[(index)%2].pop();
                if (node == nullptr){
                    continue;
                }
                tmp.push_back(node->val);
                printf("->push %d to %d\n", node->val, index);
                if (node->left)
                    container[(index+1)%2].push(node->left);
                if (node->right)
                    container[(index+1)%2].push(node->right);
            }
            else{
                result.push_back(tmp);
                printf("->push vector %d\n", index);
                tmp.clear();

                index++;
                if (container[(index)%2].empty()){
                    return result;
                }
            }

        }

    }
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
};