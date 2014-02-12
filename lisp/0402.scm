(define vhello "hello world")

(define fhello (lambda () "hello world"))

(define hello
  (lambda (name)
	(string-append "Hello " name "!")))

(define sum3
  (lambda (a b c)
  (+ a b c)))

(define three-args+
  (lambda (a b c . d)
	(list a b c d)))

(define (hello name)
  (string-append "hello " name "!"))

(define inc
  (lambda (x)
	(+ x 1)))

(define (dec x)
  (- x 1))

(define (trans-to-rad deg)
  (* (/ x 180.0) pi))

(define pi (* 4 (atan 1.0)))

(define (get-dist v t)
  (* v t))

(define (sum-gp a0 r n)
  (* a0 (if (= r 1) n
			(/ (- 1 (expt r n)) (- 1 r)))))

(define (my-abs x)
  (if (> x 0) x
	  (- x)))
(define (my-recip x)
  (if (= x 0) #f
	  (/ 1 x)))

(define (plusp x)
  (if (> x 0) #t
	  #f))
(define (plusp3 x y z)
  (if (and (plusp x) (plusp y) (plusp z)) (* x y z)
	  #f))

(define (pool-wage age)
  (cond ((or (<= age 3) (>= age 65)) 0)
	  ((<= 4 age 6) 50)
	  ((<= 7 age 12) 100)
	  ((<= 13 age 15) 150)
	  ((<= 16 age 18) 180)
	  (#t 200)))

(define (grade-point grade)
  (cond ((<= 80 grade) 'A)
		((<= 60 grade) 'B)
		((<= 40 grade) 'C)
		(#t 'D)))
(define (fact n)
  (if (= n 1) 1
	  (* n (fact (- n 1)))))

(define (fact-let n)
  (let loop((n1 n) (p n))
	(if (= n1 1) p
		(let ((m (- n1 1)))
		  (loop m (* p m))))))

