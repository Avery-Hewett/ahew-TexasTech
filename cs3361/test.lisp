;gnu clisp  2.49.60

(defun foo (a b c)
(if (< (if (< a b) a b) c) (if (< a b) a b) c))
(princ "Minimum of the three numbers is: ")
(write(foo 1 2 3))


(defun foo2(obj L)
(length L))
(princ "Length is: ")
(write(foo2 1 '(1 2 3 4 5)))

(defun towers-of-hanoi (n)
  (transfer 'A 'B 'C n))

(defun move-disk (from to)
  (list (list 'MOVE 'DISK 'FROM from 'TO to)))

(defun transfer (from to spare n)
  (cond ((equal n 1) 
     (move-disk from to))
    (t (append
           (transfer from spare to (- n 1))
        (move-disk from to)
        (transfer spare to from (- n 1))))))

(defun accept(obj L)
(startState())
(if (= -1 (nextState (cs, c))))
    (princ "false")
(isFinal(cs))
    (princ "true"))
    
