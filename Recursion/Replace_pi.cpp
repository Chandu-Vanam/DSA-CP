// Change in the given string itself. So no need to return or print anything
void func(char input[],int s)
{
    if(input[s]=='\0' || input[s+1]=='\0')
        return;
    
         
      func(input,s+1);
    
    if(input[s]=='p' && input[s+1]=='i')
    {
        int n=0;
    	for(int i=0;input[i]!='\0';i++)
        n++;
        input[s]='3';
        input[s+1]='.';
        int x=n-1;
        while(x!=s)
        {
            input[x+2]=input[x];
            x--;
        }
        input[s+2]='1';
        input[s+3]='4';
        
    }

     
}
void replacePi(char input[]) {
	// Write your code here
		
    return func(input,0);
    
}


