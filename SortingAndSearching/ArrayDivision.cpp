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
ll inf = 1e10 + 5;

void testCase() {

  ll n, k;

  std::cin >> n >> k;

  std::vector<ll> a(n);

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> a[i];
  }

  ll l = *std::max_element(a.begin(), a.end());
  ll r = std::accumulate(a.begin(), a.end(), 0ll);

  ll min = r;

  while (l <= r) {

    ll mid = (l + r) / 2, s = 0, cnt = 1;

    for (int i = 0; i <= n - 1; i++) {

      if (s + a[i] > mid) {

        cnt++;
        s = a[i];
      } else {

        s += a[i];
      }
    }

    if (cnt <= k) {

      min = mid;
      r = mid - 1;
    } else {

      l = mid + 1;
    }
  }

  std::cout << min << "\n";
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