#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  int a[N], t = 0;
  for (int i=0; i<N; i++) {
    cin >> a[i];
    t = t^a[i];
  }
  for (int i=0; i<N; i++) {
    cout << (t^(a[i])) << " ";
  }
  cout << endl;
  return 0;
}
