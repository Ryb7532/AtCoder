#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> A;
  int a;
  for (int i=0; i<N; i++) {
    cin >> a;
    A.push_back(a);
  }
  sort(A.begin(), A.end());
  int cnt = 0, p = 0;
  for (int i=0; i<N; i++) {
    if (p == A[i])
      cnt++;
    else
      p = A[i];
  }
  cout << N - (cnt+1)/2 * 2 << endl;
  return 0;
}