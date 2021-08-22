//
//  main.cpp
//  CPWorkSpace
//
//  Created by Rajveer Singh on 21/01/22.
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
ll inf = 1e18 + 5;

void testCase() {

  ll n, t;

  std::cin >> n >> t;

  std::vector<ll> a(n);

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> a[i];
  }

  ll l = 0, r = inf;
  ll minCnt = inf;

  while (l <= r) {

    ll mid = (l + r) / 2, s = 0;

    for (int i = 0; i <= n - 1 && s < t; i++) {

      s += (mid / a[i]);
    }

    if (s >= t) {

      minCnt = mid;
      r = mid - 1;
    } else {

      l = mid + 1;
    }
  }

  std::cout << minCnt << "\n";
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