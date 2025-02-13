/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:12:03 by belmiro           #+#    #+#             */
/*   Updated: 2024/07/24 12:12:03 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/so_long.h"
#include "../../includes/get_next_line.h"

int	check_extension(char *path)
{
	size_t	len;
	int		fd;

	len = ft_strlen(path);
	if (open(path, O_DIRECTORY) >= 0)
	{
		fd = open(path, O_DIRECTORY);
		close(fd);
		return (FAILURE);
	}
	else
	{
		fd = open(path, O_RDONLY);
		close(fd);
		if ((path[len - 3] != 'b' && path[len - 2] != 'e'
				&& path[len - 1] != 'r'
				&& path[len - 4] != '.') || fd < 0)
			return (FAILURE);
		else
			return (SUCCESS);
	}
}
