//
//  main4.cpp
//  main4
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

  ll res = 1, mul = 2;

  // 101

  while (n) {

    if (n % 2) {

      res = (res * mul) % 1000000007;
    }

    mul = (mul * mul) % 1000000007;

    n /= 2;
  }

  std::cout << res << "\n";
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