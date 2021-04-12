#include<stdio.h>
int main(){
    char str[100];
    gets(str);
    int l=strlen(str);
    int dia[l+1][l+1],max=0;
    for(int i=0;i<l;i++){
        dia[i][i]=1;
    }
    for(int i=0;i<l-1;i++){
        if(str[i]==str[i+1]){
            dia[i][i+1]=1;
        }
        else{
            dia[i][i+1]=0;
        }
    }
    for(int i=2;i<l;i++){
        int k=i;
        for(int j=0;j<l;j++,k++){
            if(str[j]==str[k] && dia[j+1][k-1]==1)
            {
                dia[j][k]=1;
                if(max<k-j){
                    max=k-j;
                }
            }
            else{
                dia[j][k]=0;
            }

        }
    }
    printf("%d",max+1);/*here +1? is for when count the difference of (k-j) there j starts from 0,
                        but in string lenth 0 doen't count .that why our difference is always 1 less.for that we 
                        added +1 with the max*/


}
/*In the first loop we compare each element in the array and every element in an array is palindropme for that
we make the main diagonal 1 .In the second loop we compare array elements pair by pair and if one pair is match then they are palindrome.
last we compare them in three element ...four ... and so on.
the largest difference of the column and row is the maximum lenth of the longest palindromic substring.
*/
