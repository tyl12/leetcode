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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (root == nullptr){
            return paths;
        }

        vector<string> leftPath = binaryTreePaths(root->left);
        vector<string> rightPath = binaryTreePaths(root->right);

        stringstream ss;
        ss<<root->val;
        string prefix=ss.str();


        if (leftPath.empty() && rightPath.empty()){
            paths.push_back(prefix);
            return paths;
        }

        // if (leftPath.empty())
        //     paths.push_back(prefix);
        // else{
            for (auto itor=leftPath.begin(); itor!= leftPath.end(); itor++){
                paths.push_back(prefix+"->"+*itor);
            }
        // }
        // if (rightPath.empty())
        //     paths.push_back(prefix);
        // else{
            for (auto itor=rightPath.begin(); itor!= rightPath.end(); itor++){
                paths.push_back(prefix+"->"+*itor);
            }
        // }
        return paths;
    }
};