# T3-CC4102 Bloom Filter Project

Este proyecto implementa y analiza el uso de un filtro de Bloom para la búsqueda eficiente de nombres populares de bebés.

## Estructura del Proyecto

El repositorio contiene los siguientes archivos:

- **MurmurHash3.h y MurmurHash3.cpp**: Implementación de MurmurHash3, se utilizo la libreria de https://github.com/aappleby/smhasher/blob/master/src/MurmurHash3.cpp.
- **main.cpp**: Uso del Filtro de Bloom con la base de datos de Popular Baby Names y realiza la busqueda de los nombres en ella mediante un proceso grep.
- **no_filter_main.cpp**: implementa la busqueda de los nombres de la base de datos de Popular Baby Names mediante un proceso grep.
- **bloom_filter.hpp y bloom_filter.cpp**: Implementación del Filtro de Bloom con la cantidad de bits M y cantidad de hash K definido en el header.
- **createcsv.cpp**: Crea un csv con las cantidades de palabras deceadas utilizando un csv elegido.

- **data/**: Contiene los archivos CSV.
    - `Popular-Baby-Names-Final.csv`
    - `Film-Names.csv`
    - `worldcities.csv`
    - `1024-0.csv`: Archivo CSV con 1024 nombres y p = 0, donde p = #palabras del csv Popular_Baby_Names_Final en N/ |N|.
    - `1024-1-4.csv`: Archivo CSV con 1024 nombres y p = 1/4, donde p = #palabras del csv Popular_Baby_Names_Final en N/ |N|.
    - `1024-1-2.csv`: Archivo CSV con 1024 nombres y p = 1/2, donde p = #palabras del csv Popular_Baby_Names_Final en N/ |N|.
    - `1024-3-4.csv`: Archivo CSV con 1024 nombres y p = 3/4, donde p = #palabras del csv Popular_Baby_Names_Final en N/ |N|.
    - `1024-1.csv`: Archivo CSV con 1024 nombres y p = 1, donde p = #palabras del csv Popular_Baby_Names_Final en N/ |N|.
    **se aplica el mismo sistema de nombre para el resto de csv**
    - `4096-0.csv`
    - `4096-1-4.csv`
    - `4096-1-2.csv`
    - `4096-3-4.csv`
    - `4096-1.csv`
    - `16384-0.csv`
    - `16384-1-4.csv`
    - `16384-1-2.csv`
    - `16384-3-4.csv`
    - `16384-1.csv`
    - `65536-0.csv`
    - `65536-1-4.csv`
    - `65536-1-2.csv`
    - `65536-3-4.csv`
    - `65536-1.csv`
- **results/**: Contiene los resultados de los experimentos.
    - `execution_times_bloom_filter_3_hash.csv`: Archivo CSV con los tiempos de ejecución de las pruebas realizadas con K = 3 y M = 1000000.
    - `execution_times_bloom_filter_5_hash.csv`: Archivo CSV con los tiempos de ejecución de las pruebas realizadas con K = 5 y M = 1000000.
    - `execution_times_bloom_filter_7_hash.csv`: Archivo CSV con los tiempos de ejecución de las pruebas realizadas con K = 7 y M = 1000000.
    - `execution_times_bloom_filter_3_hash.c_1500000sv`: Archivo CSV con los tiempos de ejecución de las pruebas realizadas con K = 3 y M = 1500000.
    - `execution_times_bloom_filter_5_hash.c_1500000sv`: Archivo CSV con los tiempos de ejecución de las pruebas realizadas con K = 5 y M = 1500000.
    - `execution_times_bloom_filter_7_hash.c_1500000sv`: Archivo CSV con los tiempos de ejecución de las pruebas realizadas con K = 7 y M = 1500000.
- **README.md**: Este archivo.
- **Tarea 3.md**: Archivo con el enunciado de la tarea.
- **image.png**: Foto citada en el enunciado de la tarea.
- **Makefile**: Archivo para facilitar la compilación.

## Archivos y Descripción

### MurmurHash3.h

Este archivo define las estructuras necesarias para realizar el hash, toda la documentación aparece en el link dado anteriormente

### MurmurHash3.cpp
Este archivo contiene la implementación de los métodos definidos en MurmurHash3.h.

### main.cpp

Este archivo contiene la lógica para generar el filtro de bloom y realizar la busqueda con ella, además de medir los tiempos de ejecución de la busqueda junto con sus falsos positivos.

### no_filter_main.cpp

Este archivo realiza la busqueda de las palabras en un csv mediante el uso de una función de bsuqueda tipo grep.

### bloom_filter.hpp

Este archivo contiene la definición de los valores K, M, la función `readDataFromCSV` y la clase `BloomFilter` que implementa las siguientes operaciones:
- `readDataFromCSV(filename x, bloomfilter y)`: Toma un filename `x` y le aplica el bloomfilter `y`. 
- `BloomFilter()`: Crea un filtro de bloom.
- `insert(x)`: Inserta el string `x` en el filtro de bloom.
- `contains(x)`: pregunta si el string `x` se encuentra en el filtro de bloom.

### bloom_filter.cpp

Este archivo contiene la implementación de los métodos definidos en `bloom_filter.hpp`.

### createcsv.cpp

Este archivo contiene la lógica para escribir en un csv una cantidad de strings de otro csv de manera aleatoria.


### Requisitos

- Compilador de C++ (e.g., g++)
- Biblioteca estándar de C++

### Compilación y Ejecución

Para ejecutar el programa, usa el siguiente comando:

```sh
make run-bloom
```
El programa generará un filtro de bloom con el csv de Popular-Baby-Names-Final.csv y realiza la busqueda con los csv dentro de data y registrará los tiempos de ejecución junto con los falsos positivos.

```sh
make run-grep
```

El programa generará buscara las palabras dentro de los csv de data y los buscara en Popular-Baby-Names-Final.csv mediante un proceso de busqueda grep, registrando los tiempos de ejecución junto cno los falsos positivos.

```sh
make run-csv
```
El programa tomará un csv y escribira en ella las cantidad de palabras pedidas de otro csv.


## Resultados

Para ejecutar el programa y ver los resultados de los experimentos, utiliza los comandos proporcionados en la sección "Instrucciones de Compilación". Los resultados se guardarán en la carpeta **results/**.

## Documentación del Hardware y Software

- **CPU**: AMD Ryzen 7 5800H with Radeon Graphics 3.20 GHz
- **RAM**: 8,00 GB (7,41 GB usable)
- **Sistema Operativo**: Debian GNU/Linux 12 (bookworm)
- **Compilador**: g++ (Debian 12.2.0-14) 12.2.0
- **Versión del estándar de C++**: C++11