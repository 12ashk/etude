;;; NxN盤でのクイーン問題
;;; クイーンを位置(0 0)から始めて(n m)に置いていく (0 <= n,m < N)


;;; 2つのクイーンがぶつかる位置にあるかどうかを検証
(defun threat (i j a b)       ; 1つのクイーンが(i j)に．もう1つが(a b)に．
  (or (= i a)                 ; 同じ行
      (= j b)                 ; 同じ列
      (= (- i j) (- a b))     ; 南東の対角線
      (= (+ i j) (+ a b))))   ; 北東の対角線


;;; メイン関数queen
;;; 起動時は (queen  盤のサイズ  nil  0  0) で呼出す
;;; 引数 board には位置(n m)のリストが並ぶ
(defun queen (size board n m)
  (cond ((< m size)
         ;; 現在の行と列の干渉を調べる
         (if (not (conflict n m board))
             (if (= (+ 1 n) size)
                 ;; もしすべてのクイーンが置けたら，解を印刷
                 (printboard (reverse (cons (list n m) board)))
                 ;; そうでなければ，次の行に進む
                 (queen size (cons (list n m) board) (+ 1 n) 0)))
         ;; いずれの場合も別の列を試みる
         (queen size board n (+ 1 m)))))


;;; クイーンが盤上(n m)に置けるかどうかを確かめる
(defun conflict (n m board)
  (cond ((null board) nil)
        ((threat n m (first (first board)) (second (first board))) t)
        (t (conflict n m (rest board)))))


;;; 盤面を出力する
(defun printboard (board)
  (format t "~%*")                 ; 左上の*
  (print-horizontal-border board)  ; 上の枠線
  (format t "*")                   ; 右上の*
  (dolist (queen-pos board)
    (format t "~%|")               ; 左の枠
    (dotimes (column (length board))
      (if (= column (second queen-pos))
          (format t " Q")          ; クイーンを置く
          (format t " .")))        ; クイーンの効き筋にある
    (format t " |"))               ; 右の枠
  (format t "~%*")                 ; 左下の*
  (print-horizontal-border board)  ; 下の枠線
  (format t "*"))                  ; 右下の*


;;; 上下の枠を描く
(defun print-horizontal-border (board)
  (dotimes (n (+ 1 (* 2 (length board))))
    (format t "-")))
