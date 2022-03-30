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

//用于增加标记位，
struct TreeNode {
    TreeNode * left;
    TreeNode * right;
    int val;
    TreeNode():val(0),left(nullptr), right(nullptr){}
    TreeNode(int v):val(v), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

public:

    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> result;
        stack<TNW> store;
        auto node = root;
        if (node == nullptr)
            return result;

        store.push({node});
        TNW nodeWrap;
        while(true){
            if (store.empty()){
                return result;
            }
            nodeWrap = store.top();
            store.pop(); //stack　头节点出栈
            node = nodeWrap.node;

            if (node->right == nullptr && node->left == nullptr){ //当前节点没有子节点，直接访问
                result.push_back(node->val);
                continue;
            }

            if (nodeWrap.isFlag()){//当前节点设置过标记位，说明当前节点的左右子节点之前已经入栈过，本次访问是第二次出栈，左右节点已经访问完了，不需要将左右节点再入栈了，可以直接访问该节点了
                result.push_back(node->val);
            }
            else{
                nodeWrap.setFlag();//当前节点是第一次出栈，所有设置一下标记位，然后将节点重新入栈，然后将其左右子节点入栈
                if (node->right){
                    store.push({node->right});
                }
                store.push(nodeWrap);
                if (node->left){
                    store.push({node->left});
                }
            }
        }
    }
    vector<int> inorderTraversal5(TreeNode* root) {
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
            if (node == nullptr)
                continue;

            if (nodeWrap.isFlag()){//当前节点设置过标记位，说明当前节点的左右子节点之前已经入栈过，本次访问是第二次出栈，左右节点已经访问完了，不需要将左右节点再入栈了，可以直接访问该节点了
                result.push_back(node->val);
            }
            else{
                nodeWrap.setFlag();//当前节点是第一次出栈，所有设置一下标记位，然后将节点重新入栈，然后将其左右子节点入栈

                store.push({node->right});
                store.push(nodeWrap);
                store.push({node->left});
            }
        }
    }


    using Node = pair<TreeNode*, bool>; //is first access
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<Node> st;
        if (root == nullptr)
            return result;
        st.push(Node(root, true));
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            auto TN = node.first;
            auto isFirst = node.second;
            if (TN == nullptr)
                continue;

            if (isFirst){
                st.push(Node(TN->right, true));
                node.second = false;
                st.push(node);
                st.push(Node(TN->left, true));
            }
            else{
                result.push_back(TN->val);
            }
        }
        return result;
    }
};