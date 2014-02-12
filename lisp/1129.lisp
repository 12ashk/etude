(defun add1(n)
	(mapcar #'(lambda(x) (+ x 1))  n))

(defun greater_than_five_p(n)
    (mapcar #'(lambda(x) (if (< x 5) t NIL)) n))

(defun FLIP(n)
  (mapcar #'(lambda(x) (if (equal x 'ON) 'OFF 'ON)) n))

(defun foo(n)
  (mapcar #'(lambda(x) x) n))

(defun pick(n)
  (remove-if-not #'(lambda(x) (and (<= 1 x) (<= x 5))) n))

(defun pick2(n)
	   (remove-if #'(lambda(x) (or (> 1 x) (> x 5))) n))

(defun count-the(n)
  (length (remove-if-not #'(lambda(x) (equal x 'the)) n)))

(defun my-intersection(x y)
  (remove-if-not #'(lambda(n) (member n y)) x))

(defun roughly-equal(x k)
  (find-if #'(lambda(e) (and (< (- k 10) e) (< e (+ k 10)))) x))
