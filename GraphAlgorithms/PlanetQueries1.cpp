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
ll lim = 1e6 + 5;

void testCase() {

  ll n, q;
  std::cin >> n >> q;

  ll to[n + 1][32];

  for (int i = 1; i <= n; i++) {

    std::cin >> to[i][0];
  }

  for (int k = 1; k <= 30; k++) {

    for (int i = 1; i <= n; i++) {

      to[i][k] = to[to[i][k - 1]][k - 1];
    }
  }

  auto getDest = [&](ll x, ll k) {
    ll c = 0;

    while (k) {

      if (k & 1) {

        x = to[x][c];
      }

      c++;
      k >>= 1;
    }

    return x;
  };

  for (int i = 0; i <= q - 1; i++) {

    ll x, k;
    std::cin >> x >> k;

    std::cout << getDest(x, k) << '\n';
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

  for (int i = 0; i <= t - 1; i++) {

    //        std::cout << "Case #" << i + 1 << ": ";
    testCase();
  }
}
