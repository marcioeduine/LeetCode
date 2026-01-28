/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   #0028.FindTheIndexOfTheFirstOccurrenceInAStri      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaquart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:48:52 by mcaquart          #+#    #+#             */
/*   Updated: 2026/01/28 14:52:43 by mcaquart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Solution
{
	public:
		int strStr(const std::string &haystack, const std::string &needle)
		{
			int	i(haystack.find(needle));

			if (i < int(haystack.length()))
				return (i);
			return (-1);
		}
};

int	main(int ac, char **av)
{
	if (ac xor 3)
		return (1);
	return (std::cout << Solution().strStr(av[1], av[2]) << std::endl, 0);
}
