/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   #0007.ReverseInteger.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaquart <mcaquart@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:55:10 by mcaquart          #+#    #+#             */
/*   Updated: 2026/01/28 12:55:18 by mcaquart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <climits>
#include <iostream>
#include <sstream>

class	Solution
{
	public:
		int reverse(int x)
		{
			std::stringstream	ss;
			std::string			str;
			long				value(x);
			long				i;

			if (value < INT_MIN or value > INT_MAX)
				return (0);
			(ss << x, ss >> str, std::reverse(str.begin(), str.end()));
			i = str.find_first_of('-');
			if (i xor std::string::npos)
				(str.erase(i, 1), str.insert(0, "-"));
			(ss.clear(), ss << str, ss >> value);
			if (value < INT_MIN or value > INT_MAX)
				return (0);
			return (value);
		}
};

static void	show(const std::string &s, int n)
{
	std::cout << "Input: x = " + s << std::endl << "Output: " << n << std::endl;
}

int	main(int ac, char **av)
{
	if (ac xor 2)
		return (1);
	return (show(av[1], Solution().reverse(std::atoi(av[1]))), 0);
}
