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

std::string s;
ll cnt = 0;
std::vector<std::vector<bool>> vis(7, std::vector<bool>(7));

bool vacant(ll x, ll y) {

  return x >= 0 && x <= 6 && y >= 0 && y <= 6 && !vis[x][y];
}

void dfs(ll x, ll y, ll moves) {

  if (x == 6 && y == 0) {

    cnt += (moves == 48);
    return;
  }

  vis[x][y] = true;

  if (s[moves] == '?' || s[moves] == 'R') {

    if (y + 1 <= 6 && !vis[x][y + 1]) {

      if (!(!vacant(x, y + 2) && vacant(x - 1, y + 1) &&
            vacant(x + 1, y + 1))) {

        dfs(x, y + 1, moves + 1);
      }
    }
  }

  if (s[moves] == '?' || s[moves] == 'L') {

    if (y - 1 >= 0 && !vis[x][y - 1]) {

      if (!(!vacant(x, y - 2) && vacant(x - 1, y - 1) &&
            vacant(x + 1, y - 1))) {

        dfs(x, y - 1, moves + 1);
      }
    }
  }

  if (s[moves] == '?' || s[moves] == 'D') {

    if (x + 1 <= 6 && !vis[x + 1][y]) {

      if (!(!vacant(x + 2, y) && vacant(x + 1, y - 1) &&
            vacant(x + 1, y + 1))) {

        dfs(x + 1, y, moves + 1);
      }
    }
  }

  if (s[moves] == '?' || s[moves] == 'U') {

    if (x - 1 >= 0 && !vis[x - 1][y]) {

      if (!(!vacant(x - 2, y) && vacant(x - 1, y - 1) &&
            vacant(x - 1, y + 1))) {

        dfs(x - 1, y, moves + 1);
      }
    }
  }

  vis[x][y] = false;
}

void testCase() {

  std::cin >> s;

  dfs(0, 0, 0);

  std::cout << cnt << "\n";
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