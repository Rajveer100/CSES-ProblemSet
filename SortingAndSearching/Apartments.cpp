//
//  main.cpp
//  CompetitiveProgramming
//
//  Created by Rajveer Singh on 14/01/20.
//  Copyright © 2020 Rajveer Singh. All rights reserved.
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

void testCase() {

  ll n, m, k;

  std::cin >> n >> m >> k;

  std::vector<ll> a(n), b(m);

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> a[i];
  }

  for (int i = 0; i <= m - 1; i++) {

    std::cin >> b[i];
  }

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  ll p = 0, c = 0;

  for (int i = 0; p <= n - 1;) {

    if (i <= m - 1 && a[p] >= b[i] - k && a[p] <= b[i] + k) {

      c++;
      i++;
      p++;
    } else if (i <= m - 1 && a[p] > b[i] + k) {

      i++;
    } else {

      p++;
    }
  }

  std::cout << c << "\n";
}

int main() {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  ll t = 1;

  if (test) {

    std::cin >> t;
  }

  for (ll i = 0; i <= t - 1; i++) {

    testCase();
  }
}