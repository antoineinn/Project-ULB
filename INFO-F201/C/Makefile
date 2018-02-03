TARGET=client server 
normal: $(TARGET)


client: client.c
	gcc -Wall client.c -o client

server: server.c
	gcc -Wall server.c -pthread -o server

clean:
	$(RM) $(TARGET) 
