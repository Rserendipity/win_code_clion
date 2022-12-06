//
// Created by 22490 on 2022/12/6.
//

#ifndef INC_4AVLTREE_AVLTREE_H_
#define INC_4AVLTREE_AVLTREE_H_
#include <cassert>
#include <iostream>

template<class T>
struct AVLTreeNode
{
	AVLTreeNode* left;
	AVLTreeNode* right;
	AVLTreeNode* parent;
	int bf;

	T val;
	AVLTreeNode(const T& val = T())
		: left(nullptr), right(nullptr), parent(nullptr), bf(0),
		  val(val)
	{
	}
};

template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;

 public:

	AVLTree()
		: root(nullptr)
	{
	}

	bool insert(const T& val)
	{
		if (root == nullptr)
		{
			root = new Node(val);
			return true;
		}

		// 寻找插入的地方
		Node* cur = root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->val < val)
			{
				parent = cur;
				cur = cur->right;
			}
			else if (cur->val > val)
			{
				parent = cur;
				cur = cur->left;
			}
			else
			{
				return false;
			}
		}

		// 判断插入在哪里
		if (parent->val < val)
		{
			parent->right = new Node(val);
			cur = parent->right;
			cur->parent = parent;
		}
		else
		{
			parent->left = new Node(val);
			cur = parent->left;
			cur->parent = parent;
		}

		// 判断平衡，是否需要旋转
		while (parent)
		{
			if (parent->left == cur)
			{
				parent->bf--;
			}
			else
			{
				parent->bf++;
			}

			// 已经平衡，不需要旋转
			if (parent->bf == 0)
			{
				break;
			}
			else if (parent->bf == -1 || parent->bf == 1)
			{
				// 更新位置
				parent = parent->parent;
				cur = cur->parent;
			}
			else if (parent->bf == 2 || parent->bf == -2)
			{
				// 需要旋转
				// 右单旋
				if (parent->bf == -2 && cur->bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->bf == 2 && cur->bf == 1)
				{
					RotateL(parent);
				}

				break;
			}
			else
			{
				std::cout << "Tree Err" << std::endl;
				assert(0);
			}

		}

		return true;
	}

 private:

	void RotateR(Node* parent)
	{
		Node* grandFather = parent->parent;
		Node* L = parent->left;
		Node* LR = L->right;

		parent->left = LR;
		if (LR)
			LR->parent = parent;

		L->right = parent;
		parent->parent = L;

		if (grandFather)
		{
			if (grandFather->left == parent)
				grandFather->left = L;
			else
				grandFather->right = L;
		}
		else
		{
			root = L;
		}

		L->parent = grandFather;

		L->bf = parent->bf = 0;
	}

	void RotateL(Node* parent)
	{
		Node* grandFather = parent->parent;
		Node* R = parent->right;
		Node* RL = R->left;

		if (grandFather)
		{
			if (grandFather->left == parent)
				grandFather->left = R;
			else
				grandFather->right = R;
		}
		else
		{
			root = R;
		}
		R->parent = grandFather;

		R->left = parent;
		parent->parent = R;

		parent->right = RL;
		if (RL)
			RL->parent = parent;

		R->bf = parent->bf = 0;
	}

	Node* root;
};

#endif //INC_4AVLTREE_AVLTREE_H_
