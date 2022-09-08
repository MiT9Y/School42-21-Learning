//gcc -Wall -Wextra -Werror -L. -lasm test.c -o test && ./test && rm test

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "libasm.h"


void	print_list(t_list* list)
{
	while (list)
	{
		printf("P: %p, Data: %d\n", list->data, *( (int*) list->data));
		list = list->next;
	}
}

int	cmp_el_list(void* d1, void* d2)
{
	printf("D1: %d, D2: %d\n", *((int*)d1), *((int*)d2));
	if (*((int*)d1) > *((int*)d2))
		return 1;
	return 0;
}

int	equal_el(void* d1, void* d2)
{
	printf("EQU_D1: %d, EQU_D2: %d\n", *((int*)d1), *((int*)d2));
	if (*((int*)d1) == *((int*)d2))
		return 0;
	return 1;	
}

void	free_el(void* d1)
{
	printf("F_D1: %d\n", *((int*)d1));
	(void) d1;
	return;
}

int	main()
{
	char	str[1024];

	//TEST strlen
	printf("\n ---TEST STRLEN---\n");
	printf("LEN - %lu\n", strlen("Hello!"));
	printf("LEN - %lu\n", ft_strlen("Hello!"));

	//TEST strcpy
	printf("\n ---TEST STRCPY---\n");
	printf("STR - %s, (%s)\n", strcpy(str, "Hello"), str);
	printf("STR - %s, (%s)\n", ft_strcpy(str, "WWW"), str);

	//TEST strcmp
	printf("\n ---TEST STRCMP---\n");
	printf("CMP - %d\n", strcmp("Hello", "Hello"));
	printf("CMP - %d\n", ft_strcmp("Hello", "Hello"));

	//TEST write
	printf("\n ---TEST WRITE---\n");
	printf("WRITE LEN - %zd\n", write(1, "Hello\n", strlen("Hello\n")));
	printf("WRITE ERRNO - %d (%d)\n", errno, EBADF);
	printf("WRITE LEN - %zd\n", ft_write(1, "Hello\n", strlen("Hello\n")));
	printf("WRITE ERRNO - %d (%d)\n", errno, EBADF);

	//TEST read
	printf("\n ---TEST READ---\n");
	int	fd = open("test.txt", O_RDONLY);
	bzero(str, sizeof(str));
	ssize_t len = read(fd, str, 10);
	if (len > 0)
		printf("READ - %s\n", str);
	printf("READ LEN - %zd\n", len);
	printf("READ ERRNO - %d (%d)\n", errno, EBADF);	
	close(fd);
	fd = open("test.txt", O_RDONLY);
	bzero(str, sizeof(str));
	len = ft_read(fd, str, 10);
	if (len > 0)
		printf("READ - %s\n", str);
	printf("READ LEN - %zd\n", len);
	printf("READ ERRNO - %d (%d)\n", errno, EBADF);	
	close(fd);

	//TEST strdup
	printf("\n ---TEST STRDUP---\n");
	char*	str_p;
	str_p = strdup("Hello");
	printf("STR - %s\n", str_p);
	free(str_p);
	str_p = ft_strdup("Hello !!!");
	printf("STR - %s\n", str_p);
	free(str_p);

	//TEST ft_atoi_base
	printf("\n ---TEST ft_atoi_base---\n");
	printf("ATOI: %d\n", ft_atoi_base("\t\t -+-11d", "0123"));

	//TEST ft_list
	printf("\n ---TEST ft_list---\n");
	int	a1 = 10;
	int	a2 = 20;
	int	a3 = 30;
	int	a4 = 40;
	t_list*		list = NULL;

	ft_list_push_front(&list, &a1);
	ft_list_push_front(&list, &a3);
	ft_list_push_front(&list, &a2);
	ft_list_push_front(&list, &a4);

	print_list(list);
	
	printf("LEN LIST: %d\n", ft_list_size(list));
	printf("LEN LIST: %d\n", ft_list_size(NULL));

	ft_list_sort(&list, &cmp_el_list);
	print_list(list);

	t_list*	p = NULL;
	ft_list_sort(NULL, NULL);
	ft_list_sort(&p, &cmp_el_list);

	ft_list_remove_if(&list, &a1, &equal_el, &free_el);
	print_list(list);
	ft_list_remove_if(&list, &a2, &equal_el, &free_el);
	print_list(list);
	ft_list_remove_if(&list, &a3, &equal_el, &free_el);
	print_list(list);
	ft_list_remove_if(&list, &a4, &equal_el, &free_el);
	print_list(list);

	ft_list_remove_if(&list, &a4, &equal_el, &free_el);
	ft_list_remove_if(&list, NULL, NULL, NULL);
	ft_list_remove_if(NULL, NULL, NULL, NULL);

	getchar();

	return 0;
}