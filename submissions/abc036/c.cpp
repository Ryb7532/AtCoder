#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  int a[N], b = 0;
  set<int> A;
  map<int, int> m;
  for (int i=0; i<N; i++) {
    cin >> a[i];
    A.insert(a[i]);
  }
  while (!A.empty()){
    int t = *A.begin();
    m.insert({t, b});
    A.erase(t);
    b++;
  }
  for (int i=0; i<N; i++)
    cout << m.at(a[i]) << endl;
  return 0;
}
