//
//  NonDivisibleSubset.cpp
//  hackerrank
//
//  Created by harry.wang on 2017/7/29.
//  Copyright © 2017年 harry.wang. All rights reserved.
//  https://www.hackerrank.com/challenges/non-divisible-subset/problem

#include "common.hpp"
#include "Implementation.h"

void NonDivisibleSubset() {
    Cin2File cin2file("NonDivisibleSubset00.txt");
    
    int n, k;
    cin >> n >> k;
    vi s(n, 0);
    vi m(100, 0);
    forv(s, n_i) {
        cin >> s[n_i];
        m[s[n_i]%k]++;
    }
    m[0] = m[0] ? 1 : 0;
    if(0 == k % 2)
        m[k/2] = m[k/2] ? 1 : 0;
    int ans = 0;
    repe(0, k/2, i)
        ans += max(m[i], m[k-i]);
    cout << ans << endl;
}
