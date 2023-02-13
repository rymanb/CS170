/* File header
 * ===========
 * file:       table.cpp
 * author:     Ryman Barnett
 * email:      ryman.b@digipen.edu
 * course:     CS170
 * section:    B
 * assignment: 4
 * date:       02/28/2022
 *
 * file content:
 * this is a source file for Table class, requires table.h
 */

#include "table.h"
#include <iomanip>

using namespace std;

namespace CS170 {

    /*
    * Table:
    * input:   int Rows_(rows in table), int Cols_(columns in table)
    * return:  None
    *
    * logic: create a new Table
    */
    Table::Table(int Rows_, int Cols_)
    {
        numCols_ = Cols_; // set table colomns
        numRows_ = Rows_; // set table rows

        ppData = new string*[Rows_]; // pointers to rows

        for (int r = 0; r < Rows_; ++r)
        {
            ppData[r] = new std::string[Cols_];  // rows with data
        }
    }

    /*
    * Table:
    * input:   Table rhs
    * return:  None
    *
    * logic: create a new Table copy from existing table
    */
    Table::Table(Table const& rhs)
    {
        numCols_ = rhs.numCols_; // copy colomns
        numRows_ = rhs.numRows_; // copy rows

        ppData = new string * [numRows_]; // pointers to rows
        for (int r = 0; r < numRows_; ++r)
        {
            ppData[r] = new std::string[numCols_];  // rows with data

            for (int c = 0; c < numCols_; ++c)
            {
                ppData[r][c] = rhs.ppData[r][c]; // for each row copy data
            }
        }
    }

    /*
    * ~Table:
    * input:   None
    * return:  None
    *
    * logic: delete allocated data of tables arrays
    */
    Table::~Table()
    {
        for (int r = 0; r < numRows_; ++r)
        {
            delete[] ppData[r]; // delete each row
        }
        delete[] ppData; // delete columns
    }

    /*
    * assignment
    * input:   Rational rhs
    * return:  a reference to current rational
    *
    * logic:   deletes old array, and replaces it with copy of rhs's array and other data
    */
    Table& Table::operator= (Table const& rhs)
    {
        if (this == &rhs)
        {
            return *this; // if pointers are the same just return this
        }

        // otherwise

        for (int r = 0; r < numRows_; ++r)
        {
            delete[] ppData[r]; // delete old rows
        }
        delete [] ppData; // delete old columns

        // copy col and row counts
        numCols_ = rhs.numCols_;
        numRows_ = rhs.numRows_;

        ppData = new string * [numRows_]; // new pointers to rows
        for (int r = 0; r < numRows_; ++r)
        {
            ppData[r] = new std::string[numCols_];  // new rows with data

            for (int c = 0; c < numCols_; ++c)
            {
                ppData[r][c] = rhs.ppData[r][c]; // copy over data from rhs
            }
        }

        return *this;
    }

    /*
    * getter/setter:
    * input:   unsigned r(row to get), unsigned c(column to get)
    * return:  ref to string at row and colummn
    *
    * logic: get the data at row and comumn, alows setting
    */
    std::string& Table::operator()(unsigned int r, unsigned int c)
    {
        return ppData[r][c];
    }

    /*
    * getter:
    * input:   unsigned r(row to get), unsigned c(column to get)
    * return:  const ref to string at row and colummn
    *
    * logic: get the data at row and comumn return as const
    */
    std::string const& Table::operator()(unsigned int r, unsigned int c) const
    {
        return ppData[r][c];
    }

    /*
    * Reverse:
    * input:   int i(row), int j(column)
    * return:  None
    *
    * logic: reverse the string at the given position (i,j)
    */
    void Table::Reverse(int i, int j)
    {
        int start = 0; // counter for start of string

        //go though string until start and end meet in middle of string
        for (size_t end = ppData[i][j].length() - 1; end >= ppData[i][j].size() / 2; --end)
        {
            char temp = (ppData[i][j])[start]; // store first char for swap
            (ppData[i][j])[start] = (ppData[i][j])[end]; // swap values of current start and end of string
            (ppData[i][j])[end] = temp; // make end the original start character
            ++start;
        }
    }

    /*
    * Reverse:
    * input:   int i(row)
    * return:  None
    *
    * logic: reverse the table only on row i
    */
    void Table::Reverse(int i)
    {
        // go though each column at given row value until start and end swaps meet in middle
        for (int j = 0; j < numCols_ / 2; ++j)
        {
            std::string temp = ppData[i][j]; // store original start value for swap

            (ppData[i][j]) = ppData[i][numCols_ - j - 1]; // set current value of start to end value
            ppData[i][numCols_ - j - 1] = temp; // set end value to original start
        }
    }

