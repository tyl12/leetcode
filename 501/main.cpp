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
    map<int, int> accountant;
    vector<int> findMode(TreeNode* root) {

        preTranversal(root);

        vector<pair<int, int>> tmp; //count, key
        for(auto elem:accountant){
            auto key = elem.first;
            auto val = elem.second;
            printf("key=%d, val=%d\n", key, val);
            tmp.push_back(make_pair(val, key));
        }
        sort(tmp.begin(), tmp.end(), [](const pair<int,int>& p1, const pair<int, int>& p2){
            return p2.first - p1.first < 0;
        });

        for_each(tmp.begin(), tmp.end(), [](auto& p){
            printf("key: %d, val: %d\n", p.first, p.second);
        });

        vector<int> result;

        int max = INT32_MIN;
        for(auto& elem:tmp){
            int count = elem.first;
            int key = elem.second;
                            
            if (max<count)
                max = count;

            if (max == count)
                result.push_back(key);
        }
        
        return result;

    }
    void preTranversal(TreeNode* node){
        if (node == nullptr)
            return;
        auto val = node->val;
        accountant[val]++;

        preTranversal(node->left);
        preTranversal(node->right);
    }
};