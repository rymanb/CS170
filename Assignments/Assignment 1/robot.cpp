/******************************************************************************/
/*!
* \file   robot.cpp
* \author Ryman Barnett
* \par    email: ryman.b\@digipen.edu
* \par    DigiPen login: ryman.b
* \par    Course: CS170
* \par    Section: B
* \par    Assignment# 1
* \date   01\17\2022
* \brief  Functions/struct for creating, destroying, and moving a robot on grid
*/
/******************************************************************************/

#include <cassert> // For checking NULL
#include "grid.h" // Grid Instance, Inside, Marked, Mark
#include "robot.h" // robot interface

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
    * \namespace Robot
    * \brief Contains struct and functions related to robots
    */
    /******************************************************************************/
    namespace Robot
    {
        /******************************************************************************/
        /*!
        * \struct _Robot
        * \brief Struct for robots, with x, y, orientation and grid
        */
        /******************************************************************************/
        struct _Robot
        {
            Orientation currentOrientation; //!< Robots orientation
            int x; //!< Robots current x pos
            int y; //!< Robots current y pos
            Grid::Instance grid; //!< Grid robot is on
        };

        /******************************************************************************/
        /*!
        * function: Create
        * \brief Create a valid Robot instance
        * \param _x: Robots starting x position
        * \param _y: Robots starting y position
        * \param orientation: Robots starting orientation
        * \param _grid: Pointer to grid robot is on
        * \return: Valid robot instance, or NULL if parameters were not valid
        */
        /******************************************************************************/
        Instance Create(int _x, int _y, Orientation orientation, Grid::Instance _grid)
        {
            if (_grid)   // make sure grid is valid
            {
                if (orientation >= 0 && orientation <= 3)   // and orientation is valid
                {
                    struct _Robot *robot = new struct _Robot; // allocate memory for robot
                    // fill in robots values with given values
                    robot->currentOrientation = orientation;
                    robot->x = _x;
                    robot->y = _y;
                    robot->grid = _grid;

                    return robot;
                }
            }

            return 0; // grid or orientation was not valid
        }

        /******************************************************************************/
        /*!
        * function: Destroy
        * \brief Delete a valid Robot instance
        * \param robot: Robot to destroy
        * \return: None
        */
        /******************************************************************************/
        void Destroy(Instance robot)
        {
            if (robot) // make sure robot is valid for deletion
            {
                delete robot;
            }
        }

        /******************************************************************************/
        /*!
        * function: Move
        * \brief Moves robots positon based on given command
        * \param robot: Robot to move
        * \param cmd: command to execute
        * \return: None
        */
        /******************************************************************************/
        void Move(Instance robot, char cmd)
        {
            //dont move if out of grid
            if (robot && Grid::Inside(robot->grid, robot->x, robot->y) == true)
            {
                switch (cmd) // check commands
                {
                case 'f':
                {
                    int new_x = robot->x; // robots next x
                    int new_y = robot->y; // robots next y
                    switch (robot->currentOrientation) // check orientation for moving forward
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
                    if (Grid::Inside(robot->grid, new_x, new_y) == false) // if next move would put robot out of grid
                    {
                        if (Grid::Marked(robot->grid, robot->x, robot->y) == false) // and current spot isnt marked
                        {
                            Grid::Mark(robot->grid, robot->x, robot->y); // mark it
                        }
                        else
                        {
                            break; // dont move off if on marked spot
                        }
                    }

                    robot->x = new_x; // update robot positions to new positions
                    robot->y = new_y;
                    break;
                }
                case 'l':
                    // turn left and update orientation
                    robot->currentOrientation = Orientation((robot->currentOrientation + 3) % 4);
                    break;
                case 'r':
                    // turn right and update orientation
                    robot->currentOrientation = Orientation((robot->currentOrientation + 1) % 4); 
                    break;
                default:
                    break; // if any other command do nothing

                }
            }
        }

        /******************************************************************************/
        /*!
        * function: QueryPosition
        * \brief  get the position and orientation of a robot, and if it is in grid
        * \param robot: Robot Instance
        * \param x: pointer to pass x position into
        * \param y: pointer to pass y position into
        * \param o: pointer to pass orientation into
        * \return: True if robot is in grid, False if not
        */
        /******************************************************************************/
        bool QueryPosition(Instance robot, int* x, int* y, Orientation *o)
        {
            if (robot)   // make sure robot is valid
            {
                // get robots values
                *x = robot->x;
                *y = robot->y;
                *o = robot->currentOrientation;

                if (Grid::Inside(robot->grid, *x, *y) == true)
                {
                    return true; // robot is in grid
                }
            }

            return false; // robot is not in grid or robot is not valid
        }
    }
}

