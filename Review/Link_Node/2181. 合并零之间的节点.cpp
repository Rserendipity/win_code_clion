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
//	ListNode* mergeNodes(ListNode* head) {
//		if (head == nullptr) {
//			return nullptr;
//		}
//		ListNode* cur = head->next;
//		ListNode* now = head;
//		while (cur) {
//			now->val = 0;
//			while (cur && cur->val != 0) {
//				now->val += cur->val;
//				cur = cur->next;
//			}
//			if (cur != nullptr && cur->next != nullptr)
//				now = now->next;
//			cur = cur->next;
//		}
//
//		cur = now->next;
//		while (cur) {
//			ListNode* save = cur->next;
//			delete cur;
//			cur = save;
//		}
//
//		now->next = nullptr;
//		return head;
//	}
//};