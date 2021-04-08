//KMP search algorithm//

#include<stdio.h>
#include<string.h>
int lps[100];
char pattern[100],str[100];
void lps_value()
{
    int index=0,i,l=strlen(pattern);
    lps[0]=0;
    for(i=1;i<l;){
        if(pattern[index]==pattern[i])
        {
            
            lps[i]=index+1;
            i++,index++;

        }
        else{
            if(index!=0){
                index=lps[index-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }

}
/*first we will create the lps array.Then we start to compare pattern string from index=0 and i=1.
if two element are same the value of lps[i]  will be (index+1).if the element aren't match then index
value will be pevious index lps value.and if previous index lps value is 0 then lps[i] will be 0.

*/

void kmp(){
    int i,j=0,count=0;
    for(i=0;i<strlen(str);){
        if(str[i]==pattern[j]){
            count++;
            i++,j++;
            if(count==strlen(pattern)){
                printf("found\n");
                break;
            }
        }
        else{
            if(j!=0){
                j=lps[j-1];
                count=j;
            }
            else
            {
                i++;
            }
        }
    }
}
/*
 kmp work the same way like we get the value of lps array.if we found that count become the lentgh of pattern 
 then we can print 'found' .
 */
int main()
{
   
    scanf("%s%*c%s",&str,&pattern);
    lps_value();
    kmp();
    return 0;
}
