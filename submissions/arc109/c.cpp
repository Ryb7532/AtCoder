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

map<char,int> s2num = {{'R',0}, {'P',1}, {'S',2}};

int main() {
  int n,k;
  string S;
  cin >> n >> k >> S;
  vec<int> s(n);
  rep(i,n) {
    s[i] = s2num[S[i]];
  }
  rep(_,k) {
    vec<int> t;
    rep(i,n) {
      int a,b;
      a = s[(2*i)%n];
      b = s[(2*i+1)%n];
      if ((a-b+3)%3 == 1)
        t.push_back(a);
      else
        t.push_back(b);
    }
    s = t;
  }
  if (s[0]==0)
    print('R');
  if (s[0]==1)
    print('P');
  if (s[0]==2)
    print('S');
  return 0;
}
