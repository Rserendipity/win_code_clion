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
//	ListNode* removeNthFromEnd(ListNode* head, int n) {
//		ListNode* pHead = new ListNode(-1);
//		pHead->next = head;
//
//		ListNode* cur = pHead, *fast = pHead;
//		while (n--) {
//			fast = fast->next;
//		}
//
//		while (fast && fast->next) {
//			cur = cur->next;
//			fast = fast->next;
//		}
//		fast = cur->next;
//		cur->next = cur->next->next;
//		delete fast;
//		cur = pHead->next;
//		delete pHead;
//		return cur;
//	}
//};