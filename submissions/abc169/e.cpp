#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a, b;
  cin >> N;
  vector<int> A, B;
  for (int i=0; i<N; i++) {
    cin >> a >> b;
    A.push_back(a);
    B.push_back(b);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  if (N%2 == 1) {
    cout << B[(N-1)/2] - A[(N-1)/2] + 1 << endl;
    return 0;
  }
  int l = A[N/2] + A[N/2-1], r = B[N/2] + B[N/2-1];
  cout << r-l+1 << endl;
  return 0;
}
