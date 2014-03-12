(defun drawline(x)
  (cond ((zerop x) nil)
		(t (format t "*")
		   (drawline (- x 1)))))

(defun drawbox(x y)
  (cond ((zerop y) nil)
		(t (drawline x)
		   (format t "~%")
		   (drawbox x (- y 1)))))