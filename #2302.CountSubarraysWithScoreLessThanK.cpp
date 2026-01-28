/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   #2302.CountSubarraysWithScoreLessThanK.cpp         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaquart <mcaquart@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 02:30:00 by mcaquart          #+#    #+#             */
/*   Updated: 2026/01/28 02:50:50 by mcaquart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <vector>

typedef std::vector<int>	t_vector;

class	Solution
{
	public:
		long long	countSubarrays(t_vector &nums, long long &k)
		{
			long long	sum(0);
			long long	counter(0);
			int			l(0);
			int			r(0);
			int			len[2];

			len[0] = static_cast<int>(nums.size());
			while (r < len[0])
			{
				(sum += nums[r], len[1] = r - l + 1);
				while (sum * len[1] >= k)
					(sum -= nums[l], l++, len[1] = r - l + 1);
				(counter += len[1], r++);
			}
			return (counter);
		}
};

static void	print_vector(const t_vector &vec, const int &k)
{
	size_t	size(vec.size());
	size_t	i(0);

	std::cout << "Input: nums = [";
	while (i < size)
		if ((std::cout << vec[i], i++ + 1 < size))
			std::cout << ",";
	std::cout << "], k = " << k << std::endl << "Output: ";
}

int	main(int ac, char **av)
{
	t_vector	vec;
	int			i(1);
	long long	k(std::atoll(av[1]));

	if (ac < 3)
		return (1);
	vec.reserve(1);
	while (++i < ac - 1)
		vec.push_back(std::atoi(av[i]));
	print_vector(vec, k);
	return (std::cout << Solution().countSubarrays(vec, k) << std::endl, 0);
}
