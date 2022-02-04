#include "libft.h"
#include <stdio.h>
#include <string.h>

/*
Ptr parametresi ile gösterilen bellek bölgesinin
n parametre değeri kadar ilk byte'ında c parametresi ile
gösterilen değerin (unsigned char olarak değerlendirilir)
ilk geçtiği yeri arar ve bu bellek adresini gösteren bir işaretçi geri döndürür.
Eğer ptr parametresi NULL bir işaretçi ise anlamsız bir sonuç elde edilir.

ptr: Aramanın yapılacağı bellek bölgesinin başlangıcını gösteren bir işaretçidir.

c: Aranacak olan değeri gösterir. Değer int olarak verilir ancak fonksiyon
bu değeri unsigned char bir değere çevirerek arama işlemi yapar.

n: Ptr parametresi ile gösterilen bellek bölgesinde aranacak byte sayısını gösterir.
*/
void    *ft_memchr(const void *s, int c, size_t n)
{
    const char  *str;
    size_t  i;

    str = (const char *)s;
    i = 0;
    while (i < n)
    {
        if (str[i] == c)
            return ((void *)(s + i));
        i++;
    }
    return (0);
}

/*
Program memchr() fonksiyonu ile bir karakter dizisi içinde
'g' karakterini arar. Karakterin bellek adresini ekrana yazar.
*/

int main()
{
    const char *str = "armut";

    printf("%s", ft_memchr(str, 'm', 5));
    printf("\n%s", memchr(str, 'm', 5));
}