    /*
    * Reverse:
    * input:   None
    * return:  None
    *
    * logic: Transposes the entire table
    */
    void Table::Reverse()
    {
        // swap rows and colomns
        int temp = numRows_;
        numRows_ = numCols_;
        numCols_ = temp;

        std::string** reversed = new std::string*[numRows_]; // create a new array for strings
        for (int r = 0; r < numRows_; ++r)
        {
            reversed[r] = new std::string[numCols_];  // rows with data
        }

        for (int i = 0; i < numRows_; ++i)
        {
            for (int j = 0; j < numCols_; ++j)
            {
                reversed[i][j] = ppData[j][i]; // transpose old array into new array
            }
        }

        for (int r = 0; r < numCols_; ++r)
        {
            delete[] ppData[r]; // delete old array rows
        }
        delete[] ppData; // delete old arrays columns

        ppData = reversed; // set the new array

    }

    /*
    * addition
    * input:   Table table2
    * return:  a const ref to new table
    *
    * logic:   overlap the two tables(add to gether) into new table
    */
    Table Table::operator+ (Table const& table2) const
    {
        int row = numRows_;
        int col = numCols_;

        if (numRows_ < table2.numRows_)
        {
            row = table2.numRows_; // find largest row dimension
        }
        if (numCols_ < table2.numCols_)
        {
            col = table2.numCols_; // find largest column dimension
        }

        Table newTab(row, col); // create a new table for adding

        for (int i = 0; i < numRows_; ++i)
        {
            for (int j = 0; j < numCols_; ++j)
            {
                // fill in new table with first tables values to be overlapped later
                newTab.ppData[i][j] = ppData[i][j];
            }
        }

        for (int i = 0; i < table2.numRows_; ++i)
        {
            for (int j = 0; j < table2.numCols_; ++j)
            {
                // overlap table1's data with table 2's data
                newTab.ppData[i][j] = newTab.ppData[i][j] + table2.ppData[i][j];
            }
        }

        return newTab;
    }

    /*
    * multiplication
    * input:   Table table2
    * return:  a const ref to new table
    *
    * logic:   find tensor product of the two tables and put into new table
    */
    Table Table::operator* (Table const& table2) const
    {
        Table newTab(numRows_ * table2.numRows_, numCols_ * table2.numCols_); // new table with dimensions multiplied

        // loop through table 1
        for (int r1 = 0; r1 < numRows_; ++r1)
        {
            for (int c1 = 0; c1 < numCols_; ++c1)
            {
                // for each thing in t2 multiply by t1 values
                for (int r2 = 0; r2 < table2.numRows_; ++r2)
                {
                    for (int c2 = 0; c2 < table2.numCols_; ++c2)
                    {
                        int currRow = r1 * table2.numRows_ + r2; // new tables row index
                        int currCol = c1 * table2.numCols_ + c2; // new tables column index

                        // add t1 and t2 vals together and place in new table
                        newTab.ppData[currRow][currCol] = ppData[r1][c1] + table2.ppData[r2][c2];
                    }
                }
            }
        }

        return newTab;
    }

    /*
    * Display
    * input:   os
    * return:  None
    *
    * logic:   display data from table simple
    */
    void Table::Display(std::ostream& os) const
    {
        for (int r = 0; r < numRows_; ++r)
        {
            for (int c = 0; c < numCols_; ++c)
            {
                os << ppData[r][c] << " ";
            }
            os << std::endl;
        }
    }

    /*
    * Display2
    * input:   os
    * return:  None
    *
    * logic:   display data from table into console with fancy formatting
    */
    void Table::Display2(std::ostream& os) const
    {
        // loop though each row for printing + 1 for last dashed row
        for (int r = 0; r <= numRows_; ++r)
        {
            size_t length = 0; // initial length for calculating

            for (int i = 0; i < numCols_; ++i)
            {
                for (int j = 0; j < numRows_; ++j)
                {
                    // find the largest word in each column for width calc
                    if (ppData[j][i].length() >= length)
                    {
                        length = ppData[j][i].length();
                    }
                }

                length += 2; // add 2 for side buffers
                os << "+"; // print + between dashes

                for (int l = 0; l < (int)length; ++l)
                {
                    os << "-"; // print current columns dashes
                }

                length = 0; // reset and do for each column
            }
            os << "+" << std::endl; // output last + on row

            // if not on last row print out table data
            if (r < numRows_)
            {
                for (int c = 0; c < numCols_; ++c)
                {
                    size_t length = 0; // initial len for width calculation

                    for (int j = 0; j < numRows_; ++j)
                    {
                        // find the largest word in each column for width calc
                        if (ppData[j][c].length() >= length)
                        {
                            length = ppData[j][c].length();
                        }
                    }

                    // output bars and data
                    os << "|" << " " << std::setw((int)length) << ppData[r][c] << " ";
                    length = 0;
                }

                os << "|" << std::endl; // final end bar
            }
        }
    }

    /*
    * stream insertion
    * input:   os, table
    * return:  os
    *
    * logic:   insert table into stream for output to console
    */
    std::ostream& operator<<(std::ostream& os, Table const& t)
    {
        //t.Display2( os );   // fancy (see fancy_out* )
        t.Display(os);   // simple (see out* )

        return os;
    }
}
