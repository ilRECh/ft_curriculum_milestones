#ifndef SORT_CONFIGURE_H
# define SORT_CONFIGURE_H

///
/// SAFE LIBFT INCLUDE, DEFINES ARE AFTER
///
# include "libft.h"

///
/// CONFIGURE DEFINES
///
# define INT

# ifdef CHAR
#  include "TYPE_CHAR.h"
# endif
# ifdef UCHAR
#  include "TYPE_UCHAR.h"
# endif
# ifdef INT
#  include "TYPE_INT.h"
# endif
# ifdef UINT
#  include "TYPE_UINT.h"
# endif
# ifdef LONG
#  include "TYPE_LONG.h"
# endif
# ifdef ULONG
#  include "TYPE_ULONG.h"
# endif
# ifdef FLOAT
#  include "TYPE_FLOAT.h"
# endif
# ifdef DOUBLE
#  include "TYPE_DOUBLE.h"
# endif

static int	function_by_data_type(t_function *function, t_DATA_TYPE type)
{
	if (!function)
		return (1);
	if (type == INT_)
		(function->assign = int_assign) && (function->compare = int_compare);
	return (0);
}

#endif