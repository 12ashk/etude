(defun factorial (n)
	   (if (= n 0) 1
	       (* (factorial (- n 1)) n)))