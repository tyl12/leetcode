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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty())
            return nullptr;
        auto itor = max_element(nums.begin(), nums.end());
        auto leftV = vector<int>(nums.begin(), itor);
        auto left = constructMaximumBinaryTree( leftV );

        auto rightV = vector<int>(itor+1, nums.end());
        auto right = constructMaximumBinaryTree( rightV );
        return new TreeNode(*itor, left, right);
    }
};