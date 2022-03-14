#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* virtualNode = new ListNode(0, head);
        ListNode* ptr = virtualNode;
        while(ptr != NULL){
            if (ptr->next && ptr->next->val == val){

                ListNode* del = ptr->next;
                ptr->next = ptr->next->next;
                                //printf("remove %d,", del->val);

                delete del;

                continue;
            }
            ptr = ptr->next;
        }
        ListNode* res = virtualNode->next;
        delete virtualNode;
        return res;
    }
};


int main(){
    Solution s;

    int src[] = {1,2,3,4,5,6,6,7,8,9};
    ListNode* head = NULL;
    
    ListNode* cur = head;

    for (int i=0;i<sizeof(src)/sizeof(int);i++){
        auto val = src[i];
        ListNode* node = new ListNode(val);
        if (cur){
            cur->next = node;
        }
        else{
            head = node;
        }
        cur = node;
    }
    cur = head;
    while(cur){
        printf("%d,", cur->val);
        cur = cur->next;
    }


   s.removeElements(head, 6);
    

}