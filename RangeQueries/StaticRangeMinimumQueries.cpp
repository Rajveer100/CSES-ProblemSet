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

std::vector<std::vector<ll>> sp;

ll query(ll l, ll r) {

  ll len = r - l + 1, k = ll(log2(len * 1.0));

  return std::min(sp[l][k], sp[r - (1ll << k) + 1][k]);
}

void buildSparse(ll n, std::vector<ll> a) {

  ll maxLog = 20;
  sp.resize(n, std::vector<ll>(maxLog));

  for (int i = 0; i <= n - 1; i++) {

    sp[i][0] = a[i];
  }

  for (int i = 1; i <= maxLog; i++) {

    for (int j = 0; j + (1ll << i) - 1 <= n - 1; j++) {

      sp[j][i] = std::min(sp[j][i - 1], sp[j + (1ll << (i - 1))][i - 1]);
    }
  }
}

void testCase() {

  ll n, q;

  std::cin >> n >> q;

  std::vector<ll> a(n);

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> a[i];
  }

  buildSparse(n, a);

  for (int i = 0; i <= q - 1; i++) {

    ll l, r;

    std::cin >> l >> r;

    l--;
    r--;

    std::cout << query(l, r) << "\n";
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