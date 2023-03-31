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
//	ListNode* _addTwoNumbers(ListNode* l1, ListNode* l2, int cur) {
//		int sum = cur;
//
//		if (sum == 0 && !l1 && !l2) {
//			return nullptr;
//		}
//
//		if (l1) {
//			sum += l1->val;
//			l1 = l1->next;
//		}
//		if (l2) {
//			sum += l2->val;
//			l2 = l2->next;
//		}
//
//
//
//		cur = sum / 10;
//		sum %= 10;
//
//		ListNode* node = new ListNode(sum);
//		node->next = _addTwoNumbers(l1, l2, cur);
//
//		return node;
//	}
// public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		return _addTwoNumbers(l1, l2, 0);
//	}
//};