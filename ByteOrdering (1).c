

//program to find the host byte order
#include<stdio.h>
#include<stdlib.h>
union{
 short s;
 char c[sizeof(short)];
 } un;
int main(int argc, char **argv)
{
 un.s = 0x0102;// hex value of 01 and 02 assigned to the variable, host assign the value to variable according to its host byte ordering standard.
    
printf("%d\n",un.s); // print decimal value of hex value 0102
 if (sizeof(short) == 2) {
 if (un.c[0] == 1 && un.c[1] == 2) // check if MSB is 1st byte
 printf("big-endian\n");
 else if (un.c[0] == 2 && un.c[1] == 1) // check if MSB is  2nd byte
 printf("little-endian\n");
 else
 {
     printf("unknown\n");
 } 
 
 printf("sizeof(short) = %lu\n", sizeof(short));
 
     un.s = htons(un.s); // conversion to network byte order
     
     printf("%d\n",un.s); // printing decimal value after coverting to netwrok byte order
     
     if (sizeof(short) == 2) {
     if (un.c[0] == 1 && un.c[1] == 2) // check if MSB is 1st byte
     printf("After conversion: big-endian\n");
     else if (un.c[0] == 2 && un.c[1] == 1) // check if MSB is  2nd byte
     printf("After coversion : little-endian\n");
     else
     {
         printf("unknown\n");
     }

     }
     
     return 0;
}
}
