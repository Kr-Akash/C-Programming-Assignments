#include <ctype.h>
#include <string.h>
#include "revwords.h"

void reverse_substring(char str[], int start, int end) { 
  char temp;
  while(start < end){
	//swap the character str[start] with str[end]  
	temp = str[start];
	str[start] = str[end];
	str[end] = temp;
	++start; //move one index to the right
	--end; //move one index to the left
  }
}


int find_next_start(char str[], int len, int i) { 
  if(i == 0 && len > 0) //the first character is the starting index of the non-empty string
  	return 0;
  for(int k = i; k < len; ++k){
  	//after reading ' ' space character, if there is atleast one more character to the right of space
  	//then that is the next_start of the new word
  	if(str[k] == ' ' && (k+1 < len))
  		return k+1;
  }
  return -1; //there is no more word left, so return -1
}

int find_next_end(char str[], int len, int i) {

  for(int k = i; k < len; ++k){
  	if(str[k] == ' ' || str[k] == ',' || str[k] == '.' || str[k] == '!' || str[k] == '?'){
  		return k-1;
  	}
  }
  return -1; // i >= len, i must be strictly less than len, so return -1
}

void reverse_words(char s[]) { 
	int len = strlen(s);
	int ns = 0, ne = 0; //ns means next_start index, ne means next_end index of any word
	//loop while ns does not equals to -1, -1 means there is no more next word.
	while((ns = find_next_start(s, len, ns)) != -1){
		ne = find_next_end(s, len, ns);
		reverse_substring(s, ns, ne);
		//previous ending word index +1 will be the new i to be passed in the find_next_start function
		ns = ne+1;
		
	}
}

















