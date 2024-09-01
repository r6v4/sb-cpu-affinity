# Copyright (c) 2008 Nikodemus Siivola <nikodemus@random-state.net>
#
# Permission is hereby granted, free of charge, to any person
# obtaining a copy of this software and associated documentation
# files (the "Software"), to deal in the Software without
# restriction, including without limitation the rights to use,
# copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following
# conditions:
#
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
# OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
# HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
# WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
# OTHER DEALINGS IN THE SOFTWARE.

VERSION=0.2.1

all: 
	gcc -shared -fPIC cpu-affinity-wrapper.c
        cp a.out /lib64/cpu-affinity-wrapper.so

clean:
	rm -f *~ *.o *.fasl *.so *.tar.gz

release: clean
	mkdir sb-cpu-affinity-$(VERSION)
	cp Makefile LICENSE README *.lisp *.c *.asd sb-cpu-affinity-$(VERSION)/
	tar -czvf sb-cpu-affinity-$(VERSION).tar.gz sb-cpu-affinity-$(VERSION)
	rm -rf sb-cpu-affinity-$(VERSION)
