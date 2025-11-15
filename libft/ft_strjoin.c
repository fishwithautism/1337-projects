char *ft_strjoin(char const *s1, char const *s2)
{
      size_t size;
      char *join;
      if (!s1 || !s2)
          return (NULL);
      size = ft_strlen(s1) + ft_strlen(s2);
      join = malloc(size + 1);
      if (join == NULL)
          return (NULL);
      ft_strlcpy(join, s1, size + 1);
      ft_strlcat(join, s2, size + 1);
      return (join);
}
