(defun my-append(x y)
	(cond((null x)  y)
		(t (cons (car x) (my-append (cdr x) y)))))

(defun my-append2(x y)
	(cond ((null x)  y)
		(t (list (car x) (my-append (cdr x) y)))))

(defun add-up(x)
  (cond ((null x) 0)
		(t (+ (car x) (add-up(cdr x))))))

(defun laugh(x)
  (cond ((zerop x) NIL)
		(t (cons 'HA (laugh(- x 1))))))

(defun count-down(x)
  (cond ((zerop x) NIL)
		(t (cons x (count-down(- x 1))))))

(defun square-list(x)
  (cond ((null x) NIL)
		(t (cons (* (car x) (car x)) (square-list(cdr x))))))

(defun anyoddp(x)
  (if (null x) NIL
	(if (oddp (car x)) t
	(anyoddp(cdr x)))))

(defun anyoddp2(x)
  (cond ((null x) NIL)
		((oddp (car x)) t)
		(t (anyoddp(car x)))))

(defun extract-number(x)
  (if (null x) NIL
	(if (numberp (car x)) (cons (car x) (extract-number(cdr x)))
	  (extract-number(cdr x)))))

(defun extract-number2(x)
  (cond ((null x) NIL)
		((numberp (car x)) (cons (car x) (extract-number(cdr x))))
		(t (extract-number(cdr x)))))

(defun count-odd(x)
  (if (null x) 0
  	(if (oddp (car x)) (+ 1 (count-odd(cdr x)))
		(count-odd(cdr x)))))

(defun count-odd2(x)
  (cond ((null x) 0)
		((oddp (car x)) (+ 1 (count-odd(cdr x))))
		(t (count-odd(cdr x)))))
