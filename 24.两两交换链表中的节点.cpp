/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
// @lc code=start

  


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *cur = dummy;
        while(cur->next != nullptr && cur->next->next != nullptr){
            ListNode *first = cur->next;
            ListNode *second = cur->next->next;
            first->next = second->next;
            second->next = first;
            cur->next = second;
            cur = cur->next->next;
        }
        ListNode *ans = dummy->next;
        delete dummy;
        dummy = nullptr;
        return ans;
    }
};
// @lc code=end

