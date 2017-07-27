//
//  common.hpp
//  demo
//
//  Created by haosha.wang on 17/4/10.
//  Copyright © 2017年 haosha.wang. All rights reserved.
//

#ifndef common_hpp
#define common_hpp

#include <stdio.h>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <time.h>
#include <assert.h>

using namespace std;

#define vi vector<int>
#define si set<int>
#define di deque<int>
#define vs vector<string>
#define vb vector<bool>
#define forv(v, i) for (int i = 0; i < v.size(); i++)
#define forl(l, i) for (int i = 0; i < l; i++)
#define rep(init, len, i) for (int i = init; i < len; i++)
#define repe(init, len, i) for (int i = init; i <= len; i++)
typedef long long I64;
#define vl vector<I64>
#define vvi vector<vector<int>>
#define vvl vector<vector<I64>>
#define SWAP(a, b) \
if (a != b) { \
a ^= b; \
b = a ^ b; \
a = a ^ b; \
}
#define sz(x) (int)x.size()

class Cin2File {
public:
    Cin2File(string filePath);
    ~Cin2File();
    
private:
    fstream *fs_;
    streambuf *sb_;
};

class TimeProfile {
public:
    TimeProfile();
    ~TimeProfile();
private:
    clock_t t_;
};

void print_arr(vi& arr);

#endif /* common_hpp */
