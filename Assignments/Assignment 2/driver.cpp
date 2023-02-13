#include <iostream>
#include <string>
#include "grid.h"
#include "robot.h"

char Orientation2char(CS170::Robot::Orientation o) {
  switch (o) {
    case CS170::Robot::NORTH: return 'n';
    case CS170::Robot::SOUTH: return 's';
    case CS170::Robot::EAST: return 'e';
    case CS170::Robot::WEST: return 'w';
  }
  return '?';
}

CS170::Robot::Orientation Char2orientation(char ch) {
  switch (ch) {
    case 'n': return CS170::Robot::NORTH;
    case 's': return CS170::Robot::SOUTH;
    case 'e': return CS170::Robot::EAST ;
    case 'w': return CS170::Robot::WEST ;
  }
  return CS170::Robot::NORTH;
}

#include <fstream>
void run_test( char const * filename) {
  std::ifstream fin( filename, std::ifstream::in );
  int dim1, dim2;
  fin >> dim1 >> dim2;
  CS170::Grid field( dim1, dim2 );
  
  // statistics
  int * last_positions = new int[ dim1*dim2 ]; // flat array
  for ( int i=0; i<dim1; ++i ) { // horisontal offset (to the right)
    for ( int j=0; j<dim2; ++j ) { // vertical offset (down)
      last_positions[ i*dim2 + j ] = -1; // // -1 means unoccupied
    }
  }

  bool go = true;
  while ( go ) {
    // robot ?
    char new_robot;
    fin >> new_robot;

    if (new_robot == 'n') { // done
      go = false;
      continue; // loop will terminate
    } 

    int rx,ry;
    char ch_o;
    int counter = 1;
    std::string plan;
    fin >> rx >> ry;
    fin >> ch_o;
    fin >> plan;
    CS170::Robot robot( field, rx, ry, Char2orientation(ch_o) );

    // execute plan
    int plan_size = plan.size();
    for (int i=0;i<plan_size;++i) {
      //uncomment for testing
      //bool alive = QueryPosition(robot,&x,&y,&o);
      //std::cout << "robot position is " << x << " " << y << " " << Orientation2char(o);
      //if (!alive)  std::cout << " lost";
      //std::cout << std::endl << "moving " << plan[i] << std::endl;
      ///////////////////
      robot.Move( plan[i] );
    }

    // collect statistics
    bool alive = robot.GetStatus();
    int x = robot.GetX();
    int y = robot.GetY();
    CS170::Robot::Orientation orientation = robot.GetO();
    std::cout << "robot final position " << x << " " << y << " " << Orientation2char( orientation );
    if (!alive) { 
      std::cout << " lost";
    } else {
      last_positions[ x*dim2 + y ] = counter; // record last robot's position
      ++counter;
    }
    std::cout << std::endl;
  }

  // Extra output ===========================================================
  // top line
  std::cout << std::endl << "Last robots' positions" << std::endl;
  std::cout << "+";
  for ( int i=0; i<dim1; ++i ) { std::cout << "-"; }
  std::cout << "+" << std::endl;

  // for printing we need to change the order of for-loops
  for ( int j=0; j<dim2; ++j ) { // vertical offset (down)
    std::cout << "|"; // left border
    for ( int i=0; i<dim1; ++i ) { // horisontal offset (to the right)
      if ( last_positions[ i*dim2 + j ] >= 0 ) {
        std::cout << "r";
        //std::cout << last_positions[ i*dim2 + j ];
      } else {
        std::cout << " ";
      }
    }
    std::cout << "|" << std::endl; // right border and new line
  }

  // bottom line
  std::cout << "+";
  for ( int i=0; i<dim1; ++i ) { std::cout << "-"; }
  std::cout << "+" << std::endl;

  std::cout << std::endl << "Marked positions" << std::endl;

  // top line
  std::cout << "+";
  for ( int i=0; i<dim1; ++i ) { std::cout << "-"; }
  std::cout << "+" << std::endl;

  // for printing we need to change the order of for-loops
  for ( int j=0; j<dim2; ++j ) { // vertical offset (down)
    std::cout << "|"; // left border
    for ( int i=0; i<dim1; ++i ) { // horisontal offset (to the right)
      if ( field.Marked( i, j ) ) {
        std::cout << "M";
      } else {
        std::cout << " ";
      }
    }
    std::cout << "|" << std::endl; // right border and new line
  }

  // bottom line
  std::cout << "+";
  for ( int i=0; i<dim1; ++i ) { std::cout << "-"; }
  std::cout << "+" << std::endl;
  // Extra output ends ======================================================

  delete [] last_positions;
}


void test0() { run_test( "plan0.txt" ); }
void test1() { run_test( "plan1.txt" ); }
void test2() { run_test( "plan2.txt" ); }
void test3() { run_test( "plan3.txt" ); }
void test4() { run_test( "plan4.txt" ); }
void test5() { run_test( "plan5.txt" ); }
void test6() { run_test( "plan6.txt" ); }
void test7() { run_test( "plan7.txt" ); }
void test8() { run_test( "plan8.txt" ); }
void test9() { run_test( "plan9.txt" ); }

void (*pTests[])(void) = { 
    test0, test1, test2, test3, test4, test5, test6, 
    test7, test8, test9, 
    //  test10, test11, test12, test13, 
};


#include <cstdio> /* sscanf */
int main(int argc, char *argv[] ) {
    if (argc >1) {
        int test = 0;
        std::sscanf(argv[1],"%i",&test);
        try {
            pTests[test]();
        } catch( const char* msg) {
            std::cerr << msg << std::endl;
        }
    } else { // run all
        try {
            for (size_t i = 0; i<sizeof(pTests)/sizeof(pTests[0]); ++i) {
                pTests[i]();
            }
        } catch( const char* msg) {
            std::cerr << msg << std::endl;
        }
    }


    return 0;
}
