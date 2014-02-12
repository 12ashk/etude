(defun power(x y)
  (if (= y 1) x
	(* x (power x (- y 1)))))

(defun count-atom(x)
  (cond ((null x) 0)
		((atom x) 1)
		(t (+ (count-atom (car x))
			  (count-atom (cdr x))))))

(defun count-anywhere(x y)
  (cond ((null y) 0)
		((eql x y) 1)
		((atom y) 0)
		(t (+ (count-anywhere x (car y))
			  (count-anywhere x (cdr y))))))

(defun mappend(fn the-list)
  "apply fn to each element of list and append the results"
  (apply #'apply (mapcar fn the-list)))

(defun dot-product(x y)
  (apply #'+ (mapcar #'* x y)))

(defun sentence()
  (append (noun-phrase) (verb-phrase)))

(defun noun-phrase()
  (append (Article) (Noun)))

(defun verb-phrase()
  (append (Verb) (noun-phrase)))

(defun Article()
  (one-of '(the a)))

(defun Noun()
  (one-of '(man ball woman table)))

(defun Verb()
  (one-of '(hit took saw liked)))

(defun one-of(set)
  (list (random-elt set)))

(defun random-elt(choices)
  (elt choices (random (length choices))))

(defun Adj*()
  (if (= (random 2) 0) nil
	(append (Adj) (Adj*))))

(defun PP*()
  (if (random-elt '(t nil)) (append (PP) (PP*))
	nil))

(defun nou-phrase()
  (append (Article) (Adj*) (Noun) (PP*)))
(defun PP()
  (append (Prep) (noun-phrase)))
(defun Adj()
  (one-of '(big little blue green adiabatic)))
(defun Prep()
  (one-of '(to in by with on)))

(defparameter *simple-grammer*
			  '((sentence -> (noun-phrase verb-phrase))
				(noun-phrase -> (Article Noun))
				(verb-phrase -> (Verb noun-phrase))
				(Article -> the a)
				(Noun -> man ball woman table)
				(Verb -> hit took saw liked)))

(defvar *grammer* *simple-grammer*)

(defun rule-lhs(rule)
  (car rule))

(defun rule-rhs(rule)
  (cddr rule))

(defun rewrites(category)
  (rule-rhs (assoc category *grammer*)))

(defun generate(phrase)
  "generate a random sentence or phrase"
  (cond ((listp phrase)
		 (mappend #'generate phrase))
		((rewrites phrase)
		 (generate (random-elt (rewrites phrase))))
		(t (list phrase))))
