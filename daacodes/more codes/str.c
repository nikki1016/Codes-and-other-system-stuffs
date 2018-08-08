#include <stdio.h>
#include <string.h>

int main() {
	int t,i;
	scanf("%d",&t);
	while(t--){
	    char str[1000];
	    scanf("%s",str);
	    int l = strlen(str);
	printf("%d l\n",l);
	    char str1[l],str2[l];
	    i=0;
	    int j = 0;
	    int k = 0;
	    while(i < l){
	        if(str[i] >= 'a' && str[i] <= 'z'){
	            str1[j++] = str[i];
	        }
	        else if(str[i] >= 'A' && str[i] <= 'Z'){
	            str2[k++] = str[i];
	        }
		i++;
	    }
	    str1[j] = str2[k]  = '\0';
		printf("%d j %s  str1\n",j,str1);
		printf("%d k %s  str2\n",k,str2);
	    int brr[26] = {0};
	    for(i = 0; i < j; i++){
	        brr[ str1[i] - 'a']++;
	    }
	    for(i = 1; i < 26; i++){
	        brr[i] = brr[i] + brr[i-1];
	    }
	    for(i = j-1; i >= 0; i--){
	        str[brr[str1[i] - 'a'] -1] = str1[i];
		brr[ str1[i] - 'a' ]--;
	    }
		
	    for(i = 0; i<j ;i++){
	        str1[i]  = str[i];
	    }
	    
	     for(i = 0; i<26 ;i++){
	        brr[i]  = 0;
	    }
	    for(i = 0; i < k; i++){
	        brr[ str2[i] - 'A']++;
	    }
	    for(i = 1; i < 26; i++){
	        brr[i] = brr[i] + brr[i-1];
	    }
	    for(i = k-1; i >= 0; i--){
	        str[brr[str2[i] - 'A'] -1] = str2[i];
		brr[ str2[i] - 'A' ]--;
	    }
		
	    for(i = 0; i<k ;i++){
	        str2[i]  = str[i];
	    }
		printf("%d j %s  str1\n",j,str1);
		printf("%d k %s  str2\n",k,str2);
	    for(i = 0; i< j && i < k; i++ ){
	        printf("%c",str2[i]);
	        printf("%c",str1[i]);
	    }
	    while(i <j  ){
	         printf("%c",str1[i++]);
	    }
	    while(i < k  ){
	         printf("%c",str2[i++]);
	    }
	    printf("\n");
	}
	return 0;
}
