#include <iostream>
using namespace std;

//降順
int des(const void *a, const void *b)
{
  return *(int *)b - *(int *)a;
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i=0; i<n; i++)
    cin >> a[i];
  qsort(a, n, sizeof(int), des);
  long h = 0, w = 0, p = 0;
  for (int i=0; i<n; i++) {
    if (p != a[i]) {
      p = a[i];
      continue;
    }
    if (h == 0) {
      h = p;
      p = 0;
    } else {
      w = p;
      break;
    }
  }
  cout << h*w << '\n';
  return 0;
}