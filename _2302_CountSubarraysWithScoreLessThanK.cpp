/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _2302_CountSubarraysWithScoreLessThanK.cpp         :+:      :+:    :+:   */
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
		long long	countSubarrays(t_vector &nums, long long &k);
};

long long	Solution::countSubarrays(t_vector &nums, long long &k)
{
	long long	sum(0);
	long long	counter(0);
	int		l(0);
	int		r(0);
	int		len[2];

	len[0] = static_cast<int>(nums.size());
	while (r < len[0])
	{
		sum += nums[r];
		len[1] = r - l + 1;
		while (sum * len[1] >= k)
			(sum -= nums[l], l++, len[1] = r - l + 1);
		(counter += len[1], r++);
	}
	return (counter);
}

static void	print_vector(const t_vector &vec, const int &k)
{
	size_t	i(0);

	std::cout << "Input: nums = [";
	while (i < vec.size())
		if ((std::cout << vec[i], i++ + 1 < vec.size()))
			std::cout << ",";
	std::cout << "], K = " << k << std::endl << "Output: ";
}

int	main(int ac, char **av)
{
	t_vector	vec;
	long long	k;
	int		i(1);

	if (ac < 3)
		return (1);
	k = std::atoll(av[1]);
	while (++i < ac)
		vec.push_back(std::atoi(av[i]));
	print_vector(vec, k);
	std::cout << Solution().countSubarrays(vec, k) << std::endl;
	return (0);
}
