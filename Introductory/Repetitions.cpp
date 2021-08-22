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

  std::string s;

  std::cin >> s;

  std::vector<ll> dp((ll)s.length(), 0);

  dp.front() = 1;
  ll max = 1;

  for (int i = 1; i <= (ll)s.length() - 1; i++) {

    if (s[i] == s[i - 1]) {

      dp[i] += dp[i - 1] + 1;
    } else {

      dp[i]++;
    }

    max = std::max(max, dp[i]);
  }

  std::cout << max << "\n";
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