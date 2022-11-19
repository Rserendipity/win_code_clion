//
// Created by 22490 on 2022/11/18.
//

#ifndef INC_3LIST_REVERSE_ITERATOR_H
#define INC_3LIST_REVERSE_ITERATOR_H

namespace cjj {
    template<class iterator, class Ref, class Ptr>
    class reverse_iterator {
        typedef reverse_iterator<iterator, Ref, Ptr> self;
    public:

        reverse_iterator(iterator it)
                : _it(it) {}

        self &operator++() {
            --_it;
            return *this;
        }

        self operator++(int) {
            iterator tmp = _it;
            --_it;
            return tmp;
        }

        self &operator--() {
            ++_it;
            return *this;
        }

        self operator--(int) {
            iterator tmp = _it;
            ++_it;
            return tmp;
        }

        Ref operator*() {
            iterator tmp = _it;
            return *--tmp;
        }

        Ptr operator->() {
            iterator tmp = _it;
            --tmp;
            return &tmp.operator*();
        }

        bool operator!=(const self &it) const {
            return _it != it._it;
        }

        bool operator==(const self &it) const {
            return _it == it._it;
        }

    private:
        iterator _it;
    };


}


#endif //INC_3LIST_REVERSE_ITERATOR_H
