#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep1(n) rep2(_,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define out1(a) cout << (a) << endl
#define out2(a,b) cout << (a) << " " << (b) << endl
#define out3(a,b,c) cout << (a) << " " << (b) << " " << (c) << endl
#define print(...) GET_MACRO(__VA_ARGS__,out3,out2,out1)(__VA_ARGS__)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyn(f) cout << (f ? Yes : No) << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}

// Task: Range Maximum(Minimum) Query
// Segment Tree
template < typename Monoid >
class RMQ {
  // Binary-op in Monoid
  using F = function<Monoid(Monoid, Monoid)>;
  int sz;
  vector<Monoid> data;
  const F f;
  // identity element of Monoid
  const Monoid M1;

  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while(a<sz) {
      Monoid nxt = type ? f(data[2*a+type], M) : f(M, data[2*a+type]);
      if(check(nxt)) a = 2*a+type;
      else M = nxt, a = 2*a+1-type;
    }
    return a - sz;
  }

public:
  RMQ(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz<n) sz <<= 1;
    data.assign(2*sz, M1);
  }
  // let k-th element as x
  void set(int k, const Monoid &x) {
    data[k+sz] = x;
  }
  // build the segment tree
  void build() {
    for(int k=sz-1; k>0; k--) {
      data[k] = f(data[2*k], data[2*k+1]);
    }
  }
  // update k-th element to x
  void update(int k, const Monoid &x) {
    k += sz;
    data[k] = x;
    while(k>>=1) {
      data[k] = f(data[2*k], data[2*k+1]);
    }
  }
  // calculete f in [a,b)
  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, data[a++]);
      if(b & 1) R = f(data[--b], R);
    }
    return f(L, R);
  }
  // get value of k-th (0<=k<sz)
  Monoid operator[](const int &k) const {
    return data[k+sz];
  }
  // return minimum x such that satisfy check in [a,x)
  template< typename C >
  int find_first(int a, const C &check) {
    Monoid L = M1;
    if(a <= 0) {
      if(check(f(L, data[1]))) return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        Monoid nxt = f(L, data[a]);
        if(check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }
  // return maximum x such that satisfy check in [x,b)
  template< typename C >
  int find_last(int b, const C &check) {
    Monoid R = M1;
    if(b >= sz) {
      if(check(f(data[1], R))) return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        Monoid nxt = f(data[--b], R);
        if(check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};

// Task: Suffix Array
// Suffix Array Induced Sorting
class SuffixArrayIS {
  int N;
  int *S, *bkt, *sa, *lcp, *rank;
  RMQ<int> rmq;

  inline void bucket(int *data, int n, int num_bkt) {
    bkt = new int[num_bkt];
    rep(i,num_bkt) bkt[i] = 0;
    rep(i,n) bkt[data[i]]++;
    rep(i,num_bkt-1) bkt[i+1] += bkt[i];
  }
  inline void induced_sort(int *arr, int *data, int n, int num_bkt, bool *stype) {
    bucket(data, n, num_bkt);
    rep(i,n) {
      int j = arr[i] - 1;
			if (j >= 0 && !stype[j]) arr[bkt[data[j]-1]++] = j;
    }
    bucket(data, n, num_bkt);
    rrep(i,n) {
      int j = arr[i] - 1;
      if (j >= 0 && stype[j]) arr[--bkt[data[j]]] = j;
    }
  }
  inline bool is_LMS(int i, int n, bool *stype) {
    if (i == 0)
      return false;
    return stype[i] && !stype[i-1];
  }
  void buildSA(int *arr, int *data, int n, int num_bkt) {
    rep(i,n)
      arr[i] = -1;
    if (n == 1) {
      arr[0] = 0;
      return ;
    }
    bool Stype[n];
    Stype[n-1] = true;
    rrep(i,n-1)
      Stype[i] = (data[i] < data[i+1] || (data[i] == data[i+1] && Stype[i+1]));
    bucket(data, n, num_bkt);
    rep(i,n)
      if (is_LMS(i,n,Stype)) arr[--bkt[data[i]]] = i;
    induced_sort(arr, data, n, num_bkt, Stype);

    int N_ = 0;
    rep(i,n) if (is_LMS(arr[i],n,Stype)) arr[N_++] = arr[i];

    rep(i,N_,n)
      arr[i] = -1;
    arr[N_+arr[0]/2] = 0;
    rep(i,1,N_) {
      int prev = arr[i-1], curr = arr[i];
      bool diff = (i == 1 || data[prev] != data[curr]);
      for (int j=1; !diff; j++) {
        if (data[prev+j] != data[curr+j]) diff = true;
        if (!is_LMS(prev+j,n,Stype) && !is_LMS(curr+j,n,Stype)) continue;
        if (!(is_LMS(prev+j,n,Stype) && is_LMS(curr+j,n,Stype))) diff = true;
        break;
      }
      if (diff)
        arr[N_+curr/2] = arr[N_+prev/2]+1; // N_ <= N/2 and LCMs are not continuous
      else
        arr[N_+curr/2] = arr[N_+prev/2];
    }

    int label = arr[N_+arr[N_-1]/2]+1;
    int r = n;
    rrep(i,N_,n)
      if (arr[i] != -1) arr[--r] = arr[i]; // Rearrange the original array to right
    if (N_ != label) {
      buildSA(arr, arr+n-N_, N_, label);

      rep(i,N_)
        arr[r+arr[i]] = i;
      int l = 0;
      rep(i,n)
        if (is_LMS(i,n,Stype)) arr[arr[r+l++]] = i;
    }

    rep(i,N_,n)
      arr[i] = -1;
    bucket(data, n, num_bkt);
    rrep(i,N_)
      swap(arr[--bkt[data[arr[i]]]], arr[i]);
    induced_sort(arr, data, n, num_bkt, Stype);
  }
  void buildLCP() {
    rank = new int[N];
    lcp = new int[N-1];
    rep(i,N) rank[sa[i]] = i;
    int h = 0;
    rep(i,N-1) {
      int j = sa[rank[i]-1];
      if (h > 0) h--;
      while (j+h < N && i+h < N && S[j+h] == S[i+h]) h++;
      lcp[rank[i]-1] = h;
    }
  }
  void buildRMQ() {
    rep(i,N-1) rmq.set(i, lcp[i]);
    rmq.build();
  }

public:
  SuffixArrayIS(const string &s)
    : N(s.size()+1), rmq(N-1, [](int a, int b){return min(a,b);}, 1e9)
  {
    S = new int[N];
    sa = new int[N];
    rep(i,N-1) {
      S[i] = (int)(s[i]);
    }
    S[N-1] = 0;
    int NB = 256;
    buildSA(sa, S, N, NB);
    buildLCP();
    buildRMQ();
  }
  SuffixArrayIS(const vector<int> &v)
    : N(v.size()+1), rmq(N-1, [](int a, int b){return min(a,b);}, 1e9)
  {
    S = new int[N];
    sa = new int[N];
    int m = INT_MAX, M = INT_MIN;
    rep(i,N-1) {
      S[i] = v[i];
      m = min(m,v[i]);
      M = max(M,v[i]);
    }
    S[N-1] = --m;
    int NB = M-m+1;
    buildSA(sa, S, N, NB);
    buildLCP();
    buildRMQ();
  }
  int common_prefix(int a, int b) {
    if (a == b) return N-1-a;
    if (b >= N-1) return 0;
    if (rank[a] > rank[b]) swap(a,b);
    return rmq.query(rank[a], rank[b]);
  }
  inline int &operator[](int id) { return sa[id+1]; };
};


int main() {
  string S;
  cin >> S;
  SuffixArrayIS SA(S);
  int N = S.size();
  int Q;
  cin >> Q;
  rep(i,Q) {
    string T;
    cin >> T;
    string U = T;
    U.push_back('~');
    int t = T.size();
    int ll = -1, lr = N, rl = -1, rr = N;
    while (lr-ll > 1) {
      int m = (lr+ll)/2;
      bool flag = true;
      int s = SA[m];
      rep(i,t) {
        if (i+s >= N || S[i+s] < T[i])
          flag = false;
        if (S[i+s] > T[i])
          break;
        if (!flag)
          break;
      }
      if (flag)
        lr = m;
      else
        ll = m;
    }
    while (rr-rl > 1) {
      int m = (rr+rl)/2;
      bool flag = true;
      int s = SA[m];
      rep(i,t+1) {
        if (i+s >= N || S[i+s] < U[i])
          break;
        if (S[i+s] > U[i])
          flag = false;
        if (!flag)
          break;
      }
      if (flag)
        rl = m;
      else
        rr = m;
    }
    print(rr-lr);
  }
  return 0;
}