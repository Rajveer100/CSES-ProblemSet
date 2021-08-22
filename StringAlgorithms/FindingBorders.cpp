//
//  main.cpp
//  CPWorkSpace
//
//  Created by Rajveer Singh on 21/01/22.
//

#include <algorithm>
#include <array>
#include <chrono>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// MARK:- PRACTICE

#define len(a) (ll) a.size()
typedef long long ll;
typedef long double ld;

constexpr bool test = false;
constexpr ll mod1 = 1e9 + 7;
constexpr ll mod2 = 998244353;
constexpr ll inf = 1e18 + 5;
constexpr ll lim = 1e6 + 5;

template <ll mod> class Modular {

public:
  ll val;

  Modular(ll x = 0) {

    val = x % mod;

    if (val < 0)
      val += mod;
  }

  Modular &operator+=(const Modular &x) {

    if ((val += x.val) >= mod)
      val -= mod;

    return *this;
  }

  Modular &operator-=(const Modular &x) {

    if ((val -= x.val) < 0)
      val += mod;

    return *this;
  }

  Modular &operator*=(const Modular &x) {

    val = (val * x.val) % mod;

    return *this;
  }

  Modular &operator/=(const Modular &x) {

    ll a = 0, b = 1, c = x.val;
    ll m = mod;

    while (c != 0) {

      ll t = m / c;
      m -= (t * c);

      std::swap(c, m);

      a -= (t * b);

      std::swap(a, b);
    }

    a %= mod;

    if (a < 0)
      a += mod;
    val = (val * a) % mod;

    return *this;
  }

  friend Modular operator+(const Modular &l, const Modular &r) {

    return Modular(l) += r;
  }

  friend Modular operator-(const Modular &l, const Modular &r) {

    return Modular(l) -= r;
  }

  friend Modular operator*(const Modular &l, const Modular &r) {

    return Modular(l) *= r;
  }

  friend Modular operator/(const Modular &l, const Modular &r) {

    return Modular(l) /= r;
  }

  Modular &operator++() { return *this += 1; }

  Modular &operator--() { return *this -= 1; }

  Modular operator++(int) {

    Modular z(*this);
    *this += 1;

    return z;
  }

  Modular operator--(int) {

    Modular z(*this);
    *this -= 1;

    return z;
  }

  Modular operator-() const { return Modular(-val); }

  bool operator==(const Modular &r) const { return val == r.val; }

  bool operator!=(const Modular &r) const { return val != r.val; }

  bool operator<(const Modular &r) const { return val < r.val; }

  bool operator>(const Modular &r) const { return val > r.val; }
};

template <ll mod> std::string to_string(const Modular<mod> &x) {

  return std::to_string(x.val);
}

template <ll mod>
std::ostream &operator<<(std::ostream &stream, const Modular<mod> x) {

  return stream << x.val;
}

template <ll mod>
std::istream &operator>>(std::istream &stream, Modular<mod> &x) {

  stream >> x.val;
  x.val %= mod;

  if (x.val < 0)
    x.val += mod;

  return stream;
}

using mint = Modular<mod1>;

std::vector<mint> p29(lim);

void preCalc() {

  p29[0] = 1;

  for (int i = 1; i <= lim - 1; i++) {

    p29[i] = p29[i - 1] * 29;
  }
}

void testCase() {

  std::string s;
  std::cin >> s;

  std::vector<mint> hash(len(s));
  hash[0] = mint(s[0] - 'a' + 1);

  for (int i = 1; i <= len(s) - 1; i++) {

    hash[i] = hash[i - 1] + p29[i] * mint(s[i] - 'a' + 1);
  }

  for (int i = 1; i <= len(s) - 1; i++) {

    mint suffHash = (hash[len(s) - 1] - hash[len(s) - 1 - i]) / p29[len(s) - i];

    if (hash[i - 1] == suffHash)
      std::cout << i << ' ';
  }

  std::cout << '\n';
}

int main() {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.precision(20);

  preCalc();

  ll t = 1;

  if (test) {

    std::cin >> t;
  }

  for (int i = 0; i <= t - 1; i++) {

    //        std::cout << "Case #" << i + 1 << ": ";
    testCase();
  }
}
