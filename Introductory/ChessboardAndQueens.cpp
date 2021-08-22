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

std::vector<bool> col(8), leftD(15), rightD(15);
std::string s[8];
ll ways = 0;

void dfs(ll i) {

  if (i == 8) {

    ways++;
    return;
  }

  for (int j = 0; j <= 7; j++) {

    if (s[i][j] != '*' && !leftD[i + j] && !rightD[i - j + 7] && !col[j]) {

      col[j] = true;
      leftD[i + j] = true;
      rightD[i - j + 7] = true;

      dfs(i + 1);

      col[j] = false;
      leftD[i + j] = false;
      rightD[i - j + 7] = false;
    }
  }
}

void testCase() {

  for (int i = 0; i <= 7; i++) {

    std::cin >> s[i];
  }

  dfs(0);

  std::cout << ways << "\n";
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