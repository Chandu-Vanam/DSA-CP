#include<bits/stdc++.h>

string reverseString(string str)
{
    // Write your code here.
    vector<string>tmp;
    
    int i=0;
    string word;
    while(i<str.size())
    {
        if(str[i]==' ')
        {
            tmp.push_back(word);
            word.clear();
            
            while(i<str.size() && str[i]==' ')
                i++;
        }
        else
        {
            word+=str[i];
            i++;
        }
    }
    
    if(word.length()!=0)
        tmp.push_back(word);
    
    str.clear();
    
    for(int i=tmp.size()-1;i>=0;i--)
    {
        str.append(tmp[i]);
        str+=' ';
    }
    
    str.pop_back();
    
    return str;
}
