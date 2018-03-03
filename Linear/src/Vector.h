#ifndef AISDI_LINEAR_VECTOR_H
#define AISDI_LINEAR_VECTOR_H

#include <cstddef>
#include <initializer_list>
#include <stdexcept>


namespace aisdi
{

template <typename Type>
class Vector
{
public:
    using difference_type = std::ptrdiff_t;
    using size_type = std::size_t;
    using value_type = Type;
    using pointer = Type*;
    using reference = Type&;
    using const_pointer = const Type*;
    using const_reference = const Type&;

    class ConstIterator;
    class Iterator;
    using iterator = Iterator;
    using const_iterator = ConstIterator;

private:
    size_type length;
    size_type capacity;
    Type *head;
    Type *tail;

    void left_shift(const const_iterator& position_to, const const_iterator& position_from)
    {
        iterator to = iterator(position_to.pointee, *this);
        const_iterator from = position_from;

        for(; from != cend(); ++to, ++from)
            *to = *from;

        tail = to.pointee;
    }

    void right_shift(const const_iterator& position)
    {
        if(isEmpty())
        {
            ++tail;
            return;
        }

        iterator it = end() - 1;

        ++tail;

        for(; it != position; --it)
            *(it+1) = *it;

        *(it+1) = *it;
    }

    Type* resize()
    {
        if(length + 1 <= capacity)
            return NULL;

        capacity = 2 * length;

        return new Type[capacity];
    }

public:

    Vector(size_type cap = 16):length(0), capacity(cap)
    {
        tail = head = new Type[cap];
    }

    Vector(std::initializer_list<Type> l):Vector(l.size())
    {
        typename std::initializer_list<Type>::iterator it;

        for(it = l.begin(); it != l.end(); ++it)
            append(*it);
    }

    Vector(const Vector& other):Vector(other.capacity)
    {
        for(const_iterator it = other.cbegin(); it != other.cend(); ++it)
            append(*it);
    }

    Vector(Vector&& other)
    {
        length = other.length;
        capacity = other.capacity;

        head = other.head;
        tail = other.tail;

        other.length = 0;
        other.capacity = 0;
        other.tail = other.head = nullptr;
    }

    ~Vector()
    {
        tail = nullptr;

        length = 0;
        capacity = 0;

        if(head) delete[] head;

        head = nullptr;
    }

    Vector& operator=(const Vector& other)
    {
        if(head != other.head && tail != other.tail)
        {
            erase(cbegin(), cend());

            for(const_iterator it = other.cbegin(); it != other.cend(); ++it)
                append(*it);
        }


        return *this;
    }

    Vector& operator=(Vector&& other)
    {
        Type *del = head;

        length = other.length;
        capacity = other.capacity;

        head = other.head;
        tail = other.tail;

        other.length = 0;
        other.capacity = 0;
        other.tail = other.head = nullptr;

        delete[] del;

        return *this;
    }

    bool isEmpty() const
    {
        return !length;
    }

    size_type getSize() const
    {
        return length;
    }

    void append(const Type& item)
    {
        Type *temp;

        if((temp = resize()))
        {
            Type *del = head;

            Type  *i;
            const_iterator it = cbegin();

            for(i = temp; it != cend(); ++i, ++it)
                *i = *it;

            head = temp;
            tail = i;

            delete[] del;
        }
	++length;
        *(tail++) = item;
    }

    void prepend(const Type& item)
    {
        Type *temp;

        if((temp = resize()))
        {
            Type *del = head;

            *temp = item;

            Type *i;
            const_iterator it = cbegin();

            for(i = temp + 1; it != cend(); ++i, ++it)
                *i = *it;

            head = temp;
            tail = i;

            delete[] del;
        }
        else
        {
            right_shift(cbegin());

            *head = item;
        }

        ++length;
    }

    void insert(const const_iterator& insertPosition, const Type& item)
    {
        if(insertPosition == cend())
        {
            append(item);
            return;
        }

        Type *temp;

        if((temp = resize()))
        {
            Type *del = head;

            Type *i;
            const_iterator it = cbegin();

            for(i = temp; it != insertPosition; ++i, ++it)
                *i = *it;

            *i = item;

            for(++i; it != cend(); ++i, ++it)
                *i = *it;

            head = temp;
            tail = i;

            delete[] del;
        }

        else
        {
            right_shift(insertPosition);

            *( (iterator)insertPosition ) = item;
        }

        ++length;
    }

