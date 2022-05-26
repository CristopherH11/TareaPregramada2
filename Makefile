all:
	mkdir -p bin
	g++ -g -c --std=c++17 src/empleado.cpp -o bin/empleado.o
	g++ -g -c --std=c++17 src/empleadoNomina.cpp -o bin/empleadoNomina.o
	g++ -g -c --std=c++17 src/empleadoPorHoras.cpp -o bin/empleadoPorHoras.o
	g++ -g -c --std=c++17 src/planilla.cpp -o bin/planilla.o
	g++ -g -c --std=c++17 src/main.cpp -o bin/main.o
	g++ -g -o bin/programa bin/empleado.o bin/planilla.o bin/empleadoNomina.o bin/empleadoPorHoras.o bin/main.o

test:
	mkdir -p bin
	g++ -g -c --std=c++17 src/empleado.cpp -o bin/empleado.o
	g++ -g -c --std=c++17 src/empleadoNomina.cpp -o bin/empleadoNomina.o
	g++ -g -c --std=c++17 src/empleadoPorHoras.cpp -o bin/empleadoPorHoras.o
	g++ -g -c --std=c++17 tests/test_empleado.cpp -o bin/test_empleado.o
	g++ -g -o bin/tests bin/empleado.o bin/test_empleado.o bin/empleadoNomina.o bin/empleadoPorHoras.o -lgtest -lgtest_main -lpthread

clean:
	rm -Rf bin