# Category: [Algorithms - implementation](https://www.hackerrank.com/domains/algorithms/implementation)
- ### [Between Two Sets](#Between-Two-Sets)
- ### [Save the Prisoner](#Save-the-Prisoner)
- ### [Circular Array Rotation](#Circular-Array-Rotation)
- ### [Append and Delete](#Append-And-Delete)
- ### [Extra Long Factorials](#Extra-Long-Factorials)
- ### [Sherlock and Squares](#Sherlock-and-Squares)
- ### [Non-Divisible Subset](#Non-Divisible-Subset)
- ### [Picking Numbers](#Picking-Numbers)
- ### [Bigger is Greater](#Bigger-is-Greater)
- ### [Flatland Space Stations](#Flatland-Space-Stations)
- ### [Manasa and Stones](#Manasa-and-Stones)
- ### [Strange Counter](#Strange-Counter)
- ### [Absolute Permutation](#Absolute-Permutation)
- ### [Larry's Array](#Larry's-Array)
- ### [Almost Sorted](#Almost-Sorted)
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
### [Append and Delete](https://www.hackerrank.com/challenges/append-and-delete/problem)
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



<a id="Sherlock-and-Squares"></a>
### [Sherlock and Squares](https://www.hackerrank.com/challenges/sherlock-and-squares/problem)
求a，b（b>a）两个整数间的完全平方数，可考虑x（完全平方数）满足区间范围:
> **ceil(sqrt(a)) <= x <= floor(sqrt(b))**

那么，floor(sqrt(b)) - ceil(sqrt(a)) + 1即为该区间内完全平方数个数（整数个），由于ceil操作包含一个整数被减去，所以最后需要加上个1



<a id="Non-Divisible-Subset"></a>
### [Non-Divisible Subset](https://www.hackerrank.com/challenges/non-divisible-subset/problem)
此题可通过模运算的性质：
**(a + b) % k = (a % k + b % k) % k**

推导出对于S中任意的两个数a，b之和如果能被k整除，那么下述结论成立:

**a % k + b % k = k** 
> Tip: 可用反证法证明

实现中使用一个数组（k<=100）保存S中每个元素的模：
```cpp
forv(s, n_i) {
        cin >> s[n_i];
        m[s[n_i]%k]++;
    }
```
需要注意两个模重叠的情况：
1. 当模为0时
2. 当k为偶数，模为k／2时

以上两种情况中任意两个数组合都可以被k整除，所以只取1即可（如果有的话），其他的模值取对应的大数即可：
```cpp
m[0] = m[0] ? 1 : 0;
if(0 == k % 2)
    m[k/2] = m[k/2] ? 1 : 0;
int ans = 0;
repe(0, k/2, i)
    ans += max(m[i], m[k-i]);
```



<a id="Picking-Numbers"></a>
### [Picking Numbers](https://www.hackerrank.com/challenges/picking-numbers)
由条件任意两数（0 < X < 100）之差小于等于1可知符合条件的X一定是相邻的两个数（或一个数），那么我们可以通过统计两两相邻数的数量解决：
```cpp
vi m(100, 0);
for(int a_i = 0;a_i < n;a_i++){
    int a;
    cin >> a;
    m[a]++;
}
int max_cnt = 0;
rep(1, 99, i)
    max_cnt = max(max_cnt, m[i]+m[i+1]);
```



<a id="Bigger-is-Greater"></a>
### [Bigger is Greater](https://www.hackerrank.com/challenges/bigger-is-greater/problem)
此题是实现nextPermutation的具体算法，该算法可用来快速求全排列：
1. 从排列的末端找到第一个逆序（降序排列），令逆序排列首位的索引为I，如果I为0，那么该排列已为最大排列
```cpp
int i = sz(s) - 1;
while(i > 0 && s[i-1] >= s[i])
    i--;
if(0 == i) {
    cout << "no answer" << endl;
    continue;
}
```
2. 在逆序排列中找出恰好大于（最小）I-1的元素J，交换I，J元素
```cpp
int j = sz(s) - 1;
while(s[j] <= s[i-1])
    j--;
SWAP(s[i-1], s[j]);

```
3. reverse逆序序列，即得nextPermutation
```cpp
j = sz(s) - 1;
while(i < j) {
    SWAP(s[i], s[j]);
    i++;
    j--;
}
```



<a id="Flatland-Space-Stations"></a>
### [Flatland Space Stations](https://www.hackerrank.com/challenges/flatland-space-stations/problem)
由题意可知，城市c[i]的距离可表示为：**min(c[i-1] + 1, c[i+1] + 1)**

