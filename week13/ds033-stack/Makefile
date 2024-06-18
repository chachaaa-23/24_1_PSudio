#사용할 컴파일러
CC = g++	
#소스파일 지정	
SRC = main.cpp CouponStack.cpp		
OBJ = $(SRC:.cpp=.o)
#executable name
EXEC = main		

#default target 지정. 
$(EXEC): $(OBJ)		
	$(CC) -o $@ $^	
#^컴파일러를 사용해 오브젝트 파일을 링크해 실행파일&의존파일 만들기.

%.o: %.cpp
	$(CC) -c $<		
#^컴파일러를 사용해서 .cpp파일을 컴파일해 .o파일 만듬.

clean:	
	rm -f $(OBJ) $(EXEC)
#^빌드된 오브젝트 파일과 실행파일 삭제.