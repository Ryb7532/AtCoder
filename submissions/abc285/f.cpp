#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"
#define printYorN(f) cout << (f ? Yes : No) << endl


// Task: Subset Sum Problem
// Binary Indexed Tree (Point Update and Range Query)
template<typename T>
struct BIT {
  int n;
  vector<T> dat;
  BIT(int n) : n(n), dat(n+1,0){}
  void add(int i,T x) {
    for (++i; i<=n; i+=(i&-i)) dat[i] += x;
  }
  T sum(int i) {
    T res = 0;
    for (++i; i>0; i-=(i&-i))
      res += dat[i];
    return res;
  }
  T range_sum(int l,int r) { // [l,r)
    return sum(r-1)-sum(l-1);
  }
}; // 0-indexed


int main() {
  int N,Q;
  string S;
  cin >> N >> S >> Q;
  vector<int> A(N);
  vector<BIT<int>> charPos(26, BIT<int>(N));
  vector<int> cnt(26,0);
  rep(i,N) {
    int n = S[i]-'a';
    A[i] = n;
    charPos[n].add(i,1);
    cnt[n]++;
  }
  rep(_,Q) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      char c;
      cin >> x >> c;
      x--;
      int n = c-'a';
      int a = A[x];
      charPos[a].add(x,-1);
      cnt[a]--;
      charPos[n].add(x,1);
      cnt[n]++;
      A[x] = n;
    } else {
      int l,r;
      cin >> l >> r;
      l--;
      int n = A[l];
      bool flag = false;
      int inlr = charPos[n].range_sum(l,r);
      if (inlr == charPos[n].range_sum(l,l+inlr)) {
        flag = true;
        n++;
        l += inlr;
      }
      while (flag && n < 26 && l < r) {
        if (cnt[n] == 0) {
          n++;
          continue;
        }
        inlr = charPos[n].range_sum(l,r);
        if (charPos[n].range_sum(l,l+inlr) != inlr) {
          flag = false;
        }
        l += inlr;
        if (l < r && cnt[n] != inlr) {
          flag = false;
        }
        n++;
      }
      if (n >= 26 && l != r)
        flag = false;
      printYorN(flag);
    }
  }
  return 0;
}
