
test_sort: test_sort.o sort.o
	gcc -o test_sort sort.o test_sort.o

run-sort:
	./test_sort

clean:
	rm -rf reverseLinkedList addIntsNoOverflow max_minus_min count_pwful_inverses test_sort *.o 