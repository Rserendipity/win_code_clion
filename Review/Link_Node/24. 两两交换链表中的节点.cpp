///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode() : val(0), next(nullptr) {}
// *     ListNode(int x) : val(x), next(nullptr) {}
// *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// * };
// */
//class Solution {
// public:
//	ListNode* swapPairs(ListNode* head) {
//		if (!head || !head->next) {
//			return head;
//		}
//		ListNode phead(-1);
//		phead.next = head;
//		ListNode* cur = &phead;
//		while (cur->next && cur->next->next) {
//			ListNode* next = cur->next, *nnext = next->next;
//
//			next->next = nnext->next;
//			nnext->next = next;
//			cur->next = nnext;
//
//			cur = cur->next->next;
//
//		}
//		return phead.next;
//	}
//};