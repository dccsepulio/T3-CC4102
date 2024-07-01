# T3-CC4102 Bloom Filter Project

Este proyecto implementa y analiza el uso de un filtro de Bloom para la búsqueda eficiente de nombres populares de bebés.

## Requisitos

- g++ (o cualquier compilador de C++)
- GNU Make

## Instrucciones de Compilación

1. Clona el repositorio:
    ```bash
    git clone https://github.com/dccsepulio/T3-CC4102.git
    cd T3-CC4102
    ```

2. Compila el código:
    ```bash
    make
    ```

3. Ejecuta el programa:
    ```bash
    ./bloom_filter
    ```

4. Otras opciones de ejecución:
    - Ejecuta con depuración:
        ```bash
        make run-g
        ```
    - Ejecuta con sanitizadores de direcciones y comportamiento indefinido:
        ```bash
        make run-san
        ```
    - Ejecuta con sanitizador de hilos:
        ```bash
        make run-thr
        ```

## Estructura del Proyecto

- **data/**: Contiene los archivos CSV.
    - `Popular-Baby-Names-Final.csv`
    - `Film-Names.csv`
- **include/**: Contiene los archivos de cabecera.
    - `bloom_filter.hpp`
- **results/**: Contiene los resultados de los experimentos.
- **src/**: Contiene el código fuente en C++.
    - `main.cpp`
    - `bloom_filter.cpp`
- **README.md**: Este archivo.
- **Tarea 3.md**: Archivo con el enunciado de la tarea.
- **image.png**: Foto citada en el enunciado de la tarea.
- **Makefile**: Archivo para facilitar la compilación.

## Funcionalidades

- Implementación del filtro de Bloom.
- Búsqueda con y sin el filtro de Bloom.
- Medición del tiempo de búsqueda y tasa de error.

## Ejecución y Resultados

Para ejecutar el programa y ver los resultados de los experimentos, utiliza los comandos proporcionados en la sección "Instrucciones de Compilación". Los resultados se guardarán en la carpeta **results/**.

