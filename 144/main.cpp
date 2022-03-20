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
    int value;
    TreeNode():value(0),left(nullptr), right(nullptr){}
    TreeNode(int v):value(v), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : value(x), left(left), right(right) {}
};

struct TNW{
    TreeNode* node;
    bool flag;
    TNW(TreeNode* _node=nullptr, bool _flag = false):node(_node),flag(_flag){}

    void setFlag(){
        flag = true;
    }
    bool isFlag(){
        return flag;
    }
};
class Solution {
private:
    void _preorderTraversal(TreeNode* root, vector<int>& result){
        if (root == nullptr){
            return;
        }
        result.push_back(root->value);

        _preorderTraversal(root->left, result);

        _preorderTraversal(root->right, result);
    }
public:

    vector<int> preorderTraversal1(TreeNode* root) {
        vector<int> result;
        _preorderTraversal(root, result);
        return result;
    }
    vector<int> preorderTraversal2(TreeNode* root) {
        stack<TreeNode*, deque<TreeNode*>> store;
        vector<int> result;

        // if (root == nullptr){
        //     return result;
        // }
        
        TreeNode* node = root;
        while (true){
            if (node){
                store.push(node);
                result.push_back(node->value);
                node = node->left;
                continue;
            }
            else{
                if (store.empty())
                    return result;
                node = store.top();
                store.pop();
                node = node->right;
            }
        }
        return result;
    }
    vector<int> preorderTraversal4(TreeNode* root) {
        stack<TreeNode*, deque<TreeNode*>> store;
        vector<int> result;
        TreeNode* node = root;
        if (node == nullptr)
            return result;
        
        store.push(node);
        while(true){
            if (store.empty())
                return result;
            node = store.top();
            store.pop();
            if (node == nullptr)
                continue;
            result.push_back(node->value);
            store.push(node->right);
            store.push(node->left);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TNW> store;
        auto node = root;

        store.push({node});
        TNW nodeWrap;
        while(true){
            if (store.empty()){
                return result;
            }
            nodeWrap = store.top();
            store.pop(); //stack　头节点出栈
            node = nodeWrap.node;
            if (node == nullptr){
                continue;
            }

            if (nodeWrap.isFlag()){//当前节点设置过标记位，说明当前节点的左右子节点之前已经入栈过，本次访问是第二次出栈，左右节点已经访问完了，不需要将左右节点再入栈了，可以直接访问该节点了
                result.push_back(node->value);
            }
            else{
                nodeWrap.setFlag();//当前节点是第一次出栈，所有设置一下标记位，然后将节点重新入栈，然后将其左右子节点入栈
                store.push({node->right});
                store.push({node->left});
                store.push(nodeWrap);
                
            }
        }
    }
};