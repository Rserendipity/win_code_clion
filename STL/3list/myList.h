//
// Created by 22490 on 2022/11/18.
//

#ifndef INC_3LIST_MYLIST_H
#define INC_3LIST_MYLIST_H

#include <iostream>
#include "reverse_iterator.h"


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

        bool operator!=(const self &it) const {
            return _it != it._it;
        }

        bool operator==(const self &it) const {
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

        typedef reverse_iterator<const_iterator, T &, T *> const_reverse_iterator;
        typedef reverse_iterator<iterator, T &, T *> reverse_iterator;


        iterator begin() {
            return iterator(_head->next);
        }

        iterator end() {
            return iterator(_head);
        }

        const_iterator begin() const {
            return iterator(_head->next);
        }

        const_iterator end() const {
            return iterator(_head);
        }

        reverse_iterator rbegin() {
            return reverse_iterator(end());
        }

        reverse_iterator rend() {
            return reverse_iterator(begin());
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

    void test2() {
        list<int> l1;
        l1.push_back(10);
        l1.push_back(20);
        l1.push_back(30);
        l1.push_back(40);

        list<int>::reverse_iterator it = l1.rbegin();
        while (it != l1.rend()) {
            cout << *it << endl;
            ++it;
        }
    }

}
#endif //INC_3LIST_MYLIST_H
