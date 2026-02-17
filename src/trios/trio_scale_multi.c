
#include "miniRT.h"

int	trio_multiply_get(t_trio dst, t_trio a, t_trio b)
{
	if (!dst || !a || !b)
		return (ft_error(EINVAL, "trio_multiply_get"));
	dst[0] = a[0] * b[0];
	dst[1] = a[1] * b[1];
	dst[2] = a[2] * b[2];
	return (SUCCESS);
}

int	trio_multiply_apply(t_trio dst, t_trio c)
{
	if (!dst || !c)
		return (ft_error(EINVAL, "trio_multiply_apply"));
	dst[0] *= c[0];
	dst[1] *= c[1];
	dst[2] *= c[2];
	return (SUCCESS);
}

int	trio_multiply_scalar_get(t_trio dst, t_fl scalar, t_trio src)
{
	if (!dst || !src)
		return (ft_error(EINVAL, "trio_multiply_scalar_get"));
	dst[0] = src[0] * scalar;
	dst[1] = src[1] * scalar;
	dst[2] = src[2] * scalar;
	return (SUCCESS);
}

int	trio_multiply_scalar_apply(t_trio dst, t_fl scalar)
{
	if (!dst || !scalar)
		return (ft_error(EINVAL, "trio_multiply_scalar_apply"));
	dst[0] *= scalar;
	dst[1] *= scalar;
	dst[2] *= scalar;
	return (SUCCESS);
}