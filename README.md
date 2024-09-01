## info
SB-CPU-AFFINITY is a simple API to Linux scheduler affinity masks for
SBCL. See documentation of symbols exported from SB-CPU-AFFINITY
package.

## author:

  fork from [niko's repo](https://github.com/nikodemus/sb-cpu-affinity)

## license:

  MIT-style. See file LICENSE for details.

## issues:

  Currently each call to GET-CPU-AFFINITY-MASK (and
  WITH-CPU-AFFINITY-MASK) mallocs 128 bytes of memory for the
  mask, which is never freed by the system -- at least not
  on the Lisp side: freeing this memory causes glibc to complain
  about a double-free, and breaks SBCL.
  In other words, sbcl will not release each 128-byte mask created by the package when it is running.
  Wait until the sbcl process ends before releasing all resources.

## install
```bash
git clone https://github.com/r6v4/sb-cpu-affinity.git

cd sb-cpu-affinity

make

sbcl
```
```common-lisp
(require :asdf)

(pushnew
    (probe-file "../sb-cpu-affinity")
    asdf:*central-registry* :test #'equal)

(asdf:load-system :sb-cpu-affinity)
```

## example
```common-lisp
(let ((all-worker-count (* 2 (sb-cpu-affinity:cpu-count)))
      (all-vcpu-count (sb-cpu-affinity:cpu-count)) )
    (loop for my-worker-number from 0 below all-worker-count do
        (let ((my-worker-number my-worker-number)
              (my-vcpu (nth-value 1 (floor my-worker-number all-vcpu-count))) )
            (sb-thread:make-thread (lambda ()
                (sb-cpu-affinity:with-cpu-affinity-mask (mask :save t)
                    (sb-cpu-affinity:clear-cpu-affinity-mask mask)
                    (setf (sb-cpu-affinity:cpu-affinity-p my-vcpu mask) t)
                    (loop
                        (progn
                            (sleep 1)
                            (format t " [~A,~A] " my-worker-number my-vcpu)
                            (finish-output) ))))))))

```
