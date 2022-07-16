void func(char input[],int i)
{
    if(input[i]=='\0')
        return;
    
    func(input,i+1);
    
    if(input[i]==input[i+1])
    {
        int x=i;
        
        while(input[x+2]!='\0')
        {
            input[x+1]=input[x+2];
            x++;
        }
        input[x+1]='\0';
    }
}
void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/

	func(input,0);
}
