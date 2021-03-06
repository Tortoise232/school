;find position of an element in a linear list
(defun findPos(l p)
	(cond
		( (null l) nil)
		( (= p 1) (car l) )
		( t (findPos (cdr l) (- p 1)) )))

;find element in a list on any level
(defun findE(l e)
  (Cond
   ( (null l) nil)
   ( (listp (car l)) (or (findE (car l) e) (findE (cdr l) e) ) )
   ((= e (car l)) t)
   (t (findE (cdr l) e))))

;get all sublists of a list
(defun getLists(l)
  (cond
   ( (null l ) nil)
   ( (listp (car l)) (cons (cons (car l) (getLists( car l)) ) (getLists (cdr l))))
   ( t (getLists( cdr l)))
  )
)
;this does not work?
(defun lists(l)
  (cond 
   ( t (cons l (getLists l)))))

;not functional
(defun setfromlist(l)
  (cond 
   ((atom l) l)
   ((finde l (car l)) (setfromlist (cdr l)) )
   (t (cons (car l) (setfromlist (cdr l) ) ) )
   )
)
;dot product of 2 vectors
(defun dotProduct(l1 l2)
  (cond
  ((or (null l1) (null l2)) 0)
  (t (+ (* (car l1) (car l2)) (dotProduct (cdr l1) (cdr l2))))
  )
)

;not functional
;(defun listDepth(l maxPayne depth)
;  (cond 
;   ((null l) maxPayne)
;   ((listp (car l)) (listDepth (car l) maxPayne (+ depth 1))) 
;   ( t (if 
;           (> depth maxPayne) (listDepth (cdr l) depth depth) (listDepth (cdr l)  maxPayne depth) ))
;))

;intersect 2 sets
(defun interset(s1 s2)
  (cond 
  ( (null s1) s2)
  ( (findE s2 (car s1)) ( interset (cdr s1) s2) )
  ( t ( cons (car s1) (interset (cdr s1) s2) )))
)

;add an element after the 2nd, forth, etc elem of a list; call with 2
(defun add2(l e parity)
  (cond
   ( (null l) nil)
   ( (= parity 2) (add2 (cdr l) e 1))
   ( (= parity 0) (cons (car l) (cons e (add2 (cdr l) e 1))))
   ( (= parity 1) (cons (car l) (add2 (cdr l) e 0) ))
  )
)

;reverse heterogeneus list
(defun reverseList(l)
(cond
 ( (null l) '())
 ( (listp (car l)) (reverseList (car l)))
 ( t (cons (car l) (reverseList (cdr l))))
)
)

;sort a list from a set

(defun insertSort(l e)
(cond
 ( (null l) (list e))
 ( (equal (member e l) t) l)
 ( (or (= e (car l)) (< e (car l))) (cons e l))
 ( t (cons (car l) (insertSort (cdr l) e))
)
 ))

(defun sortList(l)
(cond
 ( (null l) nil)
 ( t (insertSort (car l) (sortList (cdr l) )))
))

(defun vezi_adancime(l)
	(cond
		( (atom l ) 0 )
		( t ( + 1 ( apply #'+ ( mapcar #'vezi_adancime (cdr l) ) ) ) )
	)
) ;stolen


;map functions bois
(defun inmulteste(l)
  (cond
   ((atom l) l)
   (t ( apply #'* ( mapcar #'inmulteste (cdr l))))
   )
)
;cu map functions babeh
(defun replaceElem(l a b)
  (cond 
   ( (null l) nil)
   ( (and (atom l) ( = l a))    b)
   ( (and (atom l) (not ( = l a)  ))  l )
   ( t ( apply #'list (mapcar #'(lambda (l) (replaceelem l a b) )  l) ) )
   )
)

;return the level of a node x in a tree of type (2) 
;(root (left) (right))
(defun getLevel(l n c)
  (cond 
   ((or (null l) (and (atom l) (not ( = l n))) ) nil)
   ((and (atom l) ( = l n)) c)
   ((= (car l) n) c)
   (t (or (getLevel (caddr l) n (+ c 1)) (getLevel (cadr l) n (+ c 1))))
  )
)
;get tree inorder; looks weird bc of random null value
(defun inorder(l)
  (cond
   ((atom l) l)
   ((not (null l)) (cons (inorder (cadr l)) (cons (car l) (inorder (caddr l)) ) ) )
  )
)
;check if tree is balanced
;not executed
(defun balanced (l)
    (cond
        ((or (null l) (atom l)) 0)
        (t 
            (+ 
            (if (not (null (cadr l))) (- (balanced (cadr l)) 1) 0) 
            (if (not (null (caddr l))) ( +(balanced (caddr l)) 1) 0)
            )
        )
    )
)
