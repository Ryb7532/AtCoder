#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  string S;
  cin >> S;
  int n = S.size();
  rep(i,n) {
    if (S[i] == 'B')
      S[i] = '8';
    else if (S[i] == 'S')
      S[i] = '5';
    else if (S[i] == 'Z')
      S[i] = '2';
    else if (S[i] == 'I')
      S[i] = '1';
    else if (S[i] == 'O' || S[i] == 'D')
      S[i] = '0';
  }
  print(S);
  return 0;
}
