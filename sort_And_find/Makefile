CC = g++
EXEC := prog

INCS= \
  BSTNode.h \
  BSTTree.h \
  Find.h \
  Sort.h \

  
SRCS= \
  BSTTree.cpp \
  BSTNode.cpp \
  Find.cpp \
  main.cpp \
  Sort.cpp

GCH= \
	BSTNode.h,gch \
	BSTTree.h.gch \
	Find.h.gch

CFLAGS = -g 
#CFLAGS2 =-I../../libs/ff4.2.4/include
CFLAGS2 =

#CFLAGS =-I../../libs/ff4.3.1/include
#FFMPEG_LIB_PATH=../../libs/ff4.3.1/lib

#LFLAGS= -lpthread  -lm -lrt -ldl -lmyso1 -lmyso2 
LFLAGS=

#LFLAGS0=-L../mylibs/ -lmyso1 -lmyso2 
LFLAGS2=

$(EXEC): $(INCS) $(SRCS) Makefile
	$(CC) -o $(EXEC) $(SRCS) $(CFLAGS) $(CFLAGS2) $(LFLAGS) $(LFLAGS2)    

#	mv $(EXEC) ../ -f

.PHONY: clean
clean:
	rm -f $(EXEC) $(GCH)
