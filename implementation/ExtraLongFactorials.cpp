//
//  ExtraLongFactorials.cpp
//  hackerrank
//
//  Created by harry.wang on 2017/7/27.
//  Copyright © 2017年 harry.wang. All rights reserved.
//  https://www.hackerrank.com/challenges/extra-long-factorials/problem

#include "common.hpp"
#include "Implementation.h"

void ExtraLongFactorials() {
    Cin2File cin2file("ExtraLongFactorials00.txt");
    
    int n;
    cin >> n;
    
    vi result(200, 0);
    result[0] = 1;
    int k = 1;
    repe(1, n, i) {
        int carry = 0;
        rep(0, k, j) {
            result[j] *= i;
            result[j] += carry;
            carry = result[j]/10;
            result[j] %= 10;
        }
        while(carry) {
            result[k] = carry;
            carry = result[k]/10;
            result[k] %= 10;
            k++;
        }
    }
    for(int i=k-1; i>=0; i--)
        cout << result[i];
    cout << endl;
}
