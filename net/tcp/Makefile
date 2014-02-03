
EXEC = client server
CC = gcc
CFLAGS = -I../include

V = @
Q = $(V:1=)
Q_CC = $(Q:@=@echo    '     CC       '$@;)
Q_LINK = $(Q:@=@echo    '     LINK     '$@;)


all: $(EXEC)

client:
	$(Q_CC) $(CC) $(CFLAGS) client.c -o client

server:
	$(Q_CC) $(CC) $(CFLAGS) server.c -o server

clean:
	@(rm -rf $(EXEC))

world: clean all
