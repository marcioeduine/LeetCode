/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _3_LongestSubstringWithoutRepeatingCharacters.cp   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaquart <mcaquart@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:33:10 by mcaquart          #+#    #+#             */
/*   Updated: 2026/01/26 05:58:46 by mcaquart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>

class	Solution
{
	public:
		int	lengthOfLongestSubstring(std::string s);
};

int	Solution::lengthOfLongestSubstring(std::string s)
{
	const int	length(s.length());
	unsigned char	c;
	int		tab[256];
	int		counter(0);
	int		i(-1);
	int		j(0);

	memset(tab, -1, sizeof(tab));
	while (++i < length)
	{
		c = static_cast<unsigned char>(s[i]);
		if (j <= tab[c])
			j = tab[c] + 1;
		tab[c] = i;
		if (i - j + 1 > counter)
			counter = i - j + 1;
	}
	return (counter);
}

int	main(int ac, char **av)
{
	if (ac xor 2)
		return (1);
	std::cout << Solution().lengthOfLongestSubstring(av[1]) << std::endl;
	return (0);
}
