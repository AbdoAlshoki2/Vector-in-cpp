
//
// Created by Alshoki on 12/11/2022.
//

#include "Vector.h"

/**
 * default constructor
 * make the Vector with size 1
 * @tparam T
 */
template<typename T>
Vector<T>::Vector() {
    data = new T[1];
    MaxCapacity = 1;
    sze = 0 ;
}

/**
 * constructor that take a size
 * initialize the Vector with this size
 * check if the size is allocatable
 * @tparam T
 * @param size
 */
template<typename T>
Vector<T>::Vector(int size) : sze(size) , MaxCapacity(size * 1.5){
    if(size <0 || size > 10000000) throw error("Invalid size for the array");
    data = new T[MaxCapacity];
}

/**
 * constructor that take a size and specific value
 * initialize the Vector with this size and initial value
 * check if the size is allocatable
 * @tparam T template parameter
 * @param size the size of the Vector
 * @param value the initial value
 */
template<typename T>
Vector<T>::Vector(int size , T value) : sze(size) , MaxCapacity(size * 1.5){
    if(size <=0 || size > 10000000) throw error("Invalid size for the array");
    data = new T[MaxCapacity];
    for (int i = 0; i < size; ++i) {
        data[i] = value ;
    }
}

/**
 * constructor that takes a pointer to array and the size of this array
 * copy elements from this array
 * @tparam T template parameter
 * @param array the name of the pointer to the array
 * @param size size of array
 */
template<typename T>
Vector<T>::Vector(T * array, int size) : sze(size) , MaxCapacity(size * 1.5){
    data = new T [size];
    for (int i = 0; i < size; ++i) {
        data[i] = array[i] ;
    }
}

/**
 * copy constructor that copy elements from Vector to another
 * @tparam T template parameter
 * @param other the Vector will be copied
 */
template<typename T>
Vector<T>::Vector(Vector<T>& other) : sze(other.size()) , MaxCapacity(other.capacity()){
    data = new T[other.size()];
    for (int i = 0; i < other.size(); ++i) {
        data[i] = other.data[i];
    }
}

/**
 * move constructor that move elements from Vector to another
 * and delete all elements from the other Vector
 * @tparam T template parameter
 * @param other the Vector that will be deleted
 */
template<typename T>
Vector<T>::Vector(Vector<T>&& other) : sze(other.size()) , MaxCapacity(other.size()){
    data = other.data;
    other.data = nullptr;
    other.sze = 0;
    other.MaxCapacity = 1;
}

/**
 * constructor that take a list
 * assign values for this list to Vector
 * @tparam T template parameter
 * @param list an initializer list
 */
template<typename T>
Vector<T>::Vector(initializer_list<T> list) {
    sze = MaxCapacity = list.size();
    data = new T[sze];
    auto it = list.begin();
    for (int i = 0; i < sze; ++i , it++) {
        data[i] = *it ;
    }
}

/**
 * operator = to copy vector to another
 * copy the values from other
 * @tparam T template parameter
 * @param other that we copy its elements
 * @return the new Vector
 */

template<typename T>
Vector<T> &Vector<T>::operator=(Vector<T> & other) {
    if(&other == this){
        return *this;
    }
    else {
        data = new T[other.size()];
        for (int i = 0; i < other.size(); ++i) {
            data[i] = other.data[i];
        }
        sze = other.size();
        MaxCapacity = other.capacity();
        return *this;
    }
}

/**
 * operator = to move vector to another
 * take the values from other and delete the data
 * @tparam T template parameter
 * @param other that we delete its elements
 * @return the new Vector
 */
template<typename T>
Vector<T> &Vector<T>::operator=(Vector<T> && other) {
    if(&other == this){
        return *this;
    }
    else {
        sze = other.size();
        MaxCapacity = other.capacity();
        data = other.data;
        other.data = nullptr;
        other.sze = 0;
        other.MaxCapacity = 1;
        return *this;
    }
}

