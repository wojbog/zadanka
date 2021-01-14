#include<bits/stdc++.h>
#define duzo 300003
using namespace std;
vector<int> tab[duzo];
int n,a,b;
int vertex[duzo];
bool visit[duzo];
int wynik,ppp; 
int dfs(int x, int k)
{
    int suma=0;
    int dzieci=0;
    visit[x]=true;
    for(int i=0;i<tab[x].size();i++)
    {
        if(!visit[tab[x][i]])
        {
            dzieci++;
            suma+=dfs(tab[x][i],k);
        }
    }
    return max(0,(suma+dzieci-k));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("plik.in","r",stdin);
    freopen("plik.out","w",stdout);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        tab[a].push_back(b);
        tab[b].push_back(a);
    }
    int l=1,sr,r=n-1;
    sr=(l+r)/2;
    while(l<=r)
    {
        ppp=dfs(1,sr);
        if(ppp==0)
        {
            wynik=sr;
            r=sr-1;
            sr=(l+r)/2;
        }
        else
        {
            l=sr+1;
            sr=(l+r)/2;
        }
        
        for(int j=0;j<n;j++)
            visit[j]=false;
        

    }
    cout<<wynik;
    /*
    for(int i=1;i<(n-1);i++)
    {
        ppp=dfs(1,i);
        if(ppp==0)
        {
            wynik=i;
            break;
        }
        for(int j=0;j<n;j++)
        visit[j]=false;

    }
    
    
    cout<<"----------------\n";
    for(int i=1;i<=n;i++)
    {
        cout<<vertex[i]<<"\n";
    }*/
    return 0;
}