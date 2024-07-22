#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep1(n) rep2(_,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyn(f) cout << ((f) ? Yes : No) << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}
void print() {cout << endl;}
template<typename Arg, typename... Args> void print(const Arg a, const Args... b) {
  cout << a;
  (cout << ... << (cout << ' ', b)) << endl;
}

vector<string> st;
map<ll, string> memo;
string formatting(string s) {
  int l = st.size();
  string res;
  rep(i,l) {
    res += st[i];
    res += "*";
  }
  string tmp = res;
  reverse(all(tmp));
  res += s;
  res += tmp;
  return res;
}

string dfs(ll n) {
  if (memo.find(n) != memo.end())
    return memo[n];
  {
    bool f = true;
    string s = to_string(n);
    int l = s.size();
    rep(i,l) {
      if (s[i] == '0' || s[i] != s[l-i-1])
        f = false;
    }
    if (f) {
      return memo[n] = formatting(s);
    }
  }
  string res = "";
  for (ll i=2; i*i <= n; i++) {
    if (n%i)
      continue;
    string si = to_string(i);
    bool f = true;
    fore(c,si) if (c == '0') f = false;
    if (!f)
      continue;
    string sj = si;
    reverse(all(sj));
    ll j = stoll(sj);
    if (n/i%j)
      continue;
    st.push_back(si);
    memo[n] = dfs(n/i/j);
    st.pop_back();
    if (memo[n].size() != 0)
      res = memo[n];
  }
  return res;
}

int main() {
  ll N;
  cin >> N;
  string res = dfs(N);
  if (res == "")
    res = "-1";
  print(res);
  return 0;
}