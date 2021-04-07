#include<stdio.h>
#include<string.h>
int main(){
    int t;
    scanf("%d",&t);
    while (t--)
    {
        char str1[100],str2[100];
        int lcs[100][100],max=0;
        scanf("%s%s",&str1,&str2);
        int l1,l2,i,j;
        l1=strlen(str1);
        l2=strlen(str2);
        for(i=0;i<=l1;i++){
            lcs[0][i]=0;
        }
        for(i=0;i<=l2;i++){
            lcs[i][0]=0;
        }
        for(i=0;i<l1;i++){
            for(j=0;j<l2;j++){
                if(str1[i]==str2[j])
                {
                    lcs[i+1][j+1]=1+lcs[i][j];
                    if(lcs[i+1][j+1]>max){
                    max=lcs[i+1][j+1];
                }

                }
                else
                {
                    lcs[i+1][j+1]=0;
                }

            }
        }
        printf("%d",max);
       
    }
    
}
/*  if there are two string str1 and str2 we have to find the longest common substring 
     
     first we create a 2D array name lcs[lenth str1+1][lenth str2+1].then first colum and first row fill with 0
             
                                     LCS table
                    ------------>l2
        0  |  1   2   3   4   5   6   7   8   9   10  11  12  13  14
      -------------------------------------------------------------
   0  | 0  |  0   0   0   0   0   0   0   0   0    0   0   0   0   0
      --------------------------------------------------------------
   1  | 0  |                                                        
           |
 | 2  | 0  |                                                       
 |         |
 | 3  | 0  |                                                       
 |         |
 ↓ 4  | 0  |                                                       
l1         |
   5  | 0  |                                                       
           |
   6  | 0  |                                                                                                           
           |
   7  | 0  |                                                                                                               |
      -------------------------------------------------------------

      array will start from i=0 and j=0 but lcs value start from (i+1) and (j+1).if one element from str1 and str2 match 
       lcs value will be (1+previous corner lcs value).
       Maximum value will be the longest common subtstring.
       */
