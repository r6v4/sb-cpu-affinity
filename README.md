## info
SB-CPU-AFFINITY is a simple API to Linux scheduler affinity masks for
SBCL. See documentation of symbols exported from SB-CPU-AFFINITY
package.

## Author:

  Nikodemus Siivola <nikodemus@random-state.net>

## License:

  MIT-style. See file LICENSE for details.

## Bugs and Issues:

  Currently each call to GET-CPU-AFFINITY-MASK (and
  WITH-CPU-AFFINITY-MASK) mallocs 128 bytes of memory for the
  mask, which is never freed by the system -- at least not
  on the Lisp side: freeing this memory causes glibc to complain
  about a double-free, and breaks SBCL.

  Patches and/or explantions for this welcome.

## install
```bash
make
```

## Usage example:
```common-lisp
  (ql:quickload :sb-cpu-affinity)

  (use-package :sb-cpu-affinity)

  (with-cpu-affinity-mask (mask)
    (print mask))

  (with-cpu-affinity-mask (mask :save t)
    ;; Remove all
    (clear-cpu-affinity-mask mask)
    ;; Set CPU 0.
    (setf (cpu-affinity-p 0 mask) t))
 
  (with-cpu-affinity-mask (mask)
    (print mask))

  (with-cpu-affinity-mask (mask :save t)
    ;; Only odd CPUs in mask.
    (dotimes (cpu (cpu-count))
      (setf (cpu-affinity-p cpu mask) (oddp cpu))))
  
  (with-cpu-affinity-mask (mask)
    (print mask))
```
