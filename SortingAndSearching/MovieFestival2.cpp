//
//  main.cpp
//  CPWorkSpace
//
//  Created by Rajveer Singh on 23/09/21.
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

  ll n, k;

  std::cin >> n >> k;

  std::vector<std::pair<ll, ll>> a(n);

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> a[i].first >> a[i].second;
  }

  std::sort(a.begin(), a.end(),
            [](auto &l, auto &r) { return l.second < r.second; });

  ll cnt = 1;

  std::set<std::pair<ll, ll>> s;
  s.insert({-a[0].second, 0});

  for (int i = 1; i <= n - 1; i++) {

    auto vacant = s.lower_bound({-a[i].first, -1});

    if (vacant != s.end()) {

      s.erase(vacant);
      s.insert({-a[i].second, i});
      cnt++;
    } else if (len(s) < k) {

      s.insert({-a[i].second, i});
      cnt++;
    }
  }

  std::cout << cnt << "\n";
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