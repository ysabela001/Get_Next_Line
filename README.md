📜 Get Next Line — Projeto 42

O Get Next Line é um projeto da 42 que tem como objetivo implementar uma função em C capaz de ler uma linha por vez de um descritor de arquivo, independentemente do tamanho da linha.
Esse projeto reforça o uso de buffers, alocação dinâmica de memória e manipulação de ponteiros.

---

📍 Objetivo

Criar uma função chamada get_next_line() que retorna uma linha de texto por chamada, até atingir o final do arquivo (EOF).
A função deve ser eficiente, reutilizável e não causar memory leaks.

---

🧠 Protótipo da Função
char	*get_next_line(int fd);

---

⚙️ Como Funciona

A função lê o arquivo pedaço por pedaço, utilizando um buffer definido por BUFFER_SIZE.

O conteúdo é armazenado dinamicamente e reconstruído até formar uma linha completa (terminada por \n).

Quando o arquivo chega ao fim, a função retorna NULL.

---

🧾 Exemplo de Uso
```
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("example.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

🔧 Compilação e Execução

Compile com o comando:

```
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=42
```

Depois, execute o programa:

```
./a.out
```

🗂️ Estrutura do Projeto

```
├── get_next_line.c         # Lógica principal de leitura e montagem da linha
├── get_next_line_utils.c   # Funções auxiliares (strlen, strchr, substr, etc.)
├── get_next_line.h         # Cabeçalho com protótipos e includes
├── main.c                  # Arquivo de teste
└── Makefile                # Automação da compilação
```

💡 Conceitos Importantes

Buffer: Armazena dados lidos temporariamente de um arquivo  
Static variable: Mantém dados entre chamadas sucessivas da função  
File descriptor: (fd) Inteiro que representa um arquivo aberto  
EOF: Fim do arquivo, sinaliza quando get_next_line deve retornar NULL  

---

🚫 Regras da 42

❌ Não é permitido usar lseek(), fread(), ou funções de leitura prontas.

✅ Apenas read(), malloc(), free() e funções próprias.

✅ Cada linha deve ser retornada exatamente uma vez.

✅ O projeto deve funcionar com qualquer tamanho de BUFFER_SIZE.

---

🧰 Tecnologias Utilizadas

C Linguagem utilizada;
Makefile	Compilação automatizada;
Valgrind	Verificação de memory leaks;

---
🧑‍💻 Autora

Projeto desenvolvido por Ysabela durante a formação da 42 São Paulo.
📎 GitHub: ysabela001
