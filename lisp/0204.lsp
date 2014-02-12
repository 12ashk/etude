(defun q-sort(f l)
  (unless (atom l)
	(let ((p (car l)) l1 l2)
	  (dolist (n (cdr l))
		(if (funcall f n p) (push n l1) (push n l2)))
	  (append (q-sort f l1) (cons p (q-sort f l2))))))

(defun return-ans(x input weight)
  (setq x (apply #'+ (mapcar #'* input weight))))

(defun check-ans(input answer)
  (let ((x (mapcar #'- input answer)))
	(do ((l x (cdr l)) (f 0))
		((null l) f)
	  (if (<= (car l) 0.3) nil
		  (setq f 1)))))
  
(defun ANN(input answer weight)
  (if (zerop (check-ans input answer))
	  (print input (mapcar #'* input weight))
	  ()))