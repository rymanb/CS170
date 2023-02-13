#include <iostream>             // cout
#include <cstdlib>              // abort
#include "Vector.h"

namespace CS170 {

  Vector::Vector( void ) 
  {
    array_ =  NULL;
    size_ =  0;
    capacity_ =  0;
    allocs_ =  0;
  } 

  Vector::Vector(Vector const & rhs)
  {
    size_ = rhs.size_;
    capacity_ = rhs.size_;
    allocs_ = 0;
    if (rhs.array_)
    {
      array_ = new int[size_];
      ++allocs_;
      for (unsigned i = 0; i < size_; ++i)
      {
        array_[i] = rhs.array_[i];
      }
    }
    else
    {
      array_ = NULL;
    }
  }

  Vector::Vector( int const array[], unsigned size )
  {
    array_ = new int[size];
    allocs_ = 1;
    capacity_ = 0;
    size_ = size;
    for (unsigned i = 0; i < size; ++i)
    {
      array_[i] = array[i];
      if(array_[i])
      {
        ++capacity_;
      }
    }
  }

  Vector::~Vector()
  {
    delete [] array_;
  }

  bool Vector::empty( void ) const 
  {
    return size_ == 0;
  } 

  void Vector::push_back( int value )
  {
    if (capacity_ == 0 || size_ >= capacity_)
    {
      this->grow();
    }
    
    *(array_ + size_) = value;

    ++size_;
  }

  void Vector::pop_back()
  {
    if (size_ > 0)
    {
      --size_;
    }
  }

  Vector & Vector::operator+=( const Vector & rhs )
  {
    unsigned origSize = rhs.size_;
    for (unsigned i = 0; i < origSize; ++i)
    {
      this->push_back(rhs.array_[i]);
    }

    return *this;
  }

  Vector Vector::operator+( const Vector & rhs ) const
  {
    Vector cpy(*this);
    cpy += rhs;
    return cpy;
  }

  Vector & Vector::operator=( Vector const & rhs )
  { 
    if (rhs.size_ > capacity_)
    {
      delete [] array_;
      array_ = new int[rhs.size_];
      ++allocs_;
      capacity_ = rhs.size_;
    }

    for (unsigned i = 0; i < rhs.size_; ++i)
    {
      array_[i] = rhs.array_[i];
    }

    size_ = rhs.size_;

    return *this;
  }

  void Vector::push_front( int value )
  {
    if (capacity_ == 0 || size_ >= capacity_)
    {
      this->grow();
    }

    for (int i = size_; i > 0; i--)
    {
      *(array_ + i) = *(array_ + i - 1);
    }

    *(array_) = value;
    ++size_;
  }

  void Vector::pop_front()
  {
    if (size_ > 0)
    {
      for (unsigned i = 1; i < size_; ++i)
      {
        array_[i - 1] = array_[i];
      }

      --size_;
    }
  }

  void Vector::remove( int value )
  {
    for (unsigned i = 0; i < size_; ++i)
    {
      if (array_[i] == value)
      {
        for (unsigned j = i; j < size_ - 1; ++j)
        {
          array_[j] = array_[j + 1];
        }

        --size_;
        break;
      }
    }
  }

  void Vector::insert( int value, unsigned position )
  {
    check_bounds(position);

    if (size_ == 0 || size_ >= capacity_)
    {
      this->grow();
    }

    for (unsigned i = size_; i > position; i--)
    {
      array_[i] = array_[i - 1];
    }

    ++size_;
    array_[position] = value;

  }

  int Vector::operator[]( unsigned index ) const
  {
    check_bounds(index);

    return *(array_ + index);

  }

  int &Vector::operator[]( unsigned index )
  {
    check_bounds(index);

    return *(array_ + index);
  }
  
  void Vector::clear( void )
  {
    delete [] array_;
    array_ = new int[capacity_];
    size_ = 0;
    capacity_ = 0;
  }


  unsigned Vector::size( void ) const 
  {
    return size_;
  } 

  unsigned Vector::capacity( void ) const 
  {
    return capacity_;
  } 

  unsigned Vector::allocations( void ) const 
  {
    return allocs_;
  }
  // /////////////////////////////////////////////////////////////////////////////// /////////////////////////////////////////////////////////////////////////////// private // /////////////////////////////////////////////////////////////////////////////// /////////////////////////////////////////////////////////////////////////////
  void Vector::check_bounds( unsigned index ) const 
  {
    // Don't have to check for < 0 because index is unsigned
    if ( index >= size_ ) {
      std::cout << "Attempting to access index " << index << ".";
      std::cout << " The size of the array is " << size_ << ". Aborting...\n";
      std::abort(  );
    }
  } 

  void Vector::grow(void)
  {
    // Double the capacity ( or set to 1 if it was zero)
    capacity_ = (capacity_) ? capacity_ * 2 : 1;

    // Rest of the code here...
    int* tempArray = new int[capacity_];

    if (capacity_ != 1)
    {
      for (unsigned int i = 0; i < capacity_ / 2; i++)
      {
        *(tempArray + i) = *(array_ + i);
      }
    }
    
    delete [] array_;

    array_ = tempArray;
    ++allocs_;
  }

}                               // namespace CS170
