(define (average x y)
  (/ (+ x y) 2))

(define (imporve guess x)
  (average guess (/ x guess)))

(define (square x)
  (* x x))

(define (good-enough? guess x)
  (< (abs (- (square guess) x)) 0.001))

(define (new-if predicate then-clause else-clause)
  (cond (predicate then-clause)
		(else else-clause)))

(define (sqrt-iter guess x)
  (new-if (good-enough? guess x)
		  guess
		  (sqrt-iter (imporve guess x)
					 x)))

;; ex 1.11
(define (F n)
	(if (< n 3)
		n
		(+ (F (- n 1)) (* 2 (F (- n 2))) (* 3 (F (- n 3))))))


