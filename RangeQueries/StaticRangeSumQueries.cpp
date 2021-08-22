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

void testCase() {

  ll n, q;

  std::cin >> n >> q;

  std::vector<ll> a(n), pref(n);

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> a[i];

    if (i) {

      pref[i] += pref[i - 1] + a[i];
    } else {

      pref[i] = a[i];
    }
  }

  for (int i = 0; i <= q - 1; i++) {

    ll l, r;

    std::cin >> l >> r;

    l--;
    r--;

    std::cout << pref[r] - (l ? pref[l - 1] : 0) << "\n";
  }
}

int main() {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.precision(15);

  ll t = 1;

  if (test) {

    std::cin >> t;
  }

  for (ll i = 0; i <= t - 1; i++) {

    //        std::cout<<"Case #"<<i+1<<": ";
    testCase();
  }
}