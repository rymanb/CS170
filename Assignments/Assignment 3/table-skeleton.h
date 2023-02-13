#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <fstream>
#include <iostream>

namespace CS170 {
    class Table {
        // ...

        public:
        // ...

        // getter and setter (overloaded similar to operator[] from notes)
        std::string       & operator () ( unsigned int r, unsigned int c );
        std::string const & operator () ( unsigned int r, unsigned int c ) const;

        // ...

        void Display( std::ostream & os ) const;    // provided
        void Display2( std::ostream & os ) const;   // fancy    (10% of your grade)
    };

    std::ostream & operator<<( std::ostream & os, Table const& t );
}
#endif
