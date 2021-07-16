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


int main() {
  int N;
  cin >> N;
  int A,B;
  int maxA=0,minB=1000;
  rep(i,N) {
    cin >> A;
    maxA = max(A,maxA);
  }
  rep(i,N) {
    cin >> B;
    minB = min(B,minB);
  }
  print(max(minB-maxA+1,0));
  return 0;
}
