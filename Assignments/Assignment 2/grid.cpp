/******************************************************************************/
/*!
* \file   grid.cpp
* \author Ryman Barnett
* \par    email: ryman.b\@digipen.edu
* \par    DigiPen login: ryman.b
* \par    Course: CS170
* \par    Section: B
* \par    Assignment# 2
* \date   02\02\2022
* \brief  Functions/class for creating, destroying, and managing a grid
*/
/******************************************************************************/

#include <cassert> // For checking NULL
#include <cstdlib> // For checking NULL
#include "grid.h"

/******************************************************************************/
/*!
* \namespace CS170
* \brief contains Robot and Grid classes
*/
/******************************************************************************/
namespace CS170
{

    /******************************************************************************/
    /*!
    * function: Grid
    * \brief Constroctor to create a valid grid
    * \param x: x dimension of grid
    * \param y: y dimension of grid
    * \return: None
    */
    /******************************************************************************/
    Grid::Grid(int x, int y)
    {
        if (x > 0 && y > 0) // Smake sure grid dimensions are positive/valid
        {
            this->x_max = x;
            this->y_max = y;
            data = new int[x * y];

            for (int i = 0; i < x * y; i++) // set grid to 0's
            {
                data[i] = 0;
            }
        }
    }

    /******************************************************************************/
    /*!
    * function: ~Grid
    * \brief Dconstroctor to delete the Grid
    * \return: None
    */
    /******************************************************************************/
    Grid::~Grid()
    {
        delete[] this->data;
    }

    /******************************************************************************/
    /*!
    * function: Inside
    * \brief Checks if coordinates are in a grid
    * \param x: x coordinate
    * \param y: y coordinate
    * \return: valid grid instance
    */
    /******************************************************************************/
    bool Grid::Inside(int x, int y)
    {
        if (x < this->x_max && x >= 0) // checks if given x is within 0 and max grid x dimension
        {
            if (y < this->y_max && y >= 0) // checks if given y is within 0 and max grid y dimension
            {
                return true; // if it is its in grid
            }
        }

        return false; // otherwise its not
    }

    /******************************************************************************/
    /*!
    * function: Mark
    * \brief Mark a position on grid
    * \param x: x coordinate
    * \param y: y coordinate
    * \return: None
    */
    /******************************************************************************/
    void Grid::Mark(int x, int y)
    {
        data[(this->x_max * y) + x] = 1;
    }

    /******************************************************************************/
    /*!
    * function: Marked
    * \brief Check if gird is marked at coordinates
    * \param x: x coordinate
    * \param y: y coordinate
    * \return: True if grid is marked, False if not
    */
    /******************************************************************************/
    bool Grid::Marked(int x, int y)
    {
        if (this->Inside(x, y) == true) // if inside
        {
            if (data[(this->x_max * y) + x] == 1) // and cell is 1
            {
                return true; // its marked
            }
        }

        return false;
    }

}
