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

  std::vector<ll> a(n);

  for (int i = 0; i <= n - 1; i++) {

    a[i] = i + 1;
  }

  ll sum = (n * (n + 1)) / 2;

  if (sum % 2 || n == 1) {

    std::cout << "NO\n";
    return;
  }

  std::vector<ll> f, s;

  sum /= 2;

  for (ll i = n; i >= 1; i--) {

    if (sum - i >= 0) {

      f.push_back(i);
      sum -= i;
    } else {

      s.push_back(i);
    }
  }

  std::cout << "YES\n";
  std::cout << (ll)f.size() << "\n";

  for (int i = 0; i <= (ll)f.size() - 1; i++) {

    std::cout << f[i] << " ";
  }

  std::cout << "\n";

  std::cout << (ll)s.size() << "\n";

  for (int i = 0; i <= (ll)s.size() - 1; i++) {

    std::cout << s[i] << " ";
  }

  std::cout << "\n";
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