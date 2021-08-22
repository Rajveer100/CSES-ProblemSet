//
//  main2.cpp
//  main2
//
//  Created by Rajveer Singh on 05/11/20.
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

std::vector<ll> a(25);
ll min = 1e18;

void f(ll n, ll s, ll sum) {

  min = std::min(min, std::abs(sum - 2 * s));

  if (n < 0) {

    return;
  }

  f(n - 1, s + a[n], sum);
  f(n - 1, s, sum);
}

void testCase() {

  ll n;

  std::cin >> n;

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> a[i];
  }

  ll sum = std::accumulate(a.begin(), a.end(), 0ll);

  f(n - 1, 0ll, sum);

  std::cout << min << "\n";
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