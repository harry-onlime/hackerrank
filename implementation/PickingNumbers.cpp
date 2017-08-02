//
//  PickingNumbers.cpp
//  hackerrank
//
//  Created by harry.wang on 2017/7/29.
//  Copyright © 2017年 harry.wang. All rights reserved.
//  https://www.hackerrank.com/challenges/picking-numbers

#include "common.hpp"
#include "Implementation.h"

void PickingNumbers() {
    Cin2File cin2file("PickingNumbers00.txt");
    
    int n;
    cin >> n;
    vi m(100, 0);
    for(int a_i = 0;a_i < n;a_i++){
        int a;
        cin >> a;
        m[a]++;
    }
    int max_cnt = 0;
    rep(1, 99, i)
        max_cnt = max(max_cnt, m[i]+m[i+1]);
    cout << max_cnt << endl;
}
