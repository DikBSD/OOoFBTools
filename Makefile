oxt_file = OOoFBTools.oxt

.PHONY:	build clean

build:
	cd oxt; zip -r ../$(oxt_file) *; cd ..

clean:
	rm -f $(oxt_file)

