// { Driver Code Starts
//Initial Template for C


#include <stdio.h>

 // } Driver Code Ends
//User function Template for C

void toBinary(int N)
{
    // your code here
    int bin[32],i=0;
    while(N!=0)
    {
        bin[i++] = N%2;
        N/=2;
        
    }
    for(int j=i-1;j>=0;j--)
    {
        printf("%d", bin[j]);
    }
        
}

// { Driver Code Starts.

int main() {
	//code
	
	int t;
	scanf("%d", &t);
	
	
	while(t--)
	{
	    int n;
	    scanf("%d", &n);
	    
	    toBinary(n);
	    printf("\n");
	}
	return 0;
}  // } Driver Code Ends