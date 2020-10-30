# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <string.h>
// File included with the subject

char	*str_join(char const *s1, char const *s2)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dest = (char*)malloc(sizeof(*dest) * (strlen(s1) + strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (*s1 != '\0')
		dest[i++] = *s1++;
	while (*s2 != '\0')
		dest[i++] = *s2++;
	dest[i] = '\0';
	return (dest);
}

int extract_message(char **buf, char **msg)
{
	char *newbuf;
	int i;
	if (buf == 0)
		return (0);
	while ((*buf)[i])
	{
		if (((*buf)[i]) == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf)+strlen(*buf + i + 1) + 1);
			if (newbuf == 0)
				return (-1);
			srtcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[1 + i] = 0;
			*buf = *newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

int main ()
{
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;
	// Creating and validating socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		printf("The creation of the socket failed\n");
		exit(0);
	}
	else
		printf("The socket was succesfully created\n");
	bzero(&servaddr, sizeof(servaddr));
	// Configuring IP and PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
	servaddr.sin_port = htons(8081);
	// Bind and wait for conections
	if ((bind(sockfd, (const struct sockaddr*)&servaddr, sizeof(servaddr))) != 0)
	{
		printf("Bind failed\n");
		exit(0);
	}
	else
		printf("Binding worked\n");
	if (listen(sockfd, 10) != 0)
	{
		printf("listen error \n");
		exit(0);
	}
	len = sizeof(cli);
	connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
	if (connfd < 0)
	{
		printf("accept error\n");
	}
	else
		printf("bind ok\n");
}
