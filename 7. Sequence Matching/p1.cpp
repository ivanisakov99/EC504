#include <iostream>

using namespace std;
  
// function to find out the minimum penalty
void getMinimumPenalty(string x, string y, int pxy, int pgap)
{
    int i, j; // intialising variables
      
    int m = x.length(); // length of gene1
    int n = y.length(); // length of gene2
      
    // table for storing optimal substructure answers
    int dp[m+1][n+1];

    for(int i = 0; i < m + 1; i++){
        for(int j = 0; j < n + 1; j++){
            dp[i][j] = 0;
        }
    }
  
    // intialising the table 
    for (i = 0; i <= (n+m); i++)
    {
        dp[i][0] = i * pgap;
        dp[0][i] = i * pgap;
    }    
  
    // calcuting the minimum penalty
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min({dp[i - 1][j - 1] + pxy , 
                                dp[i - 1][j] + pgap    , 
                                dp[i][j - 1] + pgap    });
            }
        }
    }
  
    // Reconstructing the solution
    int l = n + m; // maximum possible length
      
    i = m; j = n;
      
    int xpos = l;
    int ypos = l;
  
    // Final answers for the respective strings
    int xans[l+1], yans[l+1];
      
    while ( !(i == 0 || j == 0))
    {
        if (x[i - 1] == y[j - 1])
        {
            xans[xpos--] = (int)x[i - 1];
            yans[ypos--] = (int)y[j - 1];
            i--; j--;
        }
        else if (dp[i - 1][j - 1] + pxy == dp[i][j])
        {
            xans[xpos--] = (int)x[i - 1];
            yans[ypos--] = (int)y[j - 1];
            i--; j--;
        }
        else if (dp[i - 1][j] + pgap == dp[i][j])
        {
            xans[xpos--] = (int)x[i - 1];
            yans[ypos--] = (int)'_';
            i--;
        }
        else if (dp[i][j - 1] + pgap == dp[i][j])
        {
            xans[xpos--] = (int)'_';
            yans[ypos--] = (int)y[j - 1];
            j--;
        }
    }
    while (xpos > 0)
    {
        if (i > 0) xans[xpos--] = (int)x[--i];
        else xans[xpos--] = (int)'_';
    }
    while (ypos > 0)
    {
        if (j > 0) yans[ypos--] = (int)y[--j];
        else yans[ypos--] = (int)'_';
    }
  
    // Since we have assumed the answer to be n+m long, 
    // we need to remove the extra gaps in the starting 
    // id represents the index from which the arrays
    // xans, yans are useful
    int id = 1;
    for (i = l; i >= 1; i--)
    {
        if ((char)yans[i] == '_' && (char)xans[i] == '_')
        {
            id = i + 1;
            break;
        }
    }
  
    // Printing the final answer
    cout << "Minimum Penalty in aligning the genes = ";
    cout << dp[m][n] << "\n";
    cout << "The aligned genes are :\n";
    for (i = id; i <= l; i++)
    {
        cout<<(char)xans[i];
    }
    cout << "\n";
    for (i = id; i <= l; i++)
    {
        cout << (char)yans[i];
    }
    return;
}
  
// Driver code
int main(){
    // input strings
    string gene1 = "PERPLEX";
    string gene2 = "PURUSE";
      
    // intialsing penalties of different types
    int misMatchPenalty = 3;
    int gapPenalty = 1;
  
    // calling the function to calculate the result
    getMinimumPenalty(gene1, gene2, 
        misMatchPenalty, gapPenalty);
    return 0;
}