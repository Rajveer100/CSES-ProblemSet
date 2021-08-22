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

  ll x, n;

  std::cin >> x >> n;

  std::vector<ll> a(n);

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> a[i];
  }

  std::multiset<ll> maxLen = {x};
  std::set<ll> pos = {0, x};

  for (int i = 0; i <= n - 1; i++) {

    auto r = pos.upper_bound(a[i]);

    ll rVal = *r;

    r--;
    ll lVal = *r;

    maxLen.erase(maxLen.find(rVal - lVal));
    maxLen.insert(a[i] - lVal);
    maxLen.insert(rVal - a[i]);

    pos.insert(a[i]);

    auto max = maxLen.end();
    max--;

    std::cout << *max << " ";
  }

  std::cout << "\n";
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