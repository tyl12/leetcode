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
    TreeNode* deleteNode2(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        auto node = root;

        auto parent = node;
        while(node){
            if (key > node->val){
                parent = node;
                node = node->right;
                continue;
            }
            if (key < node->val){
                parent = node;
                node = node->right;
                continue;
            }
            if (key == node->val){
                if (node->left == nullptr && node->right == nullptr){
                    if (key < parent->val)
                        parent->left = nullptr;
                    else
                        parent->right = nullptr;
                }
                else if (node->right == nullptr){
                    if (key < parent->val)
                        parent->left = node->left;
                    else
                        parent->right = node->left;
                }
                else if (node->left == nullptr){
                    if (key < parent->val)
                        parent->left = node->right;
                    else
                        parent->right = node->left;
                }
                else{
                    if (key < parent->val){
                        TreeNode* tmp = node; //search to right
                        TreeNode* tmpParent = node;
                        while(tmp->right){
                            tmpParent = tmp;
                            tmp = tmp->right;
                        }
                        
                        tmpParent->right = nullptr;
                        tmp->left = node->left;
                        tmp->right = node->right;
                        parent->left = tmp;

                        return root;
                    }
                    else{
                        TreeNode* tmp = node; //search to left
                        TreeNode* tmpParent = node;
                        while(tmp->left){
                            tmpParent = tmp;
                            tmp = tmp->left;
                        }
                        
                        tmpParent->left = nullptr;
                        tmp->right = node->right;
                        tmp->left = node->left;
                        parent->right = tmp;
                        
                        return root;
                    }
                } 
            }
        }
        return root;
    }

    TreeNode* findNode(TreeNode* node, int key, vector<TreeNode*>& path){
        while(node){
            path.push_back(node);
            if (node->val == key){
                return node;
            }
            if (key < node->val){
                node = node->left;
                continue;
            }
            else{
                node = node->right;
                continue;
            }
        }
        return nullptr;
    }

    TreeNode* reconstructTree(TreeNode* delNode){
        if (delNode == nullptr)
            return nullptr;
        if (delNode->left == nullptr && delNode->right == nullptr)
            return nullptr;
        if (delNode->left != nullptr && delNode->right == nullptr)
            return delNode->left;
        if (delNode->right != nullptr && delNode->left == nullptr)
            return delNode->right;
        
        //both not null
        bool useLeft = true;
        if (useLeft){
            TreeNode* node = delNode->left;
            while(node->right){
                node = node->right;
            }
            
{

}
        }
        else{ //use right

        }

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return root;
        
        vector<TreeNode*> path;
        auto targetNode = findNode(root, key, path);
        if (targetNode == nullptr)
            return nullptr;

        for_each(path.begin(), path.end(), [](TreeNode* node){
            printf("%d->", node->val);
        });
        printf("\n");

        auto newTree = reconstructTree(targetNode);

        if (path.size() == 1){
            return newTree;
        }
        if (path.size() >= 2){
            auto node = path[path.size()-2];
            if (key > node->val)
                node->right = newTree;
            else
                node->left = newTree;
            return root;
        }
        
    }
};

