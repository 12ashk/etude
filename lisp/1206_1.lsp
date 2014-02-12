(defun g(x z)
  (if (zerop z) x
	  (g (+ x 1) (- z 1))))

(defun f(x y z)
  (if (zerop x) (list (g x z) y)
	  (f (- x 1) (+ y 1) (+ z 1))))

(defun ->(x y)
  (setq y 0)
  (setq z 0)
  (f x y z))

(defun succ(x)
  (+ x 1))

(defun u(i n)
  (if (> i (length n)) nil
	  (if (= i 1) (car n)
		  (u (- i 1) (cdr n)))))

(defun plus(k x)
  (if (zerop k) x
	  (succ (plus (- k 1) x))))

(defun mult(k x)
  (if (zerop k) 0
	  (plus (mult (- k 1) x) x)))

(defun myeq(x y)
  (if (= x y) 1
	  0))

(defun ge(x y)
  (if (< x y) 0
	  1))

(defun zero?(x)
  (if (zerop x) 1
	  0))

(defun &(x y)
  (mult x y))

(defun v(x y)
  (zero? (^ (zero? x) (zero? y))))