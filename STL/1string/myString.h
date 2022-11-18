//
// Created by 22490 on 2022/11/18.
//

#ifndef INC_1STRING_MYSTRING_H
#define INC_1STRING_MYSTRING_H
#include <cstring>
#include <cassert>
#include <iostream>
using std::cout;
using std::endl;

namespace cjj{

    class myString{
        friend std::ostream& operator<<(std::ostream& out, cjj::myString& s);
    public:
        myString(const char* str = "")
        : _str(nullptr)
        , _size(strlen(str))
        , _capicity(_size)
        {
            _str = new char[_size + 1];
            strcpy(_str, str);
        }

        typedef char* iterator;
        typedef const char* const_iterator;

        iterator begin()
        {
            return _str;
        }

        iterator end()
        {
            return _str + _size;
        }

        const_iterator begin() const
        {
            return _str;
        }

        const_iterator end() const
        {
            return _str + _size;
        }

        void reserve(size_t newCap)
        {
            if (newCap < _size)
            {
                _str[newCap] = '\0';
                _size = newCap;
            }
            else
            {
                if (newCap > _capicity)
                {
                    _capicity = newCap;
                    char* tmp = new char[newCap + 1];
                    strcpy(tmp, _str);
                    delete[] _str;
                    _str = tmp;
                }
            }
        }

        void push_back(const char& ch)
        {
            if (_size == _capicity)
            {
                reserve(_capicity == 0 ? 4 : _capicity * 2);
            }
            _str[_size++] = ch;
            _str[_size] = '\0';
        }

    private:
        char* _str;
        size_t _size;
        size_t _capicity;
    };

    std::ostream& operator<<(std::ostream& out, cjj::myString& s)
    {
        out << s._str;
        return out;
    }


    void test1()
    {
        myString s("abc");
        s.push_back('a');
        s.push_back('b');
        s.push_back('c');
        for (auto ch : s)
        {
            cout << ch;
        }
        cout << endl;
    }
}

#endif //INC_1STRING_MYSTRING_H
