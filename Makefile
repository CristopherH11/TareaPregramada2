all:
	mkdir -p bin
	g++ -g -c --std=c++17 src/empleado.cpp -o bin/empleado.o
	g++ -g -c --std=c++17 src/empleadoNomina.cpp -o bin/empleadoNomina.o
	g++ -g -o bin/tests bin/empleado.o bin/tipoEnvio.o bin/empleadoNomina.o

test:
	mkdir -p bin
	g++ -g -c --std=c++17 src/empleado.cpp -o bin/empleado.o
	g++ -g -c --std=c++17 src/empleadoNomina.cpp -o bin/empleadoNomina.o
	g++ -g -c --std=c++17 tests/tests_empleadoPorHoras.cpp -o bin/tests_empleadoPorHoras.o
	g++ -g -o bin/tests bin/tests_empleadoPorHoras.o bin/empleado.o bin/empleadoNomina.o -lgtest -lgtest_main -lpthread

clean:
	rm -Rf bin