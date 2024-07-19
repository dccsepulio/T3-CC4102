run-bloom:
	g++ -o bloom_filter main.cpp
	./bloom_filter
run-grep:
	g++ -o no_filter_main no_filter_main.cpp 
	./no_filter_main
run-csv:
	g++ -o create_csv createcsv.cpp
	./create_csv