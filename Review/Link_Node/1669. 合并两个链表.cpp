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
//	ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
//		int n = b - a;
//		ListNode* cur = list1, *next = nullptr;
//		while (--a) {
//			cur = cur->next;
//		}
//		next = cur->next;
//		cur->next = list2;
//
//		while (cur && cur->next)
//			cur = cur->next;
//
//		while (n--) {
//			next = next->next;
//		}
//		cur->next = next->next;
//		return list1;
//	}
//};