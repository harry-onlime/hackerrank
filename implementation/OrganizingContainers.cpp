//
//  OrganizingContainers.cpp
//  hackerrank
//
//  Created by harry.wang on 2017/8/14.
//  Copyright © 2017年 harry.wang. All rights reserved.
//  https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem

#include "common.hpp"
#include "Implementation.h"

void OrganizingContainers() {
    Cin2File cin2file("OrganizingContainers00.txt");
    
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        cin >> n;
        vector< vector<int> > M(n,vector<int>(n));
        vl c(n);
        for(int M_i = 0;M_i < n;M_i++){
            for(int M_j = 0;M_j < n;M_j++){
                cin >> M[M_i][M_j];
                c[M_i] += M[M_i][M_j];
            }
        }
        vl t(n);
        forl(n, i) {
            forl(n, j) {
                t[i] += M[j][i];
            }
        }
        sort(c.begin(), c.end());
        sort(t.begin(), t.end());
        bool possible = true;
        forl(n, i) {
            if(c[i] != t[i]) {
                possible = false;
                break;
            }
        }
        cout << (possible ? "Possible" : "Impossible ") << endl;
    }
}