那么可通过正向，反向遍历计算得出每个c[i]的距离，取最大值即可：
1. 以-1作为占位符，表示无限远，0表示空间站
```cpp
vi c(n, -1);
for(int c_i = 0;c_i < m;c_i++){
    int station;
    cin >> station;
    c[station] = 0;
}
```
2. 正向计算，空间站不需要计算，还需排除掉c[i-1]为-1的（前面还没有空间站）
```cpp
rep(1, n, i) {
    if(c[i-1] != -1 && c[i] != 0)
        c[i] = c[i-1] + 1;
}
```
3. 反向计算，若当前不为-1（正向有值），取较小的，反之直接取c[i+1] + 1
```cpp
int max_distance = -1;
for(int i=n-1; i>=0; i--) {
    int distance = c[i];
    if(i < n-1) {
        distance = distance != -1 ? min(distance, c[i+1] + 1) : c[i+1] + 1;
        c[i] = distance;
    }
    max_distance = max(max_distance, distance);
}
```


<a id="Manasa-and-Stones"></a>
### [Manasa and Stones](https://www.hackerrank.com/challenges/manasa-and-stones/problem)
通过观察排列Pi和n之间的关系：
 
Pi | n=2 | n=3 | n=4 | n=5
-- | --- | --- | --- | ---
1 | a | aa | aaa | aaaa
2 | b | ab | aab | aaab
3 | | bb | abb | aabb
4 | | | bbb | abbb
5 | | | | bbbb

可得：

**Pi = a\*(i-1) + b\*(n-i) *WHEN a != b***

**Pi = a\*(n-1) *WHEN a == b***



<a id="Strange-Counter"></a>
### [Strange Counter](https://www.hackerrank.com/challenges/strange-code)
设Ti为时间，Ri为轮换组次，Vi为值，观察下表：

Ti | Ri | Vi
-- | -- | --
1 | 0 | 3
2 | 0 | 2
3 | 0 | 1
4 | 1 | 6
5 | 1 | 5
... | ... | ...
10 | 2 | 12
11 | 2 | 11
... | ... | ...
21 | 2 | 1
22 | 3 | 24
... | ... | ...

可知，每r次轮换的对应第一个值的v0和t0的关系:

**v0 = 3\*pow(2, r)**

**t0 = v0 - 2**

取对数可得: 

**r = LOG(t/3) *WHEN t%3 == 0***

**r = LOG(t/3 + 1) *WHEN t%3 > 0***

最终可求得v: 

**v = v0 - (t - t0)**



<a id="Absolute-Permutation"></a>
### [Absolute Permutation](https://www.hackerrank.com/challenges/absolute-permutation/problem)
看表找规律:

K | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12
-- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | --
k=0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12
k=1 | 2 | 1 | 4 | 3 | 6 | 5 | 8 | 7 | 10 | 9 | 12 | 11
k=2 | 3 | 4 | 1 | 2 | 7 | 8 | 5 | 6 | 11 | 12 | 9 | 10
k=3 | 4 | 5 | 6 | 1 | 2 | 3 | 10 | 11 | 12 | 7 | 8 | 9

可见每隔2k个距离反折k个序列即为所得，可归纳为：
1. N必须为偶数个，奇数个无法全部反折
2. N % 2k必需为0，否则也无法反折
3. 如果k = 0，则为自然数列，无论奇偶
4. 一共有n/2k个反折序列
5. 每个序列反折k次即可



<a id="Larry's-Array"></a>
### [Larry's Array](https://www.hackerrank.com/challenges/larrys-array/problem)
该题涉及到一些数学概念：***[排列的奇偶性](https://zh.wikipedia.org/wiki/置换的奇偶性)***

不考虑复杂的数学过程，我们分别挑选两对数据(123, 321), (345, 543)进行左移操作，并计算其逆序数：

123 | 逆序数 | 321 | 逆序数 | 345 | 逆序数 | 543 | 逆序数
--- | --- | --- | --- | --- | --- | --- | ---
231 | 2 | 213 | 1 | 453 | 2 | 435 | 1
312 | 2 | 132 | 1 | 534 | 2 | 354 | 1
123 | 0 | 321 | 3 | 345 | 0 | 543 | 3

很明显***正序***无论如何移动都能够满足，***反序***的则无法满足题目要求，而正序的逆序数都为偶，反序的逆序数都为奇，而左移操作实际上是由两个交换组成的，按照排列的奇偶性：
> 一个偶置换可以由恒同置换通过偶数次两个元素互换（称为对换）得到，而一个奇置换可由奇数次对换得到。

我们可知一个奇排列（奇数个逆序）无法通过偶数个交换（左移）变成自然数列（排好序的），那么该题只要计算排列的奇偶性即可！



<a id="Almost-Sorted"></a>
### [Almost Sorted](https://www.hackerrank.com/challenges/almost-sorted)
该题可以先找到最左边和最右边违反排序规则的边界：l和r，然后判断(l, r)区间内是单调递增，还是单调递减来确定swap和reverse，最后通过检查[l, r]的边界条件，确定是否能最终形成有序排列
1. l = 0 同时 r = 0，已经是有序排列
2. 交换l和r的值，如果是reverse，还需交换l+1和r-1的值
3. 判断l-1和r+1的值是否符合条件
4. 判断l+1和r-1的值是否符合条件
