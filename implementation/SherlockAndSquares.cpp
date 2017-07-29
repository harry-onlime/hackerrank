//
//  SherlockAndSquares.cpp
//  hackerrank
//
//  Created by harry.wang on 2017/7/28.
//  Copyright © 2017年 harry.wang. All rights reserved.
//  https://www.hackerrank.com/challenges/sherlock-and-squares/problem

#include "common.hpp"
#include "Implementation.h"

void SherlockAndSquares() {
    Cin2File cin2file("SherlockAndSquares00.txt");
    
    int t;
    cin >> t;
    rep(0, t, t_i) {
        int a, b;
        cin >> a >> b;
        cout << (floor(sqrt(b)) - ceil(sqrt(a)) + 1) << endl;
    }
}
