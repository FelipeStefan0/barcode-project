Bom dia, boa tarde ou boa noite, professor! Sou Felipe Marques de Stefano.

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

O QUE FOI FEITO?

Das funcionalidades solicitadas e implementadas existe o gerador de código de barras, o qual recebe o argumento obrigatório (código de barras), argumentos opcionais (espaçamento lateral, pixel por área, altura do código de barras e o nome da imagem). Assim como setar valores padrões para caso o usuário não informe os argumentos. Foi realizado também a validação do código de barras, mostrando os possíveis problemas, verifica a existência de possíveis arquivos já presentes com o nome e se deseja subscrever e por fim a geração da imagem.

A outra funcionalidade implementada foi o extrator de código de barras que recebe o nome da imagem a qual terá o código extraído, a verificação da existência do arquivo e se a extensão é válida e por fim a extração do código de barras.

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

O QUE NÃO FOI FEITO?

Algo que não foi realizado foi a utilização e structs, o uso do formato PBM em modo binário, inserção dos dígitos abaixo do código de barras, uso de interfaces gráficas ou alguma outra biblioteca externa.

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

O QUE SERIA FEITO DIFERENTE?

Melhora na organização do código, padronização dos métodos, aplicação de boas práticas, começar mais cedo para desenvolver sem pressa e utilização de bibliotecas que pudessem facilitar meu trabalho.

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

COMO COMPILAR?

Como não foi utilizado nenhuma biblioteca extra e nenhum parâmetro a mais, a compilação é normal:

	gcc barcode-generator.c functions.c -o generator
	
	gcc barcode-extractor.c functions.c -o extractor

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

OBSERVAÇÕES

O código se apresenta sem acentuação devido o prompt de comando não reconher. Existe uma imagem de teste na pasta e os executáveis também, apenas para adiantar o trabalho.