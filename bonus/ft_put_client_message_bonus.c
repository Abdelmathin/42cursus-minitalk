/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_client_message_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabachi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 05:34:34 by ahabachi          #+#    #+#             */
/*   Updated: 2022/10/31 05:34:35 by ahabachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*  .___  ___.  __  .__   __.  __  .__________.    ___       __       __  ___ */
/*  |   \/   | |  | |  \ |  | |  | |          |   /   \     |  |     |  |/  / */
/*  |  \  /  | |  | |   \|  | |  | `---|  |---`  /  ^  \    |  |     |  '  /  */
/*  |  |\/|  | |  | |  . `  | |  |     |  |     /  /_\  \   |  |     |    <   */
/*  |  |  |  | |  | |  |\   | |  |     |  |    /  _____  \  |  `----.|  .  \  */
/*  |__|  |__| |__| |__| \__| |__|     |__|   /__/     \__\ |_______||__|\__\ */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */
/*  █████████            ██████████         ██████████         ██████████     */
/*  ██     ██                    ██                 ██         ██      ██     */
/*         ██                    ██                 ██         ██      ██     */
/*         ██                    ██                 ██                 ██     */
/*         ██            ██████████         ██████████                 ██     */
/*         ██                    ██                 ██                 ██     */
/*         ██                    ██                 ██                 ██     */
/*         ██                    ██                 ██                 ██     */
/*      ████████         ██████████         ██████████                 ██     */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>

size_t	ft_unicode_len(const char *c)
{
	if (0 <= c[0])
		return (1);
	else if (-16 <= c[0])
		return (4);
	else if (-32 <= c[0])
		return (3);
	return (2);
}

void	ft_put_client_message(t_client *c)
{
	if (c->message[0] >= 0)
	{
		write(1, c->message, 1);
	}
	else
	{
		if (c->message[c->offset] >= 0)
			c->offset = 0;
		c->offset++;
		if (c->offset == ft_unicode_len(c->message))
		{
			write(1, c->message, c->offset);
			c->offset = 0;
		}
	}
}
