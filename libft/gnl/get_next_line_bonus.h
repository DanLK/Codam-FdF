/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 15:04:59 by dloustal      #+#    #+#                 */
/*   Updated: 2025/01/02 17:21:38 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 28

# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	read_to_list(int fd, t_list **list);
char	*get_current_line(t_list *head);
void	copy_line(t_list *head, char *line);
void	set_list(t_list **list);

// UTILS

t_list	*ft_lstnew(char *content);
void	ft_lstadd_back(t_list **lst, t_list *new_node);
t_list	*ft_lstlast(t_list *lst);
int		find_new_line(t_list *node, char mode);
void	clear_list(t_list **list, t_list *node, char *content);

#endif