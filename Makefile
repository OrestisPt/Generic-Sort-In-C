
test_sort: test_sort.o sort.o
	gcc -o test_sort sort.o test_sort.o

run-sort:
	./test_sort

clean:
	rm -rf test_sort *.o 