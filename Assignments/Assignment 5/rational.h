/* File header
 * ===========
 * file:       rational.h
 * author:     Ryman Barnett
 * email:      ryman.b@digipen.edu
 * course:     CS170
 * section:    B
 * assignment: 6
 * date:       04/11/2022
 * 
 * file content: 
 * this is a header file for Rational class, requires rational.cpp
 */

#ifndef RATIONAL_H
#define RATIONAL_H
#include <fstream>  // fstream

namespace CS170 {

    /* assume type T is 
    * 1) able to represent a negative value 
    * 2) supports addition, subtraction, and division and multiplication
    */

    
      /* Class header 
      * ============
      * Class Rational represent a fraction with a numerator and denominator.
      * Implemented interface:
      *  - constructors:
      *  -                   no input (0/1)
      *  -                   numerator but no denominator (n/1)
      *  -                   numerator and denominator (n/d)
      *  - addition:         operator+= and operator+
      *  - unary negate:     operator-
      *  - subtraction:      operator-= and operator-
      *  - division:         operator/= and operator/
      *  - multiplication:   operator *= and operator*
      *  - stream insertion: operator<<
      *  - comparisons:      operator< 
      *  -                   operator> 
      *  -                   operator>=
      *  -                   operator<=
      *  -                   operator==
      *  -                   operator!=
      *
      */
    template< typename T >
    class Rational {
        public:
            Rational();
            Rational( T i );
            Rational( T _n, T _d );

            
            T numerator() const { return n; }
            T denominator() const { return d; }

            // set width for 
            static void Width(T w);


            // unary negate
            Rational<T> operator-() const ;

            // arithmetic
            Rational<T>& operator+=(Rational<T> const& op2);
            Rational<T>& operator-=(Rational<T> const& op2);
            Rational<T>& operator*=(Rational<T> const& op2);
            Rational<T>& operator/=(Rational<T> const& op2);

            Rational<T> operator+(Rational<T> const& op2) const;
            Rational<T> operator-(Rational<T> const& op2) const;
            Rational<T> operator*(Rational<T> const& op2) const;
            Rational<T> operator/(Rational<T> const& op2) const;

            ////////////////////////////////////////////////////////////////////////
            // comparisons
            bool operator==(Rational<T> const& op2) const;
            bool operator<(Rational<T> const& op2) const;
            bool operator>(Rational<T> const& op2) const;
            bool operator<=(Rational<T> const& op2) const;
            bool operator>=(Rational<T> const& op2) const;
            bool operator!=(Rational<T> const& op2) const;
            // ....
            ////////////////////////////////////////////////////////////////////////

            // ...
            //
            ////////////////////////////////////////////////////////////////////////
            // to declare templated friend we will use a different template parameter 
            template< typename U >
              friend std::ostream& operator<<( std::ostream& os, Rational<U> const& r );

        private:
            T n,d;
            static int width; // used by stream insertion, do not change
            ////////////////////////////////////////////////////////////////////////
            void CheckSign();
            void CheckGCD();
            int  GCD() const;
    };
}
#include "rational.cpp"
#endif
