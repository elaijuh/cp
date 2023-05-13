// https://leetcode.com/problems/longest-common-prefix/description/
// #pointer

char * longestCommonPrefix(char ** strs, int strsSize){
    int i=0;
    while(*(*strs+i)) {
        for(int j=1; j<strsSize; j++) {
            if(*(*(strs+j)+i) != *(*strs+i)) {
                *(*strs+i)='\0';
                return *strs;
            }
        }
        i++;
    }
    return *strs;
}
