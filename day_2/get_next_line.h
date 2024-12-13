/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:46:26 by gumallet          #+#    #+#             */
/*   Updated: 2024/12/13 16:10:56 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* Include needed libraries for NULL definition and allowed functions */

# include <stdlib.h>
# include <unistd.h>

/* Define BUFFER_SIZE if it isn't done via the -D flag */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* Function prototype */

char	*get_next_line(int fd);

/* Utility function prototypes */

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *s);
void	safe_free(char **ptr);
char	**ft_split(char const *s, char c);

#endif