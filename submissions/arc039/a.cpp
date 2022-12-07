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


int main() {
  string A,B;
  cin >> A >> B;
  if (A[0]=='9' && B[0]=='1') {
    rep1(i,2) {
      if (A[i]=='9' && B[i]=='0') {
        continue;
      } else if ('9'-A[i]>B[i]-'0') {
        A[i] = '9';
        break;
      } else {
        B[i] = '0';
        break;
      }
    }
  } else if ('9'-A[0]>B[0]-'1') {
    A[0] = '9';
  } else {
    B[0] = '1';
  }
  int a=0,b=0;
  rep(i,3) {
    a*=10; b*=10;
    a+=A[i]-'0'; b+=B[i]-'0';
  }
  print(a-b);
  return 0;
}
