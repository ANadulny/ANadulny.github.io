#ifndef VECTOR_H
#define VECTOR_H
#include <stdlib.h>
#include <iostream>

template <class T=double>
class vector
{
private:
    T * myVector;            // zbiór
    int length;         // rozmiar zbioru
    int capacity;     //  2*length
    void getAllocate( int newSize );

public:

    int GetLength() const { return length; }
    int GetMaxLength() const { return capacity; }
    T& GetElement(int a) const {return myVector[a];}

	vector();        // konstruktor tworzacy zbiór pusty
    vector( int size, const T& value);         // kostrutkor wypelniajacy
    vector(const vector & cont);           // konstruktor kopiujacy
     ~vector ()  {   clear(); }
    void clear();
    void push_back(const T & x);
    void push_back( int Size, const T & x);
    void pop_back(int numberToRemove = 1);
    void resize( int newSize, const T & value = 0);
    void show();
    bool is_empty() const { return length==0; }
    const T & operator [] ( int index) const;
    template <class G>
    vector<T> & operator = (const vector <G> & cont);
    vector<T> & operator = (const vector <T> & cont);

    vector<T> & operator += (const vector <T> & cont);
    template <class G>
    vector<T> & operator += (const vector <G> & cont);

};

template<class T>
    vector<T> ::vector()
    {
        length = 0; myVector = 0; capacity=0;
    }


template<class T>
    vector<T> ::vector( int size, const T& value)
    {
        length = size;
        capacity = 2*size;
        myVector = new T[2*size];
        for( int i = 0; i < length; i++)
        {
            myVector[i] = value;
        }
    }



template<class T>
    vector<T> ::vector(const vector & cont)
    {
        length = cont.GetLength();
        capacity=2*cont.GetLength();
        myVector = new T [2*cont.GetLength()];
        for(int k = 0; k < cont.GetLength(); k++)
        {
            myVector[k] = cont.GetElement(k);
        }
    }


template<class T>
    void vector<T> ::clear()
    {
        delete [] myVector;
        myVector = 0;
        length = 0;
        capacity = 0;
    }


template<class T>
    void vector<T> ::push_back(const T & x)
    {
        if(length == capacity && capacity != 0)
            getAllocate(capacity);
        else if(capacity == 0)
            {
                getAllocate(5);
                resize(0,0);
            }

        myVector[length++] = x;
    }


template<class T>
    void vector<T> ::push_back( int Size, const T & x)
    {
        if(capacity == 0)
            {
                getAllocate(5);
                resize(0,0);
            }

        for(int i=0; i<Size; i++)
        {
            if(length == capacity)
                getAllocate(capacity);

            myVector[length++] = x;
        }
    }


template<class T>
    void vector<T> ::pop_back(int numberToRemove )
    {

        for(int i = length ; i > 0 && numberToRemove > 0; i--, numberToRemove--)
        {
            myVector[i]=0;
            length--;
        }
    }


template<class T>
    void vector<T> ::resize( int newSize, const T & value)
    {
        if( length == newSize || newSize<0) return;

        int numToCopy = newSize < length ? newSize : length;
        if( numToCopy == newSize)
        {
            pop_back(length-newSize);
        }

        else if( numToCopy == length && newSize < capacity)
        {
            for( int k=length; k < newSize; k++)
            {
                myVector[k]=value;
            }
            length = newSize;
        }

        else
        {
            getAllocate(newSize);
            for( int k=numToCopy; k < newSize; k++)
            {
                myVector[k] = value;
            }
        }
    }


template<class T>
    void vector<T> ::show()
    {
        for( int i = 0; i < length; i++)
        {
            std::cout<<myVector[i]<<" ";
        }
    }


template<class T>
    void vector<T> ::getAllocate( int newSize )
    {
        T * newvector = new T[2*newSize];
        for( int k = 0; k < length && k < newSize; k++)
        {
            newvector[k] = myVector[k];
        }

        delete [] myVector;
        length = newSize;
        myVector = newvector;
        capacity = 2*newSize;
    }


template<class T>
    const T & vector<T>::operator [] ( int index) const
    {
        return myVector[index];
    }

template <class T>
   template < class G>
         vector<T>& vector<T>::operator=(const vector<G>& cont)

         {

            delete [] myVector;
            length = cont.GetLength();
            capacity=2*cont.GetMaxLength();
            myVector = new T [2*(cont.GetLength() )];
            for(int k = 0; k < cont.GetLength(); k++)
            {
                myVector[k] = static_cast<T>(cont.GetElement(k));
            }

            return *this;

         }


   template < class T>
         vector<T>& vector<T>::operator=(const vector<T>& cont)

         {

            delete [] myVector;
            length = cont.GetLength();
            capacity=2*cont.GetMaxLength();
            myVector = new T [2*(cont.GetLength() )];
            for(int k = 0; k < cont.GetLength(); k++)
            {
                myVector[k] = cont.GetElement(k);
            }

            return *this;

         }


   template < class T>
         vector<T>& vector<T>::operator+=(const vector<T>& cont)

         {
            if(capacity == 0)
            {
                getAllocate(5);
                resize(0,0);
            }

            for(int k = 0; k < cont.GetLength(); k++)
            {
                if(GetLength() == GetMaxLength() ) getAllocate(GetMaxLength() );
                myVector[GetLength()] = cont.GetElement(k);
                length++;
            }

            return *this;

         }


template <class T>
   template < class G>
         vector<T>& vector<T>::operator+=(const vector<G>& cont)

         {
            if(capacity == 0)
            {
                getAllocate(5);
                resize(0,0);
            }

            for(int k = 0; k < cont.GetLength(); k++)
            {
                if(GetLength() == GetMaxLength() ) getAllocate(GetMaxLength() );
                myVector[GetLength()] = static_cast<T>(cont.GetElement(k));
                length++;
            }

            return *this;

         }
#endif // VECTOR_H
