/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   #0231.PowerOfTwo.cpp                               :+:      :+:    :+:   */
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
		bool	isPowerOfTwo(int n)
		{
			return (n > 0 and not (n & n - 1));
		}
};

int	main(int ac, char **av)
{
	if (ac xor 2)
		return (1);
	std::cout << std::boolalpha
		<< Solution().isPowerOfTwo(std::atoi(av[1])) << std::endl;
	return (0);
}
