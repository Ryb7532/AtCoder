#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()

int main() {
  int a, b, c;
  vector<int> A;
  cin >> a >> b >> c;
  A.push_back(a);
  A.push_back(b);
  A.push_back(c);
  sort(all(A));
  print(A[1]);
  return 0;
}
