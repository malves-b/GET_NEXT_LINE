/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:34:49 by malves-b          #+#    #+#             */
/*   Updated: 2024/04/30 18:07:38 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t	ft_strlen(const char *s);
/**
 * @brief Funcao que concatena duas Strings
*/
char	*ft_strjoin(char const *s1, char const *s2);
/* -------------------------------------------------------------------------- */
/**
 * @brief Funcao que verifica um caractere dentro de uma string
 * @return Pointer para o caractere encontrado 
*/
char	*ft_strchr(char *s, int c);
/* -------------------------------------------------------------------------- */
/**
 * @brief Funcao que cria uma nova substring a partir dos parametros passados: 
 *        estou realizando um teste agora.
 * @return teste.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*get_next_line_aux(int fd, char *buffer, char *backup);
char	*ft_exclude_line(char *str);
char	*get_next_line(int fd);

#endif
