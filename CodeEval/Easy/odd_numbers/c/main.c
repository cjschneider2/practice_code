#include <stdio.h>

int main (void)
{
   const int MIN = 1;
   const int MAX = 99;

   for (int itr = MIN; itr <= MAX; itr++)
   {
      if (itr%2)
         printf ("%d\n", itr);
   }
   return 0;
}
