/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _713_subarrayProductLessThanK.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaquart <mcaquart@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 02:00:00 by mcaquart          #+#    #+#             */
/*   Updated: 2026/01/28 02:14:01 by mcaquart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <vector>

typedef std::vector<int>	t_vector;

class	Solution
{
	public:
		int	numSubarrayProductLessThanK(t_vector &nums, int k);
};

int	Solution::numSubarrayProductLessThanK(t_vector &nums, int k)
{
	int	size(static_cast<int>(nums.size()));
	int	product(1);
	int	counter(0);
	int	left(0);
	int	right(0);

	if (k <= 1)
		return (0);
	while (right < size)
	{
		product *= nums[right];
		while (product >= k)
			product /= nums[left++];
		counter += right++ - left + 1;
	}
	return (counter);
}

static void	print_vector(t_vector &vec, const int &k)
{
	size_t	i(0);

	std::cout << "Input: nums = [";
	while (i < vec.size())
		if ((std::cout << vec[i], i++ + 1 < vec.size()))
			std::cout << ",";
	std::cout << "], k = " << k << std::endl << "Output: ";
}

int	main(int ac, char **av)
{
	t_vector	vec;
	int		i(1);
	int		k;

	if (ac < 3)
		return (1);
	k = std::atoi(av[1]);
	while (++i < ac)
		vec.push_back(std::atoi(av[i]));
	print_vector(vec, k);
	std::cout << Solution().numSubarrayProductLessThanK(vec, k);
	return (std::cout << std::endl, 0);
}
