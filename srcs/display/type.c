/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <dhojt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 13:42:45 by dhojt             #+#    #+#             */
/*   Updated: 2018/08/26 09:06:53 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/acl.h>
#include <sys/xattr.h>

static char			*get_str(int value)
{
	if (value == 1)
		return (PER_1);
	if (value == 2)
		return (PER_2);
	if (value == 3)
		return (PER_3);
	if (value == 4)
		return (PER_4);
	if (value == 5)
		return (PER_5);
	if (value == 6)
		return (PER_6);
	if (value == 7)
		return (PER_7);
	return (PER_0);
}

static char			get_type(t_args *args)
{
	if (args->data.ifo)
		return (PER_IFO);
	if (args->data.chr)
		return (PER_CHR);
	if (args->data.dir)
		return (PER_DIR);
	if (args->data.blk)
		return (PER_BLK);
	if (args->data.reg)
		return (PER_REG);
	if (args->data.lnk)
		return (PER_LNK);
	if (args->data.sock)
		return (PER_SOCK);
	return (' ');
}

char				get_acl(t_args *args)
{
	ssize_t 		xattr;
	acl_t			acl;
	char			acl_char;

	xattr = listxattr(args->data.path, NULL, 0, XATTR_NOFOLLOW);
	acl = acl_get_file(args->data.path, ACL_TYPE_EXTENDED);
	if (xattr > 0)
		acl_char = '@';
	else if (acl)
		acl_char = '+';
	else
		acl_char = ' ';
	acl_free(acl);
	return (acl_char);
}

void				type(t_frame *frame, t_args *args)
{
	int				i;
	int				type;
	char			*str;
	char			*tmp;

	i = 3;
	type = args->data.type;
	if ((str = (char *)malloc(sizeof(char) * 12)))
	{
		tmp = str;
		*(tmp++) = get_type(args);
		while (i--)
		{
			ft_strcpy(tmp, get_str((type >> (3 * i)) & 7));
			tmp += 3;
		}
		*(tmp++) = get_acl(args);
		*tmp = '\0';
		ft_printf("%-12s", str);
		free(str);
	}
	else
		ft_printf("%s ", frame->malloc_failed);
}
