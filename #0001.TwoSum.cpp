/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   #0001.TwoSum.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaquart <mcaquart@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 03:21:56 by mcaquart          #+#    #+#             */
/*   Updated: 2026/01/28 11:47:03 by mcaquart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>

typedef std::map<int, int>	t_map;
typedef std::vector<int>	t_vector;

class	Solution
{
	public:
		t_vector	twoSum(t_vector &nums, int target)
		{
			t_map			seen;
			t_map::iterator	it;
			t_vector		result;
			const int		length(nums.size());
			int				i(-1);

			while (++i < length)
			{
				it = seen.find(target - nums[i]);
				if (it != seen.end())
				{
					result.push_back(it->second);
					return (result.push_back(i), result);
				}
				seen[nums[i]] = i;
			}
			return (result);
		}
};

int	main(int ac, char **av)
{
	t_vector	vec[2];
	int			i(0);

	if (ac < 3)
		return (1);
	vec[0].reserve(ac - 2);
	while (++i < ac - 1)
		vec[0].push_back(std::atoi(av[i]));
	vec[1] = Solution().twoSum(vec[0], std::atoi(av[ac - 1]));
	std::cout << '[' << vec[1][0] << ',' << vec[1][1] << ']' << std::endl;
	return (0);
}
