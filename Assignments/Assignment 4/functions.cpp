/* File header
 * ===========
 * file:       functions.cpp
 * author:     Ryman Barnett
 * email:      ryman.b@digipen.edu
 * course:     CS170
 * section:    B
 * assignment: 5
 * date:       03/21/2022
 *
 * file content:
 * this is a source file for function templates requires functions.h
 */

#include <iostream>
#include "functions.h"

namespace CS170 {

    /*
    * display(Template):
    * input:   begin(pointer to range start), end(pointer to range end)
    * return:  None
    *
    * logic: go through range and output elements to console
    */
  template <typename T>
    void display( T const *begin, T const *end )
    {
      //empty array check
      if (begin != end) 
      {
        std::cout << *begin++; // print first index
      }
      // go thorough array
      while (begin < end) 
      {
        // print each index
        std::cout << ", " << *begin;
        ++begin;
      }

      std::cout << std::endl;
    }

    /*
    * swap(Template):
    * input:   left(pointer to first val), end(pointer to second val)
    * return:  None
    *
    * logic: swaps the values at the pointers
    */
  template <typename T>
    void swap( T *left, T *right )
    {
      T temp(*right);
      // swap right and left values
      (*right) = (*left);
      (*left) = temp;
    }

    /*
    * min_element(Template):
    * input:   begin(pointer to range start), end(pointer to range end)
    * return:  pointer to smallest element (non const)
    *
    * logic: go through range and find smallest element
    */
  template <typename T>
    T* min_element( T *begin, T *end )
    {
      T* min = begin; // default min first index
      // check each other index
      while (begin != end) 
      {
        if (*begin < *min) 
        {
          min = begin; // if new val is less, set new min
        }   

        ++begin;
      }

      return min;
    }

    /*
    * const min_element(Template):
    * input:   begin(pointer to range start), end(pointer to range end)
    * return:  pointer to smallest element (const)
    *
    * logic: go through range and find smallest element
    */
  template <typename T>
    T const* min_element( T const *begin, T const *end )
    {
      T const* min = begin;  // default min first index
      // check each other index
      while (begin != end) 
      {
        if (*begin < *min) 
        {
          min = begin; // if new val is less, set new min
        }

        ++begin;
      }

      return min;
    }

    /*
    * max_element(Template):
    * input:   begin(pointer to range start), end(pointer to range end)
    * return:  pointer to largest element (non const)
    *
    * logic: go through range and find largest element
    */
  template <typename T>
    T* max_element( T* begin, T* end )
    {
      T* max = begin; // default max first index
      // check each other index
      while (begin != end) 
      {
        if (*begin > *max) 
        {
          max = begin; // if new val is less, set new min
        }

        ++begin;
      }

      return max;
    }

    /*
    * max_element(Template):
    * input:   begin(pointer to range start), end(pointer to range end)
    * return:  pointer to largest element (const)
    *
    * logic: go through range and find largest element
    */
  template <typename T>
    T const* max_element( T const *begin, T const *end )
    {
      T const* max = begin; // default max first index
      // check each other index
      while (begin != end) 
      {
        if (*begin > *max) 
        {
          max = begin; // if new val is less, set new min
        }

        ++begin;
      }

      return max;
    }

    /*
    * swap_ranges(Template):
    * input:   beginR1(pointer to range 1 start), endR1(pointer to range end), beginR2(pointer to range 2 start)
    * return:  None
    *
    * logic: go through range1 and swap values in R1 and R2
    */
  template <typename T>
    void swap_ranges(T* beginR1, T* endR1, T* beginR2)
    {
      // go through range 1
      while (beginR1 != endR1)
      {
        swap(beginR1, beginR2); // swap values in r1 and r2
        ++beginR1;
        ++beginR2;
      }
    }

    /*
    * remove(Template):
    * input:   begin(pointer to range start), end(pointer to range end), Value(to remove)
    * return:  pointer to new end
    *
    * logic: go through range and remove all instances of value
    */
  template <typename T>
    T* remove(T* begin, T* end, T const value)
    {
      T* walk = begin; // to walk through
      // look to remove while not at end of list
      while (walk != end && end != begin)
      {
        // check if needs to be removed
        if (*walk == value)
        {
            T* push = walk; // to push elements into remove gap 

            while (push <= end - 1)
            {
              *(push) = *(push + 1); // move elements after remove forward by 1 index
              ++push;
            }

            *(end - 1) = value; // put removed at end
            --end; // set new end to be shorter
        }

          ++walk;
      }

      return (end); // return new end pointer
  }

