#pragma once
template<typename elemtype>
class Vector {
public:
    typedef elemtype* iterator;
private:
    elemtype* _data;
    size_t _size;
    size_t _capacity;

public:
    Vector() :_data(NULL), _size(0), _capacity(0) {}
    ~Vector() 
    {
        delete[] _data;
        _data = NULL;
        _size = 0;
        _capacity = 0;
    }
    Vector(const Vector& vec) 
    {
        _size = vec._size;
        _capacity = vec._capacity;
        _data = new elemtype[_capacity];
        for (int i = 0; i < _size; ++i)
        {
            _data[i] = vec._data[i];
        }
    }
    Vector& operator=(const Vector& vec) 
    {
        if (this == &vec) return *this;
        elemtype* temp = new elemtype[vec._capacity];
        for (int i = 0; i < vec._size; ++i) 
        {
            temp[i] = vec._data[i];
        }
        delete[] _data;
        _data = temp;
        _size = vec._size;
        _capacity = vec._capacity;
        return *this;
    }
    void push_back(elemtype val) 
    {
        if (0 == _capacity) 
        {
            _capacity = 1;
            _data = new elemtype[1];
        }
        else if (_size + 1 > _capacity) 
        {
            _capacity *= 2;
            elemtype* temp = new elemtype[_capacity];
            for (int i = 0; i < _size; ++i) 
            {
                temp[i] = _data[i];
            }
            delete[] _data;
            _data = temp;
        }
        _data[_size] = val;
        ++_size;
    }
    void pop_back()
    { 
        --_size; 
    }
    size_t size()const 
    {
        return _size; 
    }
    size_t capacity()const 
    { 
        return _capacity;
    }
    bool empty() 
    {
        return _size == 0; 
    }
    elemtype& operator[](size_t index)
    {
        return _data[index];
    }
    bool operator==(const Vector& vec)const
    {
        if (_size != vec._size) return false;
        for (int i = 0; i < _size; ++i) 
        {
            if (_data[i] != vec._data[i]) return false;
        }
        return true;
    }
    elemtype front()const
    {
        return _data[0];
    }
    elemtype back() const 
    {
        return _data[_size - 1];
    }

    void insert(iterator it, elemtype val)
    {
        int index = it - _data;
        if (0 == _capacity)
        {
            _capacity = 1;
            _data = new elemtype[1];
            _data[0] = val;
        }
        else if (_size + 1 > _capacity)
        {
            _capacity *= 2;
            elemtype* temp = new elemtype[_capacity];
            for (int i = 0; i < index; ++i) 
            {
                temp[i] = _data[i];
            }
            temp[index] = val;
            for (int i = index; i < _size; ++i)
            {
                temp[i + 1] = _data[i];
            }
            delete[] _data;
            _data = temp;
        }
        else 
        {
            for (int i = _size - 1; i >= index; --i) 
            {
                _data[i + 1] = _data[i];
            }
            _data[index] = val;
        }
        ++_size;

    }
    void erase(iterator it) 
    {
        size_t index = it - _data;
        for (int i = index; i < _size - 1; ++i)
        {
            _data[i] = _data[i + 1];
        }
        --_size;
    }

    iterator begin() 
    {
        return  _data; 
    }
    iterator end() 
    { 
        return _data + _size;
    }
};

