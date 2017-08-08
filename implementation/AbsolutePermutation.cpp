//
//  AbsolutePermutation.cpp
//  hackerrank
//
//  Created by harry.wang on 2017/8/8.
//  Copyright © 2017年 harry.wang. All rights reserved.
//  https://www.hackerrank.com/challenges/absolute-permutation/problem

#include "common.hpp"
#include "Implementation.h"

void AbsolutePermutation() {
    Cin2File cin2file("AbsolutePermutation00.txt");
    
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        if(k && (n % 2 || n % (2*k))) {
            cout << -1 << endl;
            continue;
        }
        if(0 == k) {
            repe(1, n, i)
                cout << i << " ";
            cout << endl;
            continue;
        }
        vi N(n + 1);
        rep(0, n/(2*k), i) {
            repe(1, k, j) {
                int idx = 2*k*i + j;
                N[idx] = idx + k;
                N[idx+k] = idx;
            }
        }
        rep(1, sz(N), i)
            cout << N[i] << " ";
        cout << endl;
    }
}
