#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<string.h>
using namespace std;

constexpr int SIZE=1e5+7;

//Origin version of Hash Table Reinvention
struct Hash_Table
{
    struct Node
    {
        int next,value,key;
    }data[SIZE];
    
    int head[SIZE],size;
    int f(int key){return (key%SIZE+SIZE)%SIZE;}

    int get(int key)
    {
        int h=f(key);
        for(int i=head[h];i;i=data[i].next)
            if(data[i].key==key)
                return data[i].value;
        return -1;
    }
    int modify(int key,int value){
        for(int p=head[f(key)];p;p=data[p].next)
            if(data[p].key==key)
                return data[p].value=value;
    }
    int add(int key,int value){
        if(get(key)!=-1) return -1;
        int h=f(key);
        data[++size]={head[h],value,key};
        head[h]=size;
        return value;
    }
};

//Oi Wiki provide packed version
struct Hash_Table_Packed{
    struct data {
    long long u;
    int v, nex;
  };  // 前向星结构
    static constexpr int SZ = 100000 + 7;
  data e[SZ << 1];  // SZ 是 const int 表示大小
  int h[SZ], cnt;

  int hash(long long u) { return (u % SZ + SZ) % SZ;} 

  int& operator[](long long u) {
    int hu = hash(u);  
    for (int i = h[hu]; i; i = e[i].nex)
      if (e[i].u == u) return e[i].v;
    return e[++cnt] = data{u, -1, h[hu]}, h[hu] = cnt, e[cnt].v;
  }

  Hash_Table_Packed() {
    cnt = 0;
    memset(h, 0, sizeof(h));
  }
};