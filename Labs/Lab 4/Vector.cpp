#include <iostream>  // cout
#include <cstdlib>   // abort
#include "Vector.h"

namespace CS170
{

  Vector::Vector(void) : array_(0), size_(0), capacity_(0), allocs_(0)
  {
  }

  Vector::~Vector()
  {
    delete [] array_;
  }

  void Vector::push_back( int value )
  {
    if (size_ >= capacity_)
    {
      this->grow();
    }
    
    *(array_ + size_) = value;

    ++size_;
  }

  void Vector::push_front( int value )
  {
    if (size_ >= capacity_)
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

  bool Vector::empty(void) const
  {
    return size_ == 0;
  }

  unsigned Vector::size(void) const
  {
    return size_;
  }

  unsigned Vector::capacity(void) const
  {
    return capacity_;
  }

  unsigned Vector::allocations(void) const
  {
    return allocs_;
  }

  ///////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////
  // private 
  ///////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////

  void Vector::check_bounds(unsigned index) const
  {
    // Don't have to check for < 0 because index is unsigned
    if (index >= size_)
    {
      std::cout << "Attempting to access index " << index << ".";
      std::cout << " The size of the array is " << size_ << ". Aborting...\n";
      std::abort();
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

} // namespace CS170
