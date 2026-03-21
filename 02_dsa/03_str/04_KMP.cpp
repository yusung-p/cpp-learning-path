#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef vector <char> String;
//计算next数组
void get_next(const String&T,vector<int>&next){
    int i=1;
    int j=0;
    next.resize(T[0]+1);
    next[1]=0;
    while(i<T[0]){
        if(j==0||T[i]==T[j]){
            i++;
            j++;
            next[i]=j;
        }else{
            j=next[j];
        }
    }
}
//计算nextval数组
void get_nextval(const String&T,vector<int>&nextval){
    int i=0;
    int j=1;
    nextval.resize(T[0]+1);
    nextval[1]=0;
    while(i<T[0]){
        if(j==0||T[i]==T[j]){
            i++;
            j++;
            if(T[i]!=T[j]){
                nextval[i]=j;
            }else{
                nextval[i]=nextval[j];
            }
        }else{
            j=nextval[j];
        }
    }
}
//KMP匹配
int Index_KMPnext(const String&S,const String&T,int pos){
    int i=pos;
    int j=1;
    vector <int>next;
    get_next(T,next);
    while(i<=S[0]&&j<=T[0]){
        if(j==0||S[i]==T[j]){
            ++i;
            ++j;
        }else{
            j=next[j];
        }
    }
    if(j>T[0]){
        return i-T[0];
    }else{
        return 0;
    }
}
int Index_KMPnextval(const String&S,const String&T,int pos){
    int i=pos;
    int j=1;
    vector <int>nextval;
    get_nextval(T,nextval);
    while(i<=S[0]&&j<=T[0]){
        if(j==0||S[i]==T[j]){
            ++i;
            ++j;
        }else{
            j=nextval[j];
        }
    }
    if(j>T[0]){
        return i-T[0];
    }else{
        return 0;
    }
}
void StrAssign(String &T,const string&chars){
    T.resize(chars.size()+1);
    T[0]=chars.size();
    for(size_t i=0;i<chars.size();++i){
        T[i+1]=chars[i];
    }
}
int main(){
    String S,T;
    StrAssign(S,"ababcabcacbab");
    StrAssign(T,"abcac");
    int pos1=Index_KMPnext(S,T,1);
    int pos2=Index_KMPnextval(S,T,1);
    if(pos1!=-0){
        cout<<"匹配成功，位置："<<pos1<<endl;
    }else{
        cout<<"匹配失败"<<endl;
    }
    if(pos2!=-0){
        cout<<"匹配成功，位置："<<pos2<<endl;
    }else{
        cout<<"匹配失败"<<endl;
    }
    return 0;
}
