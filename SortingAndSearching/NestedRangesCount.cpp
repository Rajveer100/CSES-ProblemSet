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

std::vector<ll> segTree, lazy;

ll rangeQuery(ll node, ll left, ll right, ll l, ll r) {

  if (lazy[node]) {

    segTree[node] += lazy[node] * (right - left + 1);

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

    segTree[node] += lazy[node] * (right - left + 1);

    if (left != right) {

      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }

    lazy[node] = 0;
  }

  if (left >= l && right <= r) {

    segTree[node] += newVal * (right - left + 1);

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

  segTree.resize(0);
  lazy.resize(0);

  ll num = n;

  n = (1ll << ll(std::ceil(log2(n * 1.0))));

  segTree.resize(2 * n, 0);
  lazy.resize(2 * n, 0);

  for (ll i = 0; i <= num - 1; i++) {

    segTree[n + i] = a[i];
  }

  for (ll i = num; i <= n - 1; i++) {

    segTree[n + i] = 0;
  }

  for (ll i = n - 1; i >= 1; i--) {

    segTree[i] = segTree[2 * i] + segTree[2 * i + 1];
  }
}

void testCase() {

  ll n;

  std::cin >> n;

  std::vector<std::pair<ll, std::pair<ll, ll>>> a(n);

  std::vector<ll> s;

  for (int i = 0; i <= n - 1; i++) {

    std::cin >> a[i].second.first >> a[i].second.second;
    s.push_back(a[i].second.first);
    s.push_back(a[i].second.second);

    a[i].first = i;
  }

  std::sort(s.begin(), s.end());
  s.erase(std::unique(s.begin(), s.end()), s.end());

  ll m = len(s);
  std::vector<ll> p(m, 0);

  buildTree(m, p);

  std::sort(a.begin(), a.end(), [](auto &l, auto &r) {
    if (l.second.first == r.second.first) {

      return l.second.second > r.second.second;
    }

    return l.second.first < r.second.first;
  });

  std::vector<ll> contains(n, 0), contained(n, 0);
  ll endMin = inf, endMax = -inf;
  ll endMinPos = -1, endMaxPos = -1;

  for (int i = 0; i <= n - 1; i++) {

    ll cur =
        std::lower_bound(s.begin(), s.end(), a[i].second.second) - s.begin();

    if (a[i].second.second > endMax) {

      endMax = a[i].second.second;
      endMaxPos = cur;
    }

    contained[a[i].first] += rangeQuery(1, 0, m - 1, cur, endMaxPos);
    rangeUpdate(1, 0, m - 1, cur, cur, 1);
  }

  m = len(s);
  buildTree(m, p);
  std::reverse(a.begin(), a.end());

  for (int i = 0; i <= n - 1; i++) {

    ll cur =
        std::lower_bound(s.begin(), s.end(), a[i].second.second) - s.begin();

    if (a[i].second.second < endMin) {

      endMin = a[i].second.second;
      endMinPos = cur;
    }

    contains[a[i].first] += rangeQuery(1, 0, m - 1, endMinPos, cur);
    rangeUpdate(1, 0, m - 1, cur, cur, 1);
  }

  for (auto x : contains) {

    std::cout << x << " ";
  }

  std::cout << "\n";

  for (auto x : contained) {

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