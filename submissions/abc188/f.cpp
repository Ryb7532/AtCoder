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

long X,Y;

map<long,long> memo;
long solve(long a) {
  if (a == 1) {
    memo[a] = abs(X-1);
    return memo[a];
  } else if (a%2) {
    if (memo.find((a+1)/2) == memo.end())
      memo[(a+1)/2] = solve((a+1)/2);
    if (memo.find((a-1)/2) == memo.end())
      memo[(a-1)/2] = solve((a-1)/2);
    memo[a] = min(abs(X-a), min(memo[(a+1)/2], memo[(a-1)/2])+2);
    return memo[a];
  } else {
    if (memo.find(a/2) == memo.end())
      memo[a/2] = solve(a/2);
    memo[a] = min(abs(X-a), memo[a/2]+1);
    return memo[a];
  }
}


int main() {
  cin >> X >> Y;
  print(solve(Y));
  return 0;
}
