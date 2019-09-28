# 容器适配器
## 栈
### 构造函数
```
stack<T> s;//定义一个空栈
stack<T> s(v);//定义一个栈，并用容器中的元素初始化栈；
栈默认使用deque作为底层，当然也可以自己指定一个具有从尾端插入和删除元素的容器作为底层，
比如stack<T,vector<T>> s;
```
### 成员函数
```
s.pop();//弹出栈顶元素，但是不返回其值
s.push(val)；//向栈添加元素
s.top()；//返回栈顶元素，但是不将元素弹出
```
## 队列
## 优先队列

# 逆波兰式
逆波兰式，也叫后缀表达式，将运算符写在操作数之后
## 逆波兰式定义
```
1. 如果E本身是一个变量或者常量，则E本身逆波兰式
2. 如果E是 E1 op E2 ,z则其逆波兰式是 E1 F2 op
3. 如果E是(E1)形式，则其逆波兰式是E1的逆波兰式
```
举例：
（a+b)*c-(d+e)/f,这是一个中缀表达式
转换成后缀表达式的步骤如下：
```
根据运算级，先算减号：
((a+b)*c)((d+e)/f)-
之后对每个子表达式继续转换
((a+b)c*)((d+e)f/)-
(ab+c*)(de+f/)-
ab+c*de+f/-
```
## 将表达式转换成逆波兰式
```
1. 分配两个栈，S1存储临时运算符，S2存储当前输出序列
2. 从输入的表达式左侧开始取字符，如果是数字，则入栈S2，
3. 如果取出是运算符，且优先级大于栈S1的栈顶运算符（括号不参与比较），则该运算符入栈S1，否则将S1的栈顶元素出栈到S2，
   直到遇到S1的栈顶元素优先级大于当前从表达式取出的运算符，然后将取出的运算符入栈S1。
   ---为了保证栈S1中只有运算符且越靠近栈顶的运算符优先级越高
4. 如果取出的是左括号，直接入栈S1
5. 如果取出的是右括号，则将S1中的元素逐个出栈到S2，直到遇到一个左括号，然后舍弃这个左括号
6. 重复2~5，直到表达式取完字符，然后将栈S1中的运算符逐个出栈到S2
此时S2从栈底到栈顶的输出即为所求
```
- 关于运算符的优先级，+优先级大于+和-，其余同理
## 根据逆波兰式求表达式的值
假设逆波兰式放置在一个数组中，另外设置一个栈S
对数组从前往后遍历，每次执行如下操作
```
1. 如果是数字，则入栈
2. 如果是运算符，则出栈两个元素，作为运算符的操作数，将运算结果入栈
```

# 波兰式
波兰式也叫前缀表达式
## 由中缀表达式求前缀表达式的方法
```
与中缀求后缀的方法类似，只需要把表达式由从左边获取字符改为从右边开始获取字符，
运算符优先级小于S1栈顶元素时入栈S1，
将对左括号的处理改为对右括号的处理，
处理运算符时还是+优先级大于+和-，其余同理
最后将栈S2中的元素从栈顶到栈底输出即为所求表达式
```
## 根据前缀表达式求值
将表达式从左向右入栈，一旦栈顶两个元素都是操作数，出栈三个字符，将运算结果入栈
## 对比波兰式与逆波兰式，发现还是逆波兰式更好用