/**
 * operator == to check if two Vector are equal
 * looping on the two Vectors and check if they have the same size and same elements
 * @tparam T template parameter
 * @param other the other Vector that we compare to
 * @return if they equal
 */
template<typename T>
bool Vector<T>::operator==(Vector<T> & other) {
    if(sze != other.size())
        return false;
    else{
        for (int i = 0; i < size(); ++i) {
            if(data[i] != other.data[i])
                return false;
        }
        return true ;
    }
}

/**
 * operator != check if these Vectors are not equal
 * @tparam T template parameter
 * @param other the other Vector that we compare to
 * @return if they are not equal
 */
template<typename T>
bool Vector<T>::operator!=(Vector<T> & other) {
    return ! (*this == other) ;
}

/**
 * operator > check return Vector < another Vector
 * looping and check for every elements in the two Vectors
 * first element that will be different , function returns
 * @tparam T template parameter
 * @param other the other Vector that we compare to
 * @return if the fist different element is less than or greater than
 */
template<typename T>
bool Vector<T>::operator<(Vector<T> & other)  {
    for (int i = 0; i < min(size(),other.size()); ++i) {
        if(data[i] > other.data[i])
            return false;
        else if ( data[i] < other.data[i])
            return true;
    }
    if(size() >= other.size())
        return false;

    return true ;
}

/**
 * operator > check return Vector > another Vector
 * return if not equal and not less than
 * @tparam T template parameter
 * @param other the other Vector that we compare to
 * @return if fist Vector is greater than the second
 */
template<typename T>
bool Vector<T>::operator>(Vector<T> & other)  {
    return ! (*this == other) && ! (*this < other) ;
}

/**
 * operator [] to get the value in this index
 * check if the index is in Vector
 * else throw an exception
 * @tparam T template parameter
 * @param index the element's index
 * @return the value at this index
 */
template<typename T>
T & Vector<T>::operator[](int index ) {
    if (index >= size() || index < 0) throw out_of_range("");
    else
        return *(data + index);
}

/**
 * function end that return an iterator to the first element
 * @tparam T template parameter
 * @return iterator that points to the first element
 */
template<typename  T >
typename Vector<T>:: Iterator Vector<T>:: begin(){
    return Iterator (data);
}

/**
 * function end that return an iterator to the last element
 * @tparam T template parameter
 * @return iterator that points to the last element
 */
template<typename  T >
typename Vector<T>:: Iterator Vector<T>::end(){
    return Iterator (data+sze);
}

/**
 * operator << that will print the content of Vector
 * looping on the size of Vector and print elements
 * @tparam U template parameter
 * @param out the ostream parameter that will ne used to print
 * @param vec the specific Vector that will be printed
 * @return
 */
template<typename U>
ostream &operator<<(ostream & out , Vector<U> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        out<<vec[i] <<" ";
    }
    out<<"\n";
    return out ;
}

/**
 * function push back that add element to the end of the Vector
 *
 * @tparam T template parameter
 * @param value the value that will be added
 */
template<typename T>
void Vector<T>::push_back(T value) {
    if(size()  >= MaxCapacity){
        resize();
    }
    data[sze++] = value ;
}

/**
 * function that remove last element
 * by decrease the size of the element
 * @tparam T template parameter
 */
template<typename T>
void Vector<T>::pop_back() {
    if (size() == 0) throw std::out_of_range("Under flow");
    else
        --sze;
}


/**
 * function front that return the last element in the Vector
 * @tparam T template parameter
 * @return the value of the last element
 */
template<typename T>
T Vector<T>::back() {
    return *(data + sze);
}

/**
 * function front that return the first element in the Vector
 * @tparam T template parameter
 * @return the value of the first element
 */
template<typename T>
T Vector<T>::front() {
    return *data;
}


/**
 * function capacity that check if capacity of my vector
 * check if i can put more values
 * @tparam T template parameter
 * @return int MaxCapacity the value of capacity (how many)
 */
template<typename T>
int Vector<T>::capacity(){
    return MaxCapacity;
}

