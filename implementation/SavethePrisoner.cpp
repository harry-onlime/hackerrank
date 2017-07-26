//
//  SavethePrisoner.cpp
//  hackerrank
//
//  Created by haosha.wang on 2017/7/26.
//  Copyright © 2017年 haosha.wang. All rights reserved.
//  https://www.hackerrank.com/challenges/save-the-prisoner

#include "common.hpp"
#include "Implementation.h"

I64 saveThePrisoner(I64 n, I64 m, I64 s){
    I64 mod = (m+s-1) % n;
    return 0 == mod ? n : mod;
}

void SavethePrisoner() {
    Cin2File cin2file("SavethePrisoner01.txt");
    
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        I64 n;
        I64 m;
        I64 s;
        cin >> n >> m >> s;
        I64 result = saveThePrisoner(n, m, s);
        cout << result << endl;
    }
}
