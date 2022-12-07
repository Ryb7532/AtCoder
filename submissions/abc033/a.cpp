#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,s,n) for(int i=s, i<n; i++)
#define rep1(i,n) for(int i=1; i<=n; i++)
#define print(a) cout<<a<< endl;

int main() {
  string N;
  cin >> N;
  int n[4];
  rep(i, 4)
    n[i] = N[i] - '0';
  rep1(i, 3)
    if (n[i] != n[i-1]){
      print("DIFFERENT");
      return 0;
    }
  print("SAME");
  return 0;
}
