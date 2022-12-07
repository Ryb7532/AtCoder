#include <bits/stdc++.h>
using namespace std;

//降順
int des(const void *a, const void *b)
{
  return *(long *)b - *(long *)a;
}

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  long h[N];
  for (int i=0; i<N; i++)
    cin >> h[i];
  qsort(h, N, sizeof(long), des);
  long b = 0, t = 1000000000;
  while (t-b > 1) {
    long m = (t+b)/2, cnt = 0;
    for (int i=0; i<N; i++) {
      if (h[i]-m*B<=0)
        continue;
      cnt += (h[i]-m*B-1)/(A-B)+1;
    }
    if (cnt <= m)
      t = m;
    else
      b = m;
  }
  cout << t << endl;
  return 0;
}