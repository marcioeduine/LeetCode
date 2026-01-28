/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   #0008.StringToInteger_atoi_.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaquart <mcaquart@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:00:15 by mcaquart          #+#    #+#             */
/*   Updated: 2026/01/28 13:03:12 by mcaquart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

class	Solution
{
	public:
		int	myAtoi(const std::string &s)
		{
			std::istringstream  is(s);
			int                 r(0);

			return (is >> r, r);
		}
};

/*
#include <cctype>
#include <climits>

class Solution
{
    public:
        int myAtoi(string s)
        {
            long r(0);
            int signal(1);
            int i(0);
        
            if (s.empty())
                return (0);
            while (isspace(s[i]))
                i++;
            if (s[i] == '-' or s[i] == '+')
                if (s[i++] == '-')
                    signal = -1;
            while (s[i] and isdigit(s[i]))
            {
                r = r * 10 + s[i++] - 48;
                if (r * signal < INT_MIN)
                    return (INT_MIN);
                if (r * signal > INT_MAX)
                    return (INT_MAX);
            }
            return (r * signal);
        }
};
*/
int	main(int ac, char **av)
{
	if (ac xor 2)
		return (1);
	return (std::cout << Solution().myAtoi(av[1]) << std::endl, 0);
}
