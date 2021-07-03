/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

// 0 1 1 2 3 5 

int main() {
    int num;
    int n;
    int a=0;
    int b=1;
    
    
    printf("Enter the range: ");
    scanf ("%d" , &num);
    printf("%d %d ", a,b);
    for (int i=0;i<num-2 ;i++)
    {
        n=a+b;
        a=b;
        b=n;
        printf ("%d ",n);
    }
    

    return 0;
}
