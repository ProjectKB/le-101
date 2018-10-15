/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 12:53:38 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 17:15:54 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"
#include <stdio.h>

char	*ft_return_rest(char *str)
{
	int	i;

	i = 0;

	while (str[i] != '\n')
	{
		if (!(str[i]))
			return (NULL);
		i++;
	}
	if (*str == '\n')
		return (&str[i + 1]);
	return (&str[i + 1]);
}

char	*ft_transform_line(char *line)
{
	int	i;

	/*if (line[0] == '\n')
		i = 1;
	else*/
	i = ft_strlen(line) - ft_strlen(ft_strchr(line, '\n'));
	line = ft_strsub(line, 0, i);
	return (line);
}

char	*ft_read(const int fd, char **line)
{
	static int	rt = 0;
	char		*buf;
	static char	*rest = NULL;

	if (!(*line = ft_strnew(0)) || !(buf = ft_strnew(BUFF_SIZE + 1)))
		return (NULL);






	while ((rt = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rt] = '\0';
		*line = ft_strjoin(*line, buf);
		if (ft_strchr(*line, '\n'))
		{
			//printf("Ligne lue = '%s' ||\n ", *line);
			if (rest)
				*line = ft_strjoin(rest, *line);
			//printf("Ligne lue + reste  = '%s' ||\n ", *line);
			break ;
		}
	}
		if (rt > 0)
		{
			rest = ft_strdup(ft_return_rest(*line));
			*line = ft_transform_line(*line);
		}
		else
		{
			*line = ft_strdup(ft_transform_line(rest));
			rest = ft_return_rest(rest);
		}
		printf("Ligne transfo  = '%s' ||\n ", *line);
		//printf("A rest = '%s' ||\n\n ", rest);
		return (*line);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	i;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	//ft_putstr(ft_read(fd, &line));
	//ft_putstr(ft_read(fd, &line));
	//ft_putstr(ft_read(fd, &line));
	ft_read(fd, &line);
	ft_read(fd, &line);
	ft_read(fd, &line);
	ft_read(fd, &line);
	ft_read(fd, &line);
	ft_read(fd, &line);
	ft_read(fd, &line);
	ft_read(fd, &line);
	ft_read(fd, &line);
	close(fd);
	return (0);
}
