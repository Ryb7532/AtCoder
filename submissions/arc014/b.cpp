#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << a << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


int main() {
  int N;
  cin >> N;
  map<string,int> W;
  string p;
  cin >> p;
  W[p]++;
  rep1(i,N-1) {
    string w;
    cin >> w;
    if (W[w] != 0 || p.back() != w.front()) {
      print((i%2?"WIN":"LOSE"));
      return 0;
    }
    W[w]++;
    p.assign(w);
  }
  print("DRAW");
  return 0;
}
