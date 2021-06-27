CC = g++
LABEL = -Wall
TARGET = a.out b.out c.out d.out e.out f.out

all: $(TARGET)

a.out: a.cpp
	$(CC) $(LABEL) -o $@ $^
b.out: b.cpp
	$(CC) $(LABEL) -o $@ $^
c.out: c.cpp
	$(CC) $(LABEL) -o $@ $^
d.out: d.cpp
	$(CC) $(LABEL) -o $@ $^
e.out: e.cpp
	$(CC) $(LABEL) -o $@ $^
f.out: f.cpp
	$(CC) $(LABEL) -o $@ $^

a: a.out
	./$^

b: b.out
	./$^

c: c.out
	./$^

d: d.out
	./$^

e: e.out
	./$^

f: f.out
	./$^

clean:
	rm *.out