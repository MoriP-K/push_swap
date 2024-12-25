#include <stdio.h>
#include "libft/libft.h"

int	ft_memflow(int sign, long result, char **endptr, char *nptr)
{
	if (sign == 1 && result > (LONG_MAX - (*nptr - '0')) / 10)
	{
		*endptr = ++nptr;
		return (1);
	}
	else if (sign == -1 && result > (LONG_MAX - (*nptr - '0')) / 10)
	{
		*endptr = ++nptr;
		return (-1);
	}
	return (0);
}

int	set_endptr(long result, char **endptr, char *nptr)
{
	*endptr = nptr;
	return (result);
}

long	ft_strtol(const char *nptr, char **endptr)
{
	size_t		i;
	int			sign;
	long int	result;

	i = 0;
	while (nptr[i] == '\t' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -sign;
	result = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
		return (set_endptr(result, endptr, (char *)&nptr[--i]));
	while (nptr[i] && ft_isdigit((int)nptr[i]))
	{
		if (ft_memflow(sign, result, endptr, (char *)&(nptr[i])) == 1)
			return (LONG_MAX);
		if (ft_memflow(sign, result, endptr, (char *)&(nptr[i])) == -1)
			return (LONG_MIN);
		result = result * 10 + (nptr[i++] - '0');
	}
	if (endptr)
		*endptr = (char *)&nptr[i];
	return (sign * result);
}

void    test(char *s)
{
    long    res;
    long    exp;
    char    *rep;
    char    *eep;

    // strtolとmy_strtol_10の結果が一致するか調べる
    res = strtol(s, &rep, 10);
    exp = ft_strtol(s, &eep);
    if (res == exp && rep == eep)
        printf(".");
    else
    {
        printf("F\n");
        printf("s: %s\n", s);
    }
    if (res != exp)
    {
        printf("%ld != %ld (exp != res)\n", exp, res);
    }
    if (rep != eep)
    {
        printf("%p != %p (eep != rep)\n", eep, rep);
    }
}

int    main(void)
{
    // 有効系
    test("-9223372036854775808");
    test("-9223372036854775807");
    test("-9223372036854775806");
    test("-9223372036854775805");
    test("-9223372036854775804");
    test("-10000000000");
    test("-100000");
    test("-100");
    test("-9");
    test("-5");
    test("-4");
    test("-3");
    test("-2");
    test("-1");
    test("0");
    test("1");
    test("2");
    test("3");
    test("4");
    test("53232");
    test("100000");
    test("10000000000");
    test("9223372036854775806");
    test("9223372036854775807");
    test("  3123");
    test("  -3123");
    test("");
    // 無効系
    // オーバーフロー
    test("-9223372036854775810");
    test("-9223372036854775809");
    test("9223372036854775808");
    test("9223372036854775809");
    // 符号が2つ
    test("--1");
    test("+-1");
    test("++1");
    test("-+1");
    // 空白
    test("1 ");
    test(" 1 ");
    // 数字以外
    test("a");
    test("1a");
    test("a1");
    test("1a1");
    test("1 1");
}