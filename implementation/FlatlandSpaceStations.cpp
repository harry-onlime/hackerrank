//
//  FlatlandSpaceStations.cpp
//  hackerrank
//
//  Created by harry.wang on 2017/8/2.
//  Copyright © 2017年 harry.wang. All rights reserved.
//  https://www.hackerrank.com/challenges/flatland-space-stations/problem

#include "common.hpp"
#include "Implementation.h"

void FlatlandSpaceStations() {
    Cin2File cin2file("FlatlandSpaceStations00.txt");
    
    int n;
    int m;
    cin >> n >> m;
    vi c(n, -1);
    for(int c_i = 0;c_i < m;c_i++){
        int station;
        cin >> station;
        c[station] = 0;
    }
    rep(1, n, i) {
        if(c[i-1] >= 0 && c[i] != 0)
            c[i] = c[i-1] + 1;
    }
    int max_distance = -1;
    for(int i=n-1; i>=0; i--) {
        int distance = c[i];
        if(i < n-1) {
            distance = distance != -1 ? min(distance, c[i+1] + 1) : c[i+1] + 1;
            c[i] = distance;
        }
        max_distance = max(max_distance, distance);
    }
    cout << max_distance << endl;
}
