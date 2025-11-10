# Makefile para compilar múltiplos exercícios em C++ no Windows
#
# Uso:
#   make           - Compila todos os exercícios
#   make all       - O mesmo que 'make'
#   make clean     - Remove todos os arquivos .exe e .o gerados

# Define o compilador
CXX = g++

# Define flags de compilação (opcional, mas recomendado)
# Use -std=c++11 ou mais recente, -Wall para todos os warnings
CXXFLAGS = -std=c++11 -Wall -Wextra

# --- ATENÇÃO ---
# Lista de todos os executáveis .exe que serão criados.
# O nome '9_mesmos_elementos.exe' foi um palpite baseado na imagem
# onde o nome estava cortado.
# ** Se o seu arquivo for '9_mesmos.cpp' ou outro, altere o nome na lista abaixo! **
TARGETS = 1_k_maior.exe \
          2_sao_anagramas.exe \
          3_ordenar_alunos.exe \
          4_remover_duplicatas.exe \
          5_strings_por_tamanho.exe \
          6_quadro_medalhas.exe \
          7_menor_diferenca.exe \
          8_k_mais_proximos.exe \
          9_mesmos_elementos.exe \
          10_uniao.exe \
          11_intersecao.exe

# O(s) arquivo(s) objeto compartilhados
OBJS = utils.o

# Regra principal: 'all' depende de todos os executáveis listados em TARGETS
# Esta é a regra executada por padrão quando você digita 'make'
all: $(TARGETS)

# Regra de padrão para criar um .exe
# Ela diz ao make como criar um 'arquivo.exe' a partir de um 'arquivo.cpp'
# e dos objetos em $(OBJS)
#
# $@ é uma variável automática para o nome do alvo (ex: 1_k_maior.exe)
# $< é uma variável automática para a primeira dependência (ex: 1_k_maior.cpp)
%.exe: %.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $< $(OBJS)

# Regra para compilar o utils.o
# Se 'utils.h' existir e for modificado, 'utils.o' será recompilado.
# Se você não tiver um 'utils.h', pode remover a dependência 'utils.h'.
$(OBJS): utils.cpp utils.h
	$(CXX) $(CXXFLAGS) -c utils.cpp -o $(OBJS)

# Regra "clean": remove os arquivos gerados
# Usa o comando 'del' do Windows.
clean:
	# O '-' no início ignora erros (caso os arquivos não existam)
	# /F força a exclusão, /Q é o modo silencioso
	# 2>nul redireciona mensagens de erro para o "nada"
	-del /F /Q $(TARGETS) $(OBJS) 2>nul

# Declara 'all' e 'clean' como alvos "phony" (falsos)
# Isso diz ao make que 'all' e 'clean' não são nomes de arquivos reais
.PHONY: all clean