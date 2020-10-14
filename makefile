all:
	gcc -Wall binary_parser.c -o binary_parser

memtest: all
	valgrind ./binary_parser < test_case2.txt

run: all
	./binary_parser < test_case2.txt
