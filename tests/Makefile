CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

test: test_utilities
	./test_utilities

test_utilities: test_utilities.cpp extracted_utilities.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

extracted_utilities.cpp: ../Utilities.h
	echo "#include <cstdint>" > $@
	echo "long random(long max);" >> $@
	grep "uint8_t getRandom()" $< >> $@

clean:
	rm -f test_utilities extracted_utilities.cpp

.PHONY: test clean
