//
//  common.cpp
//  demo
//
//  Created by harry.wang on 17/4/10.
//  Copyright © 2017年 harry.wang. All rights reserved.
//

#include "common.hpp"

Cin2File::Cin2File(string filePath): fs_(new fstream()), sb_(cin.rdbuf()) {
    fs_->open(filePath, ios::in);
    cin.rdbuf(fs_->rdbuf());
}

Cin2File::~Cin2File() {
    fs_->close();
    cin.rdbuf(sb_);
    delete fs_;
}

TimeProfile::TimeProfile(): t_(clock()) {;}

TimeProfile::~TimeProfile() {
    clock_t t = clock() - t_;
    cout << "Prog time: " << (float)t/CLOCKS_PER_SEC << " seconds" << endl;
}

void print_arr(vi& arr) {
    forv(arr, a_i)
        cout << arr[a_i] << " ";
    cout << endl;
}
