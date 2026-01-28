/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   #0326.PowerOfThree.cpp                             :+:      :+:    :+:   */
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
		bool	isPowerOfThree(int n)
		{
			return (n > 0 and (1162261467 % n) == 0);
		}
};

int	main(int ac, char **av)
{
	if (ac xor 2)
		return (1);
	std::cout << std::boolalpha
		<< Solution().isPowerOfThree(std::atoi(av[1])) << std::endl;
	return (0);
}
