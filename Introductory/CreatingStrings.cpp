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

void testCase() {

  std::string s;

  std::cin >> s;

  std::sort(s.begin(), s.end());

  ll c = 0;

  do {

    c++;
  } while (std::next_permutation(s.begin(), s.end()));

  std::cout << c << "\n";

  do {

    std::cout << s << "\n";
  } while (std::next_permutation(s.begin(), s.end()));
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