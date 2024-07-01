# Nombre del proyecto
PROJ=bloom_filter

# Detectar la arquitectura del sistema
ARCH=$(shell arch)

# Archivos fuente y de cabecera
SRCS= src/main.cpp src/bloom_filter.cpp
HDRS= include/bloom_filter.hpp

# Configuraciones del compilador
CXX=g++
CXXFLAGS=-std=c++11 -Wall -Werror -Iinclude
LDFLAGS=

# Definir el ejecutable
EXEC=$(PROJ)

# Variables para make
MAK=make --no-print-directory

# Reglas del Makefile

all: $(EXEC)

$(EXEC): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(EXEC) $(LDFLAGS)

# Reglas de ejecución

run: $(EXEC)
	./$(EXEC)

# Reglas de depuración

run-g: $(EXEC)-g
	./$(EXEC)-g

run-san: $(EXEC)-san
	./$(EXEC)-san

run-thr: $(EXEC)-thr
	./$(EXEC)-thr

# Compilaciones especiales

$(EXEC)-g: $(SRCS) $(HDRS)
	$(CXX) -g $(CXXFLAGS) $(SRCS) -o $(EXEC)-g $(LDFLAGS)

$(EXEC)-san: $(SRCS) $(HDRS)
	$(CXX) -g -fsanitize=address -fsanitize=undefined $(CXXFLAGS) $(SRCS) -o $(EXEC)-san $(LDFLAGS)

$(EXEC)-thr: $(SRCS) $(HDRS)
	$(CXX) -g -fsanitize=thread $(CXXFLAGS) $(SRCS) -o $(EXEC)-thr $(LDFLAGS)

# Limpieza

clean:
	rm -rf *.o *.log $(EXEC)* core

# Leer README

readme:
	@less README.md
