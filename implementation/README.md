# Implementation
- ### [Between Two Sets](#Between-Two-Sets)
- ### [Save the Prisoner](#Save-the-Prisoner)
***



<a id="Between-Two-Sets"></a>
### [Between Two Sets](https://www.hackerrank.com/challenges/between-two-sets)
分析：该题可以分解为求集合A的LCM（Least Common Multiple）和集合B的GCD（Greatest Common Divisor)，也即最小公倍数和最大公约数：
因为x一定是集合A的LCM的倍数，同时也一定是集合B的GCD的约数，所以可以继续简化为从LCM的倍数中找到能被GCD整除的数。
```cpp
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
```



<a id="Save-the-Prisoner"> </a>
### [Save the Prisoner](https://www.hackerrank.com/challenges/save-the-prisoner/problem)
分析：该题比较简单，但有两处陷阱：
1. N和M的数量级达到了10的9次方，要使用64位数据结构
2. 当求模运算返回0时，即为第N位
```cpp
I64 saveThePrisoner(I64 n, I64 m, I64 s){
    I64 mod = (m+s-1) % n;
    return 0 == mod ? n : mod;
}
```
