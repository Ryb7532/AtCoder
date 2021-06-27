#include <bits/stdc++.h>
using namespace std;
using Ele = struct{
  int a;
  long b;
};

//昇順
int acs(const void *x, const void *y)
{
  return ((Ele *)x)->a - ((Ele *)y)->a;
}

int main() {
  long N, K;
  cin >> N >> K;
  Ele a[N];
  for (int i=0; i<N; i++)
    cin >> a[i].a >> a[i].b;
  qsort(a, N, sizeof(Ele), acs);
  long cnt = 0;
  int i;
  for (i=0; i<N; i++) {
    cnt += a[i].b;
    if (cnt >= K)
      break;
  }
  cout << a[i].a << endl;
  return 0;
}
