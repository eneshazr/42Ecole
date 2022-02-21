/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehazir <eneshazrr@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:37:15 by ehazir            #+#    #+#             */
/*   Updated: 2022/02/21 11:21:51 by ehazir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
typedef ifadesinin standart veri türleri (int, char vb.) dışında 
kullanıcı kendi belirlediği isimle tanımlayabilir.
Örn: typedef int armut;
Program içinde int bir değişken tanımlamak için
int ifadesi yerine armut ifadesini kullanabiliriz.

Yapı, farklı veri türlerini bir grup altında toplayan kullanıcı
tanımlı bir veri türüdür. İki veya daha fazla elemandan oluşur.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*
int main()
{
    char new1[] = "enes";
	t_list new;
    // new = (t_list *)malloc(sizeof(int));
    //printf("%s", (char *)ft_lstnew(new1));
	new = *ft_lstnew(new1);
	printf("%p", new.next);

}
*/