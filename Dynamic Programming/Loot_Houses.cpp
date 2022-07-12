
int getMaxMoney(int arr[], int n, int i=0, int *temp=new int[10002]()){

	
    if(i>=n)
	{
		return 0;
	}
    if(temp[i]>0)
    {
        return temp[i];
    }
	int maximum=0;
    
	int including=arr[i]+getMaxMoney(arr, n, i+2, temp);
    
	int not_including=getMaxMoney(arr,n, i+1, temp);
    
	maximum=max(including, not_including);
    
    temp[i]=maximum;
	return maximum;
}

int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
    return getMaxMoney(arr,n);
}
