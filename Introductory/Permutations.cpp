//
//  main3.cpp
//  main3
//
//  Created by Rajveer Singh on 05/11/20.
//  Copyright © 2020 Rajveer Singh. All rights reserved.
//

#include <algorithm>
#include <array>
#include <chrono>
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
#include <vector>

// MARK:- PRACTICE

typedef long long ll;
typedef long double ld;

void testCase() {

  ll n;

  std::cin >> n;

  if (n == 1) {

    std::cout << "1\n";
    return;
  } else if (n == 2 || n == 3) {

    std::cout << "NO SOLUTION\n";
    return;
  } else if (n == 4) {

    std::cout << "3 1 4 2\n";
  }

  ll even = 2, odd = 1;

  for (int i = 0; i <= n - 1; i++) {

    if (odd <= n) {

      std::cout << odd << " ";
      odd += 2;
    } else {

      std::cout << even << " ";
      even += 2;
    }
  }

  std::cout << "\n";
}

int main() {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  ll t = 1;

  //    std::cin>>t;

  for (int i = 0; i <= t - 1; i++) {

    testCase();
  }
}