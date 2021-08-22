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
ll inf = 1e15 + 5;

std::vector<std::vector<char>> map;
std::vector<std::vector<ll>> vis;

std::vector<std::pair<ll, ll>> d = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

ll n, m;

void dfs(ll i, ll j) {

  vis[i][j] = true;

  for (int k = 0; k <= 3; k++) {

    if (i + d[k].first >= 0 && j + d[k].second >= 0 &&
        i + d[k].first <= n - 1 && j + d[k].second <= m - 1 &&
        map[i + d[k].first][j + d[k].second] == '.') {

      if (!vis[i + d[k].first][j + d[k].second]) {

        dfs(i + d[k].first, j + d[k].second);
      }
    }
  }
}

void testCase() {

  std::cin >> n >> m;

  map.resize(0);
  vis.resize(0);
  map.resize(n, std::vector<char>(m));
  vis.resize(n, std::vector<ll>(m, 0));

  for (int i = 0; i <= n - 1; i++) {

    for (int j = 0; j <= m - 1; j++) {

      char c;
      std::cin >> c;

      map[i][j] = c;
    }
  }

  ll cnt = 0;

  for (int i = 0; i <= n - 1; i++) {

    for (int j = 0; j <= m - 1; j++) {

      if (!vis[i][j] && map[i][j] == '.') {

        dfs(i, j);
        cnt++;
      }
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