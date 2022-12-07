#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


int main() {
  string A;
  cin >> A;
  int n = A.size();
  if (n>1)
    A.pop_back();
  else {
    if (A[0]-'a'>0)
      A[0] = A[0]-1;
    else {
      print(-1);
      return 0;
    }
  }
  print(A);
  return 0;
}
