#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

static int my_strlen(const char *s)
{
    int i = 0;
    while (s && s[i])
        i++;
    return i;
}

static void my_putstr(char *s, int *count)
{
    if (!s)
        s = "(null)";
    int len = my_strlen(s);
    write(1, s, len);
    *count += len;
}

static void my_putchar(char c, int *count)
{
    write(1, &c, 1);
    (*count)++;
}

static char *itoa(int n)
{
    char *str;
    int tmp = n;
    int len = (n <= 0) ? 1 : 0;

    while (tmp)
    {
        tmp /= 10;
        len++;
    }

    str = malloc(len + 1);
    if (!str)
        return NULL;
    str[len] = '\0';

    unsigned int num = (n < 0) ? -n : n;
    if (n == 0)
        str[0] = '0';
    while (num)
    {
        str[--len] = (num % 10) + '0';
        num /= 10;
    }
    if (n < 0)
        str[0] = '-';
    return str;
}

static char *utoa_base(unsigned long n, int base, int uppercase)
{
    char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    char buf[65];
    int i = 64;
    buf[i] = '\0';

    if (n == 0)
        buf[--i] = '0';

    while (n)
    {
        buf[--i] = digits[n % base];
        n /= base;
    }
    char *res = malloc(65 - i);
    if (!res)
        return NULL;
    int j = 0;
    while (buf[i])
        res[j++] = buf[i++];
    res[j] = '\0';
    return res;
}

int my_printf(char *restrict format, ...)
{
    va_list args;
    int count = 0;
    int i = 0;

    va_start(args, format);
    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'd')
            {
                int n = va_arg(args, int);
                char *str = itoa(n);
                if (str)
                {
                    my_putstr(str, &count);
                    free(str);
                }
            }
            else if (format[i] == 'u')
            {
                unsigned int n = va_arg(args, unsigned int);
                char *str = utoa_base(n, 10, 0);
                if (str)
                {
                    my_putstr(str, &count);
                    free(str);
                }
            }
            else if (format[i] == 'o')
            {
                unsigned int n = va_arg(args, unsigned int);
                char *str = utoa_base(n, 8, 0);
                if (str)
                {
                    my_putstr(str, &count);
                    free(str);
                }
            }
            else if (format[i] == 'x')
            {
                unsigned int n = va_arg(args, unsigned int);
                char *str = utoa_base(n, 16, 1); 
                if (str)
                {
                    my_putstr(str, &count);
                    free(str);
                }
            }
            else if (format[i] == 'c')
            {
                char c = (char)va_arg(args, int);
                my_putchar(c, &count);
            }
            else if (format[i] == 's')
            {
                char *s = va_arg(args, char *);
                my_putstr(s, &count);
            }
            else if (format[i] == 'p')
            {
                void *p = va_arg(args, void *);
                unsigned long addr = (unsigned long)p;
                my_putstr("0x", &count);
                char *str = utoa_base(addr, 16, 0);
                if (str)
                {
                    my_putstr(str, &count);
                    free(str);
                }
            }
            else if (format[i] == '%')
            {
                my_putchar('%', &count);
            }
            else
            {
                my_putchar('%', &count);
                if (format[i])
                    my_putchar(format[i], &count);
            }
            i++;
        }
        else
        {
            my_putchar(format[i], &count);
            i++;
        }
    }
    va_end(args);
    return count;
}
