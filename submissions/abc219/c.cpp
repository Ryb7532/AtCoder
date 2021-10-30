#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  string X;
  int N;
  cin >> X >> N;
  map<char, char> new2old;
  rep(i,26) {
    new2old[X[i]] = 'a'+i;
  }
  vec<string> S(N);
  rep(i,N) {
    string T;
    cin >> T;
    int t = T.size();
    rep(j,t) {
      S[i].push_back(new2old[T[j]]);
    }
  }
  sort(all(S));
  rep(i,N) {
    string T;
    int s = S[i].size();
    rep(j,s) {
      T.push_back(X[S[i][j]-'a']);
    }
    print(T);
  }
  return 0;
}
