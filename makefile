all:
	g++ *.cpp *.h expressions/*.cpp *.h commands/*.cpp *.h -std=c++14 -Wall -pthread
