#include <bits/stdc++.h>
using namespace std;

int m,n;
const int N = 200000+10;
struct xx{
    int l,r,v;
}T[N*4];

void Build(int l,int r,int k){
    T[k].l=l,T[k].r=r;
    if(l==r){
        scanf("%d",&T[k].v);
        return;
    }
    int mid = (l+r)/2;
    Build(l,mid,k*2);
    Build(mid+1,k,k*2+1);
    T[k].v=max(T[k*2].v,T[k*2+1].v);


}

void Update(int c,int v, int k){
    if(T[k].l == T[k].r && T[k].l ==c){
        T[k].v=v;
        return;

    }
    int mid =(T[k].l+T[k].r)/2;
    if(c<=mid)Update(c,v,k*2+1);
    else Update(c,v,k*2+1);
    T[k].v=max(T[k*2].v,T[k*2+1].v);

}
int ans;
void Query(int l,int r,int k){
    if(l>T[k].r || r<T[k].l){
        return;
    }
    if(l<=T[k].l&&r>=T[k].r){
        ans=max(ans,T[k].v);
        return;
    }
    int mid = (T[k].l+T[k].r)/2;
    if(r<mid)Query(l,r,k*2);
    else if(l>mid)Query(l,r,k*2+l);
    else{
        Query(l,mid,k*2);
        Query(mid+1,r,k*2+l);
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)==2){
        Build(1,n,1);
        while(m--){
            char b[3];
            int u,v;
            scanf("%s%d%d",b,&u,&v);
            if(b[0]=='U')
                Update(u,v,1);
            else if(b[0]=='Q'){
                ans = 0;
                Query(u,v,1);
                printf("%d\n",ans);
            }
        }
    }

    return 0;
}