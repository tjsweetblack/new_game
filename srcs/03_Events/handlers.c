/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:11:19 by belmiro           #+#    #+#             */
/*   Updated: 2024/07/24 12:11:19 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/so_long.h"

int	handle_resize(t_data *data)
{
	render(data);
	return (0);
}

int	key_convert(int keysym)
{
	int	key;

	key = keysym;
	if (keysym == XK_Up)
	{
		key = 119;
	}
	else if (keysym == XK_Down)
	{
		key = 115;
	}
	else if (keysym == XK_Right)
	{
		key = 100;
	}
	else if (keysym == XK_Left)
	{
		key = 97;
	}
	return (key);
}

int	handle_keypress(int keysym, t_data *data)
{
	keysym = key_convert(keysym);
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	else if (ft_strchr("wasd", keysym))
		move_player(data, keysym);
	return (0);
}

int	handle_btnrealease(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	return (0);
}
