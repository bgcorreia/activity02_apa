all: ordenacao2

ordenacao2: ordenacao2.cpp
	@echo "Compilando arquivo objeto: ordenacao2"
	@g++ -o ordenacao2 ordenacao2.cpp

install: ordenacao2
	@echo "Instalando no Sistema."
	@sudo cp ordenacao2 /usr/local/bin/ordenacao2

clean:
	@echo "Limpando arquivos"
	-@rm -f ordenacao2
