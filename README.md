# get_next_line


## Preview

### Que entregar
- get_next_line.c, get_next_line_utils.c, get_next_line.h

### Prototipo
- char *get_next_line(int fd);

### Parámetros
- fd : file descriptor a leer

### Retorno
La línea leída o NULL si se ha alcanzado el final del archivo o si ha ocurrido un error

### Funciones externas autorizadas
- read
- malloc
- free

### Comportamiento esperado

- Llamar de forma repetida a la función, devera leer las lineas del archivo de forma sucesiva.
- Si se llega al final del archivo, la función deberá devolver NULL.
- Comportamiento adecuado cuando se lee de un archivo y cuando se lee de stdin.
- Usar variables estáticas
```c
int main(void)
{
	printf("%s\n", get_next_line(fd)); //linea 1 del archivo
	printf("%s\n", get_next_line(fd)); //linea 2 del archivo
	printf("%s\n", get_next_line(fd)); //linea 3 del archivo
	printf("%s\n", get_next_line(fd)); //NULL (EOF alcanzado)
}
```

- Lectura desde stdin (teclado)
```c
int main(void)
{
    printf("%s\n", get_next_line(0)); //line 1 from stdin
    printf("%s\n", get_next_line(0)); //line 2 from stdin
    printf("%s\n", get_next_line(0)); //line 3 from stdin
    printf("%s\n", get_next_line(0)); //NULL (EOF reached)
}
```

- Flag -D BUFFER_SIZE=xx para compilar con un buffer definido por el usuario.

El tamaño del buffer determina la cantidad de caracteres que se leen cada vez que se llama a la función read.

```c
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=2 get_next_line.c get_next_line_utils.c


```

## Bonus


- Uso de una única variable estática
- Manejo de múltiples fd con get_next_line
```c
int main(void)
{
		int fd1;
		int fd2;
		int fd3;
		char *line;

		fd1 = open("test1.txt", O_RDONLY);
		fd2 = open("test2.txt", O_RDONLY);
		fd3 = open("test3.txt", O_RDONLY);
		line = get_next_line(fd1);
		printf("%s\n", line); //line 1 from test1.txt
		free(line);
		line = get_next_line(fd2);
		printf("%s\n", line); //line 1 from test2.txt
		free(line);
		line = get_next_line(fd1);
		printf("%s\n", line); //line 2 from test1.txt
		free(line);
		line = get_next_line(fd3);
		printf("%s\n", line); //line 1 from test3.txt
		free(line);
		line = get_next_line(fd2);
		printf("%s\n", line); //line 2 from test2.txt
		free(line);
		line = get_next_line(fd3);
		printf("%s\n", line); //line 2 from test3.txt
		free(line);
		line = get_next_line(fd3);
		printf("%s\n", line); //line 3 from test3.txt
		free(line);
		line = get_next_line(fd3);
		printf("%s\n", line); //NULL (EOF reached)
		free(line);
}
```

## Ejemplos

```c
int main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line); //line 1 from test.txt
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line); //line 2 from test.txt
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line); //line 3 from test.txt
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line); //NULL (EOF reached)
	free(line);
}
```


## codigo

