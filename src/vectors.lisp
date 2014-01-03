(lisp
 (defun type-spec (type)
   (ecase type
     (double 'd)
     (float 'f)
     (int 'i)
     (unsigned\ int 'ui)
     (char 'c)
     (unsigned\ char 'uc)
     ))

 (defun vectype (dim type)
   (cintern (format nil "vec~a~a" dim (type-spec type))))

 (defun cn (n dim)
   "component-name. shortened name for readability in the actual code."
   (if (<= dim 4)
       (cintern (string (char "xyzw" n)))
       (cintern (format nil "x~a" n))))

 (defparameter *all-types* (list 
			    'float
			    'double
			    'int
			    'unsigned\ int
			    'char
			    'unsigned\ char)))

(defmacro define-instances-of-dimension (function comp)
  `(lisp (cgen ,@(loop for type in *all-types* collect `(,function ,comp ,type)))))

(defmacro define-instances (function from to)
  `(lisp (cgen ,@(loop for dim from from to to append
		      (loop for type in *all-types* collect `(,function ,dim ,type))))))

(defmacro defvmacro (name args &body body)
  `(defmacro ,name ,(append `(dim type) args)
     (let ((vec (vectype dim type)))
       ,@body)))

;;; actual mcm functions

(defvmacro cross-vec3 ()
  `(function ,(cintern (format nil "cross-vec3~a" (type-spec type)))
       ((,vec *out) (const ,vec *lhs) (const ,vec *rhs)) -> void
     (set out->x (- (* lhs->y rhs->z) (* lhs->z rhs->y))
	  out->y (- (* lhs->z rhs->x) (* lhs->x rhs->z))
	  out->z (- (* lhs->x rhs->y) (* lhs->y rhs->x)))))
     

(defvmacro make-vec ()
  `(function ,(cintern (format nil "make-~a" vec))
       ((,vec *out)
	,@(loop for i from 0 to (1- dim) collect `(,type ,(cn i dim)))) -> void
     ,@(loop for i from 0 to (1- dim)
	 collect `(set (pref out ,(cn i dim)) ,(cn i dim)))))

(defvmacro set-vec-component-val ()
  `(function ,(cintern (format nil "set-~a-component-val" vec))
       ((,vec *v) (int c) (,type newval)) -> void
     (set (aref (cast ,(cintern (format nil "~a*" type)) v) c)
	  newval)))

(defvmacro vec-component-val ()
  `(function ,(cintern (format nil "~a-component-val" vec))
       ((,vec *v) (int c)) -> void
     (return (aref (cast ,(cintern (format nil "~a*" type)) v) c))))

; ehm, c kann das auch mit struct=struct.
(defvmacro copy-vec ()
  `(function ,(cintern (format nil "copy-~a" vec))
       ((,vec *out) (const ,vec *in)) -> void
     ,@(loop for i from 0 to (1- dim)
	  collect `(set (pref out ,(cn i dim)) (pref in ,(cn i dim))))))

(defmacro define-component-wise-operation-macro (name op)
  (flet ((op-name (op)
  	   (ecase op
	     (/ 'div)   (* 'mul)
	     (+ 'add)   (- 'sub)
  	     (add 'add) (sub 'sub))) ; bug
	 (remap (x) (case x (add '+) (sub '-) (otherwise x)))) ; bug
    `(defvmacro ,name ()
       `(function ,(cintern (format nil "~a-components-~a" ',(op-name op) vec))
	    ((,vec *out) (const ,vec *lhs) (const ,vec *rhs)) -> void
	  ,@(loop for i from 0 to (1- dim)
	       collect `(set (pref out ,(cn i dim))
	  		     (,',(remap op)
				 (pref lhs ,(cn i dim))
				 (pref rhs ,(cn i dim)))))))))
  
;;; debugging 

;(pprint (macroexpand-1 '(set-vec-component-val 2 int)))

;;; instantiation of functions

(define-instances-of-dimension cross-vec3 3)
(define-instances make-vec 2 5)
(define-instances set-vec-component-val 2 5)
(define-instances vec-component-val 2 5)
(define-instances copy-vec 2 5)

;(pprint (macroexpand-1 '(define-component-wise-operation-macro add-comp-vec add)))
;(pprint (define-component-wise-operation-macro add-comp-vec add))
(define-component-wise-operation-macro add-comp-vec add)
(define-component-wise-operation-macro sub-comp-vec sub)
(define-component-wise-operation-macro mul-comp-vec *)
(define-component-wise-operation-macro div-comp-vec /)
(define-instances add-comp-vec 2 5)
(define-instances sub-comp-vec 2 5)
(define-instances mul-comp-vec 2 5)
(define-instances div-comp-vec 2 5)

;(function "operator<<" ((int a) (int b)) -> char `(return 9))

;; code der vektor-funktionen verwendet könnte so konfigurierbar sein
;; ...
;; (function my-function (params) -> T
;;   (macrolet ((vec-add (a b) (,my-add-version ...)))
;;     ... (vec-add x y)))...
;; 
;; also falls macrolet im code geht...

; <3
(function foo ((vec3f x) (vec3f y)) -> void
  (macrolet ((add (a b) `(add-components-vec3f ,a ,b)))
    (symbol-macrolet ((z y))
      (return (add x z)))))

