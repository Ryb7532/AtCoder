#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, K, d;
  cin >> N >> K;
  bool D[10];
  fill(D, D+10, true);
  for (int i=0; i<K; i++) {
    cin >> d;
    D[d] = false;
  }
  int i;
  for (i=N; ;i++) {
    int m = i;
    while (m != 0) {
      if (!D[m%10])
        break;
      m /= 10;
    }
    if (m == 0)
      break;
  }
  cout << i << endl;
  return 0;
}