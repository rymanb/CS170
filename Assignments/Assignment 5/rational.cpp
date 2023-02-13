/* File header
 * ===========
 * file:       rational.cpp
 * author:     Ryman Barnett
 * email:      ryman.b@digipen.edu
 * course:     CS170
 * section:    B
 * assignment: 6
 * date:       04/11/2022
 *
 * file content:
 * this is a source file for Rational class, requires rational.h
 */

#include "rational.h"
#include <iomanip>  // setw
#include <cstdlib>  // abs

namespace CS170 {

    template < typename T> 
    int Rational<T>::width = 0; // no padding by default

    ////////////////////////////////////////////////////////////////////////
    template < typename T> 
    Rational<T>::Rational()               : n(0),  d(1)   {}
    ////////////////////////////////////////////////////////////////////////
    template < typename T> 
    Rational<T>::Rational( T i )        : n(i),  d(1)   {}
    ////////////////////////////////////////////////////////////////////////
    template < typename T> 
    Rational<T>::Rational(T _n, T _d) : n(_n), d(_d)  { CheckSign(); CheckGCD(); }

    /*
    * unary negate Template:
    * input:   None
    * return:  new rational with sign flipped
    *
    * logic: create a new rational with just numerator flipped
    */
    template < class T> 
    Rational<T> Rational<T>::operator-() const 
    {
        return Rational(-n, d);
    }

    /*
    * compound addition/assignment Template
    * input:   Rational<T> op2
    * return:  a reference to current rational of type T
    *
    * logic:   adds op2 to this object (no new objects created)
    */
    template < class T>  
    Rational<T>& Rational<T>::operator+=(Rational<T> const& op2)
    {
        n = (n * op2.d) + (op2.n * d); // get common numerator and denominator and add numerators
        d *= op2.d; // common denominator

        CheckSign(); // make sure signs are right
        CheckGCD(); // make sure its simplified

        return *this;
    }

    /*
    * compound subtraction/assignment Template
    * input:   Rational<T> op2
    * return:  a reference to current rational of type T
    *
    * logic:   subtracts op2 to this object (no new objects created)
    */
    template < class T> 
    Rational<T>& Rational<T>::operator-=(Rational<T> const& op2)
    {
        *this += -op2; // add the negitive of operator 2(subtraction)

        return *this;
    }

    /*
    * compound multiplication/assignment Template
    * input:   Rational<T> op2
    * return:  a reference to current rational of type T
    *
    * logic:   multiplies this object by op2 (no new objects created)
    */
    template < class T> 
    Rational<T>& Rational<T>::operator*=(Rational<T> const& op2)
    {
        n *= op2.n; // multiply numerators
        d *= op2.d; // multiply denominators

        CheckSign(); // make sure signs are right
        CheckGCD(); // make sure its simplified

        return *this;
    }

    /*
    * compound division/assignment Template
    * input:   Rational<T> op2
    * return:  a reference to current rational of type T
    *
    * logic:   divides this object by op2 (no new objects created)
    */
    template < class T> 
    Rational<T>& Rational<T>::operator/=(Rational<T> const& op2)
    {
        n *= op2.d; // multiply this rational by op2(d/n)
        d *= op2.n;

        CheckSign(); // make sure signs are right
        CheckGCD(); // make sure its simplified

        return *this;
    }

    /*
    * addition Template:
    * input:   Rational<T> op2
    * return:  a new rational object of type T
    *
    * logic:   adds op2 to a copy of this object (new object created)
    */
    template < class T> 
    Rational<T> Rational<T>::operator+(Rational<T> const& op2) const
    {
        Rational result(*this); // copy of this
        result += op2; // add op2 to copy

        return result; // return copy
    }

    /*
    * subtraction Template:
    * input:   Rational<T> op2
    * return:  a new rational object of type T
    *
    * logic:   subtracts op2 from a copy of this object (new object created)
    */
    template < class T> 
    Rational<T> Rational<T>::operator-(Rational<T> const& op2) const
    {
        Rational result(*this); // copy of this
        result += -op2; // add negative of op2 to copy

        return result; // return copy
    }

