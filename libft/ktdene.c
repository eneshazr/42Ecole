#include "libft.h"
#include <stdio.h>

int main()
{
    char str[] = "eglendiremediklerimizdenmisiniz";
    char dest[40];
    
    ft_memset(str, '\0', 40);
    /* ft_bzero(str, 18); */
    /* ft_memcpy(dest, str,40); */
    printf("O: %s", str);
}
