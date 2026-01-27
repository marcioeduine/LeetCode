/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _30_findsubstr.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaquart <mcaquart@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:07:34 by mcaquart          #+#    #+#             */
/*   Updated: 2026/01/27 20:50:08 by mcaquart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

typedef std::string		t_text;
typedef std::map<t_text, int>	t_map;
typedef std::vector<int>	t_vector;
typedef std::vector<t_text>	t_t_vector;

class	Solution
{
	public:
		t_vector	findSubstring(t_text &s, t_t_vector &words);
};

static void	build_word_count(t_t_vector &words, t_map &word_count)
{
	size_t	i(-1);

	while (++i < words.size())
		word_count[words[i]]++;
}

static void	sliding_window(t_text &s, t_t_vector &words, t_map &word_count,
	size_t word_len, size_t offset, t_vector &vec)
{
	t_map	seen;
	t_text	word;
	size_t	left(offset);
	size_t	count(0);
	size_t	i(offset);

	while (i + word_len <= s.length())
	{
		word = s.substr(i, word_len);
		if (word_count.find(word) == word_count.end())
			(seen.clear(), count = 0, left = i + word_len);
		else
		{
			(seen[word]++, count++);
			while (seen[word] > word_count[word])
				(seen[s.substr(left, word_len)]--,
				 left += word_len, count--);
			if (count == words.size())
				vec.push_back(left);
		}
		i += word_len;
	}
}

static	t_vector	ss_function(t_vector &vec, t_text &s, t_t_vector &words)
{
	t_map		word_count;
	size_t		word_len(words[0].length());
	size_t		i(-1);

	build_word_count(words, word_count);
	while (++i < word_len)
		sliding_window(s, words, word_count, word_len, i, vec);
	return (vec);
}

t_vector	Solution::findSubstring(t_text &s, t_t_vector &words)
{
	t_vector	vec;

	if (s.empty() or words.empty())
		return (vec);
	return (ss_function(vec, s, words));
}
