//
//  main3.cpp
//  main3
//
//  Created by Rajveer Singh on 05/11/20.
//  Copyright © 2020 Rajveer Singh. All rights reserved.
//

#include <algorithm>
#include <array>
#include <chrono>
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
#include <vector>

// MARK:- PRACTICE

typedef long long ll;
typedef long double ld;

void testCase() {

  ll n;

  std::cin >> n;

  for (int i = 0; i <= n - 1; i++) {

    ll x, y;

    std::cin >> x >> y;

    // 3n-1

    ll max = std::max(x, y);
    ll diag = 1 + max * (max - 1), diff = std::abs(x - y);
    ll ans = diag;

    if (max == x) {

      if (max % 2) {

        ans -= diff;
      } else {

        ans += diff;
      }
    } else {

      if (max % 2) {

        ans += diff;
      } else {

        ans -= diff;
      }
    }

    std::cout << ans << "\n";
  }
}

int main() {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  ll t = 1;

  //    std::cin>>t;

  for (int i = 0; i <= t - 1; i++) {

    testCase();
  }
}