    /*
    * multiplication Template:
    * input:   Rational<T> op2
    * return:  a new rational object of type T
    *
    * logic:   multiplies a copy of this object by op2 (new object created)
    */
    template < class T> 
    Rational<T> Rational<T>::operator*(Rational<T> const& op2) const
    {
        Rational result(*this); // copy of this
        result *= op2; // multiply copy by op2

        return result; // return copy
    }

    /*
    * division Template:
    * input:   Rational<T> op2
    * return:  a new rational object of type T
    *
    * logic:   divides a copy of this object by op2 (new object created)
    */
    template < class T> 
    Rational<T> Rational<T>::operator/(Rational<T> const& op2) const
    {
        Rational result(*this); // copy of this
        result /= op2; // divide copy by op2

        return result; // return copy
    }

    /*
    * comparison for less Template:
    * input:   Rational<T> op2
    * return:  boolean: true if this is less than op2, false otherwise
    *
    * logic: put both rationals over common denominator and see if
    *        first rational is smaller than the second
    */
    template < class T> 
    bool Rational<T>::operator<(Rational<T> const& op2) const
    {
        // multiply numerators by opposite denominator(common denominator) and compare
        return (n * op2.d < op2.n * d);
    }

    /*
    * comparison for equal Template:
    * input:   Rational<T> op2
    * return:  boolean: true if equal, false if not
    *
    * logic: check if both numerators and denominators are equal
    */
    template < class T> 
    bool Rational<T>::operator==(Rational<T> const& op2) const
    {
        // they are equal if both numerators and deniminators are equal
        return ((n == op2.n) && (d == op2.d));
    }

    /*
    * comparison for greater Template:
    * input:   Rational<T> op2
    * return:  boolean: true if this is greater than op2, flase otherwise
    *
    * logic: check if second rational is smaller than first
    */
    template < class T> 
    bool Rational<T>::operator>(Rational<T> const& op2) const
    {
        // check if second rational is smaller than first
        return (op2 < *this);
    }

    /*
    * comparison for greater or equal Template:
    * input:   Rational<T> op2
    * return:  boolean: true if this is >= to op2, false if not
    *
    * logic: check if first rational is not less than second
    */
    template < class T> 
    bool Rational<T>::operator>=(Rational<T> const& op2) const
    {
        // check if first rational is not less than second
        return (!(*this < op2));
    }

    /*
    * comparison for less or equal Template:
    * input:   Rational<T> op2
    * return:  boolean: true if this is <= op2, flase if not
    *
    * logic: check if first rational is not greater than second
    */
    template < class T> 
    bool Rational<T>::operator<=(Rational<T> const& op2) const
    {
        // check if first rational is not greater than second
        return (!(*this > op2));
    }

    /*
    * comparison for not equal Template:
    * input:   Rational<T> op2
    * return:  boolean: true if rationals not equal, flase if they are equal
    *
    * logic: check if first rational is not equal to second, inverse of ==
    */
    template < class T> 
    bool Rational<T>::operator!=(Rational<T> const& op2) const
    {
        // check if first rational is not equal to second
        return (!(*this == op2));
    }

    ////////////////////////////////////////////////////////////////////////
    template < typename U> 
    std::ostream& operator<<( std::ostream& os, Rational<U> const& r ) {
        os << std::setw( r.width ) << r.n;
        if ( r.d != 1 ) { os << "/" << std::setw( r.width-1 ) << r.d; }
        else            { os <<        std::setw( r.width ) << " "; }
        return os;
    }
    
    ////////////////////////////////////////////////////////////////////////
    template < typename T> 
    void Rational<T>::CheckSign() {
        if ( d<0 ) { n *= -1; d*= -1; }
    }
    ////////////////////////////////////////////////////////////////////////
    template < typename T> 
    void Rational<T>::CheckGCD() {
        int gcd = GCD();
        n = n/gcd;
        d = d/gcd;
    }
    ////////////////////////////////////////////////////////////////////////
    template < typename T> 
    int Rational<T>::GCD() const {
        int a=std::abs(n), b=std::abs(d);
        while ( a && b ) {
            if ( a < b ) { b = b%a; }
            else         { a = a%b; }
        }
        if ( a==0 ) return b;
        else        return a;
    }
}
