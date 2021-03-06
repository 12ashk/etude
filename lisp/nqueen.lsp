(defun threat(i j a b)
  (or (= i a)
	  (= j b)
	  (= (- i j) (- a b))
	  (= (+ i j) (+ a b))))

(defun conflict(n m board)
  (cond ((null board) nil)
		((threat n m (caar board) (cadr board)) t)
		(t (conflict n m (cdr board)))))

(defun queen(size board n m num)
  (cond ((< m size)
		 (if (not (conflict n m board))
		   (if (= (+ 1 n) size)
			 (+ 1 num)
			 (queen size (cons (list n m) board) (+ 1 n) 0 num)))
		 (queen size board n (+ 1 m) num))))
