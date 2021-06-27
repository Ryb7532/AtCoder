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

vec<int> a = {-1,1,1,2,-1,4,9,8,-1,3,8,5,7,9,-1,7,4,0,6,3,-1,5,2,6,-1,0};

int main() {
  int N;
  cin >> N;
  string ans;
  rep(i,N) {
    string w;
    cin >> w;
    rep(j,(int)w.size()) {
      int id = w[j] -'A';
      if (id>=0 && id<26 && a[id] != -1)
         ans.push_back('0'+a[id]);
      id += 'A'-'a';
      if (id>=0 && id<26 && a[id] != -1)
        ans.push_back('0'+a[id]);
    }
    if (ans.empty() || ans.back()==' ')
      continue;
    ans.push_back(' ');
  }
  if (!ans.empty())
    ans.pop_back();
  print(ans);
  return 0;
}
