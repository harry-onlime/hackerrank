//
//  QueensAttack.cpp
//  hackerrank
//
//  Created by harry.wang on 2017/8/14.
//  Copyright © 2017年 harry.wang. All rights reserved.
//  https://www.hackerrank.com/challenges/queens-attack-2

#include "common.hpp"
#include "Implementation.h"

void QueensAttack() {
    Cin2File cin2file("QueensAttack00.txt");
    
    int n;
    int k;
    cin >> n >> k;
    int R;
    int C;
    cin >> R >> C;
    vi a(8);
    a[0] = C - 1;                 // left
    a[1] = min(n - R, C - 1);     // left up
    a[2] = n - R;                 // up
    a[3] = min(n - C, n - R);     // right up
    a[4] = n - C;                 // right
    a[5] = min(n - C, R - 1);     // right down
    a[6] = R - 1;                 // down
    a[7] = min(C - 1, R - 1);     // left down
    for(int a0 = 0; a0 < k; a0++){
        int ri;
        int ci;
        cin >> ri >> ci;
        if ((abs(R-ri) == abs(C-ci)) || ri == R || ci == C) {
            if (ri == R && ci < C){
                a[0] = min(a[0], C - ci - 1);
            }
            else if (ri > R && ci < C) {
                a[1] = min(a[1], min(ri - R, C - ci) - 1);
            }
            else if (ci == C && ri > R) {
                a[2] = min(a[2], ri - R - 1);
            }
            else if (ci > C && ri > R) {
                a[3] = min(a[3], min(ci - C, ri - R) - 1);
            }
            else if (ri == R && ci > C) {
                a[4] = min(a[4], ci - C - 1);
            }
            else if (ci > C && ri < R) {
                a[5] = min(a[5], min(ci - C, R - ri) - 1);
            }
            else if (ci == C && ri < R) {
                a[6] = min(a[6], R - ri - 1);
            }
            else if (ci < C && ri < R) {
                a[7] = min(a[7], min(C - ci, R - ri) - 1);
            }
        }
    }
    int ans = 0;
    forv(a, i) {
        ans += a[i];
    }
    cout << ans << endl;
}
