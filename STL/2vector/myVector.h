//
// Created by 22490 on 2022/11/19.
//

#ifndef INC_2VECTOR_MYVECTOR_H
#define INC_2VECTOR_MYVECTOR_H
#include <iostream>
#include <cassert>
using std::cout;
using std::endl;

namespace cjj {

    template <class T>
    class vector{

    public:
        typedef T* iterator;
        typedef const T* const_iterator;

        iterator begin()
        {
            return _start;
        }

        iterator end()
        {
            return _finish;
        }

        const_iterator begin() const
        {
            return _start;
        }

        const_iterator end() const
        {
            return _finish;
        }

        vector()
            : _start(nullptr)
            , _finish(nullptr)
            , _end_of_storage(nullptr)
        {}

        template<class InputIterator>
        vector(InputIterator begin, InputIterator end)
            : _start(nullptr)
            , _finish(nullptr)
            , _end_of_storage(nullptr)
        {
            while (begin != end)
            {
                push_back(*begin);
                ++begin;
            }
        }


        vector(const vector<T>& v)
            : _start(nullptr)
            , _finish(nullptr)
            , _end_of_storage(nullptr)
        {
            vector<T> tmp(v.begin(), v.end());
            swap(tmp);
        }

        void swap(vector<T>& v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_end_of_storage, v._end_of_storage);
        }

        size_t capicity()
        {
            return _end_of_storage - _start;
        }

        void resize(size_t n, const T& val = T())
        {
            if (n < size())
            {
                _finish = _start + n;
            }
            else
            {
                if (n > capicity())
                {
                    reserve(n);
                }

                while (_finish != _start + n)
                {
                    *_finish++ = val;
                }
            }
        }

        vector<T>& operator=(vector<T> v)
        {
            swap(v);
            return *this;
        }

        void reserve(size_t n)
        {
            if (_start + n < _finish)
            {
                _finish = _start + n;
            }
            else
            {
                if (_start + n > _end_of_storage)
                {
                    size_t sz = size();
                    T* tmp = new T[n];

                    if (_start != nullptr)
                    {
                        for (size_t i = 0;i < sz; i++)
                        {
                            tmp[i] = _start[i];
                        }
                    }

                    delete[] _start;
                    _start = tmp;
                    _finish = _start + sz;
                    _end_of_storage = _start + n;
                }
            }
        }

        size_t size()
        {
            return _end_of_storage - _start;
        }

        void push_back(const T& val)
        {
            if (_finish == _end_of_storage)
            {
                reserve(_end_of_storage == nullptr ? 4 : size() * 2);
            }
            *_finish++ = val;
        }

        T& operator[](size_t pos)
        {
            assert(pos >= 0);
            assert(pos < size());
            return _start[pos];
        }

        ~vector()
        {
            if (_start != nullptr)
            {
                delete[] _start;
                _start = _finish = _end_of_storage = nullptr;
            }
        }
    private:
        T* _start;
        T* _finish;
        T* _end_of_storage;
    };


    void test1()
    {
        vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        v.push_back(30);
        v.push_back(30);
        v.push_back(30);
        v.push_back(30);

        for (auto& n : v)
        {
            cout << n << " ";
        }
        cout << endl;

        vector<int> v2 = v;
        for (auto& n : v2)
        {
            cout << n << " ";
        }
        cout << endl;

    }

    class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> ans;
            ans.resize(numRows);
            for (int i = 0; i < numRows; i++) {
                ans[i].resize(i + 1);
                ans[i][0] = ans[i][ans[i].size() - 1] = 1;
                // ans[i].front() = ans[i].back() = 1;
            }
            for (int i = 0; i < numRows; i++) {
                for (int j = 0; j < ans[i].size(); j++) {
                    if (ans[i][j] == 0) {
                        ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
                    }
                }
            }
            return ans;
        }
    };

    void test2()
    {
        vector<vector<int>> vv = Solution().generate(7);
        for (auto& v : vv)
        {
            for (auto& n : v)
            {
                cout << n << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

#endif //INC_2VECTOR_MYVECTOR_H
