(defun fizzbuzz(x)
  (cond ((<= x 0) nil)
		(t (fizzbuzz (1- x))
		   (cond
			 ((zerop (mod x 15))
			  (print 'FizzBuzz))
			 ((zerop (mod x 3))
			  (print 'Fizz))
			 ((zerop (mod x 5))
			  (print 'Buzz))
			 (t
			  (print x))))))

(defun fizzbuzz2(x)
  (let ((y nil))
	(dotimes (n x)
	  (cond ((zerop (mod (1+ n) 15))
			 (setq y (append y '(FizzBuzz))))
			((zerop (mod (1+ n) 3))
			 (setq y (append y '(Fizz))))
			((zerop (mod (1+ n) 5))
			 (setq y (append y '(Buzz))))
			(t
			 (setq y (append y (list (1+ n)))))))
	  (print y)))