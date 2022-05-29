
debug:
	g++ --std=c++17  ./single_threaded/expressionMatchSingle.cpp  ./test/test.cpp -o ./bin/regex_debug.out 
	./bin/regex_debug.out --debug ./data/regularExpressions.txt > ./logs/debug_log.log

testall:
	g++ --std=c++17  ./single_threaded/expressionMatchSingle.cpp  ./test/test.cpp -o ./bin/regex_test.out
	./bin/regex_test.out --test ./data/regularExpressions.txt ./data/bodies.txt > ./logs/all_test.log

clean:
	rm -rf *.log
	rm -rf *.out
	cd bin; rm -rf *.out
	cd logs; rm -rf *.log
