/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int ans;
    
    int num1, num2;
    
    printf("Enter any two numbers: ");
    scanf("%d%d",&num1, &num2);
    
    for(int i = 1; i <= num1 && i <= num2; i++) {
        if(num1 % i == 0 && num2 % i == 0) {
            ans = i;
        }
    }
    
    printf("The H.C.F. is: ");
    printf("%d", ans);

    return 0;
}

