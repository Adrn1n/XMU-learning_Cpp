/*
递归求波兰表达式
描述

站在巨人的肩膀上，编程之路才能越走越宽。小华继续向小鲁讲授新的知识点：波兰表达式。

逆波兰表达式，英文为 Reverse Polish notation，跟波兰表达式（Polish notation）相对应。

之所以叫波兰表达式和逆波兰表达式，是为了纪念波兰的数理科学家 Jan Łukasiewicz的创意。

平时我们习惯将表达式写成 (1 + 2) * (3 + 4)，加减乘除等运算符写在中间，因此称呼为中缀表达式。
而波兰表达式的写法为 (* (+ 1 2) (+ 3 4))，将运算符写在前面，因而也称为前缀表达式。
逆波兰表达式的写法为 ((1 2 +) (3 4 +) *)，将运算符写在后面，因而也称为后缀表达式。
波兰表达式和逆波兰表达式有个好处，就算将圆括号去掉也没有歧义。上述的波兰表达式去掉圆括号，变为* + 1 2 + 3 4。逆波兰表达式去掉圆括号，变成1 2 + 3 4 + *也是无歧义并可以计算的。事实上我们通常说的波兰表达式和逆波兰表达式就是去掉圆括号的。而中缀表达式，假如去掉圆括号，将 (1 + 2)(3 + 4) 写成 1 + 23 + 4，就改变原来意思了。

(2 + 3) * 4的波兰表示法为* + 2 3 4

请写程序求解波兰表达式的值。

注意：本题输入的运算符只包括如下4个运算符：+ - * /

提示：可使用atof(str)把字符串转换为一个double类型的浮点数，方便求解。


输入
输入为一行波兰表达式，其中运算符和运算数之间都用空格分隔，运算数是浮点数。


输出
输出为一行，表达式的值。

可直接用printf("%f\n", v)输出表达式的值v。


输入样例 1

* + 11.0 12.0 + 24.0 35.0
输出样例 1

1357.000000
提示

Andy讲解(2021) (https://www.bilibili.com/video/BV12f4y1s7yV)
*/

#include <iostream>
#include <string>

using namespace std;

typedef string::iterator str_it;

double Cal(str_it &Start,const str_it &End)
{
    for(; Start<End; ++Start)
    {
        switch(*Start)
        {
        case '+':
        {
            double a=Cal(++Start,End);
            double b=Cal(++Start,End);
            return a+b;
        }
        case '-':
        {
            double a=Cal(++Start,End);
            double b=Cal(++Start,End);
            return a-b;
        }
        case '*':
        {
            double a=Cal(++Start,End);
            double b=Cal(++Start,End);
            return a*b;
        }
        case '/':
        {
            double a=Cal(++Start,End);
            double b=Cal(++Start,End);
            return a/b;
        }
        default:
            break;
        }
        if((*Start>='0')&&(*Start<='9'))
        {
            double res=atof((char *)(&(*Start)));
            while((*Start!=' ')&&(Start<End))
                ++Start;
            return res;
        }
    }
    return 0;
}

int main()
{
    string PN;
    getline(cin,PN);
    str_it Start=PN.begin();
    printf("%f\n", Cal(Start,PN.end()));
    return 0;
}
