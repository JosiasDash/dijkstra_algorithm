
SRC		=		src/Graph.cpp \
				src/Info.cpp \
				src/Node.cpp \
				src/Solver.cpp \
				src/main.cpp

BIN		=		pathsolver

all: $(BIN)

$(BIN): $(SRC)
		g++ $(SRC) -o $(BIN)

clean:
		rm -f *#
		rm -f *~

fclean:	clean
		rm -f $(BIN)

re: fclean all
