//
// Created by 22490 on 2022/11/18.
//

#ifndef INC_3LIST_MYLIST_H
#define INC_3LIST_MYLIST_H

#include <iostream>

using std::cout;
using std::endl;

namespace cjj {

    template<class T>
    struct ListNode {
        T val;
        ListNode *pre;
        ListNode *next;

        explicit ListNode(const T &val = T()) : val(val), pre(nullptr), next(nullptr) {}
    };

    template<class T, class Ref, class Ptr>
    struct _list_iterator {
        typedef ListNode<T> Node;
        typedef _list_iterator<T, Ref, Ptr> self;

        explicit _list_iterator(Node *node)
                : _it(node) {}

        Ref &operator*() {
            return _it->val;
        }

        self &operator++() {
            _it = _it->next;
            return *this;
        }

        self operator++(int) {
            self tmp(_it);
            _it = _it->next;
            return tmp;
        }

        self &operator--() {
            _it = _it->pre;
            return *this;
        }

        self operator--(int) {
            self tmp(_it);
            _it = _it->pre;
            return tmp;
        }

        bool operator!=(const self &it) {
            return _it != it._it;
        }

        bool operator==(const self &it) {
            return _it == it._it;
        }

        Node *_it;
    };

    template<class T>
    class list {
    private:
        typedef ListNode<T> Node;
    public:
        typedef _list_iterator<T, T &, T *> iterator;
        typedef _list_iterator<T, const T &, const T *> const_iterator;

        iterator begin() {
            return iterator(_head->next);
        }

        iterator end() {
            return iterator(_head);
        }

        explicit list() {
            _head = new Node();
            _head->next = _head;
            _head->pre = _head;
        }

        void push_back(const T &val) {
            Node *newNode = new Node(val);
            Node *pre = _head->pre;
            newNode->pre = pre;
            newNode->next = _head;
            pre->next = newNode;
            _head->pre = newNode;
        }

    private:
        Node *_head;
    };

    void test1() {
        list<int> l1;
        l1.push_back(10);
        l1.push_back(20);
        l1.push_back(30);
        l1.push_back(40);

        for (auto &n: l1) {
            cout << n << endl;
        }

    }

}
#endif //INC_3LIST_MYLIST_H
