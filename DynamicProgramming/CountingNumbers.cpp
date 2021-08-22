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

ll calc(ll n) {

  if (n < 0) {

    return 0;
  }

  if (!n) {

    return 1;
  }

  std::string s = std::to_string(n);

  std::vector<ll> dp(20);

  ll val = 1;

  for (int i = 0; i <= 19; i++) {

    dp[i] = val;
    val *= 9;
  }

  ll cnt = 0;

  for (int i = 0; i <= len(s) - 1; i++) {

    cnt += dp[i];
  }

  for (int i = 0; i <= len(s) - 1; i++) {

    if (s[i] - '0') {

      ll cur = len(s) - i - 1;
      cnt += (dp[cur] * (s[i] - '0' - (!i || s[i - 1] < s[i])));
    }

    if (i && s[i] == s[i - 1]) {

      return cnt;
    }
  }

  return cnt + 1;
}

void testCase() {

  ll a, b;

  std::cin >> a >> b;

  std::cout << calc(b) - calc(a - 1) << "\n";
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