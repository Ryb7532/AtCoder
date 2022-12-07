#include <bits/stdc++.h>
using namespace std;

//降順
int des(const void *a, const void *b)
{
  return *(int *)b - *(int *)a;
}

int main() {
  int N, K;
  cin >> N >> K;
  int l[N];
  for (int i=0; i<N; i++)
    cin >> l[i];
  qsort(l, N, sizeof(int), des);
  int ans = 0;
  for (int i=0; i<K; i++)
    ans += l[i];
  cout << ans << endl;
  return 0;
}
