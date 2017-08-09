//
//  AlmostSorted.cpp
//  hackerrank
//
//  Created by harry.wang on 2017/8/9.
//  Copyright © 2017年 harry.wang. All rights reserved.
//  https://www.hackerrank.com/challenges/almost-sorted

#include "common.hpp"
#include "Implementation.h"

void AlmostSorted() {
    Cin2File cin2file("AlmostSorted00.txt");
    
    int n;
    cin >> n;
    vi d(n + 1, 0);
    repe (1, n, i) {
        cin >> d[i];
    }
    int l = 0, r = 0;
    rep(1, n, i) {
        if(d[i] > d[i+1]) {
            l = i;
            break;
        }
    }
    rrep(n, 1, i) {
        if(d[i] < d[i-1]) {
            r = i;
            break;
        }
    }
    //cout << l << " " << r << endl;
    if(0 == l && 0 == r) {
        cout << "yes" << endl;
        return;
    }
    
    int swap = 1, reverse = 1;
    rep(l + 1, r - 1, i) {
        reverse &= (d[i+1] < d[i]);
        swap &= (d[i+1] > d[i]);
    }
    //cout << reverse << " " << swap << endl;
    
    if(swap || reverse) {
        SWAP(d[l], d[r]);
        if(reverse && !swap)
            SWAP(d[l+1], d[r-1]);
        if(l-1 > 0 && d[l] < d[l-1]) {
            cout << "no" << endl;
            return;
        }
        if(r+1 <= n && d[r] > d[r+1]) {
            cout << "no" << endl;
            return;
        }
        if(l+1 <= n && d[l] > d[l+1]) {
            cout << "no" << endl;
            return;
        }
        if(r-1 > 0 && d[r] < d[r-1]) {
            cout << "no" << endl;
            return;
        }
        cout << "yes" << endl;
        if(swap)
            cout << "swap " << l << " " << r << endl;
        else
            cout << "reverse " << l << " " << r << endl;
    }
    else {
        cout << "no" << endl;
    }
}
