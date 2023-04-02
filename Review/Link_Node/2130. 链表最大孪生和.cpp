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
//	ListNode* reverseList(ListNode* head) {
//		ListNode* prev = nullptr, *cur = head;
//		while(cur) {
//			ListNode* save = cur->next;
//			cur->next = prev;
//			prev = cur;
//			cur = save;
//		}
//		return prev;
//	}
// public:
//	int pairSum(ListNode* head) {
//		ListNode* fast = head, *slow = head, *prev = nullptr;
//		while (fast && fast->next) {
//			fast = fast->next->next;
//			prev = slow;
//			slow = slow->next;
//		}
//		prev->next = reverseList(prev->next);
//
//		fast = head, slow = prev->next;
//		int max = INT_MIN;
//		while (slow) {
//			max = std::max(max, fast->val + slow->val);
//			fast = fast->next;
//			slow = slow->next;
//		}
//		return max;
//	}
//};