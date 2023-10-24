# Makefile trab1 (@Antonio dos Santos; 02/10/2023)

EXE1=app1
EXE2=app2
EXE3=app3
CFLAGS =-c -std=c++11

all:	${EXE1} ${EXE2} ${EXE3}

${EXE1}:			Filme.o Endereco.o Cinema.o Programacao.o Aplicacao.o app1.o
				@g++ Filme.o Endereco.o Cinema.o Programacao.o Aplicacao.o app1.o -o ${EXE1}

${EXE2}:			Filme.o Endereco.o Cinema.o Programacao.o Aplicacao.o app2.o
				@g++ Filme.o Endereco.o Cinema.o Programacao.o Aplicacao.o app2.o -o ${EXE2}

${EXE3}:			Filme.o Endereco.o Cinema.o Programacao.o Aplicacao.o app3.o
				@g++ Filme.o Endereco.o Cinema.o Programacao.o Aplicacao.o app3.o -o ${EXE3}

app1.o:			Aplicacao.hpp app1.cpp
				@g++ ${CFLAGS} app1.cpp

app2.o: 		Aplicacao.hpp app2.cpp
				@g++ ${CFLAGS} app2.cpp

app3.o:			Aplicacao.hpp app3.cpp
				@g++ ${CFLAGS} app3.cpp

Filme.o: 		Filme.cpp Filme.hpp
				@g++ ${CFLAGS} Filme.cpp

Endereco.o:		Endereco.cpp Endereco.hpp
				@g++ ${CFLAGS} Endereco.cpp

Cinema.o:		Endereco.hpp Cinema.hpp Cinema.cpp
				@g++ ${CFLAGS} Cinema.cpp

Programacao.o:	Programacao.hpp Cinema.hpp Filme.hpp Programacao.cpp
				@g++ ${CFLAGS} Programacao.cpp

Aplicacao.o:	Cinema.hpp Filme.hpp Programacao.hpp Aplicacao.hpp Aplicacao.cpp
				@g++ ${CFLAGS} Aplicacao.cpp	

clean:
				@rm -f Endereco.o Filme.o Cinema.o Programacao.o Aplicacao.o app1.o app2.o app3.o ${EXE1} ${EXE2} ${EXE3}
		
		