#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, K;
  cin >> A >> B >> C >>K;
  if (A+B<K)
    cout << 2*A+B-K << endl;
  else
    cout << min(K, A) << endl;
  return 0;
}
