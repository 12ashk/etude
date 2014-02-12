(defun C1 (n k)
  (if (= k 0) 1
      (* (/ n k) (C1 (- n 1) (- k 1)))))