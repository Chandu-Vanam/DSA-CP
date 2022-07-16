#include<bits/stdc++.h>
using namespace std;

long long power(long long a,long long b,long long m)
{
  	long long x=1,y=a;
  	while(b>0)
    {
    	if(b%2!=0)
        {
    	 	x=(x*y)%m;
    	}
    	y=(y*y)%m;
    	b>>=1;
  }
  return x;
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    long long n,p,i,result,z,x;
    
    while(t--)
    {
        result=-1;
        // int n,p;
        cin>>n>>p;
        
        if(n>=p)
        {
            cout<<"0"<<endl;
            continue;
        }
        x=1;
    	for(int i=n+1;i<p;i++)
        {
     		x=(x*i)%p;
    	}
      	z=power(x,p-2,p);
      	result=(result*z)%p;
    	cout<<p+result<<endl;
  		
    }
    
    return 0;
}
