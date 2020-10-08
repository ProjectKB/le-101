#ifndef SHARED_H

# define SHARED_H

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>

extern const unsigned char g_PADDING[64];

int	 read_64_bytes(int fd, unsigned char *line);

#endif