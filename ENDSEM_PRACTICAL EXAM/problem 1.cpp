#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string t="abcab";
    string p="ab";

    int n=t.size();
    int m=p.size();

    long long base=31;
    long long mod=1000000007;

    long long ph=0;
    long long th=0;
    long long power=1;

    for(int i=0;i<m-1;i++)
        power=(power*base)%mod;

    for(int i=0;i<m;i++)
    {
        ph=(ph*base+p[i])%mod;
        th=(th*base+t[i])%mod;
    }

    vector<int> ans;

    for(int i=0;i<=n-m;i++)
    {
        if(ph==th)
        {
            int j=0;
            while(j<m&&t[i+j]==p[j])
                j++;

            if(j==m)
                ans.push_back(i);
        }

        if(i<n-m)
        {
            th=(th-(t[i]*power)%mod+mod)%mod;
            th=(th*base+t[i+m])%mod;
        }
    }

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";

    return 0;
}