    Type popFirst()
    {
        if(isEmpty())
            throw std::logic_error("Object cannot be popped.");

        Type obj = *head;

        left_shift(cbegin(), cbegin()+1);

        --length;

        return obj;
    }

    Type popLast()
    {
        if(isEmpty())
            throw std::logic_error("Object cannot be popped.");

        --length;

        return *(--tail);
    }

    void erase(const const_iterator& position)
    {
        if(isEmpty())
            throw std::out_of_range("Erasing in an empty vector.");

        if(position == cend())
            throw std::out_of_range("Erasing at end iterator");

        if(position == cend()-1)
        {
            popLast();
            return;
        }

        left_shift(position, position+1);

        --length;
    }

    void erase(const const_iterator& firstIncluded, const const_iterator& lastExcluded)
    {
        if(isEmpty())
            throw std::out_of_range("Erasing in an empty vector.");

        if(firstIncluded == lastExcluded)
            return;

        length -= lastExcluded.pointee - firstIncluded.pointee;

        left_shift(firstIncluded, lastExcluded);
    }

    iterator begin()
    {
        return iterator(head, *this);
    }

    iterator end()
    {
        return iterator(tail, *this);
    }

    const_iterator cbegin() const
    {
        return const_iterator(head, *this);
    }

    const_iterator cend() const
    {
        return const_iterator(tail, *this);
    }

    const_iterator begin() const
    {
        return cbegin();
    }

    const_iterator end() const
    {
        return cend();
    }
};

template <typename Type> //done
class Vector<Type>::ConstIterator
{
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = typename Vector::value_type;
    using difference_type = typename Vector::difference_type;
    using pointer = typename Vector::const_pointer;
    using reference = typename Vector::const_reference;

private:
    Type *pointee;
    const Vector<Type>& vec;

    friend void aisdi::Vector<Type>::erase(const ConstIterator&, const ConstIterator&);
    friend void aisdi::Vector<Type>::left_shift(const ConstIterator&, const ConstIterator&);

public:

    explicit ConstIterator(Type *pnt, const Vector<Type>& vtr): pointee(pnt), vec(vtr)
    {}

    reference operator*() const
    {
        if(pointee == vec.tail)
            throw std::out_of_range("Out of range.");

        return *pointee;
    }

    ConstIterator& operator++()
    {
        if(pointee == vec.tail)
            throw std::out_of_range("Out of range.");

        ++pointee;

        return *this;
    }

    ConstIterator operator++(int)
    {
        auto result = *this;
        operator++();
        return result;
    }

    ConstIterator& operator--()
    {
        if(pointee == vec.head)
            throw std::out_of_range("Out of range.");

        --pointee;

        return *this;
    }

    ConstIterator operator--(int)
    {
        auto result = *this;
        operator--();
        return result;
    }

    ConstIterator operator+(difference_type d) const
    {
        if(pointee + d > vec.tail)
            throw std::out_of_range("Out of range.");

        return ConstIterator(pointee + d, vec);
    }

    ConstIterator operator-(difference_type d) const
    {
        if(pointee - d < vec.head)
            throw std::out_of_range("Out of range.");

        return ConstIterator(pointee - d, vec);
    }

    bool operator==(const ConstIterator& other) const
    {
        return this->pointee == other.pointee;
    }

    bool operator!=(const ConstIterator& other) const
    {
        return this->pointee != other.pointee;
    }
};

template <typename Type>
class Vector<Type>::Iterator : public Vector<Type>::ConstIterator
{
public:
    using pointer = typename Vector::pointer;
    using reference = typename Vector::reference;

    explicit Iterator(Type *pnt, const Vector<Type>& vtr): ConstIterator(pnt, vtr)
    {}

    Iterator(const ConstIterator& other)
        : ConstIterator(other)
    {}

    Iterator& operator++()
    {
        ConstIterator::operator++();
        return *this;
    }

    Iterator operator++(int)
    {
        auto result = *this;
        ConstIterator::operator++();
        return result;
    }

    Iterator& operator--()
    {
        ConstIterator::operator--();
        return *this;
    }

    Iterator operator--(int)
    {
        auto result = *this;
        ConstIterator::operator--();
        return result;
    }

    Iterator operator+(difference_type d) const
    {
        return ConstIterator::operator+(d);
    }

    Iterator operator-(difference_type d) const
    {
        return ConstIterator::operator-(d);
    }

    reference operator*() const
    {
        return const_cast<reference>(ConstIterator::operator*());
    }
};

}

#endif // AISDI_LINEAR_VECTOR_H
