all:
	gcc server.c -o server
	gcc client.c -o client
	gnome-terminal -e "./server"
	sleep 1
	./client
