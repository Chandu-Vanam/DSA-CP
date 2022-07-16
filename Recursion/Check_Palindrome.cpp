bool check(char input[],int i,int j)
{
    if(i==j)
        return true;
    
    if(input[i]!=input[j])
        return false;
    
    if(i<j+1)
    return check(input,i+1,j-1);
    
    return true;
}

bool checkPalindrome(char input[]) {
    // Write your code here
    
    int j=0;
    for(int k=0;input[k]!='\0';k++)
        j++;
    
    j--;
    
    return check(input,0,j);

}


