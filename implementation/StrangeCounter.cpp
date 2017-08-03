//
//  StrangeCounter.cpp
//  hackerrank
//
//  Created by harry.wang on 2017/8/3.
//  Copyright © 2017年 harry.wang. All rights reserved.
//  https://www.hackerrank.com/challenges/strange-code

#include "common.hpp"
#include "Implementation.h"

inline I64 div3(I64 n) {
    return 0 == n%3 ? n/3 : n/3 + 1;
}

int div2(I64 n) {
    int cnt = 0;
    while (n/2 >= 1) {
        n /= 2;
        cnt++;
    }
    return cnt;
}

void StrangeCounter() {
    Cin2File cin2file("StrangeCounter00.txt");
    
    I64 t;
    cin >> t;
    I64 r = div2(div3(t));
    I64 tr0 = 3*pow(2, r) - 2;
    cout << (3*(I64)pow(2, r) - (t - tr0)) << endl;
}
