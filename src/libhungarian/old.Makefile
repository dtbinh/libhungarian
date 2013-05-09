CC = clang
AR = ar

CFLAGS =  -Wall -O3 -I. -I../utils/
LDFLAGS = -L. -L../utils/ -lhungarian -lreadcsv

all: libhungarian.a readcsv.a hungarian_test


hungarian_test: hungarian_test.c $(HUNGARIANLIB)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

libhungarian.a: hungarian.o
	$(AR) cr $@ hungarian.o

readcsv.a: readcsv.o
	$(AR) cr $@ readcsv.o

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *.a hungarian_test
