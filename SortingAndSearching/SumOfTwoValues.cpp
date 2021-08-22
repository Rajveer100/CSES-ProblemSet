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

std::vector<std::pair<ll, ll>> a;

ll binarySearch(ll l, ll r, ll x, ll n) {

  if (l > n - 1 || r < 0) {

    return -1;
  }

  ll mid = (l + r) / 2;

  while (l <= r) {

    mid = (l + r) / 2;

    if (x == a[mid].first) {

      return a[mid].second;
    }

    if (x > a[mid].first) {

      l = mid + 1;
    } else {

      r = mid - 1;
    }
  }

  return -1;
}

void testCase() {

  ll n, k;

  std::cin >> n >> k;

  a.resize(n);

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> a[i].first;
    a[i].second = i;
  }

  std::sort(a.begin(), a.end());

  for (int i = 0; i <= n - 1; i++) {

    ll p1 = binarySearch(i + 1, n - 1, k - a[i].first, n),
       p2 = binarySearch(0, i - 1, k - a[i].first, n);

    if (p1 != -1) {

      std::cout << a[i].second + 1 << " " << p1 + 1 << "\n";
      return;
    }

    if (p2 != -1) {

      std::cout << a[i].second + 1 << " " << p2 + 1 << "\n";
      return;
    }
  }

  std::cout << "IMPOSSIBLE\n";
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