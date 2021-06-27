#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()

int main() {
  int N;
  cin >> N;
  set<int> A;
  int a;
  rep(i, N) {
    cin >> a;
    while (a%2 == 0)
      a /= 2;
    A.insert(a);
  }
  print(A.size());
  return 0;
}
