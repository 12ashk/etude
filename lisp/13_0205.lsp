(defun fact(n)
  (fact-body n 1))

(defun fact-body(n ans)
  (if (= n 1)
	  ans
	  (fact-body (- n 1) (* ans n))))

(defun fizzbuzz(n)
  (fizzbuzz-body n nil))

(defun fizzbuzz-body(n lst)
  (cond ((= 0 n) lst)
		((= 0 (mod n 15)) (fizzbuzz-body (- n 1) (cons 'fizzbuzz lst)))
		((= 0 (mod n 3)) (fizzbuzz-body (- n 1) (cons 'fizz lst)))
		((= 0 (mod n 5)) (fizzbuzz-body (- n 1) (cons 'buzz lst)))
		(t (fizzbuzz-body (- n 1) (cons n lst)))))
