#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())

pii toInt(string T) {
  int s=0,e=0;
  rep(i,4) {
    s*=10;
    s+=T[i]-'0';
  }
  reps(i,5,9) {
    e*=10;
    e+=T[i]-'0';
  }
  s = s/100*60 + s%100;
  e = e/100*60 + e%100;
  if (s%5)
    s-=s%5;
  if (e%5)
    e+=5-e%5;
  return make_pair(s,e);
}

string toString(pii p) {
  string res;
  int f = p.first,s = p.second;
  int h = f/60,m = f%60;
  res.push_back('0'+h/10);
  res.push_back('0'+h%10);
  res.push_back('0'+m/10);
  res.push_back('0'+m%10);
  res.push_back('-');
  h = s/60,m = s%60;
  res.push_back('0'+h/10);
  res.push_back('0'+h%10);
  res.push_back('0'+m/10);
  res.push_back('0'+m%10);
  return res;
}

int main() {
  int N;
  cin >> N;
  vector<pii> T;
  rep(i,N) {
    string S;
    cin >> S;
    T.push_back(toInt(S));
  }
  sort(all(T));
  T.push_back({2000,2000});
  vector<string> ans;
  int s = T[0].first, e = T[0].second;
  rep1(i,N) {
    if (T[i].first<=e) {
      e = max(e,T[i].second);
    } else {
      ans.push_back(toString({s,e}));
      s = T[i].first;
      e = T[i].second;
    }
  }
  int n = ans.size();
  rep(i,n) {
    print(ans[i]);
  }
  return 0;
}
