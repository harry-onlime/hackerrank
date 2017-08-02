//
//  BiggerIsGreater.cpp
//  hackerrank
//
//  Created by harry.wang on 2017/7/31.
//  Copyright © 2017年 harry.wang. All rights reserved.
//  https://www.hackerrank.com/challenges/bigger-is-greater/problem

#include "common.hpp"
#include "Implementation.h"

void BiggerIsGreater() {
    Cin2File cin2file("BiggerIsGreater00.txt");
    
    int t;
    cin >> t;
    forl(t, t_i) {
        string s;
        cin >> s;
        int i = sz(s) - 1;
        while(i > 0 && s[i-1] >= s[i])
            i--;
        if(0 == i) {
            cout << "no answer" << endl;
            continue;
        }
        int j = sz(s) - 1;
        while(s[j] <= s[i-1])
            j--;
        SWAP(s[i-1], s[j]);
        j = sz(s) - 1;
        while(i < j) {
            SWAP(s[i], s[j]);
            i++;
            j--;
        }
        cout << s << endl;
    }
}
