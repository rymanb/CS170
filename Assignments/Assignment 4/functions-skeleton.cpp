#include <iostream>
#include "functions.h"

namespace CS170 {
  template <typename T>
    void display( T const *begin, T const *end )
    {
      if( begin != end ) std::cout << *begin++;
      while( begin<end ) {
        std::cout << ", " << *begin;
        ++begin;
      }
      std::cout << std::endl;
    }

  template <typename T>
    void swap( T *left, T *right )
    {
      T temp( *right );
      ( *right ) = ( *left );
      ( *left ) = temp;
    }

  template <typename T>
    T* min_element( T *begin, T *end )
    {
      T* min=begin;
      while( begin!=end ) {
        if( *begin<*min ) min=begin;
        ++begin;
      }
      return min;
    }

  template <typename T>
    T const* min_element( T const *begin, T const *end )
    {
      T const* min=begin;
      while( begin!=end ) {
        if( *begin<*min ) min=begin;
        ++begin;
      }
      return min;
    }
}
