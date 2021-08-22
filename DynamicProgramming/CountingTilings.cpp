//
//  main.cpp
//  main2
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
ll inf = 1e15 + 5;

void testCase() {

  ll n, m;

  std::cin >> n >> m;

  std::vector<ll> dpTotal(1ll << n, 0);

  dpTotal[0] = 1;

  for (int i = 0; i <= m - 1; i++) {

    for (int j = 0; j <= n - 1; j++) {

      std::vector<ll> dp(1ll << n, 0);

      for (int k = 0; k <= (1ll << n) - 1; k++) {

        (dp[k] += dpTotal[k ^ (1ll << j)]) %= mod1;

        if (j && !(k & (1ll << j)) && !(k & (1ll << (j - 1)))) {

          (dp[k] += dpTotal[k ^ (1ll << (j - 1))]) %= mod1;
        }
      }
      dpTotal = dp;
    }
  }

  std::cout << dpTotal[0] << "\n";
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