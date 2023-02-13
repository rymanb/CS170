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

    
    
    // ....


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
