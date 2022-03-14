
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

 #include <stdio.h>


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* pre, *cur, *next;
        pre = nullptr;
        cur = head;
        next= head->next;

        while(next != nullptr){
            printf("-> # %d ", cur->val);
            cur->next=pre;

            pre = cur;
            cur = next;
            next = next->next;
        }
        cur->next = pre;
        printf("\n");
        return cur;
    }
    ListNode* reverseList2(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* pre, *cur;
        pre = nullptr;
        cur = head;

        while(cur->next != nullptr){
            ListNode* tmpnext = cur->next;
            cur->next=pre;
            
            pre = cur;
            cur = tmpnext;
        }
        cur->next = pre;
        return cur;
    }
};


void showList(ListNode* head){
    ListNode* ptr;
    ptr = head;
    while(ptr != nullptr){
        printf("-> %d ", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}
int main(){
    ListNode* head;

    ListNode* tmp =new ListNode(909);
    for (int i=0;i<100;i++){
        tmp = new ListNode(i, tmp);
    }
    head = tmp;
    showList(head);

    Solution s;
    ListNode* result = s.reverseList2(head);

    showList(result);


    return 0;
}