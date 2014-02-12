(defun find_last(x)
  (car (reverse x)))

(defun my-last(x)
  (if (null (cdr x)) x
	  (my-last (cdr x))))

(defun my-but-last(x)
  (if (null (cddr x)) x
	  (my-but-last (cdr x))))
(defun element-at(x n)
  (if (= n 1) (car x)
	  (element-at (cdr x) (- n 1))))

(defun my-length(x)
  (if (null (cdr x)) 1
	  (+ (my-length (cdr x)) 1)))

(defun my-reverse(x)
  (if (null (cdr x)) x
	  (append (my-reverse (cdr x)) (list (car x)))))

(defun plindromep(x)
  (if (equal x (reverse x)) t nil))

(defun my-flatten(x)
  (if (and (atom (car x)) (null (cdr x))) (list (car x))
		 (if (atom (car x)) (append (list (car x)) (my-flatten (cdr x)))
		 (if (null (cdr x)) (append (my-flatten (car x)))
		  (append (my-flatten (car x)) (my-flatten (cdr x)))))))

(defun first-pack (items acc)
  (cond ((null items) (cons acc items))
		((null acc)
		 (first-pack (cdr items)
					 (list (car items))))
		((eql (car items)
			  (car acc))
		 (first-pack (cdr items)
					 (cons (car items) acc)))
		(t (cons acc items))))

(defun pack (x)
  (cond ((and
		  (null (car (first-pack x nil)))
		  (null (cdr (first-pack x nil)))) nil)
		((null (cdr (first-pack x nil)))
		 (first-pack x nil))
		(t
		 (cons (car (first-pack x nil))
			   (pack (cdr (first-pack x nil)))))))

(defun return-encode(x)
  (if (atom (car x)) (list (car x) (length x))
	  (list (caar x) (length x))))

(defun loop-encode(x)
  (if (null (cdr x)) (list (return-encode x))
	  (cons (return-encode (car x)) (loop-encode (cdr x)))))

(defun encode(x)
  (setf x (pack x))
  (loop-encode x))

(defun return-m-encode(x)
  (cond ((and (eql (length x) 1) (atom (car x))) (car x))
		((eql (length x) 1) (list (caar x) (length (car x))))
		((atom (car x)) (list (car x) (length x)))))

(defun loop-m-encode(x)
  (if (null (cdr x)) (list (return-m-encode x))
	  (cons (return-m-encode (car x)) (loop-m-encode (cdr x)))))

(defun my-modified-encode(x)
  (setf x (pack x))
  (loop-m-encode x))

(defun count_pack(x count stock)
   (cond ((eql (length x) 1)
		  (if (eql (car x) stock) (list (cons (+ count 1) x))
			  (list (list count stock) (car x))))
		((eql (car x) stock)
		 (count_pack (cdr x) (+ count 1) stock))
		((eql count 1)
		 (cons stock (count_pack (cdr x) 1 (car x))))
		(t
		 (cons (list count stock) (count_pack (cdr x) 1 (car x))))))

(defun encode-direct(x)
  (count_pack (cdr x) 1 (car x)))

(defun dupli(x)
  (if (null x) nil
	  (append (list (car x)) (list (car x)) (dupli (cdr x)))))

 (defun repli-body(x count) 
  (if (zerop count) nil
	  (append (list x) (repli-body x (- count 1)))))

(defun repli(x count)
  (if (null x) nil
	  (append (repli-body (car x) count) (repli (cdr x) count))))

(defun drop-body(x count c)
  (cond((null x) nil)
	   ((and (eql (length x) 1) (eql count c)) nil)
	   ((eql (length x) 1) (list (car x)))
	   ((eql count c) (drop-body (cdr x) count 1))
	   (t (append (list (car x)) (drop-body (cdr x) count (+ c 1))))))

(defun drop(x count)
  (drop-body x count 1))

(defun split-list-body(x y num)
  (if (zerop num) (list x y)
	  (split-list-body (append x (list (car y))) (cdr y) (- num 1))))

(defun split-list(x num)
  (cond ((< (length x) num) nil)
		((or (zerop num) (= (length x) num)) x)
		(t  (split-list-body (list (car x)) (cdr x) (- num 1)))))

(defun slicebody(x first last)
  (cond ((and (= first 1) (zerop last)) x)	
		((= first 1) (slicebody (reverse (cdr (reverse x))) 1 (- last 1)))
		(t (slicebody (cdr x) (- first 1) last))))

(defun slice(x first last)
  (slicebody x first (- (length x) last)))

(defun rotate(x num)
  (append (cadr (split-list x num)) (car (split-list x num))))

(defun my-remove(x num)
  (if (= num 1) (cdr x)
	  (cons (car x) (my-remove (cdr x) (- num 1)))))

(defun my-insert(a x num)
  (if (= num 1) (cons a x)
	  (cons (car x) (my-insert a (cdr x) (- num 1)))))

(defun range2(x y)
  (cond ((= x y) (list x))
		((< x y) (append (list x) (range2 (+ x 1) y)))
		((< y x) (append (list x) (range2 x (- x 1))))))
