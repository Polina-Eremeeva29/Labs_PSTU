#include <iostream>
#include <string>

using namespace std;

int NOD (int a, int b)
{
    int c;
    if (a < b)
      {
        b -= a;
        a += b;
        b = a - b;
      }
    c = a % b;
    if (c == 0) return b;
    else NOD(b, c);
}
