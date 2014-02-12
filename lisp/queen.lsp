;;; NxN$BHW$G$N%/%$!<%sLdBj(B
;;; $B%/%$!<%s$r0LCV(B(0 0)$B$+$i;O$a$F(B(n m)$B$KCV$$$F$$$/(B (0 <= n,m < N)


;;; 2$B$D$N%/%$!<%s$,$V$D$+$k0LCV$K$"$k$+$I$&$+$r8!>Z(B
(defun threat (i j a b)       ; 1$B$D$N%/%$!<%s$,(B(i j)$B$K!%$b$&(B1$B$D$,(B(a b)$B$K!%(B
  (or (= i a)                 ; $BF1$89T(B
      (= j b)                 ; $BF1$8Ns(B
      (= (- i j) (- a b))     ; $BFnEl$NBP3Q@~(B
      (= (+ i j) (+ a b))))   ; $BKLEl$NBP3Q@~(B


;;; $B%a%$%s4X?t(Bqueen
;;; $B5/F0;~$O(B (queen  $BHW$N%5%$%:(B  nil  0  0) $B$G8F=P$9(B
;;; $B0z?t(B board $B$K$O0LCV(B(n m)$B$N%j%9%H$,JB$V(B
(defun queen (size board n m)
  (cond ((< m size)
         ;; $B8=:_$N9T$HNs$N43>D$rD4$Y$k(B
         (if (not (conflict n m board))
             (if (= (+ 1 n) size)
                 ;; $B$b$7$9$Y$F$N%/%$!<%s$,CV$1$?$i!$2r$r0u:~(B
                 (printboard (reverse (cons (list n m) board)))
                 ;; $B$=$&$G$J$1$l$P!$<!$N9T$K?J$`(B
                 (queen size (cons (list n m) board) (+ 1 n) 0)))
         ;; $B$$$:$l$N>l9g$bJL$NNs$r;n$_$k(B
         (queen size board n (+ 1 m)))))


;;; $B%/%$!<%s$,HW>e(B(n m)$B$KCV$1$k$+$I$&$+$r3N$+$a$k(B
(defun conflict (n m board)
  (cond ((null board) nil)
        ((threat n m (first (first board)) (second (first board))) t)
        (t (conflict n m (rest board)))))


;;; $BHWLL$r=PNO$9$k(B
(defun printboard (board)
  (format t "~%*")                 ; $B:8>e$N(B*
  (print-horizontal-border board)  ; $B>e$NOH@~(B
  (format t "*")                   ; $B1&>e$N(B*
  (dolist (queen-pos board)
    (format t "~%|")               ; $B:8$NOH(B
    (dotimes (column (length board))
      (if (= column (second queen-pos))
          (format t " Q")          ; $B%/%$!<%s$rCV$/(B
          (format t " .")))        ; $B%/%$!<%s$N8z$-6Z$K$"$k(B
    (format t " |"))               ; $B1&$NOH(B
  (format t "~%*")                 ; $B:82<$N(B*
  (print-horizontal-border board)  ; $B2<$NOH@~(B
  (format t "*"))                  ; $B1&2<$N(B*


;;; $B>e2<$NOH$rIA$/(B
(defun print-horizontal-border (board)
  (dotimes (n (+ 1 (* 2 (length board))))
    (format t "-")))
