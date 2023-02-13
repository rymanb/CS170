#include "table.h"
#include <iomanip>

namespace CS170 {

    void Table::Display( std::ostream & os ) const
    {
        for( unsigned int r=0; r<numRows_; ++r ) {
            for( unsigned int c=0; c<numCols_; ++c ) {
                os << ppData[r][c] << " ";
            }
            os << std::endl;
        }
    }
    
    void Table::Display2( std::ostream & os ) const
    {
        // ... your code, used setw, setfill, etc 
    }

    std::ostream & operator<<(std::ostream & os, Table const & t)
    {
        t.Display2( os );   // fancy (see fancy_out* )
        //t.Display( os );   // simple (see out* )

        return os;
    }


}
