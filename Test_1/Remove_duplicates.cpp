#include<bits/stdc++.h>

void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/
	int cnt=0;
    
    for(int i=0;input[i]!='\0';i++)
        cnt++;
    
    if(cnt<=0)
        return;
    
    char ch[cnt+1];
    
    int i;
    int k=0;
    bool flag=false;
    
    for(i=1;i<cnt;i++)
    {
        if(input[i-1]!=input[i])
        {
           ch[k++]=input[i-1];
            // if(i==cnt)
            //     flag=true;
        }
    }
    
    // if(flag)
    ch[k]=input[cnt-1];
    
    i=0;
    for(i=0;i<k+1;i++)
        input[i]=ch[i];
    
    	input[i]='\0';
}
