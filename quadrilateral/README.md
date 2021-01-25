

# 📕 Introduction

## 🤔 Question

根据输入打印不同大小的四边形

* Input: size, integer number

* Output: variable size quadrilateral

* Examples:

  ![ex01](./example01.png)  	<img src="./example02.png" alt="ex02" style="zoom:85%;" />
  
  <img src="./example03.png" alt="ex03" style="zoom:50%;" />



## 🧐 思路

如果直接写其实要考虑的东西很多，但是分解成一个个小问题后就很简单了。

1. 首先是空格。空格要随着行数减少，到行数一半的时候为0，再开始增多。这个用绝对值可以实现。

2. 其次是星号。星号出现在每行空格打印完后，可以用图案的宽减去空格的空间获得。即每行空格打印完后剩下的都是星号了。

3. 最后是对称的星号。上述思路打印完只是一半的样子，如下图:

   ![img01](./img01.png)

   如果按第二步得到要打印k个星号，那再打印(k-1)x2个星号即可(因为中间的不用对称)，加起来就是k+(k-1)x2。

将问题分解成几个小部分后就简单了很多，接下来是展示代码。

**Code**:

* 使用绝对值实现星号前的空格打印个数控制，再通过减法算出星号需要的个数。

```c++
// n为输入，表示size; a为n的一半, int类型; b为n对于2的取余, int类型
int a = n / 2, b = n % 2;
// i为当前行数
for (i = 0; i < n; ++i) {
    // temp表示a-i的绝对值, a不变而i逐渐增加, 以此达到temp值从多到少再到多的效果。
    int temp = abs(a - i);
    for (j = 0; j < temp; ++j)
        cout << "  ";
    // 知道了当前行空格的数目, 接下来总空间减去空格的位置用来打印星号就好了
    for (x = 0; x < (a + b - temp + a + b - temp - 1); ++x)
        cout << "* ";
    // 每行结束以后换行
    cout << endl;
}
```

* 上述代码进行简化后即为

```c++
#include <iostream>
using namespace std;

int main(int args, char** argv) {

  // receive n and preprocessing
  int n = 0;
  cout << "Input: ";
  cin >> n;
  if (n < 0) {
    cout << "Wrong input!" << endl;
    return -1;
  }
  if (n % 2 == 0)
    ++n;
  // print quadrilateral
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < abs(n/2 - i); ++j)
      cout << "  ";
    for (int k = 0; k < (2 * (n/2 - abs(n/2 - i)) + 1); ++k)
      cout << "* ";
    cout << endl;
  }

  return 0;
}
```

