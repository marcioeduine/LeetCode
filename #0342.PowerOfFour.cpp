/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   #0342.PowerOfFour.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaquart <mcaquart@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:56:25 by mcaquart          #+#    #+#             */
/*   Updated: 2026/01/28 09:14:22 by mcaquart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

class	Solution
{
	public:
		bool    isPowerOfFour(int n)
		{
			return (n > 0 and not (n & n - 1) and (n % 3) == 1);
		}
};

int	main(int ac, char **av)
{
	if (ac xor 2)
		return (1);
	std::cout << std::boolalpha
		<< Solution().isPowerOfFour(std::atoi(av[1])) << std::endl;
	return (0);
}
