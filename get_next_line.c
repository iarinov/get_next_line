/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 09:57:02 by aiarinov          #+#    #+#             */
/*   Updated: 2022/04/22 11:31:23 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		current;
	char		*line;
	int			i;
	int			letter_amount;

	letter_amount = read(fd, &current, 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || letter_amount <= 0 || current == 0)
		return (NULL);
	i = 0;
	line = malloc(1024);
	if (line == NULL)
		return (NULL);
	while (current != '\n' && letter_amount > 0 && current != '\0')
	{
		line[i] = current;
		i++;
		letter_amount = read(fd, &current, 1);
	}
	if (current != '\n')
		current = '\0';
	line[i] = current;
	while (line[i++])
		line[i] = '\0';
	return (line);
}
