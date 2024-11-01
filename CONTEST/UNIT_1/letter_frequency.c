#include <stdio.h>
#include <string.h>

#define ALPHABET_LEN 26

int main (){
    char c = getchar();
    while (getchar() != '\n');
    char buffer[100];

    fgets(buffer,sizeof(buffer),stdin);
//question: size_t laf gi vay? 
/*answer size_t is an unsigned data type, usually used to represent the size,
 length of the object*/
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n'){
        buffer[len - 1] = '\0';
    }
	int count = 0;
	for (int i = 0; i < len ; i++) {
		if (c == buffer[i]) count ++;
	}
	printf("%d",count);

	return 0;
}
