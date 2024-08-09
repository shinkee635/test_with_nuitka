
all: cpptest libmypythontest.so

cpptest: cpptest.cpp pythontest.py
	nuitka --module pythontest.py --output-filename=libmypythontest.so
	g++ -o mytest cpptest.cpp -I/usr/include/python3.8 -L. -lmypythontest -lpython3.8
