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

  ll n;

  std::cin >> n;

  std::vector<std::pair<ll, ll>> a(n);

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> a[i].first >> a[i].second;
  }

  std::sort(a.begin(), a.end(),
            [](auto &l, auto &r) { return l.second < r.second; });

  ll cnt = 1, max = 1;
  ll pos = 0;

  for (int i = 1; i <= n - 1; i++) {

    if (a[i].first >= a[pos].second) {

      cnt++;
      pos = i;
    }

    max = std::max(max, cnt);
  }

  std::cout << max << "\n";
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