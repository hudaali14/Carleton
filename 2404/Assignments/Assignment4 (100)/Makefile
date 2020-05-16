a4: main.o Date.o Object.o Student.o Control.o View.o
	g++ -o a4 main.o Date.o Object.o Student.o Control.o View.o

main.o:    main.cc Control.h
	g++ -c main.cc

Date.o:    Date.cc Date.h
	g++ -c Date.cc

Object.o: Object.cc Object.h
	g++ -c Object.cc

Student.o: Student.cc Student.h
	g++ -c Student.cc

Control.o: Control.cc Control.h View.h List.h
	g++ -c Control.cc

View.o: View.cc View.h
	g++ -c View.cc

clean:
	rm -f *.o a4
