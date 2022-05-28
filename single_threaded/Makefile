
debug:
	g++ --std=c++17  expressionMatchSingle.cpp  main.cpp -o regex.out 
	./regex.out --debug > basic.log

release:
	g++ --std=c++17 expressionMatchSingle.cpp main.cpp -o regex.out
	./regex.out > basic.log

test:
	g++ --std=c++17  expressionMatchSingle.cpp  main.cpp -o regex.out 
	./regex.out --test ../data/bodies.txt > basic.log

clean:
	rm -rf *.log
	rm -rf *.out
