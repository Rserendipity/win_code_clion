///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode(int x) : val(x), next(NULL) {}
// * };
// */
//class Solution {
// public:
//	ListNode* reverseList(ListNode* head) {
//		ListNode *prev = nullptr, *cur = head;
//		while (cur) {
//			ListNode *save = cur->next;
//			cur->next = prev;
//			prev = cur;
//			cur = save;
//		}
//		return prev;
//	}
//};