/**
 * function insert some value in specific position
 * looping to get this position and put the value , and shift the rest values to the right
 * @tparam T template parameter
 * @param position the specific position that value will be in
 * @param value the value we add to the Vector
 */
template<typename T>
void Vector<T>::insert(Iterator position, T value) {
    if(position> end() || position < begin()) throw error("invalid range");
    if(position == this->end()){
        this->push_back(value);
    }
    else {
        T *new_data;
        if (size() >= MaxCapacity) {
            resize();
        }
        else
            new_data = new T[MaxCapacity];

        for (int i = 0 , j = 0; i < size(); ++i) {
            if(&data[i] == position){
                new_data[j++] = value ;
                new_data[j] = data[i];
                j++;
                continue;
            }
            new_data[j] = data[i];
            j++;
        }
        delete [] data;
        data = nullptr ;
        data = new_data;
        sze++;
    }
}

/**
 * function erase to remove specific position from my Vector
 * looping to get this position and shift the rest of Vector to the left
 * @tparam T template parameter
 * @param position the specific position we need to move
 */
template<typename T>
void Vector<T>::erase(Iterator position){

    if (position > end() || position < begin()) throw error("out of range");
    bool found = false;
    for (int i = 0; i < size(); ++i) {
        if (&data[i] == position) {
            found = true;
        }
        if (found) {
            data[i] = data[i + 1];
        } else
            continue;
    }
    sze--;
}

/**
 * function erase to remove range of values
 * from first iterator to the second iterator
 * @tparam T template parameter
 * @param _1st_position start of the range
 * @param _2nd_position end of the range
 */
template<typename T>
void Vector<T>::erase(Iterator _1st_position , Iterator _2nd_position){
    bool begining  = false , ending = false;
    if(_1st_position >  _2nd_position) throw error("invalid range");
    if (_1st_position > end() || _2nd_position < begin()) throw error("out of range");
    for (int i = 0 , j = 0; i < size(); ++i) {
        if(&data[i] == _1st_position){
            begining = true;
            j = i ;
        }
        if(&data[i] == _2nd_position){
            ending = true ;
        }
        if(begining && ending){
            data[j] = data[i];
            j++;
        }
    }
    sze -= (_2nd_position - _1st_position) ;
}

/**
 * function clear to format my Vector
 * remove elements and change capacity and sze
 * @tparam T template parameter
 */
template<typename T>
void Vector<T>::clear() {
    delete [] data;
    data = nullptr;
    data = new T[1];
    sze = 0;
    MaxCapacity = 1;
}

/**
 * function size to return current size (or elements) in Vector
 * @tparam T template parameter
 * @return sze : the number of elements in Vector
 */
template<typename T>
int Vector<T>::size() {
    return sze;
}

/**
 * function empty to check if there is no elements in Vector
 * @tparam T template parameter
 * @return bool : if size = 0 then there is no elements
 */
template<typename T>
bool Vector<T>::empty() {
    return size() == 0;
}

/**
 * function resize that increase capacity (by *2)
 * @tparam T template parameter
 */
template<typename T>
void  Vector<T>::resize() {
    T* new_data;
    new_data = new T[MaxCapacity*2];
    for (int i = 0; i < sze; ++i) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = nullptr;
    data = new_data;
    MaxCapacity *= 2;
}

/**
 * function resize that make new Vector with new_size
 * @tparam T template parameter
 * @param new_size the new size for the Vector
 */
template<typename T>
void  Vector<T>::resize(int new_size){
    T* new_data;
    if (new_size <= 0) throw error("Invalid size");
    new_data = new T[new_size];
    for (int i = 0; i < min(new_size, size()); ++i) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = nullptr;
    data = new_data;
    MaxCapacity = new_size;
    sze = new_size;

}

/**
 * destructor that delete Vector
 * @tparam T template parameter
 */
template<typename T>
Vector<T>::~Vector() {
    delete [] data;
    data = nullptr;
}


