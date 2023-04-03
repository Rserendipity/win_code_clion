///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// * };
// */
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
//	vector<ListNode*> listOfDepth(TreeNode* tree) {
//		queue<TreeNode*> Q;
//		vector<ListNode*> ans;
//		if (tree)
//			Q.push(tree);
//
//		while (!Q.empty()) {
//			int n = Q.size();
//			ListNode* head = nullptr, *cur = nullptr;
//			while (n--) {
//				TreeNode* top = Q.front();
//				if (head == nullptr) {
//					head = cur = new ListNode(top->val);
//				} else {
//					cur->next = new ListNode(top->val);
//					cur = cur->next;
//				}
//				Q.pop();
//				if (top->left)
//					Q.push(top->left);
//				if (top->right)
//					Q.push(top->right);
//			}
//			ans.push_back(head);
//		}
//		return ans;
//	}
//};