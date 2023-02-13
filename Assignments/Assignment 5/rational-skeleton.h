#ifndef RATIONAL_H
#define RATIONAL_H
#include <fstream>  // fstream

namespace CS170 {

  /* assume type T is 
   * 1) able to represent a negative value 
   * 2) supports addition, subtraction, and division and multiplication
   */

  template< typename T >
    class Rational {
      public:
        Rational();
        Rational( T i );
        Rational( T _n, T _d );

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
