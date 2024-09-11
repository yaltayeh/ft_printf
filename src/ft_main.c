#include "ft_printf.h"

static struct s_main_data
{
	size_t	count;
	char	*out[2];
	size_t	len0;
	size_t	len1;
	size_t	limit_put;
	t_handler_data *in;
};

static void ft_upper(unsigned int i, char *s)
{
	(void)i;
	*s = ft_toupper(*s);
}

static int	ft_putstr_limit(struct s_main_data *data, int i)
{
	size_t	len;
	ssize_t		ret;
	char	*str;

	str = data->out[i];
	if (str)
	{
		len = ft_strlen(str);
		if (data->in->to_upper)
				ft_striteri(str, ft_upper);
		if (!len && data->in->is_char)
			len = 1;
		if (len > data->limit_put)
		{
			write(STDOUT_FILENO, str, data->limit_put);
			data->count += (size_t)data->limit_put;
		}
		else
		{
			ret = write(STDOUT_FILENO, str, len);
			data->count += (size_t)len;
			data->limit_put -= (size_t)len;
		}
		free(str);
		return (1);
	}
	return (0);
}

static size_t ft_putstr_2(char *str)
{
	size_t	len;
	ssize_t	ret;

	len = ft_strlen(str);
	ret = write(STDOUT_FILENO, str, len);
	return (len);
}

static void ft_put_numbers(int *numbers)
{
	char *names[8] = {
		"SHARP" ,
		"PLUS"  ,
		"SPACE" ,
		"MINUS" ,
		"DOT"   ,
		"ZERO"  ,
		"NUMBER",
		"",
	};
	for (int i = 0; i < 8; i++)
	{
		printf("%s = %d\n", names[i], numbers[i]);
	}
}

int	ft_main(t_handler_data in)
{
	struct s_main_data	data;	

	ft_bzero(&data, sizeof(data));
	data.limit_put = -1;
	data.in = &in;
	//ft_put_numbers(in.numbers);
	in.handle(in.input, data.out);
	if (!data.out[0])
		return (-1);

	if (in.flags & SHARP)
		data.out[1] = ft_strdup("0x");
	data.len0 = ft_strlen(data.out[0]);
	if (data.out[1])
		data.len1 = ft_strlen(data.out[1]);

	
	if (in.flags & DOT && !in.is_digit)
		data.limit_put = in.numbers[4];
	if (data.limit_put < data.len0)
		data.len0 = data.limit_put;


	if (in.flags & NUMBER)
		while (in.numbers[6] > (data.count + data.len0))
			data.count += ft_putstr_2(" ");

	ft_putstr_limit(&data, 1);
	if (in.flags & PLUS && in.input.i32 >= 0)
		data.count += ft_putstr_2("+");
	else if (in.flags & SPACE && in.input.i32 >= 0)
		data.count += ft_putstr_2(" ");
		
	if (in.flags & DOT && in.is_digit)
		while (in.numbers[4] + data.len1 > data.count + data.len0)
			data.count += ft_putstr_2("0");
	if (in.flags & ZERO)
		while (in.numbers[5] > (data.count + data.len0))
			data.count += ft_putstr_2("0");


	ft_putstr_limit(&data, 0);

	if (in.flags & MINUS)
		while (in.numbers[3] > data.count)
			data.count += ft_putstr_2(" ");

	return (data.count);
}