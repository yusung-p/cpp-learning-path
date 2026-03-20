#include <iostream>
#include <cstring>
using namespace std;
//串的堆分配储存结构
typedef struct {
    char *ch;
    int length;
}HString;

//初始化
void InitString(HString &T) {
    T.ch = nullptr;
    T.length = 0;
}

//赋值
bool StrAssign(HString &T,const char *chars){
    if (T.ch) delete []T.ch;
    int len = strlen(chars);
    if(len==0){
        T.ch=NULL;
        T.length=0;
        return true;
    }
    T.ch=new char[len+1];
    strcpy(T.ch,chars);
    T.length=len;
    return true;
}
//求长度
int StrLength(HString S){
    return S.length;
}
//比较
int StrCompare(const HString &S,const HString &T){
    int minLen = S.length < T.length ? S.length : T.length;
    for(int i = 0; i < minLen; i++) {
        if (S.ch[i] != T.ch[i]) {
            return (unsigned char)S.ch[i] - (unsigned char)T.ch[i];
        }
    }
    return S.length - T.length;
}
//清空
void ClearString(HString &S){
    if(S.ch){
        delete[]S.ch;
        S.ch=NULL;
        S.length=0;
    }
}
int main(){
    HString S,T;
    InitString(S);
    InitString(T);

    StrAssign(S,"Hello");
    StrAssign(T,"Hello");
    cout<<"S长度："<<StrLength(S)<<endl;
    cout<<"S和T比较："<<StrCompare(S,T)<<endl;
    ClearString(S);
    cout<<"清空后S长度："<<StrLength(S)<<endl;

    ClearString(T);
    return 0;
}