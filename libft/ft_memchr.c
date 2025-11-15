void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

  if (n == 0)
		return (NULL);
	ptr = (unsigned char *)s;
	while (n--)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
