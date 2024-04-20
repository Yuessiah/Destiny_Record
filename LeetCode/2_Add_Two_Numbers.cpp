/*
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* l3 = new ListNode();
      ListNode *ans = l3, *prv;
      while (l1 != NULL && l2 != NULL) {
        prv = l3;

        int x = l1->val + l2->val + l3->val;
        l3->val = x%10;
        l3 = l3->next = new ListNode(x/10);
        l1 = l1->next, l2 = l2->next;
      }

      if (l1 == NULL) l1 = l2; // swap for WLOG
      while (l1 != NULL) {
        prv = l3;

        int x = l1->val + l3->val;
        l3->val = x%10;
        l3 = l3->next = new ListNode(x/10);
        l1 = l1->next;
      }

      if (l3->val == 0) prv->next = NULL;
      return ans;
    }
};
