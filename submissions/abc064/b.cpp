#include <bits/stdc++.h>
using namespace std;

//昇順
int acs(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}

int main() {
  int N;
  cin >> N;
  int a[N];
  for (int i=0; i<N; i++)
    cin >> a[i];
  qsort(a, N, sizeof(int), acs);
  cout << a[N-1]-a[0] << endl;
  return 0;
}
