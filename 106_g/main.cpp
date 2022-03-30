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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty())
            return nullptr;

        int rootVal = postorder.back();
        auto itor = find(inorder.begin(), inorder.end(), rootVal);
        auto inorderLeft = vector<int>(inorder.begin(), itor);
        auto inorderRight = vector<int>(itor+1, inorder.end());

        int leftSize = itor - inorder.begin();
        int rightSize = inorder.end() - itor-1;

        auto postorderLeft = vector<int>(postorder.begin(), postorder.begin()+ leftSize);
        auto postorderRight = vector<int>(postorder.begin()+leftSize, postorder.end()-1);

        TreeNode* left = buildTree(inorderLeft, postorderLeft);
        TreeNode* right = buildTree(inorderRight, postorderRight);
        TreeNode* root = new TreeNode(rootVal, left, right);
        return root;
    }
};