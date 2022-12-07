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
  vector<int> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  int id = 0;
  vector<int> res;
  while(id<N-1 && A[id]<=A[id+1]) {
    id++;
  }
  stringstream ss;
  rep(i,N) {
    if (A[i]==A[id])
      continue;
    ss << A[i] << ' ';
  }
  string str = ss.str();
  if (!str.empty())
    str.pop_back();
  print(str);
  return 0;
}
