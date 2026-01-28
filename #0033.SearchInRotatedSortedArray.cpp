/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   #0033.SearchInRotatedSortedArray.cpp               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaquart <mcaquart@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:41:08 by mcaquart          #+#    #+#             */
/*   Updated: 2026/01/28 16:38:10 by mcaquart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <vector>

typedef std::vector<int>	t_vector;

typedef struct s_print_element
{
	bool	flag;

	s_print_element() : flag(true) {}
	void	operator()(int n)
	{
		if (not flag)
			std::cout << ',';
		(flag = false, std::cout << n);
	}
}	t_print_element;

class	Solution
{
	private:
		int create_pairs(t_vector &vec, const int &pos)
		{
			t_vector	v1(vec.begin(), vec.begin() + pos);
			t_vector	v2(vec.begin() + pos, vec.end());

			(vec.clear(), vec.insert(vec.end(), v2.begin(), v2.end()));
			return (vec.insert(vec.end(), v1.begin(), v1.end()), pos);
		}
	public:
		int search(t_vector &nums, int target)
		{
			t_vector::iterator  it(std::find(nums.begin(), nums.end(), target));

			if (it == nums.end())
				return (-1);
			return (create_pairs(nums, std::distance(nums.begin(), it)));
		}
};

static void	print_vector(const t_vector &vec)
{
	std::cout << "nums = [";
	std::for_each(vec.begin(), vec.end(), t_print_element());
	std::cout << ']';
}

static void	show(const t_vector &vec, const int &index, const int &target)
{
	std::cout << ", TARGET = " << target << std::endl << "Output: ";
	(print_vector(vec), std::cout << ", INDEX = " << index << std::endl);
}

int	main(int ac, char **av)
{
	t_vector	vec;
	int			i(0);

	if (ac < 3)
		return (1);
	while (++i < ac - 1)
		vec.push_back(std::atoi(av[i]));
	(i = std::atoi(av[ac - 1]), std::cout << "Input: ", print_vector(vec));
	return (show(vec, Solution().search(vec, i), i), 0);
}
