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

  std::vector<ll> a(n - 1);

  for (int i = 0; i <= n - 2; i++) {

    std::cin >> a[i];
  }

  std::sort(a.begin(), a.end());

  for (int i = 1; i <= n - 1; i++) {

    if (i != a[i - 1]) {

      std::cout << i << "\n";
      return;
    }
  }

  std::cout << n << "\n";
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