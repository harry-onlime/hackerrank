//
//  LarryArray.cpp
//  hackerrank
//
//  Created by harry.wang on 2017/8/8.
//  Copyright © 2017年 harry.wang. All rights reserved.
//  https://www.hackerrank.com/challenges/larrys-array/problem

#include "common.hpp"
#include "Implementation.h"

void LarryArray() {
    Cin2File cin2file("LarryArray00.txt");
    
    int t;
    cin >> t;
    for (int t_i=0; t_i<t; t_i++) {
        int n;
        cin >> n;
        vi N(n+1);
        int ans = 0;
        repe (1, n, n_i) {
            cin >> N[n_i];
            for (int i=n_i-1; i>=1; i--) {
                if (N[n_i] < N[i])
                    ans ^= 1;
            }
        }
        cout << (0 == ans % 2 ? "YES" : "NO") << endl;
    }
}
