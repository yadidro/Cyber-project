# All Targets
all: cyber

# Tool invocations
# Executable "cyber" depends on the files cyber.o and cyber.o.
cyber: bin/CyberDNS.o bin/CyberExpert.o bin/CyberPC.o bin/CyberWorm.o bin/Day.o bin/main.o 

	g++ -o bin/cyber bin/CyberDNS.o bin/CyberExpert.o bin/CyberPC.o bin/CyberWorm.o bin/Day.o bin/main.o

# Depends on the source and header files
bin/CyberDNS.o: src/CyberDNS.cpp include/CyberDNS.h
	g++ -g -Wall  -c -Linclude -o bin/CyberDNS.o src/CyberDNS.cpp
bin/CyberExpert.o: src/CyberExpert.cpp include/CyberExpert.h
	g++ -g -Wall  -c -Linclude -o bin/CyberExpert.o src/CyberExpert.cpp
bin/CyberPC.o: src/CyberPC.cpp include/CyberPC.h
	g++ -g -Wall  -c -Linclude -o bin/CyberPC.o src/CyberPC.cpp
bin/CyberWorm.o: src/CyberWorm.cpp include/CyberWorm.h
	g++ -g -Wall  -c -Linclude -o bin/CyberWorm.o src/CyberWorm.cpp
bin/Day.o: src/Day.cpp include/Day.h
	g++ -g -Wall  -c -Linclude -o bin/Day.o src/Day.cpp
bin/main.o: src/main.cpp
	g++ -g -Wall  -c -Linclude -o bin/main.o src/main.cpp

# Depends on the source and header files 



#Clean the build directory
clean: 
	rm -f bin/*