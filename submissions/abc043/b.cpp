#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  string ans = "";
  for (auto c :s) {
    if (c == '0' || c == '1')
      ans.push_back(c);
    else if (!ans.empty())
      ans.pop_back();
  }
  cout << ans << endl;
  return 0;
}
