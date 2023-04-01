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
//	struct com {
//		bool operator()(const ListNode* l1, const ListNode* l2) {
//			return l1->val > l2->val;
//		}
//	};
// public:
//	ListNode* mergeKLists(vector<ListNode*>& lists) {
//		if (lists.size() == 0) {
//			return nullptr;
//		}
//
//		ListNode* pHead = nullptr, *cur = nullptr;
//		priority_queue<ListNode*, vector<ListNode*>, com> pq;
//		for (int i = 0; i < lists.size(); i++) {
//			if (lists[i])
//				pq.push(lists[i]);
//		}
//		while (!pq.empty()) {
//			ListNode* pop = pq.top();
//			pq.pop();
//
//			if (pop->next) {
//				pq.push(pop->next);
//			}
//
//			if (pHead == nullptr) {
//				pHead = cur = pop;
//			} else {
//				cur->next = pop;
//				cur = cur->next;
//			}
//
//		}
//		return pHead;
//	}
//};