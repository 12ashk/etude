(defun rev(x)
  (if (NULL x) '()
	(append (rev (cdr x)) (list (car x)))))

(defun rm(x y)
  (if (NULL y) NIL
	(if (equal (car y) x) (cdr y)
	  (append (list (car y)) (rm x (cdr y))))))

(defun mem(x y)
  (if (NULL y) NIL
	(if (equal (car y) x) y
	  (mem x (cdr y)))))

(defun beforep(x y z)
  (mem y (mem x z)))

(defun rmdup(x)
  (if (NULL x) NIL
	(if (NULL (mem (car x) (cdr x))) (append (list (car x)) (rmdup (cdr x)))
	  (rmdup (cdr x)))))

(defun rmdup2(x)
  (if x (cons (car x) (rmdup (rm (car x) (cdr x))))))

(defun wa(x y)
  (rmdup (append x y)))

(defun seki(x y)
  (cond ((null x) nil)
		((mem (car x) y)
		 (cons (car x) (seki (cdr x) y)))
		(t (seki (cdr x) y))))