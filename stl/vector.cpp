#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

template <class T>
class Vector
{
public:

   typedef T * iterator;

   Vector();
   Vector(unsigned int size);
   Vector(unsigned int size, const T & initial);
   Vector(const Vector<T> & v);      
   ~Vector();

   unsigned int capacity() const;
   unsigned int size() const;
   bool empty() const;
   iterator begin();
   iterator end();
   T & front();
   T & back();
   void push_back(const T & value); 
   void pop_back();  

   void reserve(unsigned int capacity);   
   void resize(unsigned int size);   

   T & operator[](unsigned int index);  
   Vector<T> & operator=(const Vector<T> &);

private:
   unsigned int my_size;
   unsigned int my_capacity;
   T * buffer;
};

// Your code goes here ...
template<class T>
Vector<T>::Vector()
{
    my_capacity = 0;
    my_size = 0;
    buffer = 0;
}

template<class T>
Vector<T>::Vector(const Vector<T> & v)
{
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T[my_size];  
    for (int i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];  
}

template<class T>
Vector<T>::Vector(unsigned int size)
{
    my_capacity = size;
    my_size = size;
    buffer = new T[size];
}

template<class T>
Vector<T>::Vector(unsigned int size, const T & initial)
{
    my_size-size;
    my_capacity = size;
    buffer = new T [size];
    for (int i = 0; i < size; i++)
        buffer[i] = initial;
        T();
}

template<class T>
Vector<T> & Vector<T>::operator = (const Vector<T> & v)
{
    delete[ ] buffer;
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T [my_size];
    for (int i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];
    return *this;
}

template<class T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return buffer;
}

template<class T>
typename Vector<T>::iterator Vector<T>::end()
{
    return buffer + size();
}

template<class T>
T& Vector<T>::Vector<T>::front()
{
    return buffer[0];
}

template<class T>
T& Vector<T>::Vector<T>::back()
{
    return buffer[size - 1];
}

template<class T>
void Vector<T>::push_back(const T & v)
{
    if (my_size >= my_capacity)
    reserve(my_capacity +5);
    buffer [my_size++] = v;
}

template<class T>
void Vector<T>::pop_back()
{
    my_size--;
}

template<class T>
void Vector<T>::reserve(unsigned int capacity)
{
    if(buffer == 0)
    {
        my_size = 0;
        my_capacity = 0;
    }    
    T * buffer = new T [capacity];
    assert(buffer);
    copy (buffer, buffer + my_size, buffer);
    my_capacity = capacity;
    delete[] buffer;
    buffer = buffer;

}

template<class T>
unsigned int Vector<T>::size()const//
{
    return my_size;
}

template<class T>
void Vector<T>::resize(unsigned int size)
{
    reserve(size);
    size = size;
}

template<class T>
T& Vector<T>::operator[](unsigned int index)
{
    return buffer[index];
}  

template<class T>
unsigned int Vector<T>::capacity()const
{
    return my_capacity;
}

template<class T>
Vector<T>::~Vector()
{
    delete[]buffer;
}


int main()
{  

   Vector<int> v;

   v.reserve(2);
   assert(v.capacity() == 2);

   Vector<string> v1(2);
   assert(v1.capacity() == 2);
   assert(v1.size() == 2);
   assert(v1[0] == "");
   assert(v1[1] == "");

   v1[0] = "hi";
   assert(v1[0] == "hi");

   Vector<int> v2(2, 7);
   assert(v2[1] == 7);

   Vector<int> v10(v2);
   assert(v10[1] == 7);

   Vector<string> v3(2, "hello");
   assert(v3.size() == 2);
   assert(v3.capacity() == 2);
   assert(v3[0] == "hello");
   assert(v3[1] == "hello");

   v3.resize(1);
   assert(v3.size() == 1);
   assert(v3[0] == "hello");

   Vector<string> v4 = v3;
   assert(v4.size() == 1);
   assert(v4[0] == v3[0]);
   v3[0] = "test";
   assert(v4[0] != v3[0]);  
   assert(v4[0] == "hello");

   v3.pop_back();
   assert(v3.size() == 0);

   Vector<int> v5(7, 9);
   Vector<int>::iterator it = v5.begin();
   while (it != v5.end())
   {
      assert(*it == 9);
      ++it;
   }

   Vector<int> v6;
   v6.push_back(100);
   assert(v6.size() == 1);
   assert(v6[0] == 100);
   v6.push_back(101);
   assert(v6.size() == 2);
   assert(v6[0] == 100);
   v6.push_back(101);

   cout << "SUCCESS\n";
}