/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   #0043.MultiplyStrings.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaquart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:22:31 by mcaquart          #+#    #+#             */
/*   Updated: 2026/01/28 17:22:41 by mcaquart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <utility>

typedef std::string					t_text;
typedef std::pair<t_text, t_text>	t_pair;

class	Solution
{
	private:
		void	operation(t_text &result, const t_pair &value, int i, int j)
		{
			int	mul;
			int	sum;
			int	x;
			int	y;

			while (--j >= 0)
			{
				mul = (value.first[i] - '0') * (value.second[j] - '0');
				y = i + j;
				x = i + j + 1;
				sum = mul + (result[x] - '0');
				result[x] = (sum % 10) + '0';
				result[y] += sum / 10;
			}
		}
	public:
		t_text	multiply(const t_text &num1, const t_text &num2)
		{
			int		i(num1.length());
			int		j(num2.length());
			t_text	result(i + j, '0');
			t_pair	value(num1, num2);

			if (num1 == "0" or num2 == "0")
				return ("0");
			while (--i >= 0)
				operation(result, value, i, j);
			i = result.find_first_not_of('0');
			if (i == int(t_text::npos))
				return ("0");
			return (result.substr(i));
		}
};

int	main(int ac, char **av)
{
	if (ac xor 3)
		return (1);
	return (std::cout << Solution().multiply(av[1], av[2]) << std::endl, 0);
}
