//
//  main.cpp
//  main2
//
//  Created by Rajveer Singh on 23/09/21.
//

#include <algorithm>
#include <array>
#include <chrono>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
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

bool test = false;
ll mod1 = 1e9 + 7;
ll mod2 = 998244353;
ll inf = 1e10 + 5;

void testCase() {

  ll n;

  std::cin >> n;

  ll s = 0;

  for (ll i = 1; i <= n; i = n / (n / i) + 1) {

    ll k = n / (n / i);

    ll l = (((i % mod1) * ((i - 1) % mod1)) % mod1 * 500000004) % mod1;
    ll r = (((k % mod1) * ((k + 1) % mod1)) % mod1 * 500000004) % mod1;

    s = (s + (n / i) % mod1 * ((r - l + mod1) % mod1)) % mod1;
  }

  std::cout << s << "\n";
}

int main() {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.precision(15);

  ll t = 1;

  if (test) {

    std::cin >> t;
  }

  for (ll i = 0; i <= t - 1; i++) {

    //        std::cout<<"Case #"<<i+1<<": ";
    testCase();
  }
}