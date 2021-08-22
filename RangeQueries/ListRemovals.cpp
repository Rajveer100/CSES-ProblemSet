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
ll inf = 1e10 + 5;

std::vector<ll> segTree, lazy;

ll rangeQuery(ll node, ll left, ll right, ll l, ll r) {

  if (lazy[node]) {

    segTree[node] += lazy[node];

    if (left != right) {

      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }

    lazy[node] = 0;
  }

  if (left >= l && right <= r) {

    return segTree[node];
  } else if (right < l || left > r) {

    return 0;
  } else {

    ll mid = (left + right) / 2;

    return rangeQuery(2 * node, left, mid, l, r) +
           rangeQuery(2 * node + 1, mid + 1, right, l, r);
  }
}

void rangeUpdate(ll node, ll left, ll right, ll l, ll r, ll newVal) {

  if (lazy[node]) {

    segTree[node] += lazy[node];

    if (left != right) {

      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }

    lazy[node] = 0;
  }

  if (left >= l && right <= r) {

    segTree[node] += newVal;

    if (left != right) {

      lazy[2 * node] += newVal;
      lazy[2 * node + 1] += newVal;
    }
  } else if (right < l || left > r) {

    return;
  } else {

    ll mid = (left + right) / 2;

    rangeUpdate(2 * node, left, mid, l, r, newVal);
    rangeUpdate(2 * node + 1, mid + 1, right, l, r, newVal);
    segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
  }
}

void pointUpdate(ll n, ll pos, ll newVal) {

  segTree[n + pos] = newVal;

  for (ll j = (n + pos) / 2; j >= 1; j /= 2) {

    segTree[j] = segTree[2 * j] + segTree[2 * j + 1];
  }
}

void buildTree(ll &n, std::vector<ll> a) {

  ll num = n;

  n = (1ll << ll(std::ceil(log2(n * 1.0))));

  segTree.resize(2 * n);
  lazy.resize(2 * n);

  for (ll i = 0; i <= num - 1; i++) {

    segTree[n + i] = a[i];
  }

  for (ll i = n - 1; i >= 1; i--) {

    segTree[i] = segTree[2 * i] + segTree[2 * i + 1];
  }
}

void testCase() {

  ll n;

  std::cin >> n;

  std::vector<ll> a(n), occ(n, 1);

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> a[i];
  }

  ll num = n;

  buildTree(n, occ);

  for (int i = 0; i <= num - 1; i++) {

    ll pos;
    std::cin >> pos;

    ll l = 0, r = num - 1, mid = (l + r) / 2;

    while (l <= r) {

      mid = (l + r) / 2;
      ll s = rangeQuery(1, 0, n - 1, 0, mid);

      if (s == pos) {

        if (segTree[n + mid]) {

          std::cout << a[mid] << " ";
          break;
        } else {

          r = mid - 1;
        }
      } else if (s < pos) {

        l = mid + 1;
      } else {

        r = mid - 1;
      }
    }

    pointUpdate(n, mid, 0);
  }
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