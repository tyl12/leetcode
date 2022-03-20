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


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    vector<vector<Node*>> levelOrder(Node* root) {
        vector<vector<Node*>> result;
        queue<Node*> container;
        int index = 0;
        if (root == nullptr)
            return result;
        Node* node = root;
        container.push(node);
        
        while(!container.empty()){
            vector<Node*> tmp;
            int cnt = container.size();
            for (int i=0;i<cnt;i++){
                node = container.front();
                container.pop();
                tmp.push_back(node);
                if (node->left)
                    container.push(node->left);
                if (node->right)
                    container.push(node->right);
            }
            result.push_back(tmp);
        }
        return result;
    }

    Node* connect(Node* root) {
        vector<vector<Node*>> result = levelOrder(root);
        for(auto itor = result.begin();itor != result.end(); itor++){
            int cnt = itor->size();
            if (cnt == 1)
                (*itor)[0]->next = nullptr;
            else{
                for (int i =0;i<cnt-1;i++){
                    (*itor)[i]->next = (*itor)[i+1];
                }
            }

            // for(auto cur = itor->begin(); cur != itor->end()-2; cur ++){
            //     (*cur)->right = *(cur+1);
            // }
            // (*(itor->end()-1))->right = nullptr;
        }
        return root;
    }
};