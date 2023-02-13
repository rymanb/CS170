/* File header
 * ===========
 * file:       table.h
 * author:     Ryman Barnett
 * email:      ryman.b@digipen.edu
 * course:     CS170
 * section:    B
 * assignment: 4
 * date:       02/28/2022
 * 
 * file content: 
 * this is a source file for Table class, requires table.cpp
 */

#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <fstream>
#include <iostream>

namespace CS170 {
    /* Class header 
    * ============
    * Class Table represent a table filled with data inputed by user.
    * Implemented interface:
    *  - constructors:
    *  -                   rows and columns (table with dims rxc)
    *  -                   existing table(copy constructor)
    *  - deconstructor:
    *  -                   delete allocated data from 2d array
    *  - addition:         operator+
    *  - multiplication:   operator*
    *  - reverse:
    *  -                   reverse string at (i,j)
    *  -                   reverse row i
    *  -                   reverse table(transpose)
    *  - stream insertion: operator<<
    *  -                   simple display
    *  -                   fancy formatted display
    */
    class Table {
        // table data
        int numRows_;
        int numCols_;
        std::string ** ppData;

        public:
        // constructors / deconstructor
        Table(int Rows_, int Cols_);
        Table(Table const& rhs);
        ~Table();

        // operators
        Table& operator= (Table const& rhs);
        // getter and setter (overloaded similar to operator[] from notes)
        std::string       & operator () ( unsigned int r, unsigned int c );
        std::string const & operator () ( unsigned int r, unsigned int c ) const;
        Table operator* (Table const& table2) const;
        Table operator+ (Table const& table2) const;

        // reverse
        void Reverse(int i, int j);
        void Reverse(int i);
        void Reverse();

        // displays
        void Display( std::ostream & os ) const;    // provided
        void Display2( std::ostream & os ) const;   // fancy    (10% of your grade)
    };

    std::ostream & operator<<( std::ostream & os, Table const& t );
}
#endif
