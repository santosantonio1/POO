#MAKEFILE LISTA 7
CFLAGS=-c -std=c++11
EXE=app
CC=g++

all:			${EXE}

${EXE}:			Pessoa.o Aluno.o Professor.o main.o
				${CC} Pessoa.o Aluno.o Professor.o main.o -o ${EXE}

Pessoa.o:		Pessoa.hpp Pessoa.cpp
				${CC} ${CFLAGS} Pessoa.cpp

Aluno.o:		Pessoa.hpp Aluno.hpp Aluno.cpp
				${CC} ${CFLAGS} Aluno.cpp

Professor.o:	Pessoa.hpp Professor.hpp Professor.cpp
				${CC} ${CFLAGS} Professor.cpp
			
clean:			
				rm -f Pessoa.o Aluno.o Professor.o main.o ${EXE}