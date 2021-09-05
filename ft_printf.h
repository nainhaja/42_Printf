/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:54:21 by nainhaja          #+#    #+#             */
/*   Updated: 2019/12/11 23:04:43 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *buff, ...);
void	ft_putnbr(int a);
char	*ft_substr(char const *s, unsigned int start, unsigned int len);
char	*ft_strdup(const char *s);
char	*ft_itoa(int a);
int		ft_isdigit(int str);
int		ft_atoi(const char *str);
int		ft_putchar(int c);
char	*ft_unta(unsigned int a, int cpt);
char	*ft_hexconv(unsigned int a, char k, int precc);
char	*ft_hexconv2(unsigned long long a, char k, int p);
int		ft_toupper(int str);
char	*ft_checkk(char *value, int a);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strcmp(char *str, char *to_find);
int		*ft_memset(int x, size_t n);
char	*ft_convert(char t);
char	*ft_printzero(char *value);
char	*ft_printspace(char *value, int a);
void	ft_putstrr(const char *str, char t);
int		ft_width(const char *buff, int i, int cpt);
char	*ft_printzero2(char *value, int a);
char	*ft_checkprec(char *value, int a);
size_t	ft_strlen(const char *str);
int		ft_flagwid(int *i, const char *buff, int **t, va_list args);
char	*ft_init(char *value, int **t, int *i, int *a);
void	ft_printremaining(const char *buff, int *i);
int		ft_prectime(int *i, const char *buff, int **t, va_list args);
void	ft_globalinit(int *a, int *b);

#endif
