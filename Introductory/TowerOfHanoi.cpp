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

void move(ll n, ll l, ll mid, ll r) {

  if (n == 1) {

    std::cout << l << " " << r << "\n";
    return;
  }

  move(n - 1, l, r, mid);

  std::cout << l << " " << r << "\n";

  move(n - 1, mid, l, r);
}

void testCase() {

  ll n;

  std::cin >> n;

  std::cout << (1ll << n) - 1 << "\n";

  move(n, 1, 2, 3);
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