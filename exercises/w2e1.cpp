#include <iostream>

using namespace std;

template <class summable>
summable sum (const summable *a, int size, summable s=0)
{
  for(int i = 0; i < size; i++)
  {
    s += a[i];
    cout << a[i] << '\t';
  }
  cout << endl;
  return s;
}

int main(int argc, char **argv)
{
  cout << "template for sum()" << endl;
  int a[] = {1, 2, 3};
  double b[] = {2.1, 2.2, 2.3};
  cout << sum(a, 3) << endl;
  cout << sum(b, 3) << endl;
}
