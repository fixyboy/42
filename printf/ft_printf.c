/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:52:43 by fhassane          #+#    #+#             */
/*   Updated: 2024/12/05 20:21:35 by fhassane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
int calculate_len_int (int n)
{
    int count;
    count = 0;
    if (n == 0)
        return 1;
    if (n < 0 )
    {
        count++;
        n = n * -1;
    }
    while (n != 0)
    {
        count++;
        n = n /10;
    }
    return (count);
}
void    ft_putchar (char c)
{
    write (1 , &c, 1);
}
void    ft_putstr (char *s)
{
    if (!s)
        return;
    while (*s)
    {
        write (1, s, 1);
        s++;
    }
}
int ft_strlen(char *s)
{
    int i;
    i = 0;

    while (s[i] != '\0')
        i++;
        return (i);
}
void ft_putnbr(int x)
{
    if (x == -2147483648)
    {
        write (1, "-", 1);
        write (1, "2" , 1);
        ft_putnbr(147483648);
    }
    else if(x < 0)
        {
            x = x * - 1;
            write (1, "-", 1);
        }
    else if (x >= 10)
     {
         ft_putnbr(x / 10);
         ft_putnbr(x % 10);
     }
     else if (x >= 0 && x <= 9)
     {
        ft_putchar(x + 48);
     }
}
int ft_printf(const char *format, ...)
{
    int return_value;
    return_value = 0;
    va_list args;
    va_start(args, format);
    
   
    int x;
    char    f;
    char * str;
    if(format[0] == '%' && format[1] == 'd' && format[2] == '\0')
    {
        x = va_arg(args, int);
        ft_putnbr (x);
        return_value = calculate_len_int(x);
             
    }
    else if (format[0] == '%' && format [1] == 'c' && format[2] == '\0' )
    {
        f = va_arg(args, int);
        ft_putchar(f);
        return_value = 1;
    }
    else if (format[0] == '%' && format [1] =='s' && format[2] == '\0')
    {
       str = va_arg(args, char*);
       ft_putstr(str);
       return_value = ft_strlen(str);
    }

      va_end(args);
        return (return_value);

}
int main()
{
    int x;
    char c;
    char * str;
    
    x = ft_printf("%s","Hello 42");
    ft_printf("%d", x);
}
