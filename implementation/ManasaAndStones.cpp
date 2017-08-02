//
//  ManasaAndStones.cpp
//  hackerrank
//
//  Created by harry.wang on 2017/8/2.
//  Copyright © 2017年 harry.wang. All rights reserved.
//  https://www.hackerrank.com/challenges/manasa-and-stones/problem

#include "common.hpp"
#include "Implementation.h"

void ManasaAndStones() {
    Cin2File cin2file("ManasaAndStones00.txt");
    
    int t, n, a, b;
    cin >> t;
    forl(t, t_i) {
        cin >> n >> a >> b;
        if(a < b)
            SWAP(a, b);
        if(a == b) {
            cout << a*(n-1) << endl;
        }
        else {
            repe(1, n, i)
                cout << (a*(i-1) + b*(n-i)) << " ";
            cout << endl;
        }
    }
}
