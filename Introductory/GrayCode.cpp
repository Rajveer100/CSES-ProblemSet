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

  std::vector<ll> a;

  a.push_back(0);
  a.push_back(1);

  for (ll i = 2; i <= (1ll << n); i++) {

    a.push_back(i ^ (i >> 1));
  }

  a.pop_back();

  std::vector<std::string> s(1ll << n);

  for (int i = 0; i <= (ll)a.size() - 1; i++) {

    while (a[i]) {

      s[i].push_back((a[i] % 2) + '0');
      a[i] >>= 1;
    }

    while ((ll)s[i].size() != n) {

      s[i].push_back('0');
    }
    std::reverse(s[i].begin(), s[i].end());
  }

  for (int i = 0; i <= (ll)s.size() - 1; i++) {

    std::cout << s[i] << "\n";
  }
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