CC = gcc
OBJS += receive.o
GOAL = receive_file

.PHONY: all clan
all:$(OBJS) 
	$(CC) -o $(GOAL) $(OBJS) $(LIBS)

clean:
	$(RM) -rf $(GOAL) $(OBJS) $(OBJS:.o=.d)



