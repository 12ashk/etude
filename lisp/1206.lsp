(load "~/lisp/blockdata.lsp")

(defun match-element(e q)
  (or (equal e q)
	  (equal q '?)))

(defun match-triple(a b)
  (every #'match-element a b))

(defun fetch(a)
  (remove-if-not #'(lambda(x) (match-triple x a)) blockdata))

(defun color-pattern(x)
  (list x 'color '?))

(defun supporters(x)
 (mapcar #'car
		 (fetch (list '? 'supports x))))

(defun desc1(x y)
  (car (mapcar #'cdr (fetch (list x y '?)))))

(defun desc2(x)
  (append (desc1 x 'shape)
		(desc1 x 'color)
		(desc1 x 'size)
		(desc1 x 'supports)
		(desc1 x 'left-of)))

(defun supp-cube(x)
  (if (eql (cadr (desc1
			(cadr (desc1 x 'supported-by)) 'shape)) 'cube) t nil))

