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
ll inf = 1e15 + 5;

void testCase() {

  ll n;

  std::cin >> n;

  std::vector<std::pair<std::pair<ll, ll>, ll>> a(n);

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> a[i].first.first >> a[i].first.second;
    a[i].second = i;
  }

  std::sort(a.begin(), a.end(), [](auto &l, auto &r) {
    if (l.first.first == r.first.first) {

      return l.first.second > r.first.second;
    }

    return l.first.first < r.first.first;
  });

  std::vector<ll> contains(n, 0), contained(n, 0);

  ll endMin = a[n - 1].first.second;

  for (ll i = n - 2; i >= 0; i--) {

    if (a[i].first.second >= endMin) {

      contains[a[i].second]++;
    }
    endMin = std::min(endMin, a[i].first.second);
  }

  ll endMax = a[0].first.second;

  for (int i = 1; i <= n - 1; i++) {

    if (a[i].first.second <= endMax) {

      contained[a[i].second]++;
    }
    endMax = std::max(endMax, a[i].first.second);
  }

  for (int i = 0; i <= n - 1; i++) {

    std::cout << contains[i] << " ";
  }

  std::cout << "\n";

  for (int i = 0; i <= n - 1; i++) {

    std::cout << contained[i] << " ";
  }

  std::cout << "\n";
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