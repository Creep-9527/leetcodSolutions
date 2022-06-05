/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseK(ListNode*head,int k){
      ListNode *cur = head->next;
      for (int i = 0; i < k; ++i){
        if(cur == nullptr){
          return nullptr;
        }
        cur = cur->next;
      }
      ListNode *pre = cur;
      cur = head->next;
      ListNode *ans = cur;
      ListNode* next = cur->next;
      for (int i = 0; i < k; ++i){
        cur->next = pre;
        pre = cur;
        cur = next;
        if(next!=nullptr){
          next = next->next;
        }
      }
      head->next = pre;
      return ans;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode *dummy = new ListNode();
      dummy->next = head;
      ListNode *cur = dummy;
      while(cur!=nullptr){
        cur = reverseK(cur, k);
      }
      return dummy->next;
    }
};
// @lc code=end

