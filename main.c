/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:51:43 by fdarrin           #+#    #+#             */
/*   Updated: 2020/11/19 21:51:46 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int		main(void)
{
	int fd;
	int i = 0;
	char s[] = "Summary: The aim of this project is to get familiar with assembly language.";
	char *s1 = "";
	char *s2 = "hello";
	char *s3 = "assembler.";
	char buf[10];

	printf("\n-----------------------------------\n");
	printf("\n--------------STRLEN---------------\n");
	printf("\n-----------------------------------\n");
	printf("STANDART  - |%lu|\nFT_STRLEN - |%lu|\n", strlen(s), ft_strlen(s));
	printf("STANDART  - |%lu|\nFT_STRLEN - |%lu|\n", strlen(s1), ft_strlen(s1));
	printf("STANDART  - |%lu|\nFT_STRLEN - |%lu|\n", strlen(s2), ft_strlen(s2));

	printf("\n-----------------------------------\n");
	printf("\n--------------STRCPY---------------\n");
	printf("\n-----------------------------------\n");
	printf("FT_STRCPY - |%s|\n", ft_strcpy(s,"The aim of this project is to "
										  "get familiar with assembly language."));
	printf("STANDART  - |%s|\n", strcpy(s,"The aim of this project is to get "
									   "familiar with assembly language."));
	printf("FT_STRCPY - |%s|\n", ft_strcpy(s,""));
	printf("STANDART  - |%s|\n", strcpy(s,""));

	printf("\n-----------------------------------\n");
	printf("\n--------------STRCMP---------------\n");
	printf("\n-----------------------------------\n");
	printf("STANDART  - |%d|\nFT_STRCMP - |%d|\n",strcmp("", ""), ft_strcmp("",
			""));
	printf("STANDART  - |%d|\nFT_STRCMP - |%d|\n",strcmp("", s3), ft_strcmp
	("", s3));
	printf("STANDART  - |%d|\nFT_STRCMP - |%d|\n", strcmp(s2, ""), ft_strcmp
	(s2, ""));
	printf("STANDART  - |%d|\nFT_STRCMP - |%d|\n", strcmp(s2, s3), ft_strcmp
	(s2, s3));

	printf("\n-----------------------------------\n");
	printf("\n--------------WRITE----------------\n");
	printf("\n-----------------------------------\n");
	fd = open("test.txt", O_RDWR);
	printf("\nFT_WRITE - |%zd|\n", ft_write(1, "\nhello", ft_strlen("\nhello")));
	printf("\nSTANDART - |%zd|\n", write(1, "\nhello", ft_strlen("\nhello")));
	printf("\nFT_WRITE - |%zd|\n", ft_write(fd, "assembler.", ft_strlen
	("assembler.")));
	printf("STANDART - |%zd|\n", write(fd, "assembler.", ft_strlen
	("assembler.")));
	fd = -1;
	printf("\nFT_WRITE - |%zd|\n", ft_write(fd, "assembler.", ft_strlen
	("assembler.")));
	printf("ERRNO FT_WRITE - |%d|\n", errno);
	printf("\nSTANDART - |%zd|\n", write(fd, "assembler.", ft_strlen
	("assembler.")));
	printf("ERRNO STANDART - |%d|\n", errno);

	printf("\n-----------------------------------\n");
	printf("\n--------------READ-----------------\n");
	printf("\n-----------------------------------\n");
	fd = open("test.txt", O_RDONLY);
	printf("\nRETURN STANDART - |%zd|\n", read(fd, buf, 10));
	printf("RESULT STANDART - |%s|\n", buf);
	printf("\nRETURN FT_READ  - |%zd|\n", ft_read(fd, buf, 10));
	printf("RESULT FT_READ  - |%s|\n", buf);
	while (i < 10)
		buf[i++] = 0;
	printf("\nCheck STDIN. Enter 3 symbols:\n");
	read(0, buf, 3);
	printf("RESULT - |%s|\n", buf);
	fd = -1;
	printf("\nRETURN STANDART - |%zd|\n", read(fd, buf, 10));
	printf("ERRNO STANDART  - |%d|\n", errno);
	printf("\nRETURN FT_READ  - |%zd|\n", ft_read(fd, buf, 10));
	printf("ERRNO FT_READ   - |%d|\n", errno);

	printf("\n-----------------------------------\n");
	printf("\n--------------STRDUP---------------\n");
	printf("\n-----------------------------------\n");
	printf("\nFT_STRDUP - |%s|\n", ft_strdup(s2));
	printf("STANDART  - |%s|\n", strdup(s2));
	printf("FT_STRDUP - |%s|\n", ft_strdup(""));
	printf("STANDART  - |%s|\n", strdup(""));
	printf("FT_STRDUP - |%s|\n", ft_strdup("abcdefghijklmnopqrstuvwxyz"));
	printf("STANDART  - |%s|\n", strdup("abcdefghijklmnopqrstuvwxyz"));
	printf("\n-----------------------------------\n");
	return (0);
}
