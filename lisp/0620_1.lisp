(defun factorial-loop (n i p)
  (if (> i n) p
      (factorial-loop n (+ i 1) (* p i))))