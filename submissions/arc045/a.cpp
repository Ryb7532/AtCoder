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
  string ans;
  while (1) {
    string s;
    cin >> s;
    if (!cin.good()) break;
    if (s == "Left")
      ans.push_back('<');
    else if (s == "Right")
      ans.push_back('>');
    else
      ans.push_back('A');
    ans.push_back(' ');
  }
  ans.pop_back();
  print(ans);
  return 0;
}
