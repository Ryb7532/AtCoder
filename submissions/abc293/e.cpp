#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


// Matrix
template< typename T >
struct Matrix {
  vector<vector<T>> A;
  Matrix(size_t n, size_t m): A(n,vector<T>(m,0)) {};
  Matrix(size_t n): A(n,vector<T>(n,0)) {};
  size_t height() const { return (A.size()); }
  size_t width() const { return (A[0].size()); }
  inline const vector< T > &operator[](int k) const { return A.at(k); }
  inline vector< T > &operator[](int k) { return A.at(k); }
  static Matrix I(size_t n) {
    Matrix mat(n);
    for(int i=0; i<n; i++) mat[i][i] = 1;
    return mat;
  }
  Matrix &operator+=(const Matrix &B) {
    size_t n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        (*this)[i][j] += B[i][j];
    return *this;
  }
  Matrix &operator-=(const Matrix &B) {
    size_t n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        (*this)[i][j] -= B[i][j];
    return *this;
  }
  Matrix &operator*=(const Matrix &B) {
    size_t n = height(), m = B.width(), p = width();
    assert(p == B.height());
    vector<vector< T >> C(n, vector< T >(m,0));
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        for(int k=0; k<p; k++)
          C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
    A.swap(C);
    return *this;
  }
  Matrix &operator^=(long long k) {
    Matrix B = Matrix::I(height());
    while(k > 0) {
      if(k & 1) B *= *this;
      *this *= *this;
      k >>= 1LL;
    }
    A.swap(B.A);
    return *this;
  }
  Matrix operator+(const Matrix &B) const { return Matrix(*this)+=B; }
  Matrix operator-(const Matrix &B) const { return Matrix(*this)-=B; }
  Matrix operator*(const Matrix &B) const { return Matrix(*this)*=B; }
  Matrix operator^(const long long k) const { return Matrix(*this) ^= k; }
  friend ostream &operator<<(ostream &os, Matrix &p) {
    size_t n = p.height(), m = p.width();
    for(int i=0; i<n; i++) {
      os << "[";
      for(int j=0; j<m; j++)
        os << p[i][j] << (j+1 == m ? "]\n" : ",");
    }
    return os;
  }
  T determinant() {
    Matrix B(*this);
    assert(width() == height());
    T ret = 1;
    for(int i=0; i<width(); i++) {
      int idx = -1;
      for(int j=i; j<width(); j++) {
        if(B[j][i]!=0) idx = j;
      }
      if(idx==-1) return (0);
      if(i!=idx) {
        ret *= -1;
        swap(B[i], B[idx]);
      }
      ret *= B[i][i];
      T vv = B[i][i];
      for(int j=0; j<width(); j++) {
        B[i][j] /= vv;
      }
      for(int j=i+1; j<width(); j++) {
        T a = B[j][i];
        for(int k=0; k<width(); k++) {
          B[j][k] -= B[i][k] * a;
        }
      }
    }
    return (ret);
  }
};


ll mod;
struct mint {
  ll x;
  mint(ll x=0) : x((x%mod+mod)%mod) {}
  mint &operator+=(const mint &p) { if((x += p.x) >= mod) x -= mod; return *this; }
  mint &operator-=(const mint &p) { if((x += mod - p.x) >= mod) x -= mod; return *this; }
  mint &operator*=(const mint &p) { x = x * p.x % mod; return *this; }
  mint &operator/=(const mint &p) { *this *= p.inverse(); return *this; }
  mint operator-() const { return mint(-x); }
  mint operator+(const mint &p) const { return mint(*this) += p; }
  friend mint operator+(const int &c,const mint &p) { return mint(c) += p; }
  mint operator-(const mint &p) const { return mint(*this) -= p; }
  friend mint operator-(const int &c,const mint &p) { return mint(c) -= p; }
  mint operator*(const mint &p) const { return mint(*this) *= p; }
  friend mint operator*(const int &c,const mint &p) { return mint(c) *= p; }
  mint operator/(const mint &p) const { return mint(*this) /= p; }
  friend mint operator/(const int &c,const mint &p) { return mint(c) /= p; }
  bool operator==(const mint &p) const { return x == p.x; }
  friend bool operator==(const int &c,const mint &p) { return mint(c) == p; }
  bool operator!=(const mint &p) const { return x != p.x; }
  friend bool operator!=(const int &c, const mint &p) { return mint(c) != p; }
  mint inverse() const {
    ll a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return mint(u);
  }
  mint pow(ll n) const {
    mint ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os,const mint &p) { return os << p.x; }
  friend istream &operator>>(istream &is,mint &a) {
    ll t;
    is >> t;
    a = mint(t);
    return (is);
  }
};


int main() {
  ll A,X;
  cin >> A >> X >> mod;
  Matrix<mint> P(2,2);
  P[0][0] = A;
  P[0][1] = 1;
  P[1][1] = 1;
  P ^= X;
  print(P[0][1]);
  return 0;
}
