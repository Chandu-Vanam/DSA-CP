int lengthOfLongestSubstring(string s) {
    // Write your code here.
    
	int st=0,total=0,maxi=0;
    int freq[26]={0};
    
    for(int e=0;e<s.size();e++)
    {
        if(freq[s[e]-'a']==0)
        {
            freq[s[e]-'a']++;
            total++;
        }
        else {
            freq[s[e]-'a']++;
        }
        
        if(total<=2)
        {
            maxi=max(maxi,e-st+1);
        }
        else
        {
            while(st<s.size() && total>2)
            {
                freq[s[st]-'a']--;
                
                if(freq[s[st]-'a']==0)
                    total--;
                
                st++;
            }
        }
        
    }
    return maxi;
}
