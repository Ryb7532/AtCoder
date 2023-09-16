#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl

// Task: Longest Palindromic Substring
// Manacher Algorithm (O(|S|))
vector<int> manacher(const string &s) {
  int l = s.size();
  vector<int> radius(l);
  int i=0, j=0;
  while(i < l) {
    while (i-j>=0 && i+j<l && s[i-j]==s[i+j])
      j++;
    radius[i] = j;
    int k = 1;
    while (i-k>=0 && i+k<l && k+radius[i-k]<j) {
      radius[i+k] = radius[i-k];
      k++;
    }
    i += k;
    j -= k;
  }
  return radius;
}


int main() {
  string S;
  cin >> S;
  string T = "#";
  for (auto c: S) {
    T.push_back(c);
    T.push_back('#');
  }
  auto vec = manacher(T);
  int res = 0;
  for(auto c: vec) {
    res = max(res, c-1);
  }
  print(res);
  return 0;
}