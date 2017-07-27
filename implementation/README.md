# Implementation
- ### [Between Two Sets](#Between-Two-Sets)
- ### [Save the Prisoner](#Save-the-Prisoner)
- ### [Circular Array Rotation](#Circular-Array-Rotation)
- ### [Append And Delete](#Append-And-Delete)
- ### [Extra Long Factorials](#Extra-Long-Factorials)
***



<a id="Between-Two-Sets"></a>
### [Between Two Sets](https://www.hackerrank.com/challenges/between-two-sets)
该题可以分解为求集合A的LCM（Least Common Multiple）和集合B的GCD（Greatest Common Divisor)，也即最小公倍数和最大公约数：
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



<a id="Save-the-Prisoner"></a>
### [Save the Prisoner](https://www.hackerrank.com/challenges/save-the-prisoner/problem)
该题比较简单，但有两处陷阱：
1. N和M的数量级达到了10的9次方，要使用64位数据结构
2. 当求模运算返回0时，即为第N位
```cpp
I64 saveThePrisoner(I64 n, I64 m, I64 s){
    I64 mod = (m+s-1) % n;
    return 0 == mod ? n : mod;
}
```



<a id="Circular-Array-Rotation"></a>
### [Circular Array Rotation](https://www.hackerrank.com/challenges/circular-array-rotation/problem)
此题检查条件和约束条件比较宽松，editor的解法是O(n)级别的，实际上是可以O(1)实现：
1. 首先计算经过k次右移，数组的第一个元素所对应的index到哪了
> `int start = k % n`;
2. 计算移动后的m对应的原index
> `int shift = m - start;`
3. 如果m < 0则加上n，因为可以把-1看成n-1，-2看成n-2，学过python的应该很容易理解；如果m >= 0，则表示移动前所在的位置
> `int i = shift >= 0 ? shift : (n + shift);`



<a id="Append-And-Delete"></a>
### [Append And Delete](https://www.hackerrank.com/challenges/append-and-delete/problem)
解决此题的思路可从考虑k和s，t的长度之间的关系开始：
1. k >= s + t，显然可以满足题目要求
2. s == t， 显然任何k都可以满足要求
3. (s + t) > k >= (s + t - 2*cpl(s, t))，cpl指的是s和t的公共前缀长度，令：diff = s + t - 2\*cpl(s, t)，那么就要考虑diff和k之间的**奇偶性**，相同则满足，不相同则不满足



<a id="Extra-Long-Factorials"></a>
### [Extra Long Factorials](https://www.hackerrank.com/challenges/extra-long-factorials/problem)
求阶乘，但需要解决数据超过64位数范围，实际是BigInteger的乘法问题，可以采用vector来存储BigInteger，低位索引对应到BigInteger的低位，高位索引对应高位。乘法的实现分为2个步骤：
1. 由低至高逐位相乘，计算进位和余数
```cpp
rep(0, k, j) {
    result[j] *= i;
    result[j] += carry;
    carry = result[j]/10;
    result[j] %= 10;
}
```
2. 向更高位进位
```cpp
while(carry) {
    result[k] = carry;
    carry = result[k]/10;
    result[k] %= 10;
    k++;
}
```

