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

  ll cnt = 0;

  while (n >= 5) {

    cnt += (n / 5);
    n /= 5;
  }

  std::cout << cnt << "\n";
}

int main() {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  ll t = 1;

  //    std::cin>>t;

  for (ll i = 0; i <= t - 1; i++) {

    testCase();
  }
}