    /*
    * count(Template):
    * input:   begin(pointer to range start), end(pointer to range end), value(to count)
    * return:  int number of value's occurances
    *
    * logic: go through range and count how many time value appears
    */
  template <typename T>
    int count(T const* begin, T const* end, T const value)
    {
      T const* walk = begin; // to walk thorugh range
      int count = 0; // times value is found

      // go through range
      while (walk != end)
      {
          if (*walk == value)
          {
            ++count; // if value is found increase count
          }

          ++walk;
      }

      return count; // return number of times value appeared
    }

    /*
    * find(Template):
    * input:   begin(pointer to range start), end(pointer to range end), value(to find)
    * return:  pointer to first occurance of value (non const)
    *
    * logic: go through range and look for value
    */
  template <typename T>
    T* find(T* begin, T* end, T const value)
    {
      // go through range
      while (begin != end) 
      {
        if (*begin == value)
        {
          break; // stop on value if found
        }

        ++begin;
      }
      
      return begin; // return pointer to value
    }

    /*
    * const find(Template):
    * input:   begin(pointer to range start), end(pointer to range end), value(to find)
    * return:  pointer to first occurance of value (const)
    *
    * logic: go through range and look for value
    */
  template <typename T>
    T const* find(T const* begin, T const* end, T const value)
    {
      // go through range
      while (begin != end) 
      {
        if (*begin == value)
        {
          break; // stop on value if found
        }

        ++begin;
      }
      
      return begin; // return pointer to value
    }

    /*
    * fill(Template):
    * input:   begin(pointer to range start), end(pointer to range end), value(to fill with)
    * return:  None
    *
    * logic: go through range and set every element to value
    */
  template <typename T>
    void fill(T* begin, T* end, T const value)
    {
      // go through range
      while (begin!=end) 
      {
        *begin = value; // set all elements to value
        ++begin;
      }
    }

    /*
    * copy(Template):
    * input:   begin(pointer to range 1 start), end(pointer to range 1 end), begin2(pointer to range 2 start)
    * return:  pointer to beginning of range 2
    *
    * logic: go through range copy values from range 1 into range 2
    */
  template <typename T, typename T2>
    T2* copy(T const* begin, T const* end, T2* begin2)
    {
      // go through range
      while (begin!=end) 
      {
        *begin2 = *begin; // copy value of range 1 into range 2
        ++begin;
        ++begin2;
      }

      return begin2; // return start of range 2
    }

    /*
    * replace(Template):
    * input:   begin(pointer to range start), end(pointer to range end), oldVal(to replace), newVal(to replace with)
    * return:  None
    *
    * logic: go through range and replace all instances of oldVal with newVal
    */
  template <typename T>
    void replace(T* begin, T* end, T const oldVal, T const newVal)
    {
      // go through range
      while (begin!=end) 
      {
        if (*begin == oldVal)
        {
          *begin = newVal; // raplace each old value with the new one
        }

        ++begin;
      }
    }

    /*
    * equal(Template):
    * input:   begin(pointer to range 1 start), end(pointer to range 1 end), begin2(pointer to range 2 start)
    * return:  true if equal, false if not
    *
    * logic: go through range and check if all elements int R1 and R2 equal eachother
    */
  template <typename T, typename T2>
    bool equal(T const* begin, T const* end, T2 const* begin2)
    {
      // go through range
      while (begin!=end) 
      {
        if (*begin != *begin2)
        {
          return false; // if not same they cant be equal
        }

        ++begin;
        ++begin2;
      }

      return true; // they are equal
    }

    /*
    * sum(Template):
    * input:   begin(pointer to range start), end(pointer to range end)
    * return:  sum of all elements in range
    *
    * logic: go through range and add all elements together
    */
  template <typename T> 
    T sum(T const* begin, T const* end)
    {
      T sumVal = 0; // sum of all elements

      // go through range
      while (begin != end)
      {
        sumVal += *begin; // add value to sum
        ++begin;
      }

      return sumVal; // return total sum
    }
    
}
