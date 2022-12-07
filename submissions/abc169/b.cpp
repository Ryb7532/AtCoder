#include <bits/stdc++.h>
using namespace std;
#define LIM 1000000000000000000

int main() {
  int N;
  cin >> N;
  long long A[N], pro = 1;
  int zero = 0;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    if (A[i] == 0)
      zero++;
  }
  if (zero > 0) {
    cout << 0 << endl;
    return 0;
  }
  for (int i=0; i<N; i++) {
    if (A[i] > LIM/pro) {
      cout << -1 << endl;
      return 0;
    }
    pro *= A[i];
  }
  if (pro > LIM)
    pro = -1;
  cout << pro << endl;
  return 0;
}
