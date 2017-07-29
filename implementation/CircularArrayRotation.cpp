//
//  CircularArrayRotation.cpp
//  hackerrank
//
//  Created by harry.wang on 2017/7/26.
//  Copyright © 2017年 harry.wang. All rights reserved.
//  https://www.hackerrank.com/challenges/circular-array-rotation

#include "common.hpp"
#include "Implementation.h"

void CircularArrayRotation() {
    Cin2File cin2file("CircularArrayRotation00.txt");
    
    int n;
    int k;
    int q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    // --------- code begin ---------
    int start = k % n;
    // --------- code end ---------
    for(int a0 = 0; a0 < q; a0++){
        int m;
        cin >> m;
        // --------- code begin ---------
        int shift = m - start;
        int i = shift >= 0 ? shift : (n + shift);
        cout << a[i] << endl;
        // --------- code end ---------
    }
}
