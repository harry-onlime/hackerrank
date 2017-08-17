//
//  Bomberman.cpp
//  hackerrank
//
//  Created by harry.wang on 2017/8/17.
//  Copyright © 2017年 harry.wang. All rights reserved.
//  https://www.hackerrank.com/challenges/bomber-man/problem

#include "common.hpp"
#include "Implementation.h"

void output(int r, int c, vector<bitset<200>>& m) {
    forl(r, r_i) {
        bitset<200>& bs = m[r_i];
        forl(c, c_i)
        cout << (bs[c_i] ?  "O" : ".");
        cout << endl;
    }
}

void f(int r, int c, vector<bitset<200>>& m) {
    vector<bitset<200>> n(m);
    forl(r, r_i) {
        bitset<200>& bm = m[r_i];
        bitset<200>& bn = n[r_i];
        forl(c-1, c_i) {
            if(bm[c_i]^bm[c_i+1]) {
                bn[c_i] = 1;
                bn[c_i+1] = 1;
            }
        }
    }
    forl(r, r_i) {
        bitset<200>& bn = n[r_i];
        if(r_i>0)
            bn |= m[r_i-1];
        if(r_i<r-1)
            bn |= m[r_i+1];
        bn = ~bn;
    }
    //output(r, c, n);
    m = n;
}

void Bomberman() {
    Cin2File cin2file("Bomberman00.txt");
    
    int r, c;
    I64 n;
    cin >> r >> c >> n;
    vector<bitset<200>> m(r);
    forl(r, r_i) {
        string s;
        cin >> s;
        forl(c, c_i)
            m[r_i][c_i] = s[c_i] == '.' ? 0 : 1;
    }
    if(n > 1) {
        if(0 == n%2) {
            forl(r, r_i)
                m[r_i].set();
        }
        else {
            f(r, c, m);
            if(1 == n%4)
                f(r, c, m);
        }
    }
    output(r, c, m);
}
