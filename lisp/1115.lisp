(defun lookup(n x)
  (cond ((null x) nil)
	  ((equal n (car (car x))) (car (cdr (car x))))
	  (t (lookup n (cdr x)))))

(defun sum-tree(x)
  (cond ((null x) 0)
		((numberp x) x)
		(t (+ (sum-tree (car x))
			  (sum-tree (cdr x))))))

(defun sum-tree2(x)
  (cond ((null x) 0)
		((numberp x) x)
		((symbolp x) 0)
		(t (+ (sum-tree2 (car x))
			  (sum-tree2 (cdr x))))))

(defun flatten(x)
  (cond ((null x) '())
		((symbolp x) (list x))
		(t (append (flatten (car x))
				   (flatten (cdr x))))))
(defun flatten(x)
  (cond ((null x) '())
		((symbolp x) (list x))
		(t (append (flatten (car x))
				   (flatten (cdr x))))))

(defun sleepy(x)
  (cond ((null x) nil)
		((symbolp x) 'z)
		(t (cond (sleepy (car x))
				   (sleepy (cdr x))))))


