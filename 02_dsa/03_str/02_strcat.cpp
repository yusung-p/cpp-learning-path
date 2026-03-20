#include <iostream>
#include <cstring>
using namespace std;

typedef struct {
    char *ch = nullptr;
    int length = 0;
} HString;

bool StrAssign(HString &T, const char *chars) {
    if (T.ch) delete[] T.ch;
    int len = strlen(chars);
    T.ch = new char[len + 1];
    strcpy(T.ch, chars);
    T.length = len;
    return true;
}

// 拼接
bool Concat(HString &T, const HString &S1, const HString &S2) {
    if (T.ch) delete[] T.ch;
    T.length = S1.length + S2.length;
    T.ch = new char[T.length + 1];
    strcpy(T.ch, S1.ch);
    strcat(T.ch, S2.ch);
    return true;
}

// 求子串
bool SubString(HString &Sub, const HString &S, int pos, int len) {
    if (pos < 1 || pos > S.length || len < 0 || pos + len - 1 > S.length)
        return false;
    if (Sub.ch) delete[] Sub.ch;
    Sub.ch = new char[len + 1];
    strncpy(Sub.ch, S.ch + pos - 1, len);
    Sub.ch[len] = '\0';
    Sub.length = len;
    return true;
}

// 测试
int main() {
    HString S1, S2, T, Sub;
    StrAssign(S1, "Hello");
    StrAssign(S2, " World");

    Concat(T, S1, S2);
    cout << "拼接: " << T.ch << endl;

    SubString(Sub, T, 1, 5);
    cout << "子串(1~5): " << Sub.ch << endl;

    // 释放分配的内存
    if (S1.ch) delete[] S1.ch;
    if (S2.ch) delete[] S2.ch;
    if (T.ch) delete[] T.ch;
    if (Sub.ch) delete[] Sub.ch;
    return 0;
}
