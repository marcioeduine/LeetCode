/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   #0912.SortArray.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaquart <mcaquart@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 21:15:00 by mcaquart          #+#    #+#             */
/*   Updated: 2026/01/28 00:49:51 by mcaquart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

typedef std::vector<int>	t_vector;

class	Solution
{
	public:
		t_vector	sortArray(t_vector &vec);
};

static void	counting_sort(t_vector &vec, const int &exp, const int &offset)
{
	t_vector	container(vec.size());
	size_t		i(vec.size());
	int			array[10];
	int			j;

	std::fill(array, array + (sizeof(array) / sizeof(array[0])), 0);
	while (i--)
		(j = ((vec[i] + offset) / exp) % 10, array[j]++);
	i = 0;
	while (++i < 10)
		array[i] += array[i - 1];
	i = vec.size();
	while (i--)
		(j = ((vec[i] + offset) / exp) % 10,
		 container[array[j] - 1] = vec[i], array[j]--);
	std::copy(container.begin(), container.end(), vec.begin());
}

static void	radix_sort(t_vector &vec, const int &max, const int &offset)
{
	int	exp(1);

	while (max / exp)
		(counting_sort(vec, exp, offset), exp *= 10);
}

t_vector	Solution::sortArray(t_vector &vec)
{
	int	min(*std::min_element(vec.begin(), vec.end()));
	int	max(*std::max_element(vec.begin(), vec.end()));
	int	offset(0);

	if (vec.empty() or vec.size() == 1)
		return (vec);
	if (min < 0)
		offset = -min;
	return (radix_sort(vec, max + offset, offset), vec);
}

static void	print_vector(t_vector &vec)
{
	size_t	i(0);

	while (i < vec.size())
		if ((std::cout << vec[i], i++ + 1 < vec.size()))
			std::cout << ',';
	std::cout << ']' << std::endl;
}

int	main(int ac, char **av)
{
	t_vector	vec;
	int			i(0);

	if (ac < 2)
		return (1);
	while (++i < ac)
		vec.push_back(std::atoi(av[i]));
	(std::cout << "Input: [", print_vector(vec), std::cout  << "Output: [");
	return (Solution().sortArray(vec), print_vector(vec), 0);
}
