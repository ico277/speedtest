build:
	g++ speed.cpp util.cpp -pthread -O3 -o speed
install : build
	sudo cp ./speed /usr/bin/speedtest
run: install
	/usr/bin/speedtest
