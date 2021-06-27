#include <bits/stdc++.h>
using namespace std;

int main() {
  int K;
  string S;
  cin >> K >> S;
  int len = S.size();
  if (len <= K)
    cout << S << endl;
  else {
    for (int i=0; i<K; i++)
      cout << S[i];
    cout << "..." << endl;
  }
  return 0;
}
