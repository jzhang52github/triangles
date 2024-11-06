.PHONY: clean run compile
clean:
	rm *.o
	rm triangles
compile triangles: triangles.o
	@gcc triangles.o -lm