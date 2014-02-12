(defun exp$ (m n)
  (if (= n 0) 1
      (* (exp$ m (- n 1)) m)))