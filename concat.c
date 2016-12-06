/*
 * Sec. 17.2
 * function concat()
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *concat(const char *s1, const char *s2);

int main(void)
{
 for (int i=1; i<=5*1E4; i++)
 {
 char str1[]="I love";
 char str2[]=" Programming.";
 char *sentence;

 sentence=concat(str1, str2);

 printf("%s", sentence);
 printf("\n");

 free(sentence);
 }
 return 0;
}

char *concat(const char *s1, const char *s2)
{
 char *result;

 result=(char *) malloc(strlen(s1)+strlen(s2)+1);
 if (!result) exit(1);

 strcpy(result, s1);
 strcat(result, s2);

 return result;
}
