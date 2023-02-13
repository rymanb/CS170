/******************************************************************************/
/*!
* \file   grid.cpp
* \author Ryman Barnett
* \par    email: ryman.b\@digipen.edu
* \par    DigiPen login: ryman.b
* \par    Course: CS170
* \par    Section: B
* \par    Assignment# 1
* \date   01\17\2022
* \brief  Functions/struct for creating, destroying, and managing a grid
*/
/******************************************************************************/

#include <cassert> // For checking NULL
#include <cstdlib> // For checking NULL
#include "grid.h" // grid interface

/******************************************************************************/
/*!
* \namespace CS170
* \brief contains Robot and Grid namespaces
*/
/******************************************************************************/
namespace CS170
{
    /******************************************************************************/
    /*!
    * \namespace Grid
    * \brief Contains struct and functions related to Grids
    */
    /******************************************************************************/
    namespace Grid
    {
        /******************************************************************************/
        /*!
        * \struct _Grid
        * \brief Struct for grids, with dimensions and 2D array
        */
        /******************************************************************************/
        struct _Grid
        {
            int dimensionX; //!< X dimension of overall grid
            int dimensionY; //!< Y dimension of overall grid
            int **array;    //!< 2D array grid of (x,y) dimensions
        };

        
        /******************************************************************************/
        /*!
        * function: Create
        * \brief Create a valid grid
        * \param x: x dimension of grid
        * \param y: y dimension of grid
        * \return: pointer to valid grid instance
        */
        /******************************************************************************/
        Instance Create(int x, int y)
        {
            Instance grid = new struct _Grid; // allocates a 1d grid of x * y dimensions
            grid->dimensionX = x; // number of columns in grid
            grid->dimensionY = y; // number of rows in grid
            grid->array = new int*[x]; // allocate x array

            // fill/allocate each x with another array for the y's
            for (int i = 0; i < x; i++)
            {
                grid->array[i] = new int[y]; // allocate

                // fill whole grid with 0's for not marked at start
                for (int j = 0; j < y; j++)
                {
                    grid->array[i][j] = 0;
                }
            }

            return grid;
        }

        /******************************************************************************/
        /*!
        * function: Destroy
        * \brief Delete a valid grid
        * \param grid: pointer to a grid
        * \return: None
        */
        /******************************************************************************/
        void Destroy(Instance grid)
        {
            if (grid != NULL) // make sure the grid is valid
            {
                // delete each y array first
                for (int i = 0; i < grid->dimensionX; i++)
                {
                    delete [] grid->array[i];
                }

                delete [] grid->array; // delete x array
                delete grid; // delete grid instance
            }
        }

        /******************************************************************************/
        /*!
        * function: Inside
        * \brief Checks if coordinates are in a grid
        * \param grid: grid pointer
        * \param x: x coordinate
        * \param y: y coordinate
        * \return: valid grid instance
        */
        /******************************************************************************/
        bool Inside(Instance grid, int x, int y)
        {
            if (grid != NULL) // check if grid is valid
            {
                if (x < grid->dimensionX && x >= 0) // checks if given x is within 0 and max grid x dimension
                {
                    if (y < grid->dimensionY && y >= 0) // checks if given y is within 0 and max grid y dimension
                    {
                        return true; // if it is its in grid
                    }
                }
            }

            return false; // otherwise its not
        }

        /******************************************************************************/
        /*!
        * function: Mark
        * \brief Mark a position on grid
        * \param grid: pointer to grid
        * \param x: x coordinate
        * \param y: y coordinate
        * \return: None
        */
        /******************************************************************************/
        void Mark(Instance grid, int x, int y)
        {
            if (grid != NULL)
            {
                grid->array[x][y] = 1; // find corresponding x and y, and marks it with 1
            }
        }

        /******************************************************************************/
        /*!
        * function: Marked
        * \brief Check if gird is marked at coordinates
        * \param grid: pointer to grid
        * \param x: x coordinate
        * \param y: y coordinate
        * \return: True if grid is marked, False if not
        */
        /******************************************************************************/
        bool Marked(Instance grid, int x, int y)
        {
            if (grid != NULL && Inside(grid, x, y) == true) // make sure grid is valid and the x/y is inside it
            {
                if (grid->array[x][y] == 1) // checks if x and y coordinate in grid is marked
                {
                    return true; // cell is marked
                }
            }

            return false; // cell is not marked/grid empty/x and y are not in grid
        }
    }
}