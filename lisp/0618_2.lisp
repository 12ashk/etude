(defun gcd$ (m n)
  (if (= (mod m n) 0) n
      (gcd$ n (mod m n))))