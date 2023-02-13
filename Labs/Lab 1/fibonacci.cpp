#include <ostream>
#include <iostream>
#include <cstdio>

void fibonacci(int max)
{
  int i;
  double fib1 = 0;
  double fib2 = 1;
  double fibNext;
  double fibQuo = 0;

  std::cout << "           Fibonacci        Fibonacci" << std::endl;
  std::cout << " N           number          quotient" << std::endl;
  std::cout << "-------------------------------------" << std::endl;

  for ( i = 0; i < max + 1; i++ )
  {
    if ( i == 0 )
    {
      fibNext = 0;
    }
    else if ( i == 1)
    {
      fibNext = 1;
    }
    else
    {
      fibNext = fib1 + fib2;
      fibQuo = fibNext / fib2;
      fib1 = fib2;
      fib2 = fibNext;
    }

    std::cout.width(2);
    std::cout << std::noshowpoint << i;

    std::cout.width(14);
    std::cout << std::noshowpoint << fibNext;
    if ( fibQuo == 0 )
    {
      std::cout.width(21);
      std::cout << "N/A" << std::endl;
    }
    else
    {
      std::cout.setf(std::ios_base::showpoint); 
      std::cout.precision(17);
      std::cout.width(21);
      std::cout << fibQuo << std::endl;
    }
  }  
}