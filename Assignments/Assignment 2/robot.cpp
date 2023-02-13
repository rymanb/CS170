/******************************************************************************/
/*!
* \file   robot.cpp
* \author Ryman Barnett
* \par    email: ryman.b\@digipen.edu
* \par    DigiPen login: ryman.b
* \par    Course: CS170
* \par    Section: B
* \par    Assignment# 2
* \date   02\02S\2022
* \brief  Functions/class for creating, destroying, and moving a robot on grid
*/
/******************************************************************************/

#include <cassert> // For checking NULL
#include "grid.h" // Grid Instance, Inside, Marked, Mark
#include "robot.h" // robot interface

/******************************************************************************/
/*!
* \namespace CS170
* \brief contains Robot and Grid Classes
*/
/******************************************************************************/
namespace CS170
{

    /******************************************************************************/
    /*!
    * function: Robot
    * \brief Constructor to create a valid Robot instance
    * \param _x: Robots starting x position
    * \param _y: Robots starting y position
    * \param orientation: Robots starting orientation
    * \param _grid: Pointer to grid robot is on
    * \return: None
    */
    /******************************************************************************/
    Robot::Robot(Grid& _grid, int _x, int _y, Orientation orientation) :grid(_grid)
    {
        this->x = _x;
        this->y = _y;

        if (orientation >= 0 && orientation <= 3)
        {
            this->heading = orientation;
        }
    }

    /******************************************************************************/
    /*!
    * function: Destroy
    * \brief Deconstruct Robot instance
    * \return: None
    */
    /******************************************************************************/
    Robot::~Robot()
    {
    }

    /******************************************************************************/
    /*!
    * function: Move
    * \brief Moves robots positon based on given command
    * \param cmd: command to execute
    * \return: None
    */
    /******************************************************************************/
    void Robot::Move(char cmd)
    {
        if (grid.Inside(this->x, this->y))
        {
            switch (cmd)
            {
            case 'f': // go forward
            {
                int new_x = this->x; // robots next x
                int new_y = this->y; // robots next y
                switch (this->heading) // check orientation for moving forward
                {
                case 0: // move north
                    new_y -= 1; // update robot next position
                    break;
                case 1: // move east
                    new_x += 1; // update robot next position
                    break;
                case 2: // move south
                    new_y += 1; // update robot next position
                    break;
                case 3: // move west
                    new_x -= 1; // update robot next position
                    break;
                default:
                    break; // if any other orientation do nothing
                }
                if (grid.Inside(new_x, new_y) == false) // if next move would put robot out of grid
                {
                    if (grid.Marked(this->x, this->y) == false) // and current spot isnt marked
                    {
                        grid.Mark(this->x, this->y); // mark it
                    }
                    else
                    {
                        break; // dont move off if on marked spot
                    }
                }

                this->x = new_x; // update robot positions to new positions
                this->y = new_y;
                break;
            }
            case 'l': // turn left
                heading = Orientation((heading + 3) % 4);
                break;
            case 'r': // turn right
                heading = Orientation((heading + 1) % 4);
                break;
            default:
                break;
            }
        }
    }

    /******************************************************************************/
    /*!
    * function: GetX
    * \brief  get the x position of robot
    * \return: return x position of robot
    */
    /******************************************************************************/
    int Robot::GetX()
    {
        return this->x;
    }

    /******************************************************************************/
    /*!
    * function: GetY
    * \brief  get the y position of robot
    * \return: y position of robot
    */
    /******************************************************************************/
    int Robot::GetY()
    {
        return this->y;
    }

    /******************************************************************************/
    /*!
    * function: GetO
    * \brief  get the orientation of robot
    * \return: orientation of robot
    */
    /******************************************************************************/
    Robot::Orientation Robot::GetO()
    {
        return this->heading;
    }

    /******************************************************************************/
    /*!
    * function: GetStatus
    * \brief  check if the robot is in grid
    * \return: True if robot is in grid, False if not
    */
    /******************************************************************************/
    bool Robot::GetStatus()
    {
        if (grid.Inside(this->x, this->y) == true)
        {
            return true;
        }

        return false;
    }
}