(defun comb(n m)
  (cond ((or (= m 0)
			 (= n m))
		 1)
		(t (+ (comb (- n 1) m)
			  (comb (- n 1) (- m 1))))))

(defun Ack(m n)
  (cond ((zerop m) (+ n 1))
		((zerop n) (Ack (- m 1) 1))
		(t (Ack (- m 1) (Ack m (- n 1))))))