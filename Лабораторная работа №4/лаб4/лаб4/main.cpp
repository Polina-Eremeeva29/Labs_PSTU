#include <iostream>
#include <cmath>
using namespace std;
int n;
int main()
{
setlocale(LC_ALL, "rus");
cin >> n;
void** A = new void*[2];
A[0] = new float[n];
A[1] = new int[n];
for (int j = 0; j < n; j++)

{
cin >> ((int*)A[0])[j] >> ((float*)A[1])[j];
cout << ((int*)A[0])[j] <<  "\t" <<

((float*)A[1])[j]<<endl;
}
}
