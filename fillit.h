/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:04:51 by mtrotsen          #+#    #+#             */
/*   Updated: 2018/12/12 12:04:53 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define CHECKLINE(j, c) c = 0; if(j > 4) return (1);
# define FALSE(i, j, c) i = 0, j = 0; free(c); c = NULL; return (0);
# define FREE(x) {ft_putendl("error"); free(x); x = NULL; return (0);}
# define MOVE(x, y, z, m) x = y; y = ft_strjoin(x, z); ft_strdel(m);
# define ALLOC(f) if(!(f = malloc(sizeof(char*) * 4))) return (NULL);
# define GALLOC(f, v) if(!(f = malloc(sizeof(char*) * v))) return (NULL);
# define ALLOCT(tmp) if(!(tmp = malloc(sizeof(t_shape)))) return (NULL);
# define ALLOCC(t, v) if(!(t[v] = malloc(sizeof(char) * 4))) return (NULL);
# define WALLOC(t, v) while(v != 4){ALLOCC(t, v); v++;}
# define CALLOC(t, v, g) while(g < v){ALLOCC(t, g); g++;}
# define W(j, f, i, c) if(j == 0 && f[i] == '\n') {i++; return (c);}
# define MY(line, i, c, j) if (line[i] == '\n') {c++; j = 0;}
# define SIGN(f, c, i, x, y) f = 0; c = 0; i = 0; x = 0; y = 0;
# define MAKE(v, t, g, f, i, l) v = 0; t = l; g = l; f = t; i = 0;
# define DEF(f, t, v, i, g) f = t; v = 0; i++; g--;
# define L(c, j, m) c = 1; j = 0; m = 0;
# define F(c, j, m) c = 0; j = 0; m = 0; return (1);
# define IF(line, i, j, cpy) if (!(line)){FALSE(i, j, cpy);}
# define Q(u, m, x, g, i) {x++; g++; while (u > i){u--; m--;}}
# define B(x, g, y, f, i, m, u, k) x = g; y = f; i = m; u = y; k = 0;
# define Z(g, m) if (g < 0 || m < 0) return (0);
# define ZQ(g, v) if (g > v) return (0);
# define AR(area) {ft_chr_str(&area[0], '$', 1); return (area);}
# define EA(area) {ft_chr_str(&area[0], '%', 1); return (area);}
# define P(g, m) {g++; m = -1;} m++;
# define AA(a, v) a = ft_chr_str(a, '.', v);
# define A(a, v) ft_clean_arr(a, v); a = ft_mem_create(a, v); AA(a, v);
# define XXX(x, y, s) if (y == 3 && s[x][y++] != '#'){x++; y = -1;} y++;
# define CCC(c, i, s) if (c == 3 && s[c++][i] != '#'){i++; c = -1;} c++;
# define VS(v, s) v = count_square(s);
# define ANN(g, m, sg, sm, v, s) g = 0; m = 0; sg = 0; sm = 0; VS(v, s);
# define AREAAA(a, v) a = ft_chr_str(a, '.', v);
# define N(s, k, a) k = s; a = ft_mem_create(a, v); AREAAA(a, v);
# define NONS(g, m, sg, sm, v, s, k, a) ANN(g, m, sg, sm, v, s); N(s, k, a);
# define MRR(s, k) s = k; break ;
# define MR(m, g, s, n) m = 0; g = 0; if(n == NULL) break ; s = n;
# define MMM(a, s, k, n, m, g) while(n != NULL){MR(m, g, s, n);} MRR(s, k);
# define MM(a, v, s, k, n, m, g) v++; s = k; MMM(a, s, k, n, m, g);
# define M(a, v, s, k, n, m, g) if (a[0][0] == '$'){MM(a, v, s, k, n, m, g);}
# define HH(s, m, g, v) shape = shape_procent(shape, m, g, v);
# define H(a, s, m, g, v) if (a[0][0] == '%'){HH(s, m, g, v); break ;}
# define KK(sa, v, s, a) sa = ft_mem_create(sa, v); s = ft_write_area(s, a, v);
# define K(sa, v, s, a, t, n) KK(sa, v, s, a); t = s; if (n == NULL) break ;
# define GFORCE(sn, a) if (sn == NULL && a[0][0] != '$') break ;

typedef struct		s_shape
{
	int				x;
	int				y;
	int				g;
	int				m;
	int				i;
	int				v;
	char			letter;
	char			**areas;
	char			**shape;
	char			**other;
	struct s_shape	*back;
	struct s_shape	*next;
}					t_shape;

char				*ft_read_file(int fd, char **line);
t_shape				*ft_arrange(char **line);
void				ft_whole_shape(t_shape *shape);
void				print_arr(char **arrange, int j);
int					ft_dot(char *line);
t_shape				*ft_shape_shift(t_shape *shape);
void				ft_clean_arr(char **arrange, int v);
void				*ft_put_shape(t_shape *shape, char **area);
char				**ft_chr_str(char **b, char c, int len);
char				**ft_make_mem(char **shape, int v);
char				**ft_mem_create(char **area, int v);
void				clean_shape(t_shape *shape, int v);
char				**area_make(t_shape *shape, char **area, int v);
t_shape				*ft_write_other(t_shape *shape, char **area, int v);
t_shape				*ft_write_area(t_shape *shape, char **area, int v);
char				**check_change(char **area, t_shape *shape, int v);
t_shape				*shape_procent(t_shape *shape, int m, int g, int v);
t_shape				*sharr(t_shape *shape, t_shape *tmp, char **area, int v);

#endif
