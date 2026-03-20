#include <iostream>
#include <cstring>
using namespace std;

// 串的堆分配存储
typedef struct {
    char *ch;
    int length;
} HString;

// 赋值
bool StrAssign(HString &T, const char *chars) {
    if (T.ch) delete[] T.ch;
    int len = strlen(chars);
    if (len == 0) {
        T.ch = NULL;
        T.length = 0;
        return true;
    }
    T.ch = new char[len + 1];
    strcpy(T.ch, chars);
    T.length = len;
    return true;
}
int Index(const HString &S, const HString &T, int pos = 1) {
    // 从主串第 pos 个字符开始匹配
    int i = pos - 1;  // 主串指针，转为 0 下标
    int j = 0;        // 模式串指针

    while (i < S.length && j < T.length) {
        if (S.ch[i] == T.ch[j]) {
            // 字符相等，继续比较下一个
            i++;
            j++;
        } else {
            // 不相等，回溯！
            i = i - j + 1;  // 主串回到本次匹配起始点的下一位
            j = 0;          // 模式串回到开头
        }
    }

    // 模式串全部匹配完，返回位置（1-based）
    if (j == T.length) {
        return i - j + 1;
    } else {
        return 0;  // 匹配失败
    }
}
int main() {
    HString S{nullptr, 0}, T{nullptr, 0};
    // 主串
    StrAssign(S, "ababcabcacbab");
    // 模式串
    StrAssign(T, "abcac");

    int pos = Index(S, T);

    if (pos != 0) {
        cout << "匹配成功，位置：" << pos << endl;
    } else {
        cout << "匹配失败" << endl;
    }

    return 0;
}
