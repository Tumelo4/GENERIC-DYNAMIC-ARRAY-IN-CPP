main:
	g++ -g -static main.cpp -o Main

clean:
	rm -f *o Main

run:
	./Main 
