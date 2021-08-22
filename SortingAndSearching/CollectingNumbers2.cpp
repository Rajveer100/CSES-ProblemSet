//
//  main.cpp
//  CompetitiveProgramming
//
//  Created by Rajveer Singh on 14/01/20.
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

  ll n, m;

  std::cin >> n >> m;

  std::vector<ll> a(n), c(n);
  std::vector<std::pair<ll, ll>> b(m);

  std::unordered_map<ll, ll> pos;

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> a[i];
    pos[a[i]] = i;
    c[i] = a[i];
  }

  for (int i = 0; i <= m - 1; i++) {

    std::cin >> b[i].first >> b[i].second;
  }

  std::sort(a.begin(), a.end());

  ll cnt = 1;

  for (int i = 1; i <= n - 1; i++) {

    cnt += (pos[a[i]] < pos[a[i - 1]]);
  }

  for (int i = 0; i <= m - 1; i++) {

    ll p1 = b[i].first, p2 = b[i].second;

    if (p1 == p2) {

      std::cout << cnt << "\n";
      continue;
    }

    if (p1 > p2) {

      std::swap(p1, p2);
    }

    ll x = c[p1 - 1], y = c[p2 - 1], fpos1 = pos[x], fpos2 = pos[y];

    std::swap(c[p1 - 1], c[p2 - 1]);
    pos[x] = p2 - 1;
    pos[y] = p1 - 1;

    if (x + 1 <= n) {

      cnt -= (fpos1 >= pos[x + 1] && pos[x] < pos[x + 1]);
      cnt += (fpos1 <= pos[x + 1] && pos[x] > pos[x + 1]);
    }

    if (x - 1 >= 1) {

      cnt -= (pos[x - 1] >= fpos1 && pos[x - 1] < pos[x]);
      cnt += (pos[x - 1] <= fpos1 && pos[x - 1] > pos[x]);
    }

    if (y + 1 <= n && y + 1 != x) {

      cnt -= (fpos2 >= pos[y + 1] && pos[y] < pos[y + 1]);
      cnt += (fpos2 <= pos[y + 1] && pos[y] > pos[y + 1]);
    }

    if (y - 1 >= 1 && y - 1 != x) {

      cnt -= (pos[y - 1] >= fpos2 && pos[y - 1] < pos[y]);
      cnt += (pos[y - 1] <= fpos2 && pos[y - 1] > pos[y]);
    }

    std::cout << cnt << "\n";
  }
}

int main() {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  ll t = 1;

  if (test) {

    std::cin >> t;
  }

  for (ll i = 0; i <= t - 1; i++) {

    testCase();
  }
}