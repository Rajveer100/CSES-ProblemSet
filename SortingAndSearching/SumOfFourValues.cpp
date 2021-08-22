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

  ll n, x;

  std::cin >> n >> x;

  std::vector<std::pair<ll, ll>> a(n);

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> a[i].first;
    a[i].second = i;
  }

  std::sort(a.begin(), a.end());

  // 1 2 5 7

  for (int i = 0; i <= n - 1; i++) {

    for (int j = i + 1; j <= n - 1; j++) {

      ll rem = x - a[i].first - a[j].first;

      ll l = j + 1, r = n - 1;

      while (l < r) {

        if (a[l].first + a[r].first == rem) {

          std::cout << a[i].second + 1 << " " << a[j].second + 1 << " "
                    << a[l].second + 1 << " " << a[r].second + 1 << "\n";
          return;
        } else if (a[l].first + a[r].first < rem) {

          l++;
        } else {

          r--;
        }
      }
    }
  }

  std::cout << "IMPOSSIBLE\n";
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