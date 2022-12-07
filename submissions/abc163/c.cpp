#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int cnt[200000] = {}, a;
  for (int i=1; i<n; i++) {
    cin >> a;
    cnt[--a]++;
  }
  for (int i=0; i<n; i++)
    cout << cnt[i] << endl;
  return 0;
}
