#include <iostream>
#include <array>
#include <cstring>

using namespace std;

template<typename T, unsigned int _size>class Array
{
private:
    T* m_buffer;
    unsigned int m_size;
public:
    Array();
    Array(const Array& val);
    ~Array();
    T& operator[] (unsigned int index);
    unsigned int size();
    T& front();
    T& back();
    T* data();
    bool empty();
    void swap(Array& _other);
    void fill(const T& val);
    T& at(unsigned int index);
    typedef T* Iterator;
    Iterator begin();
    Iterator end();
};

template<typename T, unsigned int _size> Array<T, _size>::Array()
    : m_buffer{new T[m_size]}
    , m_size{_size}
{

}

template<typename T, unsigned int _size> Array<T, _size>::Array(const Array& val)
    : m_buffer{val.m_buffer}
    , m_size{val.m_size}
{

}

template<typename T, unsigned int _size> Array<T, _size>::~Array()
{
    delete []m_buffer;
}

template<typename T, unsigned int _size> T& Array<T, _size>::operator [](unsigned int index)
{
    return m_buffer[index];
}

template<typename T, unsigned int _size> unsigned int Array<T, _size>::size()
{
    return m_size;
}

template<typename T, unsigned int _size> T& Array<T, _size>::front()
{
    return m_buffer[0];
}

template<typename T, unsigned int _size> T& Array<T, _size>::back()
{
    return m_buffer[m_size - 1];
}

template<typename T, unsigned int _size> T* Array<T, _size>::data()
{
    return m_buffer;
}

template<typename T, unsigned int _size> bool Array<T, _size>::empty()
{
    return m_size == 0;
}

template<typename T, unsigned int _size> void Array<T, _size>::swap(Array& _other)
{
    T temp;
    if(m_size == _other.m_size)
    {
        cout << "OK" << endl;
        for(unsigned int i = 0; i < m_size; i++)
        {
            temp = m_buffer[i];
            m_buffer[i] = _other.m_buffer[i];
            _other.m_buffer[i] = temp;
        }
    }
    else
        std::cout << "Size second array! " << std::endl;
}

template<typename T, unsigned int _size> T& Array<T, _size>::at(unsigned int index)
{
    return m_buffer[index];
}

template<typename T, unsigned int _size> typename Array<T, _size>::Iterator Array<T, _size>::begin()
{
    return m_buffer;
}

template<typename T, unsigned int _size> typename Array<T, _size>::Iterator Array<T, _size>::end()
{
    return m_buffer + size();
}

template<typename T, unsigned int _size> void Array<T, _size>::fill(const T& val)
{
    for(unsigned int i = 0; i < m_size; i++)
        m_buffer[i] = val;
}

int main()
{
    Array<int, 5>arr;
    for(unsigned int i = 0; i < arr.size(); i++)
    {
        arr[i] = i + 1;
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
