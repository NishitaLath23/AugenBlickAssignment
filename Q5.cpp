#include <bits/stdc++.h>
using namespace std;

int hashAlgo(string s)
{
    int ans=0;
    int ch;
    for(int i=0; i<s.length(); i++)
    {
        ch=s[i];
        ans+=ch;
        ans*=17;
        ans=(ans%256);
    }
    return ans;
}
int main()
{
    string init_seq="rn=1,cm-,qp=3,cm=2,qp-,pc=4,ot=9,ab=5,pc-,pc=6,ot=7";
    //cin>>init_seq;
    int sum=0;
    string curr="";
    for(int i=0; i<init_seq.length(); i++)
    {
        if(init_seq[i]!=',')
            curr+=init_seq[i];
        else
        {
            sum+=hashAlgo(curr);
            curr="";
        }
    }
    sum+=hashAlgo(curr);
    cout<<"The sum of the results is: "<<sum;
    return 0;
}