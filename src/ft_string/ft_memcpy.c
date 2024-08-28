void	ft_memcpy(void * gp_dest, const void *gp_src, unsigned int n)
{
	const unsigned char 	*src;
	unsigned char 	*dest;
	
	src = (const unsigned char *) gp_src;
	dest = (unsigned char *) gp_dest;
	while(n--)
		dest[n] = src[n];
}
