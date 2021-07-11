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

vec<string> S(3);
vec<char> used_alpha;
vec<bool> used_num(10,false);
map<char, int> alpha2num;
vec<ll> res(3,-1);
int cnt = 0;

void dfs(int n) {
  if (n == cnt) {
    vec<ll> N(3,0);
    bool check=true;
    rep(i,3)
      if (alpha2num[S[i][0]]==0)
        check = false;
    if (!check)
      return;
    rep(i,3) {
      for (auto &c: S[i]) {
        N[i]*=10;
        N[i]+=alpha2num[c];
      }
    }
    if (N[0]!=0 && N[1]!=0 && N[0]+N[1]==N[2])
      res=N;
    return;
  }
  for (int i=0; i<10; i++) {
    if (used_num[i])
      continue;
    char c = used_alpha[n];
    alpha2num[c] = i;
    used_num[i] = true;
    dfs(n+1);
    used_num[i] = false;
  }
  return;
}

int main() {
  rep(i,3)
    cin >> S[i];
  vec<int> alpha(26,0);
  rep(i,3) {
    for (auto &c: S[i]) {
      if (alpha[c-'a']==0)
        used_alpha.push_back(c);
      alpha[c-'a']++;
    }
  }
  cnt = used_alpha.size();
  if (cnt > 10) {
    print("UNSOLVABLE");
    return 0;
  }
  dfs(0);
  if (res[0]==-1)
    print("UNSOLVABLE");
  else {
    rep(i,3) {
      print(res[i]);
    }
  }
  return 0;
}
