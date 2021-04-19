;gnu clisp  2.49.60

;(a) function max that gives maximal
(defun maximal (a b c)
(if (> (if (> a b) a b) c) (if (> a b) a b) c))
(princ "Maximum of the three numbers is: ")
(write(maximal 1 2 3))



;(b) foo true if x occurs in l else nil
(defun foo(obj L)
(if(zerop (length L))
nil
(if(equal(car L)obj) T
(foo obj (cdr L)))))
(print(foo 1 '(1 2 3)))
(print(foo 6 '(1 2 3)))
