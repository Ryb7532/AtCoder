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
  int s[N], sum = 0;
  for (int i=0; i<N; i++) {
    cin >> s[i];
    sum += s[i];
  }
  qsort(s, N, sizeof(int), acs);
  if (sum%10) {
    cout << sum << endl;
    return 0;
  }
  for (int i=0; i<N; i++) {
    if ((sum-s[i])%10) {
      cout << sum-s[i] << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}