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

  std::vector<std::pair<ll, std::pair<ll, ll>>> a(n);

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> a[i].second.first >> a[i].second.second;
    a[i].first = i;
  }

  std::sort(a.begin(), a.end(),
            [](auto &l, auto &r) { return l.second.first < r.second.first; });

  std::vector<ll> assigned(n);
  assigned[a[0].first] = 1;

  std::set<std::pair<ll, ll>> rooms;
  rooms.insert({a[0].second.second, 1});

  ll req = 1;

  for (int i = 1; i <= n - 1; i++) {

    auto f = rooms.begin();

    if (a[i].second.first > f->first) {

      rooms.erase(rooms.begin());
      rooms.insert({a[i].second.second, f->second});

      assigned[a[i].first] = f->second;
    } else {

      rooms.insert({a[i].second.second, ++req});
      assigned[a[i].first] = req;
    }
  }

  std::cout << req << "\n";

  for (auto x : assigned) {

    std::cout << x << " ";
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