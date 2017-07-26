//
//  BetweenTwoSets.cpp
//  hackerrank
//
//  Created by haosha.wang on 2017/7/24.
//  Copyright © 2017年 haosha.wang. All rights reserved.
//  https://www.hackerrank.com/challenges/between-two-sets

#include "BetweenTwoSets.hpp"
#include "common.hpp"

int gcd(int a, int b) {
    while(a > 0 && b > 0) {
        if(0 == a % b || 0 == b % a)
            return a > b ? b : a;
        if(a > b)
            a = a % b;
        else
            b = b % a;
    }
    return 1;
}

int lcm(int a, int b) {
    return a/gcd(a, b)*b;
}

int getTotalX(vector < int > a, vector < int > b){
    int mul = 1, div = b[0];
    forv(a, i)
        mul = lcm(mul, a[i]);
    forv(b, i)
        div = gcd(div, b[i]);
    if(div % mul) return 0;
    int total = 1;
    for(int i=2; i*mul<=div; i++) {
        if(0 == div % (i*mul))
            total++;
    }
    return total;
}

void BetweenTwoSets() {
    Cin2File cin2file("BetweenTwoSets00.txt");
    
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
        cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
        cin >> b[b_i];
    }
    int total = getTotalX(a, b);
    cout << total << endl;
}
