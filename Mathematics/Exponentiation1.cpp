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

ll binExp(ll a, ll b) {

  ll res = 1, mul = a;

  while (b) {

    if (b & 1) {

      res = (res * mul) % mod1;
    }

    mul = (mul * mul) % mod1;
    b >>= 1;
  }

  return res;
}

void testCase() {

  ll q;

  std::cin >> q;

  for (int i = 0; i <= q - 1; i++) {

    ll a, b;
    std::cin >> a >> b;

    std::cout << binExp(a, b) << "\n";
  }
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