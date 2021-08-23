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
  int N;
  string S,T,fox="fox";
  cin >> N >> S;
  rep(i,N) {
    T.push_back(S[i]);
    int size = T.size();
    if (size>=3 && T.substr(size-3) == fox)
      T = T.substr(0,size-3);
  }
  print(T.size());
  return 0;
}
