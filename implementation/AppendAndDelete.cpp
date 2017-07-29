//
//  AppendAndDelete.cpp
//  hackerrank
//
//  Created by harry.wang on 2017/7/27.
//  Copyright © 2017年 harry.wang. All rights reserved.
//  https://www.hackerrank.com/challenges/append-and-delete

#include "common.hpp"
#include "Implementation.h"

void AppendAndDelete() {
    Cin2File cin2file("AppendAndDelete00.txt");
    
    string s;
    cin >> s;
    string t;
    cin >> t;
    int k;
    cin >> k;
    int l = sz(s) < sz(t) ? sz(s) : sz(t);
    int r = 0, i = 0;
    while (s[i] == t[i] && i < l) {
        i++;
        r++;
    }
    int diff = sz(s) + sz(t) - 2*r;
    if(k >= sz(s) + sz(t) || 0 == diff || (k >= diff && k%2 == diff%2)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
