#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N;
  cin >> N;
  string S,T;
  cin >> S >> T;
  vector<int> sone, tone;
  ll res = 0;
  rep(i,N) {
    if (S[i]=='1')
      sone.push_back(i);
    if (T[i]=='1')
      tone.push_back(i);
  }
  int ls=sone.size(), lt=tone.size();
  int i=0;
  rep(j,lt) {
    while(i<ls-1 && sone[i]<tone[j]) {
      res += sone[i+1] - sone[i];
      i += 2;
    }
    if (i>=ls || sone[i]<tone[j]) {
      res = -1;
      break;
    }
    res += sone[i]-tone[j];
    i++;
  }
  while (i<ls-1) {
    res += sone[i+1]-sone[i];
    i += 2;
  }
  if (i!=ls)
    res = -1;
  print(res);
  return 0;
}
