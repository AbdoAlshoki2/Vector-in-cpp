//
// Created by Alshoki on 12/5/2022.
//

#ifndef VECOTR_IMPLEMENTATION_VECTOR_H
#define VECOTR_IMPLEMENTATION_VECTOR_H

#include "bits/stdc++.h"
#include "stdexcept"
using namespace std;

class error : public exception{
private:
    char * s;
public:
    error(char * x) : s(x){}

    virtual const char * what() const noexcept override{
        return s;
    }
};


template <typename T >
class Vector {
public:


private:
    T* data;
    int sze ;
    int MaxCapacity;
public:
    // constructors

    class Iterator{
    public:
        using iterator_category = std::random_access_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T *;
        using reference = T &;
    public:
        Iterator (pointer ptr) {
            m_ptr = ptr ;
        }
        /**
         * increment the pointer by 1
         * @return the iterator after increment
         */
        Iterator & operator++(){
            m_ptr++;
            return *this;
        }

        /**
         * increment the pointer by 1
         * @return the iterator before increment
         */
        Iterator operator++(int){
            Iterator iterator = *this ;
            ++*(this);
            return iterator;
        }

        /**
         * decrement the pointer by 1
         * @return the iterator after decrement
         */
        Iterator & operator--(){
            m_ptr--;
            return *this;
        }

        /**
         * decrement the pointer by 1
         * @return the iterator before decrement
         */
        Iterator operator--(int){
            Iterator iterator = *this ;
            --*(this);
            return iterator;
        }

        /**
         * get the value of the pointer
         * @return the value of pointer
         */
        reference operator *(){
            return *m_ptr;
        }

        /**
         * get the pointer itself
         * @return the pointer
         */
        pointer operator ->(){
            return  m_ptr;
        }

        /**
         * logic operators that compare between two parameters
         * @param a first iterator
         * @param b second iterator
         * @return if the compare is true
         */
        friend bool operator==(const Iterator &a, const Iterator &b) { return a.m_ptr == b.m_ptr; };

        friend bool operator!=(const Iterator &a, const Iterator &b) { return a.m_ptr != b.m_ptr; };

        friend bool operator<(const Iterator &a, const Iterator &b) { return a.m_ptr < b.m_ptr; };

        friend bool operator>(const Iterator &a, const Iterator &b) { return a.m_ptr > b.m_ptr; };

        /**
         * operator -= that decrement the iterator by number
         * @param i int
         * @return the new iterator after decrement
         */
        Iterator &operator-=(int i) {
            m_ptr -= i;
            return *this;
        }

        /**
         * operator -= that increment the iterator by number
         * @param i int
         * @return the new iterator after increment
         */
        Iterator &operator+=(int i) {
            m_ptr += i;
            return *this;
        }

        /**
         * operator - that return a new iterator with less pointer
         * @param i int
         * @return the iterator with new value
         */
        Iterator operator -( int i ){
            return Iterator(this->m_ptr - i);
        }

        /**
         * operator - that gets the difference between two iterators
         * @param i int
         * @return the iterator with new value
         */
        int operator -( const Iterator & i ){
            return this->m_ptr - i.m_ptr;
        }

        /**
         * operator - that return a new iterator with greater pointer
         * @param i int
         * @return the iterator with new value
         */
        Iterator operator +(int i ){
            return Iterator(this->m_ptr + i);
        }

    private:
        pointer m_ptr;
    };
    Vector();
    Vector(int);
    Vector(int , T);
    Vector(T * , int);
    Vector(Vector<T> &);
    Vector(Vector<T> && );
    Vector(initializer_list<T>);

    // operators
    Vector<T > & operator = (Vector<T> &);
    Vector<T > & operator = (Vector<T> &&);
    bool operator == (Vector<T> &);
    bool operator != (Vector<T> &) ;
    bool operator < (Vector<T> &);
    bool operator > (Vector<T> &);
    T& operator[](int);
    template<typename U > friend ostream & operator << (ostream& , Vector<U>);

    // methods
    void push_back(T);
    void pop_back();
    T back();
    T front();
    void insert(Iterator , T);
    void erase (Iterator);
    void erase (Iterator , Iterator);
    Iterator begin();
    Iterator end();
    void clear ();
    int size();
    int capacity();
    bool empty();
    void resize();
    void resize(int);

    ~Vector();
};


#endif //VECOTR_IMPLEMENTATION_VECTOR_H
