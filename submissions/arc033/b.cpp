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
  int Na,Nb;
  cin >> Na >> Nb;
  set<string> A,And,Or;
  rep(i,Na) {
    string a;
    cin >> a;
    A.insert(a);
    Or.insert(a);
  }
  rep(i,Nb) {
    string b;
    cin >> b;
    if (A.find(b) != A.end())
      And.insert(b);
    Or.insert(b);
  }
  ld size1,size2;
  size1 = And.size();
  size2 = Or.size();
  printf("%.10Lf\n",size1/size2);
  return 0;
}
