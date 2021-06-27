#include <bits/stdc++.h>
using namespace std;

int main() {
  string A, B, C;
  cin >> A >> B >> C;
  int alen = A.size(), blen = B.size();
  if (A[alen-1] == B[0] && B[blen-1] == C[0])
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
