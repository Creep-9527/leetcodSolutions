/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
// @lc code=start
/**
 * Definition for singly-linked list.

 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = head;
        for (int i = 0; i < n; ++i){
            if(fast==nullptr){
                return nullptr;
            }
            fast = fast->next;
        }
        while(fast!=nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        if(slow->next != nullptr){
            slow->next = slow->next->next;
        }
        return dummy->next;
    }
};
// @lc code=end

