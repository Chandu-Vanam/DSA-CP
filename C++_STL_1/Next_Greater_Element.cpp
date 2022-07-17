#include <vector>
#include<bits/stdc++.h>

vector<int> nextGreaterElement(vector<int> input) {
	
    int n=input.size();
    vector<int>output(n);
    stack<int>s;

    output[n-1]=-1;;
	s.push(input[n-1]);
   
    int k=n-2;

    s.push(input[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        if(input[i]<s.top())
        {
            output[k--]=s.top();
        }
        else
        {
            while(!s.empty() && input[i]>=s.top())
            {
                s.pop();
            }
            if(s.empty())
            output[k--]=-1;
            else
            output[k--]=s.top();
        }
        s.push(input[i]);
    }

    return output;


}
